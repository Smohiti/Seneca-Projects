#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"

using namespace std;
using namespace sict;

// your Drive(...) function goes here
void Drive(Car& SDrive) {
    SDrive.accelerate();
	SDrive.brake();
	SDrive.display(cout);
}

// your Stop(...) function goes here

void Stop(Car& SStop) {
	while (SStop.speed() > 0) {
		SStop.brake();
	}
	SStop.display(cout);
}


int main()
{
	SportCar Tesla(240, 2);
	PickupTruck Ford;
	Tesla.display(cout) ;
	Ford.display(cout) ;

	Ford.load("Bricks", 3500);
	Drive(Tesla);
	Drive(Ford);
	Stop(Tesla);
	Stop(Ford);
	Ford.unload();

	Tesla.display(cout) ;
	Ford.display(cout) ;

	return 0;
}
/*
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
This sport car is carrying 2 passengers and is traveling at a speed of 30 km/h.
This pickup truck is carrying 3500 kgs of Bricks, traveling at the speed of 15 km/h.
This sport car is carrying 2 passengers and is parked.
This pickup truck is carrying 3500 kgs of Bricks and is parked.
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
*/