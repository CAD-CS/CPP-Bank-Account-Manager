#include "../include/IMenu.hpp"
#include "../include/Application.hpp"

void IMenu::changeMenu(IMenu* newMenu) {
    application.changeMenu(newMenu);
}