#include <vector>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "include/BankAccount.hpp"
#include "include/Util.hpp"
#include "include/Application.hpp"

int main(int argc, char *argv[])
{
  Application app = Application(createAccounts());

  char cmd;
  while (app.m_running)
  {
    app.displayCommands();
    if (app.m_selectedAccountIndex >= 0)
    {
      std::cout << "Selected account: ";
      app.m_accounts[app.m_selectedAccountIndex]->print();
    }
    std::cout << "Enter command: ";
    std::cin >> cmd;
    app.processCommand(cmd);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();

  }

  return 0;
}
