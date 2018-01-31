/*
* Name : practical1.cpp
* Purpose: To test the Account class
* Author : David McElhinney
* Version: 1.0
*/
#include "Account.h"
#include <iostream>
#include <string>

// means we don't have to prefix cout and endl with std::
using namespace std;

// Post: Print menu, accept user character input and return uppercase character
char getOption() {

	char option;
	cout << endl << "P-print, D-deposit, W-withdraw, O-overdraft, Q-quit: ";
	cin >> option;

	// toupper - standard C++ function to convert char to uppercase
	return toupper(option);
}

 // main method displays menu and processes user inputs until quit option selected
int main() {
	float amount; // user input
	char option = getOption(); // get initial user option

	Account a{ "123456" }; // create test account

	// sentinel controlled loop repeats until option is 'q' (quit)
	while (option != 'Q') {
		// complete sentinel loop to process each possible menu option

		if (option == 'P') {

			cout << a.toString() << endl;
		} else if (option == 'D') {

			cout <<  endl << "Please enter the amount you wish to deposit: ";
			cin >> amount;

			if (amount > 0.0f) {
				a.deposit(amount);
				cout << "Deposit succesful" << endl;
			} else {
				cout << "Insufficient deposit" << endl;
			}
			
		} else if (option == 'W') {

			cout << endl << "Please enter the amount you wish to withdraw: ";
			cin >> amount;

			if (a.getBalance() > 0.0f) {
				a.withdraw(amount);
				cout << "Withdrawal succesful" << endl;
			} else {
				cout << "Insufficient funds" << endl;
			}
		} else if (option == 'O') {

			cout << endl << "please enter the overdraft you wish to set: ";
			cin >> amount;

			if (amount >= 0.0f && a.getOverdraft() >= (a.getOverdraft() - a.getBalance())) {
				a.setOverdraft(amount);
				cout << "Overdraft set succesfully" << endl;
			} else { 
				cout << "Invalid overdraft" << endl;
			}
		}
		option = getOption();
	}

	cout << "thank-you for using account program" << endl;

	return 0;
}