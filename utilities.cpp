#include "utilities.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

std::string print_money(double amt)
{
	std::ostringstream oss;
	oss << "$" << std::setprecision(2) << std::fixed << amt;
	return oss.str();
}

void get_choice(int start, int end, int& choice, void (*inst)(void))
{
	while (true) {
		inst();
		cout << "Option: ";
		cin >> choice;
		if (choice < start || choice > end) {
			cout << "Invalid choice, try again!\n";
			continue;
		}
		else break;
	}
}

void deposit(BankAccount& ba)
{
	double amount;
	cout << "Please enter the amount you wish to deposit (<=0 to return): $";
	cin >> amount;
	if (amount <= 0) return;
	ba.deposit(amount);
}

void withdraw(BankAccount& ba)
{
	double amount;
	while (true) {
		cout << "Please select the amount you wish to withdraw (<=0 to return): $";
		cin >> amount;
		if (amount < 0) return;
		else if (amount > ba.get_balance()) {
			cout << "You want to withdraw " << print_money(amount)
				<< ", but you only have " << print_money(ba.get_balance()) << endl;
			continue;
		}
		else {
			ba.withdraw(amount);
			break;
		}
	}
}

void get_price(StockAccount& sa)
{
	std::string symbol;
	double price;
	cout << "Please enter the stock symbol: ";
	cin >> symbol;
	transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
	if (!sa.get_price(symbol, price)) cout << "Can't find symbol!\n";
	else {
		cout << std::setw(6) << "Symbol" << std::setw(20) << "Price per share" << endl;
		cout << std::setw(6) << symbol << std::setw(20) << print_money(price) << endl;
	}
}

void buy(BankAccount& ba, StockAccount& sa) {
	std::string symbol;
	double max_price;
	double price;
	int shares;
	double total;
	cout << "Please enter the stock symbol you wish to purchase: ";
	cin >> symbol;
	transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
	if (!sa.get_price(symbol, price)) {
		cout << "Can't find symbol!\n";
		return;
	}
	cout << "Please enter the maximum amount you are willing to pay per share: ";
	cin >> max_price;
	if (max_price < price) {
		cout << "Your limit price " << print_money(max_price)
			<< " is less than the current price " << print_money(price) << endl;
		return;
	}
	cout << "Please enter the number of shares: ";
	cin >> shares;
	total = shares*price;
	if (total > ba.get_balance()) {
		cout << "Your total " << print_money(total)
			<< " is less than your bank account balance "
			<< print_money(ba.get_balance()) << endl;
		return;
	}
	sa.buy(symbol, shares);
	ba.withdraw(total);
}

void sell(BankAccount& ba, StockAccount& sa) {
	std::string symbol;
	double min_price;
	double price;
	int shares;
	int cur_shares;
	double total;
	cout << "Please enter the stock symbol you wish to purchase: ";
	cin >> symbol;
	transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
	cur_shares = sa.get_shares(symbol);
	if (!sa.get_price(symbol, price)) {
		cout << "Can't find symbol!\n";
		return;
	}
	cout << "Please enter the minimum amount you are willing to sell per share: ";
	cin >> min_price;
	if (min_price > price) {
		cout << "Your limit price " << print_money(min_price)
			<< " is higher than the current price " << print_money(price) << endl;
		return;
	}
	cout << "Please enter the number of shares: ";
	cin >> shares;
	if (shares > cur_shares) {
		cout << "The number of shares you want to sell " << shares
			<< " is larger than the number of shares you are currently holding "
			<< cur_shares << endl;
		return;
	}
	total = shares*price;
	sa.sell(symbol, shares);
	ba.deposit(total);
}