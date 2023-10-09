#include <csignal>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int main(int ac, char** av) {
  if (ac != 4) {
    std::cout << "sed: ";
    std::cerr << "Usage: <filename> <str1> <str2>" << std::endl;
    return 1;
  }

  std::string s1 = av[2];
  std::string s2 = av[3];
  if (s1.empty() || s2.empty()) {
    std::cout << "sed: ";
    std::cerr << "Need strings to replace." << std::endl;
    return 1;
  }

  std::ifstream inFile;
  std::ofstream outFile;
  std::string line;
  std::string out = av[1];
  out.append(".replace");

  inFile.open(av[1], std::ios_base::in);
  if (!inFile.is_open() || !inFile.good()) {
    std::cout << "sed: ";
    std::cerr << av[1] << ": " << std::strerror(errno) << std::endl;
    return 1;
  }

  outFile.open(out.c_str(), std::ios_base::out);
  if (!outFile.is_open() || !outFile.good()) {
    std::cout << "sed: ";
    std::cerr << out << ": " << std::strerror(errno) << std::endl;
    return 1;
  }

  while (std::getline(inFile, line)) {
    size_t position = line.find(s1);
    while (position != std::string::npos) {
      line.erase(position, s1.length());
      line.insert(position, s2);
      position = line.find(s1, position + s2.length());
    }
    outFile << line;
    if (!inFile.eof()) {
      outFile << std::endl;
    }
  }
  inFile.close();
  outFile.close();
  return 0;
}
