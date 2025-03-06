#include "SavingAccount.h"
#include "Account.h"

using namespace Assignment3;

SavingAccount::SavingAccount(int accountNumber, std::string holdersName, double initialBalance, double rate)
	: Account(accountNumber, holdersName, initialBalance), _interestRate(0.002)
{
}

SavingAccount::SavingAccount()
{
}	

SavingAccount::~SavingAccount()
{
}

void SavingAccount::Deposit(double amount)
{
	if (amount > 0)
	{
		_balance += amount;
		std::cout << "Successfully deposited in saving account $" << amount << "\n";
	}
	else
	{
		std::cout << "Invalid amount" << "\n";
	}
}

void SavingAccount::Withdraw(double amount)
{
	if (amount > 0 && amount <= _balance)
	{
		_balance -= amount;
		std::cout << "Successfully withdrawn from saving account $" << amount << "\n";
	}
	else
	{
		std::cout << "Invalid amount" << "\n";
	}
}

void SavingAccount::DisplayDetails() const
{
	system("cls");
	Account account;
	account.AsciiArt();
	std::cout << "Saving's Account Number: " << _accountNumber << "\n";
	std::cout << "Saving's Account Holder: " << _holdersName << "\n";
	std::cout << "Saving's Account Balance: " << _balance << "\n";
	system("pause");
}

void SavingAccount::SetInterestRate(double interestRate)
{
	_interestRate = interestRate;
}

double SavingAccount::GetInterestRate() const
{
	return _interestRate;
}

void SavingAccount::CalculateAndAddInterest()
{
	double interestAmount = _balance * _interestRate;
	_balance += interestAmount;
	std::cout << "Interest earned: $" << interestAmount << std::endl;
	std::cout << "New balance after interest: $" << _balance << std::endl;
}

//
