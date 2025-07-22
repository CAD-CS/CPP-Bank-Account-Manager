#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) 
{
	std::vector<BankAccount*> accounts = createAccounts();

	std::string input;
	bool exit = 0;

	while (!exit)
	{
		std::cin >> input;

		switch (input) 
		{
			case "q":
				exit = 1;
				break;
			case "s":
				// select an account 

		}
	}
	do 
	{
		std::cin >> input;

	} while (input != "q");

	while ()
	
	for (auto account : accounts)
	{
		delete account;
	}

	return 0;
}
