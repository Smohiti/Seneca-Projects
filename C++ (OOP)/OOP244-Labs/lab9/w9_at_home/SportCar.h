// Date: 2016/11/19
// Author: M.Saeed Mohiti
// SportCar.h
/////////////////////////////////////////////
#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include"Car.h"
using namespace std;
namespace sict
{
	// complete the declaration of the class
	class SportCar:public Car
	{
	private:
		// private members go here
		int noOfPassengers_;
	public:
		// public members go here
		SportCar();
		SportCar(int mspeed, int nupass);
		void accelerate();
		void brake();
		// pure virtual members from base class go here
		ostream& display(ostream& ostr) const;
	};
}
#endif