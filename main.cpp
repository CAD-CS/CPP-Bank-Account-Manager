#include <vector>
#include <iostream>
#include <fstream>

#include "BankAccount.hpp"

std::vector<BankAccount*> createAccounts() 
{
	std::ifstream reader("data/input.txt");

	if (!reader.is_open()) 
	{
		std::cout << "Somthing went wrong with opening the file" << std::endl;
	}

	std::string firstName;
	std::string lastName;
	int initBalance;

	std::vector<BankAccount*> vec_bankAccount;
	BankAccount* p_temp;

	while (reader >> firstName >> lastName >> initBalance)
	{
		p_temp = new BankAccount(firstName, lastName, initBalance);
		p_temp->print();
		vec_bankAccount.push_back(p_temp);

	}
	reader.close();
	return vec_bankAccount;
}

int main(int argc, char* argv[]) 
{
	std::vector<BankAccount*> accounts = createAccounts();

	for (auto account : accounts)
	{
		delete account;
	}

	return 0;
}
