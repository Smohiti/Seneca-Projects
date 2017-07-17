// Date: 2016/11/15
// Author: M.Saeed Mohiti
// SportCar.cpp
/////////////////////////////////////////////
#include "SportCar.h"
#include"Car.h"
using namespace std;

namespace sict
{
	SportCar::SportCar(){
		noOfPassengers_ = 1;
	}
	SportCar::SportCar(int mspeed, int nupass) :Car(mspeed) {
		noOfPassengers_ = nupass;
	}
	void SportCar::accelerate() {
		speed(speed() + 40);
	}
	void SportCar::brake() {
		speed(speed() - 10);
	}
	ostream& SportCar::display(ostream& ostr) const {
		if (speed() > 0) {
			ostr << "This sport car is carrying" << " "<< 
noOfPassengers_ << " "<< "passengers and is traveling at a speed of " << 
speed() <<" "<< "km/h."<<endl;
		}
		else {
			ostr << "This sport car is carrying" <<  " " << noOfPassengers_ << " " << "passengers and is parked."<<endl;
		}
		return ostr;
	}

}
