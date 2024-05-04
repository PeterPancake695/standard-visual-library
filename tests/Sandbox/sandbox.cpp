#include "sandbox.hpp"

Sandbox::Sandbox() {}

Sandbox::~Sandbox() {}

svl::Application *svl::CreateApplication() { return new Sandbox(); }
