#include <iostream>

#include "../include/MainMenu.hpp"

void MainMenu::displayCommands()
{
  std::cout << "| Exit (q) " << "| Select account (s)" << std::endl;
}

void MainMenu::getCommand(char &cmd)
{
  switch (cmd)
  {
  case 'q':
    application.m_running = false;
    std::cout << "Exiting application." << std::endl;
    break;

  case 's':
    if (application.m_accounts.empty())
    {
      std::cout << "No accounts available." << std::endl;
    }
    else
    {
      displayAccounts(application.m_accounts);
      std::cout << "Select an account by index (0 to " << application.m_accounts.size() - 1 << "): ";
      std::cin >> application.m_selectedAccountIndex;

      if (application.m_selectedAccountIndex < 0 || application.m_selectedAccountIndex >= application.m_accounts.size())
      {
        std::cout << "Invalid account index." << std::endl;
        application.m_selectedAccountIndex = -1;
      }
      else
      {
        std::cout << "Selected account: ";
        application.m_accounts[application.m_selectedAccountIndex]->print();
        application.m_currentState = Application::SELECTED_MENU;
        handleSelectedMenu(application);
      }
    }
    break;

  default:
    std::cout << "Invalid command. Please try again." << std::endl;
    break;
  }
}

void MainMenu::changeMenu(IMenu* newMenu)
{
  application.changeMenu(newMenu);
}