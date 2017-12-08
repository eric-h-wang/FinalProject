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
	myfile.open(balance_file);
	string line;
	string old_line;
	while(getline(myfile, line))
	{
		old_line = line;
	}
	if (old_line.empty()) set_balance(10000);
	else {
		std::istringstream iss(old_line);
		double bal;
		iss >> bal;
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
		myfile << get_time() << " "<< oper << " " << amt << " " << get_balance() << endl;
		myfile.close();
	}
}

void BankAccount::deposit(double amt)
{
	set_balance(get_balance() + amt);
	write_to_file("d", amt);
}

void BankAccount::withdraw(double amt)
{
	set_balance(get_balance() - amt);
	write_to_file("w", amt);
}

void BankAccount::print_history() const
{
	string line;
	char oper;
	double amt;
	double bal;
	__time32_t aclock;
	std::ifstream myfile;
	myfile.open(hist_file);
	cout << setw(26) << "Date & Time" << setw(10) << "Operation" << setw(15) << "Amount" << setw(15) << "Balance" << endl;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::istringstream iss(line);
			iss >> aclock >> oper >> amt >> bal;
			struct tm newtime;
			char buffer[32];
			errno_t err_num;
			_localtime32_s(&newtime, &aclock);
			err_num = asctime_s(buffer, 32, &newtime);
			buffer[strlen(buffer) - 1] = '\0';
			std::ostringstream oss_a, oss_b;
			oss_a << "$" << setprecision(2) << fixed << amt;
			oss_b << "$" << setprecision(2) << fixed << bal;
			cout << setw(26) << buffer << setw(10) << (oper == 'w' ? "Withdraw" : "Deposit") << setw(15) << oss_a.str()
				<< setw(15) << oss_b.str() << endl;
		}
		myfile.close();
		cout << endl;
	}
}

void BankAccount::instruction()
{
	cout << "Please select an option: " << endl;
	cout << "1. View account balance" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print out history" << endl;
	cout << "5. Return to previous menu\n" << endl;
}