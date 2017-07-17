// Date: 2016/11/02
// Author: M.Saeed Mohiti
// Date.cpp
// Project: Milestone 1
/////////////////////////////////////////////
// header files go here
#include <iomanip>
#include <iostream>
#include "Date.h"
#include "wpgeneral.h"

using namespace std;
using namespace ict;
namespace ict {
   // returns a unique value representing the date
   // this value is used to compare two dates
   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

   //Sets the _readErrorCode member variable to one of the possible values listed above.
   void Date::errCode(int errorCode) {
	   readErrorCode_ = errorCode;
   }

   // bool validate(), this is an optional private function
   // for validation logic and setting the _readErrorCode.
   // see the read() function description for more details
   void Date::validate() {
	   if (year_ < MIN_YEAR || year_ > MAX_YEAR) {
		   readErrorCode_ = YEAR_ERROR;
	   }
	   else if (mon_ < 1 || mon_ > 12) {
		   readErrorCode_ = MON_ERROR;
	   }
	   else if (day_ < 1 || day_ > mdays()) {
		   readErrorCode_ = DAY_ERROR;
	   }
	   else {
		   readErrorCode_ = NO_ERROR;
	   }
   }


   // mdays():
   // returns the day of the month.
   // _mon value must be set for this function to work
   // if _mon is invalid, this function returns -1
   // leap years are considered in this logic
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   // constructors

   Date::Date() {
	   year_ = 0;
	   mon_ = 0;
	   day_ = 0;
	   readErrorCode_ = NO_ERROR;
   }

   Date::Date(int y, int m, int d) {
	   year_ = y;
	   mon_ = m;
	   day_ = d;
	   readErrorCode_ = NO_ERROR;
   }

   // member functions
   int Date::errCode() const {
	   return readErrorCode_;
   }

   bool Date::bad() const {
	   return errCode() != NO_ERROR;
   }



   // operators
   bool Date::operator==(const Date& D) const {
	   return value() == D.value();
   }

   bool Date::operator!=(const Date& D) const {
	   return value() != D.value();
   }

   bool Date::operator<(const Date& D) const {
	   return value() < D.value();
   }

   bool Date::operator>(const Date& D) const {
	   return value() > D.value();
   }

   bool Date::operator<=(const Date& D) const {
	   return value() <= D.value();
   }

   bool Date::operator>=(const Date& D) const {
	   return value() >= D.value();
   }



   // IO functions
   std::istream& Date::read(std::istream& istr) {
	   istr >> year_;
	   if (istr.get() != '/') {
		   readErrorCode_ = CIN_FAILED;
		   return istr;
	   }
	   istr >> mon_;
	   if (istr.get() != '/') {
		   readErrorCode_ = CIN_FAILED;
		   return istr;
	   }
	   istr >> day_;
	   validate();
	   return istr;
   }

   std::ostream& Date::write(std::ostream& ostr)const {
	   ostr << year_ << "/";
	   if (mon_ < 10) {
		   ostr << "0";
	   }
	   ostr << mon_ << "/";
	   if (day_ < 10) {
		   ostr << "0";
	   }
	   ostr << day_;
	   return ostr;
   }



   // non-memeber operator overloads

   std::ostream& operator<<(std::ostream& os, const Date& D) {
	   return D.write(os);
   }

   std::istream& operator >> (std::istream& is, Date& D) {
	   return D.read(is);
   }

}
