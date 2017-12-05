#include "StockAccount_HaoWang.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

StockAccount::StockAccount()
{
}


StockAccount::~StockAccount()
{
}

void StockAccount::run()
{
	int ch;
	while (true)
	{
		cout << "Please select an option: " << endl;
		cout << "1. Display the price for a stock symbol" << endl;
		cout << "2. Display the current portfolio" << endl;
		cout << "3. Buy shares" << endl;
		cout << "4. Sell shares" << endl;
		cout << "5. View a graph for the portfolio value" << endl;
		cout << "6. View transaction history" << endl;
		cout << "7. Return to previous menu\n" << endl;
		cout << "Option: ";
		cin >> ch;
		switch (ch) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 7: return;
		default: cout << "Invalid choice, try again!\n" << endl; break;
		}
	}
}