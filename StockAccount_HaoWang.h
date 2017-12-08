#pragma once
#include "Account_HaoWang.h"
#include "BankAccount_HaoWang.h"
#include "MyDLinkList_HaoWang.h"
#include <string>


class StockAccount :
	public Account
{
public:
	StockAccount();
	~StockAccount();
	bool get_price(std::string, double&);
	void print_portfolio() const;
	void print_history() const;
	void plot_portfolio_value() const;
	void buy(std::string, int);
	void sell(std::string, int);
	static void instruction();
	int get_shares(std::string);
private:
	MyDLinkList portfolio;
	const char* hist_file = "stock_transaction_history.txt";
};

