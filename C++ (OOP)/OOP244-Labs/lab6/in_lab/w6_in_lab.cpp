// OOP244 Workshop 6: operators
// File: w6_in_lab.cpp
// Version: 1.0
// Date: 2016/10/18
// Author: M.Saeed Mohiti
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Account.h"
using namespace ict;
using namespace std;
void displayABC(const Account& A,
	const Account& B,
	const Account& C) {
	cout << "A: " << A << endl << "B: " << B << endl
		<< "C: " << C << endl << "--------" << endl;
}
int main() {
	Account A;
	Account B("Saving", 10000.99);
	Account C("Checking", 100.99);
	displayABC(A, B, C);
	A = B + C;
	displayABC(A, B, C);
	A = "Joint";
	displayABC(A, B, C);
	A = B += C;
	displayABC(A, B, C);
	A = B += C += 100.01;
	displayABC(A, B, C);
//	cout << A<< endl;
	return 0;
}

