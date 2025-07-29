#pragma once

#include <iostream>

#include "../include/ApplicationState.hpp"

ApplicationState::ApplicationState(std::vector<BankAccount*>& accounts)
    : m_selectedAccountIndex(-1),
      m_running(true),
      m_accounts(accounts),
      m_currentState(MAIN_MENU)
{
  std::cout << "ApplicationState initialized." << std::endl;
}

ApplicationState::~ApplicationState()
{
  for (auto account : m_accounts)
  {
    delete account;
  }
  m_accounts.clear();
  std::cout << "ApplicationState destroyed." << std::endl;
}
