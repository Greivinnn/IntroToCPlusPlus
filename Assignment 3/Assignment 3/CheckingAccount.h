#pragma once
#include "Account.h"
//
namespace Assignment3
{
	class CheckingAccount : public Account
	{
	public:
		CheckingAccount(int accountNumber, std::string holdersName, double initialBalance = 0.0, double charge = 0.79);
		CheckingAccount();
		~CheckingAccount() override;
		void Deposit(double amount) override;
		void Withdraw(double amount) override;
		void DisplayDetails() const override;
		void SetServiceCharge(double serviceCharge);
	private:
		double _minimunBalance = 500;
		double _serviceCharge;
	};
}