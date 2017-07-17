// Final Project Milestone 1
// Faculty Submission Tester program
// File	oop_ms1AllTests.cpp
// Version 1.0
// Date	2016/11/02
// Author	M.Saeed Mohiti
// Description
// This program test the student implementation of the Date class
// for submission.
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Date.h"
#include "wpgeneral.h"
using namespace std;
using namespace ict;
bool equalDates(const char* A, const char* B);
int main() {
   int ret = 0;
   bool ok = true;
   Date A(2018, 10, 18);
   Date B;
   if (ok) {
      cout << "Checking defined values, wpgeneral.h: " << endl;
   }
   if (ok && MIN_YEAR != 2000) {
      cout << "MIN_YEAR must be 2000" << endl;
      ok = false;
   }
   if (ok && MAX_YEAR != 2030) {
      cout << "MAX_YEAR must be 2030" << endl;
      ok = false;
   }
   if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)) {
      cout << "TAX must be 0.13" << endl;
      ok = false;
   }
   if (ok && MAX_UPC_LEN != 7) {
      cout << "MAX_UPC_LEN must be 7" << endl;
      ok = false;
   }
   if (ok && MAX_NO_RECS != 2000) {
      cout << "MAX_NO_RECS must be 2000" << endl;
      ok = false;
   }
   if (ok) {
      cout << "Passed!" << endl;
      cout << "Checking define values for error code in Data.h" << endl;
   }
   if (ok && NO_ERROR != 0) {
      cout << "NO_ERROR must be 0" << endl;
      ok = false;
   }
   if (ok && CIN_FAILED != 1) {
      cout << "CIN_FAILED must be 1" << endl;
      ok = false;
   }
   if (ok && YEAR_ERROR != 2) {
      cout << "YEAR_ERROR must be 2" << endl;
      ok = false;
   }
   if (ok && MON_ERROR != 3) {
      cout << "MON_ERROR must be 3" << endl;
      ok = false;
   }
   if (ok && DAY_ERROR != 4) {
      cout << "DAY_ERROR must be 4" << endl;
      ok = false;
   }
   if (ok) {
      cout << "Passed!" << endl;
   }
   if (ok) {
      cout << "Testing Date constructor and operator>> overload; " << endl;
      cout << "enter the following date, 2018/10/18: ";
      cin >> B;

      if (!equalDates((const char*)&A, (const char*)&B)) {
         cout << "Either the constructor or operator>> is not implemented correctly." << endl;
         ok = false;
      }
      else {
         cout << "Passed!" << endl;
      }
   }
   if (ok) {
      cout << "Testing the logical operators: " << endl;
   }
   if (ok) {
      cout << "testing operator==" << endl;
      if (A == B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      cout << "testing operator>=" << endl;
      if (A >= B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      cout << "testing operator<=" << endl;
      if (A <= B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
         ok = false;
      }
   }

   A = Date(2018, 10, 17);
   if (ok) {
      cout << "testing operator!=" << endl;
      if (A != B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      cout << "testing operator<" << endl;
      if (A < B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      cout << "testing operator>" << endl;
      if (B > A) {
         cout << "passed!" << endl;
      }
      else {
         cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      cout << "testing operator<=" << endl;
      if (A < B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      cout << "testing operator>=" << endl;
      if (B >= A) {
         cout << "passed!" << endl;
      }
      else {
         cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      cout << "Testing error handling in read funciton;" << endl;
      cout << "cin faliure detection, " << endl;
      cout << "Please enter the following string \"abcd\": ";
      cin >> A;
      if (A.errCode() == CIN_FAILED) {
         cout << "passed!" << endl;
      }
      else {
         cout << "Your read function does not check cin.fail() after entry," << endl
            << "or it did not set readErrorCode_ to CIN_FAILED" << endl;
         ok = false;
      }
      cin.clear();
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "Year validation, " << endl;
      cout << "Please enter the following string \"10/1/1\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == YEAR_ERROR) {
         cout << "passed!" << endl;
      }
      else {
         cout << "Your read function does not check the year entry limits after entry," << endl
            << "or it did not set readErrorCode_ to YEAR_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "Month validation, " << endl;
      cout << "Please enter the following string \"2000/13/1\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == MON_ERROR) {
         cout << "Passed" << endl;
      }
      else {
         cout << "Your read function does not check the month entry limits after entry," << endl
            << "or it did not set readErrorCode_ to MON_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "Day validation, " << endl;
      cout << "Please enter the following string \"2000/1/50\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == DAY_ERROR) {
         cout << "Passed!" << endl;
      }
      else {
         cout << "Your read function does not check the day entry limits after entry," << endl
            << "or it did not set readErrorCode_ to DAY_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "Day validation, leap year:" << endl;
      cout << "Please enter the following string \"2016/2/29\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == DAY_ERROR) {
         cout << "Your read function does not check the day entry limits using mday()" << endl;
         ok = false;
      }
      else {
         cout << "passed!" << endl;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "You passed all the tests." << endl;
   }
   else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
      ret = 1;
   }

   return ret;
}
bool equalDates(const char* A, const char* B) {
   unsigned int i;
   for (i = 0; i < sizeof(Date); i++) {
      if (A[i] != B[i]) i = sizeof(Date);
   }
   return sizeof(Date) == i;
}