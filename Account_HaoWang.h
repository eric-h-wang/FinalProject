#pragma once
class Account
{
public:
	Account(double bal = 0);
	~Account();
	virtual void run () = 0;
//	virtual void print_history() = 0;
	double get_balance() const { return balance; }
	void set_balance(double amount) { balance = amount; }
private:
	double balance;
};

