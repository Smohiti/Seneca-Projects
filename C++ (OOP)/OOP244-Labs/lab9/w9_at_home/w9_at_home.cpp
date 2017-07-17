#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"
#include "Driver.h"

using namespace std;
using namespace sict;

int main()
{
	SportCar tesla(240, 2);
	PickupTruck ford;
	Driver john("John", tesla);
	Driver kim("Kim", ford);
	cout << tesla<<endl ;
	cout << ford<<endl ;

	ford.load("Bricks", 3500);
	john.drive();
	kim.drive();
	john.stop();
	kim.stop();
	cout << tesla<<endl;
	cout << ford<<endl;

	return 0;
}

/*
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
John is driving this car.
This sport car is carrying 2 passengers and is traveling at a speed of 30 km/h.
Kim is driving this car.
This pickup truck is carrying 3500 kgs of Bricks, traveling at the speed of 15 km/h.
John is driving this car.
This sport car is carrying 2 passengers and is parked.
Kim is driving this car.
This pickup truck is carrying 3500 kgs of Bricks and is parked.
This sport car is carrying 2 passengers and is parked.
This pickup truck is carrying 3500 kgs of Bricks and is parked.
*/
