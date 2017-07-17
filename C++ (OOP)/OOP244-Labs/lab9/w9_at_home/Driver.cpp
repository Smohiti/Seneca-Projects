// Date: 2016/11/19
// Author: M.Saeed Mohiti
// Driver.cpp
/////////////////////////////////////////////
#include<cstring>
#include<iostream>
#include "Driver.h"
using namespace std;
namespace sict
{
	Driver::Driver(const char* name, Car& theCar) : car_(theCar) {
		strncpy(name_, name, 31);
		car_ = theCar;
	}
	void Driver::drive() {
		car_.accelerate();
		car_.brake();
		showStatus();
	}
	void Driver::stop() {
		while (car_.speed() != 0)
			car_.brake();
		showStatus();
	}
	void Driver::showStatus() {
		cout << name_ << " is driving this car." << endl;
		cout << car_ << endl;
	}


}
