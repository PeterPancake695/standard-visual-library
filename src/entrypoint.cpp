#include "svl.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

#ifdef _WIN32

#else

int main(int argc, char *argv[]) {
  try {
    auto app = svl::CreateApplication();
    app->run();
    delete app;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

#endif
