#include <iostream>

#include "../include/MenuHandlers.hpp"
#include "../include/Util.hpp"
#include "../include/BankAccount.hpp"

void handleSelectedMenu(Application& state) 
{
  while (state.m_currentState == Application::SELECTED_MENU)
  {
    displayCommandsAccount();
    std::cout << "Enter command: ";
    char cmd;
    std::cin >> cmd;
    switch (cmd)
    {
      case 'b':
        state.m_currentState = Application::MAIN_MENU;
        std::cout << "Returning to main menu." << std::endl;
        break;
      case 'd':
       int amount;
        std::cout << "Enter deposit amount: ";
        std::cin >> amount;
        if (amount > 0) 
        {
          state.m_accounts[state.m_selectedAccountIndex]->deposit(amount);
          std::cout 
            << "Deposited " << amount 
            << " to account. New balance: " 
            << state.m_accounts[state.m_selectedAccountIndex]->getBalance()
            << std::endl;
        } else
        {
          std::cout << "Invalid deposit amount." << std::endl;
        }
        break;
        case 'w':
        std::cout << "Enter withdrawal amount: ";
        std::cin >> amount;
        if (amount > 0)
        {
          state.m_accounts[state.m_selectedAccountIndex]->withdraw(amount);
          std::cout 
            << "Withdrew " << amount 
            << " from account. New balance: " 
            << state.m_accounts[state.m_selectedAccountIndex]->getBalance()
            << std::endl;
        } else
        {
          std::cout << "Invalid withdrawal amount." << std::endl;
        }
        break;
      case 't':
        std::cout << "Transfer functionality not implemented yet." << std::endl;
        handleTransferMenu(state);
        break;
      default:
        std::cout << "Invalid command. Please try again." << std::endl;
        break;
      }
  }    
}

void handleTransferMenu(Application& state) 
{
  std::cout << "Transfer functionality is not implemented yet." << std::endl;
  while (state.m_currentState == Application::TRANSFER_MENU)
  {
    displayAccounts(state.m_accounts);
    std::cout << "Select an account to transfer to (0 to " 
              << state.m_accounts.size() - 1 << "): ";
    int targetAccountIndex;
    std::cin >> targetAccountIndex;
    if (targetAccountIndex < 0 || targetAccountIndex >= state.m_accounts.size())
    {
      std::cout << "Invalid account index." << std::endl;
      continue;
    }
    int amount;
    std::cout << "Enter transfer amount: ";
    std::cin >> amount;
    if (amount <= 0)
    {
      std::cout << "Invalid transfer amount." << std::endl;
      continue;
    }
    if (state.m_accounts[state.m_selectedAccountIndex]->withdraw(amount) >= 0)
    {
      state.m_accounts[targetAccountIndex]->deposit(amount);
      std::cout << "Transferred " << amount 
                << " to account " 
                << state.m_accounts[targetAccountIndex]->getName() 
                << ". New balance: " 
                << state.m_accounts[state.m_selectedAccountIndex]->getBalance() 
                << std::endl;
      state.m_currentState = Application::SELECTED_MENU;
    } 
    else
    {
      std::cout << "Transfer failed due to insufficient funds." << std::endl;
    }
  std::cout << "Returning to selected menu." << std::endl;
  state.m_currentState = Application::SELECTED_MENU;
  }
}