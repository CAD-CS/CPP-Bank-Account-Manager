#include <vector>
#include <iostream>
#include <fstream>

#include "include/BankAccount.hpp"
#include "include/Util.hpp"
#include "include/ApplicationState.hpp"
#include "include/MenuHandlers.hpp"

int main(int argc, char *argv[])
{
  ApplicationState state = ApplicationState(createAccounts());

  char cmd;
  while (state.m_running)
  {
    displayCommandsMain();
    std::cout << "Enter command: ";
    std::cin >> cmd;

    switch (cmd)
    {

    case 'q':
      state.m_running = false;
      std::cout << "Exiting application." << std::endl;
      break;
    
    case 's':
      if (state.m_accounts.empty())
      {
        std::cout << "No accounts available." << std::endl;
      }
      else
      {
        std::cout << "Select an account by index (0 to " << state.m_accounts.size() - 1 << "): ";
        std::cin >> state.m_selectedAccountIndex;

        if (state.m_selectedAccountIndex < 0 || state.m_selectedAccountIndex >= state.m_accounts.size())
        {
          std::cout << "Invalid account index." << std::endl;
          state.m_selectedAccountIndex = -1;
        }
        else
        {
          std::cout << "Selected account: ";
          state.m_accounts[state.m_selectedAccountIndex]->print();
        }
      }
      handleSelectedMenu(state);
      break;

    default:
      std::cout << "Invalid command. Please try again." << std::endl;
      break;
    }
  }

  return 0;
}
