#include "IMenu.hpp"
#include "Util.hpp"

class MainMenu : public IMenu
{
  public:
    MainMenu(Application& app) : IMenu(app) {}
    void displayCommands() override;
    void getCommand(char &cmd) override;
    void changeMenu(IMenu* newMenu) override;
    ~MainMenu() override = default;
};