#include <cctype>
#include <iostream>
#include <string>

int main(int argc, const char **argv) {
  const std::string yell = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  if (argc == 1) {
    std::cout << yell << std::endl;
    return (0);
  }

  std::string str;
  for (int i = 1; i < argc; ++i) {
    str.append(argv[i]);
    if (i < argc - 1) str.append(" ");
  }
  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    *it = std::toupper(*it);
  }
  std::cout << str << std::endl;
  return (0);
}
