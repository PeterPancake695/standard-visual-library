#pragma once

#include <memory>
#include <spdlog/spdlog.h>

#ifdef _WIN32
#ifdef SVL_BUILD_LIB
#define SVLAPI __declspec(dllexport)
#else
#define SVLAPI __declspec(dllimport)
#endif
#else
#ifdef SVL_BUILD_LIB
#define SVLAPI __attribute__((visibility("default")))
#endif
#endif

#ifndef SVLAPI
#define SVLAPI
#endif

#define SVL_CORE_TRACE(...)     ::svl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SVL_CORE_INFO(...)      ::svl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SVL_CORE_WARN(...)      ::svl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SVL_CORE_ERROR(...)     ::svl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SVL_CORE_CRITICAL(...)  ::svl::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SVL_TRACE(...)          ::svl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SVL_INFO(...)           ::svl::Log::GetClientLogger()->info(__VA_ARGS__)
#define SVL_WARN(...)           ::svl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SVL_ERROR(...)          ::svl::Log::GetClientLogger()->error(__VA_ARGS__)
#define SVL_CRITICAL(...)       ::svl::Log::GetClientLogger()->critical(__VA_ARGS__)


namespace svl {

void Init();

void Close();

class SVLAPI Log {
public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return s_CoreLogger;
  }
  inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return s_ClientLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

} // namespace svl

