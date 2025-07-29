#include <fstream>
#include <iostream>

#include "../include/BankAccount.hpp"

BankAccount::BankAccount(std::string first, std::string last)
	: m_firstName(first), 
	m_lastName(last), 
	m_balance(0) {}

BankAccount::BankAccount(std::string first, std::string last, int balance)
	: m_firstName(first),
	m_lastName(last), 
	m_balance(balance) {}

int BankAccount::deposit(int amount) 
{
	m_balance += amount;
	return m_balance;
}

int BankAccount::withdraw(int amount) 
{
	if (m_balance - amount < 0) 
	{
		std::cout << "Insufficient funds" << std::endl;
	} else 
	{
		m_balance -= amount;
	}
	return m_balance;
}

void BankAccount::print() 
{
    std::cout << "Full name: " << getName() << " | Balance : " << m_balance << std::endl; 
}

std::string BankAccount::getName()
{
    return m_firstName + " " + m_lastName;
}

int BankAccount::getBalance() 
{
    return m_balance;
}
