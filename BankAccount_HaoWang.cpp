#include "BankAccount_HaoWang.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

BankAccount::BankAccount()
{
}


BankAccount::~BankAccount()
{
}

void BankAccount::run()
{
	int ch;
	while (true)
	{
		cout << "Please select an option: " << endl;
		cout << "1. View account balance" << endl;
		cout << "2. Deposit money" << endl;
		cout << "3. Withdraw money" << endl;
		cout << "4. Print out history" << endl;
		cout << "5. Return to previous menu\n" << endl;
		cin >> ch;
		cout << "Option: " << ch << endl;
		switch (ch) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: return;
		default: cout << "Invalid choice, try again!\n" << endl; break;
		}
	}
}
