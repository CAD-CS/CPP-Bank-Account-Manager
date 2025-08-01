#pragma once

#include "IMenu.hpp"
#include "Util.hpp"

class MainMenu : public IMenu
{
  public:
    MainMenu(Application& app) : IMenu(app) {}
    void displayCommands() override;
    void processCommand(char &cmd) override;
    ~MainMenu() override = default;
};