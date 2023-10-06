/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:48 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 20:30:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) { _totalAmount += initial_deposit; }
Account::~Account() {}

void Account::displayAccountsInfos() {}
void Account::displayStatus() const {}
void Account::makeDeposit(int deposit) { (void)deposit; }
bool Account::makeWithdrawal(int withdrawal) {
  (void)withdrawal;
  return true;
}
