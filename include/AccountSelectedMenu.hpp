#pragma once

#include "IMenu.hpp"
#include "Util.hpp"

class AccountSelectedMenu : public IMenu
{
  public:
    AccountSelectedMenu(Application& app) : IMenu(app) {}
    void displayCommands() override;
    void processCommand(char &cmd) override;
    ~AccountSelectedMenu() override = default;
};