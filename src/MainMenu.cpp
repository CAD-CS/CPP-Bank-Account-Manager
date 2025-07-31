#include <iostream>

#include "../include/MainMenu.hpp"
#include "../include/AccountSelectedMenu.hpp"

void MainMenu::displayCommands()
{
  std::cout << "| Exit (q) " << "| Select account (s)" << std::endl;
}

void MainMenu::processCommand(char &cmd)
{
  switch (cmd)
  {
  case 'q':
    application.m_running = false;
    std::cout << "Exiting application." << std::endl;
    return;

  case 's':
    if (application.m_accounts.empty())
    {
      std::cout << "No accounts available." << std::endl;
      return;
    }

    application.displayAccounts();

    std::cout << "Select an account by index (0 to " << application.m_accounts.size() - 1 << "): " << std::endl;
    ;
    std::cin >> application.m_selectedAccountIndex;

    if (application.m_selectedAccountIndex < 0 || application.m_selectedAccountIndex >= application.m_accounts.size())
    {
      std::cout << "Invalid account index." << std::endl;
      application.m_selectedAccountIndex = -1;
      return;
    }

    std::cout << "Selected account: ";
    application.m_accounts[application.m_selectedAccountIndex]->print();

    changeMenu(new AccountSelectedMenu(application));

    return;

  default:
    std::cout << "Invalid command. Please try again." << std::endl;
    return;
  }
}