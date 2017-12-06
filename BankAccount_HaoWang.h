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
	void write_to_file(const char*, double) const;
	void print_history() const;
private:
	const char* hist_file = "bank_transaction_history.txt";
};

