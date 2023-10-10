#include "Harl.hpp"

int main() {
  Harl logger;
  std::cout << "DEBUG LEVEL:" << std::endl;
  logger.complain("DEBUG");
  std::cout << "INFO LEVEL:" << std::endl;
  logger.complain("INFO");
  std::cout << "WARNING LEVEL:" << std::endl;
  logger.complain("WARNING");
  std::cout << "ERROR LEVEL:" << std::endl;
  logger.complain("ERROR");
  return 0;
}
