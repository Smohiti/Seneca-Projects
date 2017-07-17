// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	???????????
// Author	?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			      Date	    	Reason
//                  09/20/2016    workshop2
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here

	void AccountNumber::name(const char name[]) {
		AccountNumber obj;
		strcpy_s(obj._name, name);
}
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {
		AccountNumber obj;
		obj._validAccNumber = false;
		if ((bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) || (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) || (accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO))
			obj._validAccNumber = true;
	}
	bool AccountNumber::isValid() const {
		
		return _validAccNumber;
	}
	void AccountNumber::display() const {
		
		if(isValid())
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber << endl;
		else
			cout << _name << " does not have a valid account number." << endl;

	}
}