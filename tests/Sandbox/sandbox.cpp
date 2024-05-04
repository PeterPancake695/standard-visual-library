#include "sandbox.hpp"

Sandbox::Sandbox() {}

Sandbox::~Sandbox() {}

void Sandbox::run() {

}

svl::Application *svl::CreateApplication() { return new Sandbox(); }
