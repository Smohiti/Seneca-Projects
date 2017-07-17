// Date: 2016/11/19
// Author: M.Saeed Mohiti
// Driver.h
/////////////////////////////////////////////
#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_
#include "Car.h"

namespace sict
{
	class Driver :public Car
	{
	private:
		// private members go here
		char name_[31];
		Car& car_;
	public:
		// public members go here
		Driver(const char* name, Car& theCar);
		void drive();
		void stop();
		void showStatus();
	};
}
#endif