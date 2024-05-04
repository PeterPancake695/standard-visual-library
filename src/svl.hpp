#pragma once

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

namespace svl {

class SVLAPI Application {
public:
  Application();
  virtual ~Application();

  void run();
};

extern Application *CreateApplication();

} // namespace svl
