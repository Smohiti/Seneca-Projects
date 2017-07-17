
// Date: 2016/10/18
// Author: M.Saeed Mohiti
// Account.cpp
/////////////////////////////////////////////
#include <iomanip>
#include <cstring>
#include "Account.h"

using namespace std;

namespace ict{

    void Account::display(bool gotoNewline)const{
        cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }


    Account::Account(){
        name_[0] = 0;
        balance_ = 0;
    }
    Account::Account(double balance){
        name_[0] = 0;
        balance_ = balance;
    }
    Account::Account(const char name[], double balance){
        strcpy(name_, name);
        balance_ = balance;
    }

	Account & Account::operator += (const Account &object) {
		balance_ += object.balance_;
		return *this;
	}
	Account & Account::operator = (const char newname[40]) {
		strncpy(name_ , newname, 41);
		return *this;
	}
	Account operator + (const Account &object, const Account &object2) {
		Account obj3;
		//obj3.name_[0] = '\0';
		obj3.balance_ = object.balance_ + object2.balance_;

		return obj3;
	}
	ostream& operator<<(ostream& os, const Account& a) {
		a.display(false);
		return os;
	}

}