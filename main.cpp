#include <vector>
#include <iostream>
#include <fstream>

#include "include/BankAccount.hpp"
#include "include/Util.hpp"
#include "include/Application.hpp"
#include "include/MenuHandlers.hpp"

int main(int argc, char *argv[])
{
  Application state = Application(createAccounts());

  char cmd;
  while (state.m_running)
  {
    displayCommandsMain();
    std::cout << "Enter command: ";
    std::cin >> cmd;
  }

  return 0;
}
