// Date: 2016/11/19
// Author: M.Saeed Mohiti
// Vehicle.h
/////////////////////////////////////////////
#ifndef SICT_VEHICLE_H
#define SICT_VEHICLE_H
#include<iostream>
namespace sict
{
	// complete the declaration of the class
	class Vehicle
	{
	public:
		// public members go here
		virtual void accelerate()=0;
		virtual void brake()=0;
		virtual std::ostream& display(std::ostream& ostr) const=0;
	};
}
#endif