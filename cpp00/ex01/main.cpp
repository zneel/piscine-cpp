#include "PhoneBook.hpp"

int main() {
  PhoneBook pb = PhoneBook();
  std::string command = "";
  pb.usage();
  while (std::getline(std::cin, command, '\n')) {
    if (command.compare("EXIT") == 0)
      std::exit(0);
    else if (command.compare("ADD") == 0)
      pb.add();
    else if (command.compare("SEARCH") == 0)
      pb.search();
    pb.usage();
  }

  return 0;
}
