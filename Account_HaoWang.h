#pragma once
class Account
{
public:
	Account();
	~Account();
	virtual void print_history() const {};
	double get_balance() const { return balance; }
	void set_balance(double amount) { balance = amount; }
private:
	double balance;
};

