// Date: 2016/11/19
// Author: M.Saeed Mohiti
// PickupTruck.cpp
/////////////////////////////////////////////
#include "PickupTruck.h"
#include"Car.h"
using namespace std;
namespace sict
{
	PickupTruck::PickupTruck(){
		loadAmount_ = 0;
		loadedMaterial_[31] = '\0';
	}
	void PickupTruck::load(const char* loadedMaterial, int loadAmount) {
		loadAmount_ = loadAmount;
		//strncpy(loadedMaterial_, loadedMaterial,31);
	for (int i = 0; i < 31; i++)
			loadedMaterial_[i] = loadedMaterial[i];
	}
	void PickupTruck::unload(){
		loadAmount_= 0;
	}
	bool PickupTruck::isEmpty() const{
		return loadAmount_ == 0;
	}
	void PickupTruck::accelerate(){
		speed(speed() + 20);

	}
	void PickupTruck::brake(){
		speed(speed() - 5);
	}

	ostream& PickupTruck::display(ostream& ostr) const{
	
		if (isEmpty()==true) {
			ostr << "This pickup truck is not carrying any load";
		}
		else {
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
		}
		if (speed() > 0) {
			ostr << ", traveling at the speed of " << speed()<< " km/h.";
		}
		else if(speed()==0) {
			ostr << " and is parked.";
		}
		return ostr;
	}
}