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
// M.Saeed Mohiti     09/20/2016    workshop2
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here
	AccountNumber obj;
	void AccountNumber::name(const char name[]) {
		strcpy (obj._name, name);
}
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) 
	{
		obj._bankCode = bankCode;
		obj._branchCode = branchCode;
		obj._accountNumber = accountNumber;

		if ((bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) && (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) && (accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO))
		obj._validAccNumber = true; 

		else 
			obj._validAccNumber = false;
		
		
	}
	bool AccountNumber::isValid() const {
		
		return obj._validAccNumber;
	}
	void AccountNumber::display() const {
		
		if(isValid())
			cout << "Name: " << obj._name << ", Account number: " << obj._bankCode << "-"
			<< obj._branchCode << "-" <<obj._accountNumber << endl;
		else
			cout <<obj._name << " does not have a valid account number." << endl;

	}
}