#pragma once
#include "Account_HaoWang.h"
class StockAccount :
	public Account
{
public:
	StockAccount();
	~StockAccount();
	void run();
	void get_price();
};

