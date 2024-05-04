#include "application.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main (int argc, char *argv[]) {
  application app;
  try {
  app.run();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  } 
  return EXIT_SUCCESS;
}
