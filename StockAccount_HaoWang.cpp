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

void StockAccount::print_history() const
{
	string line;
	string symbol;
	int n_share;
	double price;
	char oper;
	__time32_t aclock;
	std::ifstream myfile;
	myfile.open(hist_file);
	cout << setw(26) << "Date & Time" << setw(10) << "Event" << setw(10) << "Symbol" << setw(10) << "Number" << 
		setw(15) << "Price Per Share" << setw(15) << "Total Value" << endl;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::istringstream iss(line);
			iss >> aclock >> oper >> symbol >> n_share >> price;
			struct tm newtime;
			char buffer[32];
			errno_t err_num;
			_localtime32_s(&newtime, &aclock);
			err_num = asctime_s(buffer, 32, &newtime);
			buffer[strlen(buffer) - 1] = '\0';
			std::ostringstream oss_p, oss_t;
			oss_p << "$" << setprecision(2) << fixed << price;
			oss_t << "$" << setprecision(2) << fixed << n_share * price;
			cout << setw(26) << buffer << setw(10) << (oper == 'b' ? "Buy" : "Sell") << setw(10) << symbol
				<< setw(10) << n_share << setw(15) << oss_p.str() << setw(15) << oss_t.str() << endl;
		}
		myfile.close();
		cout << endl;
	}
}

void StockAccount::print_portfolio() const
{

}

void StockAccount::plot_portfolio_value() const
{

}

void StockAccount::buy()
{

}

void StockAccount::sell()
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
		case 1: get_price(); break;
		case 2: print_portfolio(); break;
		case 3: buy(); break;
		case 4: sell(); break;
		case 5: plot_portfolio_value(); break;
		case 6: print_history(); break;
		case 7: return;
		default: cout << "Invalid choice, try again!\n" << endl; break;
		}
	}
}