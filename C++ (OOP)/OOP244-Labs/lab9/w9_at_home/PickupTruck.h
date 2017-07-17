// Date: 2016/11/19
// Author: M.Saeed Mohiti
// PickupTruck.h
/////////////////////////////////////////////
#ifndef SICT_TRUCK_H_
#define SICT_TRUCK_H_
#include"Car.h"
using namespace std;
namespace sict
{
	// complete the declaration of the class
	class PickupTruck : public Car
	{
	private:
		// private members go here
		int loadAmount_;
		char loadedMaterial_[31];
	public:
		// public members go here
		PickupTruck();
		void load(const char* loadedMaterial, int loadAmount);
		void unload();
		bool isEmpty() const;
		void accelerate();
		void brake();
		// pure virtual members from base class go here
		ostream& display(ostream& ostr) const;
	};
}
#endif