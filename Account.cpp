/* *******************************************************
* Name   : Account.h
* Purpose: Implementation of an Account containing a balance
* Author : David McElhinney
* Version: 1.1
* ******************************************************/


// Implementation of Account.h
#include "Account.h"
#include <string>
// PreCondition: the account has sufficient funds
// PostConditon: balance is reduced by amount
void Account::withdraw(float amount) {

	if (amount <= (balance + overdraft)) {
		balance -= amount;
	}
}
// PreCondition: amount is a positive non-zero value
// PostCondition: amount is added to balance
void Account::deposit(float amount) {

	if (amount > 0.0f) {
		balance += amount;
	}
}

// PostCondition: balance amount is returned
float Account::getBalance() const {
	return balance;
};

// PostCondition: overdtaft amount is returned
float Account::getOverdraft() {
	return overdraft;
}

// PreCondition: over is a positive non-zero value
// PostCondition: overdtaft amount is changed
void Account::setOverdraft(float over) {

	if (over >= 0.0f && overdraft >= (overdraft - balance)) {
		overdraft = over;
	}
}

// PostCondition: customer name is returned
std::string Account::getCustomer() const {
	return customer;
}

// PostCondition: customer name is updated
void Account::setCustomer(std::string cust) {
	customer = cust;
}

// PostCondition: returns string representation of account
std::string Account::toString() const {
	return "Customer: " + customer + " Balance: " + std::to_string(balance) +
		" Overdraft: " + std::to_string(overdraft);
}

// Overload the equality operator
bool Account::operator==(const Account& right) const {

	if (balance != right.balance || customer != right.customer || overdraft != right.overdraft) {
		return false;
	}
	return true;
}

// Overload the less than operator
bool Account::operator<(const Account& right) const {

	return balance < right.balance;
}