#include <vector>
#include <iostream>
#include <fstream>

#include "include/BankAccount.hpp"
#include "include/Util.hpp"

int main(int argc, char* argv[]) 
{
	std::vector<BankAccount*> accounts = createAccounts();

	std::string input;
	bool exit = 0;
	
	for (auto account : accounts)
	{
		delete account;
	}

	return 0;
}
