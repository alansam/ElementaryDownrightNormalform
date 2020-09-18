#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <stdexcept>
#include <cstdint>

uint64_t factorial(uint64_t val, bool report = true);

int main() {
  std::cout << "ElementaryDownrightNormalform" << std::endl;

  int RC = 0;
  uint64_t val;

  try {
    uint64_t fac;
    std::cout << "Enter a number <= 20: ";
    std::cout.flush();
    std::cin >> val;
    factorial(val);

    bool rep = false;
    if (!rep) {
      fac = factorial(val, rep);
      std::cout << val << "! = " << fac << std::endl;
    }
  }
  catch (std::exception & ex) {
    std::cerr << ex.what() << " [" << val << "!]" << std::endl;
    RC = 1;
  }

  return RC;
}

uint64_t factorial(uint64_t val, bool report) {

  if (val > 20) {
    throw std::invalid_argument("Value is out of range!");
  }

  uint64_t fac = 1;

  if (report) {
    std::cout << val << "! = ";
  }
  for (uint64_t i_ = val; i_ >= 1; --i_) {
    if (report) {
      std::cout << i_ << (i_ > 1 ? " x " : "");
    }
    fac = fac * i_;
  }
  if (report) {
    std::cout.imbue(std::locale(""));
    std::cout << '\n' << val << "! = " << fac << std::endl;
  }

  return fac;
}
