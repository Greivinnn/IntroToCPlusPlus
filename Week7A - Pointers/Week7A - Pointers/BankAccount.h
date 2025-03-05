#pragma once

class BankAccount
{
public:
	BankAccount()	// constructor
	{
		_amount = 0;
	}
	~BankAccount() // deestructor
	{
		_amount = 0;
	}

	void SetAmount(int amount)
	{
		_amount = amount;
	}
private:
	int _amount;
};