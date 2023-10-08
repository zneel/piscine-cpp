#include <iostream>
#include <string>

int main() {
  std::string hi = "HI THIS IS BRAIN";
  std::string *stringPTR = &hi;
  std::string &stringREF = hi;

  std::cout << "Addr of <hi>: " << &hi << std::endl;
  std::cout << "Addr held by <stringPTR>: " << stringPTR << std::endl;
  std::cout << "Addr held by <stringREF>: " << &stringREF << std::endl;
  std::cout << "===============================" << std::endl;
  std::cout << "Value of <hi>: " << hi << std::endl;
  std::cout << "Value pointed to by <stringPTR>: " << *stringPTR << std::endl;
  std::cout << "Value pointed to by <stringREF>: " << stringREF << std::endl;
}
