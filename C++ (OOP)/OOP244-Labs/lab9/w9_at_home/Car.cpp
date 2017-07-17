// Date: 2016/11/19
// Author: M.Saeed Mohiti
// Car.cpp
/////////////////////////////////////////////
#include "Car.h"

namespace sict
{
	void Car::speed(int value) {
		speed_ = value;
		if (value > maxSpeed_)
			value = maxSpeed_;
		if (value < 0)
			value = 0;
	}
		int Car::maxSpeed() const {
			return maxSpeed_;
		}
	 
		int Car::speed() const {
			return speed_;
		}
		Car::Car(int MSpeed) {
			maxSpeed_ = MSpeed;
		    speed_ = 0;
		}
		ostream & operator<<(ostream & os, const Car & obj){
			obj.display(os);
			return os;
		}
		void Car::accelerate(){
			accelerate();
		}
		void Car::brake(){
			brake();
		}
		ostream & Car::display(ostream & os) const{
			this->display(os);
			return os;
		}

}