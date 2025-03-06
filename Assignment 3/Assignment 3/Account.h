#pragma once
#include <iostream>
#include <string>
#include <vector>
//
namespace Assignment3
{
	class Account
	{
	public:
		Account(int accountNumber, std::string holdersName, double initialBalance = 0.0);
		Account();
		virtual ~Account();

		static int accountCounter;
		static std::vector<Account*> savingAccounts; // Static vector to store saving accounts
		static std::vector<Account*> checkingAccounts; // Static vector to store checking accounts
		
		virtual void Deposit(double amount);
		virtual void Withdraw(double amount);
		virtual void DisplayDetails() const;

		void SetAccountNumber(int accountNumber);
		void SetHoldersName(std::string holdersName);
		void SetBalance(double balance);

		void RunLogic();
		void SavingsLogic(Account& ptr, Account& checkingAccount);
		void CheckingLogic(Account& ptr, Account& savingsAccount);
		void TransferLogic(double amount, Account& destinationAccount);
		void CreateAccount();
		void AsciiArt();
	protected:
		int _accountNumber;
		std::string _holdersName;
		double _balance;
	};
}