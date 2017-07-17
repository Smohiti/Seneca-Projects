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
// Name			Date		Reason
// M.Saeed Mohiti     09/20/2016    workshop2
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here
	AccountNumber obj ;
	void AccountNumber::name(const char name[]) {
		strcpy(_name, name);
	}
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber)
		
	{
		_bankCode = bankCode; 
		_accountNumber = accountNumber;
		_branchCode = branchCode;
		if ((bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) && (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) && (accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO))
			_validAccNumber = true;
		else
			_validAccNumber = false;
	}
	bool AccountNumber::isValid() const {

		return _validAccNumber;
	}


	void AccountNumber::display(bool display_name, bool display_number) const {
		if (isValid())
		{
			if (display_name == true && display_number == true)
				cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber << endl;
			else if (display_name)
			{
				displayName();
				cout << endl;
			}
			else if (display_number)
			{
				displayNumber();
				cout << endl;
			}
		}
		else
			cout << _name << " does not hve a valid account number" << endl;
	}

	void AccountNumber::displayName()const {
		cout << "Name: " << _name;

	}

	void AccountNumber::displayNumber()const {
		cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;

	}



}