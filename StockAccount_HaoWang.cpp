#include "StockAccount_HaoWang.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
using std::setw;

StockAccount::StockAccount()
{
}


StockAccount::~StockAccount()
{
}

void StockAccount::get_price()
{
	string symbol;
	string fsymbol;
	int i;
	string filename;
	string line;
	double price;
	std::ostringstream oss;
	cout << "Please enter the stock symbol: ";
	cin >> symbol;
	srand(time(NULL));
	i = rand() % 2 + 1;
	oss << "Result_" << i << ".txt";
	filename = oss.str();
	std::ifstream myfile;
	myfile.open(filename);
	while (getline(myfile, line)) {
		std::istringstream iss(line);
		iss >> fsymbol >> price;
		transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
		if (fsymbol != symbol) {
			continue;
		}
		else {
			cout << setw(6) << fsymbol << " $" << setprecision(2) << fixed << price << endl;
			return;
		}
	}
	cout << "Can't find symbol " << symbol << endl;
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
		case 1: get_price(); break;
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