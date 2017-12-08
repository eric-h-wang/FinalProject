#pragma once
#include "Account_HaoWang.h"
#include "BankAccount_HaoWang.h"
#include "MyDLinkList_HaoWang.h"

class StockAccount :
	public Account
{
public:
	StockAccount();
	~StockAccount();
	void run();
	void get_price();
	void print_portfolio() const;
	void print_history() const;
	void plot_portfolio_value() const;
	void buy();
	void sell();
	void set_ba(BankAccount *ba) { ptr_ba = ba; }
private:
	BankAccount *ptr_ba;
	MyDLinkList portfolio;
	const char* hist_file = "stock_transaction_history.txt";
};

