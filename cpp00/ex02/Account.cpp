/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:48 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/07 14:31:39 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cstddef>
#include <cstring>
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _amount = 0;
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _amount += initial_deposit;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t result = std::time(0);
  std::tm *tm = std::localtime(&result);
  tm->tm_year += 1900;
  tm->tm_mon += 1;
  std::cout << "[" << tm->tm_year;
  tm->tm_mon < 10 ? std::cout << 0 << tm->tm_mon : std::cout << tm->tm_mon;
  tm->tm_mday < 10 ? std::cout << 0 << tm->tm_mday : std::cout << tm->tm_mday;
  std::cout << "_";
  tm->tm_hour < 10 ? std::cout << 0 << tm->tm_hour : std::cout << tm->tm_hour;
  tm->tm_min < 10 ? std::cout << 0 << tm->tm_min : std::cout << tm->tm_min;
  tm->tm_sec < 10 ? std::cout << 0 << tm->tm_sec : std::cout << tm->tm_sec;
  std::cout << "]";
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:" << deposit << ";amount:" << this->_amount + deposit
            << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
  this->_amount += deposit;
  _totalAmount += deposit;
  this->_nbDeposits++;
  _totalNbDeposits += this->_nbDeposits;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (this->_amount - withdrawal < 0) {
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused"
              << std::endl;
    return false;
  }
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:" << withdrawal
            << ";amount:" << this->_amount - withdrawal
            << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  _totalNbWithdrawals += this->_nbWithdrawals;
  _totalAmount -= withdrawal;
  return true;
}
