#pragma once
#include "Account_HaoWang.h"
class BankAccount :
	public Account
{
public:
	BankAccount(double bal = 0);
	~BankAccount();
	void run();
	void deposit();
	void withdraw();
	void print_balance() const;
};

