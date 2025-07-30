#pragma once

#include "Application.hpp"

class IMenu
{
  protected:
  Application& application;

  public:
  IMenu(Application& app) : application(app) {}
  virtual void displayCommands() = 0;
  virtual void getCommand(char &cmd) = 0;
  virtual void changeMenu(IMenu* newMenu) = 0;
  virtual ~IMenu() = default;
};

