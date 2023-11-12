// A simple program that computes the square root of a number
#include <iostream>
#include <string>
#include "TutorialConfig.h"

#include "MathFunctions.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
    //          and Tutorial_VERSION_MINOR
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  std::cout << argv[0] << " "  << tutorial_VERSION_MAJOR << "."
                            << tutorial_VERSION_MINOR << "."
                            << tutorial_VERSION_PATCH << "." << std::endl;

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  const double outputValue = mathfunctions::sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
