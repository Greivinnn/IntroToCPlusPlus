#include "Account.h"
#include <string>
#include <iostream>
#include "SavingAccount.h"
#include "CheckingAccount.h"
//
using namespace Assignment3;

std::vector<Account*> Account::savingAccounts;
std::vector<Account*> Account::checkingAccounts;

Account::Account(int accountNumber, std::string holdersName, double balance)
: _accountNumber(accountNumber), _holdersName(holdersName), _balance(balance)
{
}

Account::Account()
	: _accountNumber(0), _balance(0.0)
{
}

Account::~Account()
{
}

void Account::Deposit(double amount)
{
	if (amount > 0)
	{
		_balance += amount;
	}
	else
	{
		std::cout << "Invalid amount" << std::endl;
	}
}

void Account::Withdraw(double amount)
{
	if (amount > 0 && amount <= _balance)
	{
		_balance -= amount;
	}
	else
	{
		std::cout << "Invalid amount" << std::endl;
	}
}

void Account::DisplayDetails() const
{
	std::cout << "Account Number: " << _accountNumber << std::endl;
	std::cout << "Account Holder: " << _holdersName << std::endl;
	std::cout << "Balance: " << _balance << std::endl;
}

void Account::AsciiArt()
{
	std::cout << R"(
 _______             __  __                            _______                       __       
/       \           /  |/  |                          /       \                     /  |      
$$$$$$$  |  ______  $$ |$$ |  ______    ______        $$$$$$$  |  ______   _______  $$ |   __ 
$$ |__$$ | /      \ $$ |$$ | /      \  /      \       $$ |__$$ | /      \ /       \ $$ |  /  |
$$    $$<  $$$$$$  |$$ |$$ |/$$$$$$  |/$$$$$$  |      $$    $$<  $$$$$$  |$$$$$$$  |$$ |_/$$/ 
$$$$$$$  | /    $$ |$$ |$$ |$$    $$ |$$ |  $$/       $$$$$$$  | /    $$ |$$ |  $$ |$$   $$<  
$$ |__$$ |/$$$$$$$ |$$ |$$ |$$$$$$$$/ $$ |            $$ |__$$ |/$$$$$$$ |$$ |  $$ |$$$$$$  \ 
$$    $$/ $$    $$ |$$ |$$ |$$       |$$ |            $$    $$/ $$    $$ |$$ |  $$ |$$ | $$  |
$$$$$$$/   $$$$$$$/ $$/ $$/  $$$$$$$/ $$/             $$$$$$$/   $$$$$$$/ $$/   $$/ $$/   $$/  
    )" << "\n\n";
}

void Account::SetAccountNumber(int accountNumber)
{
	_accountNumber = accountNumber;
}

void Account::SetHoldersName(std::string holdersName)
{
	_holdersName = holdersName;
}

void Account::SetBalance(double balance)
{
	_balance = balance;
}

void Account::CreateAccount()
{
	int accountNumber;
	std::string holdersName;
	double initialBalance;
	int accountType;

	system("cls");
	AsciiArt();
	std::cout << "Warning: Please create both checking and saving account before transfering funds." << "\n\n";

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;

	// Check if the account number already exists
	bool accountExists = false;
	for (const auto& account : savingAccounts) // iterator to check if the saving account number exist and matches the database
	{
		if (account->_accountNumber == accountNumber) // if the saving account number exist and matches the database
		{
			accountExists = true; // set accountExists to true
			break;
		}
	}

	if (!accountExists)	// if the saving account number does not exist and does not match the database
	{
		for (const auto& account : checkingAccounts) // iterator to check if the checking account number exist and matches the database
		{
			if (account->_accountNumber == accountNumber) // if the checking account number exist and matches the database
			{
				accountExists = true; // set accountExists to true
				break;
			}
		}
	}

	if (accountExists) // if the account number already exists
	{
		std::cout << "Account number already exists. Please choose a different account number." << "\n";
		system("pause");
		return;
	}

	std::cout << "Enter account holder's name: ";
	std::cin >> holdersName;
	std::cout << "Enter initial balance: ";
	std::cin >> initialBalance;
	std::cout << "Select account type (1 for Saving || 2 for Checking): ";
	std::cin >> accountType;

	if (accountType == 1)
	{
		SavingAccount* newSavingAccount = new SavingAccount(accountNumber, holdersName, initialBalance); //create a new saving account
		savingAccounts.push_back(newSavingAccount); // add the saving account to the saving account vector
		std::cout << "Saving account created successfully!" << "\n";
		system("pause");
		newSavingAccount->DisplayDetails();
	}
	else if (accountType == 2)
	{
		CheckingAccount* newCheckingAccount = new CheckingAccount(accountNumber, holdersName, initialBalance); //create a new checking account
		checkingAccounts.push_back(newCheckingAccount); // add the checking account to the checking account vector
		std::cout << "Checking account created successfully!" << "\n";
		system("pause");
		newCheckingAccount->DisplayDetails();
	}
	else
	{
		std::cout << "Invalid account type selected." << "\n";
	}
}

void Account::TransferLogic(double amount, Account& destinationAccount)	// transfer the amount to the destination account
{
	if (amount > 0 && amount <= _balance)
	{
		_balance -= amount;
		destinationAccount._balance += amount;
		std::cout << "Successfully transferred $" << amount << " from account "
			<< _accountNumber << " to account " << destinationAccount._accountNumber << std::endl;
	}
	else
	{
		std::cout << "Invalid amount or insufficient funds" << std::endl;
	}
}

void Account::SavingsLogic(Account& ptr, Account& checkingAccount)
{
	AsciiArt();
	ptr.DisplayDetails();
	//if saving account is called this is the logic that will be executed
	while (1)
	{
		//menu for saving account
		system("cls");
		AsciiArt();
		std::cout << "Dear " << ptr._holdersName << "\n";
		std::cout << "What would you like to do in your saving account?" << "\n";
		std::cout << "1. Deposit" << "\n";
		std::cout << "2. Withdraw" << "\n";
		std::cout << "3. View Saving Account Information" << "\n";
		std::cout << "4. Transfer to Checking Account" << "\n";
		std::cout << "5. Calculate Interest" << "\n";
		std::cout << "6. Exit" << "\n";

		int choice;
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to deposit into your saving account" << "\n";
			std::cin >> amount;
			ptr.Deposit(amount);
			system("pause");
		}
		else if (choice == 2)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to withdraw from your saving account" << "\n";
			std::cin >> amount;
			ptr.Withdraw(amount);
			system("pause");
		}
		else if (choice == 3)
		{
			ptr.DisplayDetails();
		}
		else if (choice == 4)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to transfer to your checking account" << "\n";
			std::cin >> amount;
			ptr.TransferLogic(amount, checkingAccount);	// transfer the amount to the checking account
			system("pause");
		}
		else if (choice == 5)
		{
			system("cls");
			AsciiArt();
			SavingAccount* savingPtr = dynamic_cast<SavingAccount*>(&ptr); // dynamic_cast: This is a C++ operator used for safely converting pointers or references to classes up, down, or sideways along the inheritance hierarchy.
			if (savingPtr)
			{
				savingPtr->CalculateAndAddInterest();	// calculate the interest and add it to the saving account balance
			}
			else
			{
				std::cout << "Unexpected error wow." << "\n";
			}
			system("pause");
		}
		else if (choice == 6)
		{
			std::cout << "Exiting Saving's Account" << "\n";
			break;
		}
		else
		{
			std::cout << "Invalid choice" << "\n";
			continue;
		}
	}
}

void Account::CheckingLogic(Account& ptr, Account& savingsAccount)
{
	ptr.DisplayDetails();

	while (1)
	{
		//menu for checking account
		system("cls");
		AsciiArt();
		std::cout << "Dear " << ptr._holdersName << "\n";
		std::cout << "What would you like to do in your checking account?" << "\n";
		std::cout << "1. Deposit" << "\n";
		std::cout << "2. Withdraw" << "\n";
		std::cout << "3. View Checking Account Information" << "\n";
		std::cout << "4. Transfer to Saving Account" << "\n";
		std::cout << "5. Exit" << "\n";

		int choice;
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to deposit into your checking account" << "\n";
			std::cin >> amount;
			ptr.Deposit(amount);
			system("pause");
		}
		else if (choice == 2)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to withdraw from your checking account" << "\n";
			std::cin >> amount;
			ptr.Withdraw(amount);
			system("pause");
		}
		else if (choice == 3)
		{
			ptr.DisplayDetails();
		}
		else if (choice == 4)
		{
			system("cls");
			AsciiArt();
			double amount;
			std::cout << "Enter the amount you would like to transfer to your saving account" << "\n";
			std::cin >> amount;
			ptr.TransferLogic(amount, savingsAccount); // transfer the amount to the saving account
			system("pause");
		}
		else if (choice == 5)
		{
			std::cout << "Exiting Checking Account" << "\n";
			break;
		}
		else
		{
			std::cout << "Invalid choice" << "\n";
			continue;
		}
	}
}

void Account::RunLogic()
{
	// Create 3 saving accounts and 3 checking account
	SavingAccount davidSaving(112233, "David", 1000.0);
	CheckingAccount davidChecking(112211, "David", 1000.0);
	SavingAccount johnSaving(223311, "John", 2000.0);
	CheckingAccount johnChecking(223344, "John", 2000.0);
	SavingAccount marySaving(334455, "Mary", 3000.0);
	CheckingAccount maryChecking(334466, "Mary", 3000.0);

	savingAccounts.push_back(&davidSaving);
	savingAccounts.push_back(&johnSaving);
	savingAccounts.push_back(&marySaving);

	checkingAccounts.push_back(&davidChecking);
	checkingAccounts.push_back(&johnChecking);
	checkingAccounts.push_back(&maryChecking);

	while (1)
	{
		int accountNumber;
		system("cls");
		AsciiArt();

		// Display a menu to the user with the following options:
		std::cout << "What would you like to do?" << "\n";
		std::cout << "1. Login" << "\n";
		std::cout << "2. Create an account" << "\n";
		std::cout << "3. Exit" << "\n";

		int choice;
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			AsciiArt();
			std::cout << "Which account would you like to access to?\n(1. Saving or 2. Checking)" << "\n";
			std::cin >> choice;
			if (choice == 1)
			{
				system("cls");
				AsciiArt();
				std::cout << "Please enter your saving's account number: ";
				std::cin >> accountNumber;

				Account* ptr = nullptr;	// made this pointer to point at a saving account
				Account* checkingPtr = nullptr; // made this pointer to point at the checking checking account linked to the savings account
				for (auto& account : savingAccounts) // iterator to check if the saving account number exist and matches the database
				{
					if (account->_accountNumber == accountNumber)
					{
						ptr = account;	// set ptr to point at the saving account
						break;
					}
				}

				if (ptr)	// if the saving account number exist and matches the database
				{
					for (auto& account : checkingAccounts) // iterator to check if the checking account number exist and matches the database
					{
						if (account->_holdersName == ptr->_holdersName)
						{
							checkingPtr = account; // set checkingPtr to point at the checking account linked to the saving account
							break;
						}
					}
					ptr->SavingsLogic(*ptr, *checkingPtr); // call the saving account logic, this takes in the savings account and the checking account linked to the savings account
				}
				else
				{
					std::cout << "Invalid account number" << "\n";
					system("pause");
				}
			}
			else if (choice == 2)
			{
				system("cls");
				AsciiArt();
				std::cout << "Please enter your account number (Checking): ";
				std::cin >> accountNumber;

				Account* ptr = nullptr;	// made this pointer to point at a checking account
				Account* savingPtr = nullptr; // made this pointer to point at the saving account linked to the checking account
				for (auto& account : checkingAccounts)// iterator to check if the checking account number exist and matches the database
				{
					if (account->_accountNumber == accountNumber) // if the checking account number exist and matches the database
					{
						ptr = account; // set ptr to point at the checking account
						break;
					}
				}

				if (ptr) // if the checking account number exist and matches the database
				{
					for (auto& account : savingAccounts) // iterator to check if the saving account number exist and matches the database
					{
						if (account->_holdersName == ptr->_holdersName) // if the saving account number exist and matches the database
						{
							savingPtr = account; // set savingPtr to point at the saving account linked to the checking account
							break;
						}
					}
					ptr->CheckingLogic(*ptr, *savingPtr); // call the checking account logic, this takes in the checking account and the saving account linked to the checking account
				}
				else
				{
					std::cout << "Invalid account number" << "\n";
					system("pause");
				}
			}
			else
			{
				std::cout << "Invalid choice" << "\n";
			}
		}
		else if (choice == 2)
		{
			CreateAccount();
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			std::cout << "Invalid choice" << "\n";
			continue;
		}

		
	}
}


