#include <iostream>
#include "BankAccount_HaoWang.h"
#include "StockAccount_HaoWang.h"


using std::endl;
using std::cout;
using std::cin;

int main()
{
	BankAccount ba;
	StockAccount sa;
	int ch;
	cout << "Welcome to the Account Management System." << endl;
	while (true)
	{
		cout << "Please select an account to access: " << endl;
		cout << "1. Stock Portfolio Account" << endl;
		cout << "2. Bank Account" << endl;
		cout << "3. Exit\n" << endl;
		cout << "Option: ";
		cin >> ch;
		switch (ch) {
		case 1: cout << "Stock Account\n" << endl; sa.run(); break;
		case 2: cout << "Bank Account\n" << endl; ba.run(); break;
		case 3: return 0;
		default: cout << "Invalid choice, try again" << endl; break;
		}
	}
}