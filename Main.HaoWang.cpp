#include <iostream>
#include "BankAccount_HaoWang.h"
#include "StockAccount_HaoWang.h"
#include "utilities.h"


using std::endl;
using std::cout;
using std::cin;

void instruction();

int main()
{
	BankAccount ba;
	StockAccount sa; 

	int ch;
	int ch_b;
	int ch_s;
	bool return_flag;
	cout << "Welcome to the Account Management System." << endl;
	while (true) {
		get_choice(1, 3, ch, instruction); //1. Stock 2. Bank 3. Exit
		switch (ch) {
		case 1: 
			cout << "Stock Account\n" << endl; 
			return_flag = false;
			while (!return_flag) {
				get_choice(1, 7, ch_s, StockAccount::instruction);
				switch (ch_s) {
				case 1: get_price(sa); break; // get price
				case 2: sa.print_portfolio(); break; // display portfolio
				case 3: buy(ba, sa); break; // buy
				case 4: sell(ba, sa); break; // sell
				case 5: sa.plot_portfolio_value(); break; // plot portfolio value
				case 6: sa.print_history(); break; // print history
				case 7: return_flag = true; break;
				}
			}
			break;
		case 2: 
			cout << "Bank Account\n" << endl; 
			return_flag = false;
			while (!return_flag) {
				get_choice(1, 5, ch_b, BankAccount::instruction);
				switch (ch_b) {
				case 1: ba.print_balance(); break;
				case 2: deposit(ba); break;
				case 3: withdraw(ba); break;
				case 4: ba.print_history(); break;
				case 5: return_flag = true; break;
				}
			}
			break;
		case 3: return 0;
		}
	}
}

void instruction()
{
	cout << "Please select an account to access: " << endl;
	cout << "1. Stock Portfolio Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit\n" << endl;
}