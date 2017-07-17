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
   char confirm[2000];
   bool ok = true;
   Date A(2018, 10, 18);
   Date B;
   if (ok) {
      cout << "Testing the logical operators; " << endl;
      cout << "Enter the following date, 2018/10/18: ";
      cin >> B;
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
   return 0;
}
bool equalDates(const char* A, const char* B) {
   unsigned int i;
   for (i = 0; i < sizeof(Date); i++) {
      if (A[i] != B[i]) i = sizeof(Date);
   }
   return sizeof(Date) == i;
}