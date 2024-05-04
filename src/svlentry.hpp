#pragma once

#include "svl.hpp"
#include <cstdlib>
#include <exception>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace svl {
class SVLAPI Application {
public:
  Application();
  virtual ~Application();

  virtual void run();
};

extern Application *CreateApplication();
} // namespace svl

svl::Application::Application() {}

svl::Application::~Application() {}

void svl::Application::run() {}

#ifdef _WIN32

#else

int main(int argc, char *argv[]) {
  spdlog::set_pattern("%^[%T] %n: %v%$");
  std::shared_ptr<spdlog::logger> CriticalLogger;
  CriticalLogger = spdlog::stderr_color_mt("SVL CRITICAL ERROR");
  CriticalLogger->set_level(spdlog::level::critical);
  try {
    svl::Init();
    auto app = svl::CreateApplication();
    app->run();
    delete app;
    svl::Close();
  } catch (std::exception &e) {
    CriticalLogger->critical(e.what());
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

#endif
