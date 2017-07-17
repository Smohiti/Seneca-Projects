// Final Project Milestone 1
// Faculty Submission Tester program
// File	ms1tester.cpp
// Version 1.0
// Date	2015/07/24
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2015/07/24           Preliminary release
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
   char confirm[2000];
   bool ok = true;
   Date A(2018, 10, 18);
   Date B;
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
   return 0;
}
bool equalDates(const char* A, const char* B) {
   unsigned int i;
   for (i = 0; i < sizeof(Date); i++) {
      if (A[i] != B[i]) i = sizeof(Date);
   }
   return sizeof(Date) == i;
}