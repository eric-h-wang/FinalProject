#pragma once
class Account
{
public:
	Account();
	~Account();
	virtual void run () = 0;
//	virtual void print_history() = 0;
private:
	double balance;
};

