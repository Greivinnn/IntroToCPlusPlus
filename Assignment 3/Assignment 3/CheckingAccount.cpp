#include "CheckingAccount.h"
#include "Account.h"
#include <iostream>
//
using namespace Assignment3;

CheckingAccount::CheckingAccount(int accountNumber, std::string holdersName, double balance, double charge)
	:Account(accountNumber, holdersName, balance), _serviceCharge(charge)
{
}

CheckingAccount::CheckingAccount()
{
}

CheckingAccount::~CheckingAccount()
{
}

void CheckingAccount::Deposit(double amount)
{
	if (amount > 0)
	{
		_balance += amount;
		std::cout << "Successfully deposited in checking account $" << amount << "\n";
	}
	else
	{
		std::cout << "Invalid amount" << "\n";
	}
}

void CheckingAccount::Withdraw(double amount)
{
	if (amount > 0 && amount <= _balance)
	{
		_balance -= amount;
		std::cout << "Successfully withdrawn from checking account $" << amount << "\n";

		if (_balance < _minimunBalance)
		{
			std::cout << "Warning: Balance below minimum requirement of $" << _minimunBalance << "\n";
			std::cout << "Applying service charge of $" << _serviceCharge << "\n";
			_balance -= _serviceCharge;
			std::cout << "New balance after service charge: $" << _balance << "\n";
		}
	}
	else
	{
		std::cout << "Invalid amount" << "\n";
	}
}

void CheckingAccount::DisplayDetails() const
{
	system("cls");
	Account account;
	account.AsciiArt();
	std::cout << "Checking's Account Number: " << _accountNumber << "\n";
	std::cout << "Checking's Account Holder: " << _holdersName << "\n";
	std::cout << "Checking's Balance: " << _balance << "\n";
	std::cout << "Minimum Balance Requirement: $" << _minimunBalance << "\n\n";

	if (_balance < _minimunBalance)
	{
		std::cout << "Notice: Your balance is below the minimum requirement.\n";
		std::cout << "Service charge of $" << _serviceCharge << " applied.\n\n";
	}
	system("pause");
}

void CheckingAccount::SetServiceCharge(double serviceCharge)
{
	_serviceCharge = serviceCharge;
}


