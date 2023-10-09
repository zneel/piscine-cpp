#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

/**
 * @brief
 *
 * @return int
 */
int Contact::getId() { return this->id_; }

/**
 * @brief
 *
 * @param idx
 */
void Contact::setId(int idx) { this->id_ = idx; }

/**
 * @brief
 * Display a line of the contact
 */
void Contact::displayLine() {
  if (this->id_ >= 0) {
    std::string firstName = this->firstName_;
    if (firstName.size() > 10) firstName = firstName.substr(0, 9) + ".";
    std::string lastName = this->lastName_;
    if (lastName.size() > 10) lastName = lastName.substr(0, 9) + ".";
    std::string nickName = this->nickName_;
    if (nickName.size() > 10) nickName = nickName.substr(0, 9) + ".";

    std::cout << "|" << std::right << std::setw(10) << this->id_ << "|"
              << std::setw(10) << firstName << "|" << std::setw(10) << lastName
              << "|" << std::setw(10) << nickName << "|" << std::endl;
  }
}

/**
 * @brief
 * Display the full contact
 */
void Contact::displayFull() {
  std::cout << "⏵ Index: " << this->id_ << std::endl;
  std::cout << "⏵ Firstname: " << this->firstName_ << std::endl;
  std::cout << "⏵ Lastname: " << this->lastName_ << std::endl;
  std::cout << "⏵ Nickname: " << this->nickName_ << std::endl;
  std::cout << "⏵ Phone number: " << this->phoneNumber_ << std::endl;
  std::cout << "⏵ Darkest Secret: " << this->darkestSecret_ << std::endl;
}

/**
 * @brief
 *  Set the id of the contact and prompt the user for the other fields
 * @param idx
 */
void Contact::add(int idx) {
  this->id_ = idx;
  this->firstName_ = prompt("Enter the first name: ");
  this->lastName_ = prompt("Enter the last name: ");
  this->nickName_ = prompt("Enter the nickname: ");
  this->darkestSecret_ = prompt("Enter the darkest secret: ");
  this->phoneNumber_ = prompt("Enter the phone number: ");
}

/**
 * @brief
 * Prompt the user for an input
 * @param prompt
 * @return
 */
std::string Contact::prompt(std::string prompt) {
  std::string input = "";
  std::cout << prompt << std::endl;
  std::cout << "> ";
  while (std::getline(std::cin, input) && input.empty()) {
    if (input.size() == 0) {
      std::cout << prompt << std::endl;
      std::cout << "> ";
      continue;
    }
  }
  if (std::cin.bad() || std::cin.eof()) std::exit(0);
  return input;
}
