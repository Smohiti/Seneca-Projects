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
   bool ok = true;
   Date A(2018, 10, 18);
   Date B;
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
   return 0;
}
bool equalDates(const char* A, const char* B) {
   unsigned int i;
   for (i = 0; i < sizeof(Date); i++) {
      if (A[i] != B[i]) i = sizeof(Date);
   }
   return sizeof(Date) == i;
}