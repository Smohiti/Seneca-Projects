// Date: 2016/11/19
// Author: M.Saeed Mohiti
// Car.h
/////////////////////////////////////////////
#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include"Vehicle.h"
using namespace std;
namespace sict
{
	// complete the declaration of the class
	class Car : public Vehicle
	{
	private:
		// private members go here
		int speed_;
		int maxSpeed_;
	protected:
		// protected members go here
		void speed(int value);
		int maxSpeed() const;
	public:
		// public members go here
		int speed() const;
		Car(int MSpeed=100);
		virtual void accelerate();
		virtual void brake();
		virtual ostream& display(ostream& os) const;
	};
	ostream& operator<<(ostream &os, const Car &obj);
}

#endif