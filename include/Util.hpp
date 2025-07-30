#pragma once

#include <vector>

#include "BankAccount.hpp"

std::vector<BankAccount*> createAccounts();
void displayCommandsMain();
void displayCommandsAccount();
void displayAccounts(const std::vector<BankAccount*>& accounts);
void clearScreen();