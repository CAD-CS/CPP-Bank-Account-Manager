#include <vector>

#include "BankAccount.hpp"
#include "Util.hpp"

class ApplicationState
{
  public:

    enum State
    {
        MAIN_MENU,
        ACCOUNT_MENU,
        SELECTED_MENU,
        EXIT
    };

    std::vector<BankAccount*> m_accounts;
    int m_selectedAccountIndex;
    bool m_running;

    ApplicationState(std::vector<BankAccount*>& accounts);
    ~ApplicationState();
};