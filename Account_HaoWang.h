#pragma once
class Account
{
public:
	Account();
	~Account();
	virtual void run () = 0;
	virtual void print_history() const {};

	double get_balance() const { return balance; }
	void set_balance(double amount) { balance = amount; }
private:
	double balance;
};

