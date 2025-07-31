#pragma once

class Application;

class IMenu
{
  protected:
  Application& application;

  public:
  IMenu(Application& app) : application(app) {}
  virtual void displayCommands() = 0;
  virtual void processCommand(char &cmd) = 0;
  virtual void changeMenu(IMenu* newMenu);
  virtual ~IMenu() = default;
};

