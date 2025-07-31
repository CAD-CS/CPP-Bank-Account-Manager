#include <iostream>

#include "../include/Application.hpp"
#include "../include/MainMenu.hpp"

Application::Application(std::vector<BankAccount*> accounts)
    : m_selectedAccountIndex(-1),
      m_running(true),
      m_accounts(std::move(accounts)),
      m_menu(nullptr)
{
  m_menu = new MainMenu(*this);
  std::cout << "Application initialized." << std::endl;
}

Application::~Application()
{
  for (auto account : m_accounts)
  {
    delete account;
  }
  m_accounts.clear();
  std::cout << "Application destroyed." << std::endl;
}

void Application::displayCommands()
{
  if (m_menu)
  {
    m_menu->displayCommands();
  }  
  else
  {
    std::cout << "No menu available." << std::endl;
  }
}

void Application::processCommand(char &cmd)
{
  if (m_menu)
  {
    m_menu->processCommand(cmd);
  }
  else
  {
    std::cout << "No menu available to get command." << std::endl;
  }
}

void Application::changeMenu(IMenu* newMenu)
{
  if (m_menu)
  {
    delete m_menu;
  }
  m_menu = newMenu;
  std::cout << "Menu changed." << std::endl;
}

void Application::displayAccounts()
{
  if (m_accounts.empty())
  {
    std::cout << "No accounts available." << std::endl;
    return;
  }

  std::cout << "Available accounts:" << std::endl;
  for (size_t i = 0; i < m_accounts.size(); ++i)
  {
    std::cout << i << ": ";
    m_accounts[i]->print();
  }
}