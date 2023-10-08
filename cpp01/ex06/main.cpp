#include "Harl.hpp"

int main(int ac, char** av) {
  if (ac != 2) return (1);
  Harl logger;
  std::string in = av[1];
  logger.complain(in);
  return 0;
}
