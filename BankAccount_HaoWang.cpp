#include "BankAccount_HaoWang.h"
#include <iostream>
#include <iomanip>

using std::endl;
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;

BankAccount::BankAccount(double bal) : Account(bal)
{
}


BankAccount::~BankAccount()
{
}

void BankAccount::print_balance() const
{
	cout << "You have $" << setprecision(2) << fixed << get_balance() << " in your bank account.\n";
}

void BankAccount::deposit()
{
	double amount;
	cout << "Please select the amount you wish to deposit: $";
	cin >> amount;
	while (amount < 0) {
		cout << "The amount cannot be negative, try again\n";
		cout << "Please select the amount you wish to deposit: $";
		cin >> amount;
	}
	set_balance(get_balance() + amount);
}

void BankAccount::withdraw()
{
	double amount;
	while (true) {
		cout << "Please select the amount you wish to withdraw: $";
		cin >> amount;
		if (amount < 0) {
			cout << "The amount cannot be negative, try again\n";
			continue;
		}
		else if (amount > get_balance()) {
			cout << "Not enough money, try again\n";
			continue;
		}
		else {
			set_balance(get_balance() - amount);
			break;
		}
	}
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
		cout << "Option: ";
		cin >> ch;
		switch (ch) {
		case 1: print_balance(); break;
		case 2: deposit(); break;
		case 3: withdraw(); break;
		case 4: break;
		case 5: return;
		default: cout << "Invalid choice, try again!\n" << endl; break;
		}
	}
}
