#include "BankAccount_HaoWang.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <string>
#include <sstream>

using std::endl;
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;
using std::string;


__time32_t get_time()
{
	__time32_t aclock;
	_time32(&aclock);
	return aclock;
}

BankAccount::BankAccount()
{
	std::ifstream myfile;
	myfile.open(hist_file);
	string line;
	string new_line;
	getline(myfile, new_line);
	if (new_line.empty()) set_balance(0);
	else
	{
		while (!new_line.empty())
		{
			line = new_line;
			getline(myfile, new_line);
		}
		std::istringstream iss(line);
		char c;
		unsigned long int i;
		double bal;
		iss >> i >> c >> c >> c >> bal >> c >> bal;
		set_balance(bal);
	}
	myfile.close();
}


BankAccount::~BankAccount()
{
}

void BankAccount::print_balance() const
{
	cout << "You have $" << setprecision(2) << fixed << get_balance() << " in your bank account.\n";
}

void BankAccount::write_to_file(const char* oper, double amt) const
{
	std::ofstream myfile;
	myfile.open(hist_file, std::ios::app);
	if (myfile.is_open())
	{
		myfile << get_time() << ","<< oper << "," << amt << "," << get_balance() << endl;
		myfile.close();
	}
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
	write_to_file("d", amount);
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
			write_to_file("w", amount);
			break;
		}
	}
}

void BankAccount::print_history() const
{
	string line;
	char oper;
	double amt;
	double bal;
	char separator;
	__time32_t aclock;
	std::ifstream myfile;
	myfile.open(hist_file);
	cout << setw(26) << "Date & Time" << setw(10) << "Operation" << setw(10) << "Amount" << setw(10) << "Balance" << endl;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::istringstream iss(line);
			iss >> aclock >> separator >> oper >> separator >> amt >> separator >> bal;
			struct tm newtime;
			char buffer[32];
			errno_t err_num;
			_localtime32_s(&newtime, &aclock);
			err_num = asctime_s(buffer, 32, &newtime);
			buffer[strlen(buffer) - 1] = '\0';
			cout << setw(26) << buffer << setw(10) << (oper == 'w' ? "Withdraw" : "Deposit") << setw(10) << amt
				<< setw(10) << bal << endl;
		}
		myfile.close();
		cout << endl;
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
		case 4: print_history(); break;
		case 5: return;
		default: cout << "Invalid choice, try again!\n" << endl; break;
		}
	}
}
