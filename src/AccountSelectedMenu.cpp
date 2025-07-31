#include <iostream>

#include "../include/AccountSelectedMenu.hpp"
#include "../include/MainMenu.hpp"

void AccountSelectedMenu::displayCommands()
{
  std::cout << "| Back to main menu (b) " << "| Deposit (d) " << "| Withdraw (w) " << "| Transfer money from this account to another one (t) "<< std::endl;
}

void AccountSelectedMenu::processCommand(char &cmd)
{
  switch (cmd)
  {
  case 'b':
    std::cout << "Returning to the main menu." << std::endl;
    changeMenu(new MainMenu(application));
    return;

  case 'd':
    int amount;
    std::cout << "Amount to deposit: " << std::endl;
    std::cin >> amount;

    if (amount <= 0) std::cout << "Invalid deposit amount." << std::endl;

    application.m_accounts[application.m_selectedAccountIndex]->deposit(amount);
    return;

  case 'w':
    int amount;
    std::cout << "Amount to withdraw: " << std::endl;
    std::cin >> amount;

    if (amount <= 0 || amount > application.m_accounts[application.m_selectedAccountIndex]->getBalance()) 
    {
      std::cout << "Invalid withdrawal amount." << std::endl;
      return;
    }

    application.m_accounts[application.m_selectedAccountIndex]->withdraw(amount);
    return;

  case 't':
    std::cout << "Please select the account to transfer money to: " << std::endl;
    application.displayAccounts();
    int targetIndex;
    std::cin >> targetIndex;

    if (targetIndex < 0 || targetIndex >= application.m_accounts.size() || targetIndex == application.m_selectedAccountIndex)
    {
      std::cout << "Invalid account selection." << std::endl;
      return;
    }

    std::cout << "Amount to transfer: " << std::endl;
    std::cin >> amount;

    if (amount <= 0 || amount > application.m_accounts[application.m_selectedAccountIndex]->getBalance())
    {
      std::cout << "Invalid transfer amount." << std::endl;
      return;
    }

    application.m_accounts[application.m_selectedAccountIndex]->withdraw(amount);
    application.m_accounts[targetIndex]->deposit(amount);
    
    return;

  default:
    std::cout << "Invalid command. Please try again." << std::endl;
    return;
  }
}