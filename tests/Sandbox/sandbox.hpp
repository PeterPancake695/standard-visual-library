#pragma once
#include "../../src/svl.hpp"
#include "../../src/svlentry.hpp"

class Sandbox : public svl::Application {
public:
  Sandbox();

  ~Sandbox();

  void run() override;
};
