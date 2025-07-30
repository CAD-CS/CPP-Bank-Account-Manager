#pragma once

#include <vector>

#include "BankAccount.hpp"
#include "IMenu.hpp"
#include "Util.hpp"

class Application
{
  IMenu* m_menu;

  public:

    std::vector<BankAccount*> m_accounts;
    int m_selectedAccountIndex;
    bool m_running;

    Application(std::vector<BankAccount*> accounts);
    ~Application();
    void displayCommands();
    void getCommand(char &cmd);
    void changeMenu(IMenu* newMenu);
    
};