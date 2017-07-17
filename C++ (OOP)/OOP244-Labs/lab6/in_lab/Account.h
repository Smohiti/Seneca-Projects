// Date: 2016/10/18
// Author: M.Saeed Mohiti
// Account.h
/////////////////////////////////////////////
#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict{
   class Account{
      char name_[41];
      double balance_;
   public:

      void display(bool gotoNewline = true)const;

      Account();
      Account(double balance);
      Account(const char name[], double balance = 0.0);
	  Account & operator += (const Account &object);
	  Account & operator = (const char newname[40]);
	  friend Account operator + (const Account &object, const Account &object2);
	  
   };
   
   std::ostream& operator<<(std::ostream& os, const Account& a);
}

#endif
