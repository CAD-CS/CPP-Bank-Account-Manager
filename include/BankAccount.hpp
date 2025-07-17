#include <string>

/*
Basic class representing a user's account
*/

class BankAccount 
{
	private:
		int m_balance;
		std::string m_firstName;
		std::string m_lastName;
	
	public:
		BankAccount(std::string first, std::string last);
		BankAccount(std::string first, std::string last, int balance);
		
		int deposit(int amount);
		int withdraw(int amount);
		void print();
};
