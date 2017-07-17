// OOP244 Workshop 5: Classes with resources 
// File: w5_at_home.cpp
// Version: 1.0
// Date: 2016/10/15
// Author: M.Saeed Mohiti
// Description:
// This file tests at-Home section of your workshop
/////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Contact.h"
using namespace ict;

int main() {
	Contact c("Empty Contact", 3);
	c.display();
	cout << "Enter Contact information: " << endl;
	c.read();
	c.display();
	cout << "Please wait";
	for (int i = 0; i < 1000000; i++) {
		Contact cp = c;
		c = cp;
		if (!(i % 100000)) cout << ".";
	}
	cout << endl;
	c.display();
	return 0;
}



/* output
Empty Contact
----------------------------------------
Enter Contact information:
Contact Name: John Doe
Please enter 3 phone numbers:
1: Home, 123 1234567
2: Cell, 234 2345678
3: Work, 345 3456789
John Doe
Home..........., 123 123-4567
Cell..........., 234 234-5678
Work..........., 345 345-6789
----------------------------------------
Please wait..........
John Doe
Home..........., 123 123-4567
Cell..........., 234 234-5678
Work..........., 345 345-6789
----------------------------------------

*/