#pragma once
#include "Account_HaoWang.h"
class BankAccount :
	public Account
{
public:
	BankAccount();
	~BankAccount();
	void deposit(double);
	void withdraw(double);
	void print_balance() const;
	void write_to_file(const char*, double) const;
	void print_history() const;
	const char* get_balance_file() const { return balance_file; }
	static void instruction();
private:
	const char* hist_file = "bank_transaction_history.txt";
	const char* balance_file = "portfolio_value.txt";
};

