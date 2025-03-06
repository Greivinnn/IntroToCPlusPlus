#pragma once
#include "Account.h"
//
namespace Assignment3
{
	class SavingAccount : public Account
	{
	public:
		SavingAccount(int accountNumber, std::string holdersName, double balance = 0.0, double rate = 0.002);
		SavingAccount();
		~SavingAccount() override;
		void Deposit(double amount) override;
		void Withdraw(double amount) override;
		void DisplayDetails() const override;
		void SetInterestRate(double interestRate);
		double GetInterestRate() const;
		void CalculateAndAddInterest();
	private:
		double _interestRate;
	};
}