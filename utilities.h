#pragma once
#include "BankAccount_HaoWang.h"
#include "StockAccount_HaoWang.h"
#include <string>

void get_choice(int, int, int&, void (*)(void));
std::string print_money(double);
void deposit(BankAccount&);
void withdraw(BankAccount&);
void get_price(StockAccount&);
void buy(BankAccount&, StockAccount&);
void sell(BankAccount&, StockAccount&);