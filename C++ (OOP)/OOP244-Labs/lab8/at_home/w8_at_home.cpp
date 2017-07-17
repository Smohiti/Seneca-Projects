// OOP244 Workshop 8: Derived Classes
// File	w8_at_home.cpp
// Version 1.0
// Date	2016/11/06
// Author	Franz Newland, Eden Burton
// Description
//      This file demonstrates the client module of w8
/////////////////////////////////////////////////////

#include <iostream>
#include "SuperHero.h"

int main()
{
	SuperHero p;
	p.display(std::cout);

	SuperHero w("wimpy", -10, 5);
	w.display(std::cout);

	SuperHero h("Hercules", 100, 5);
	h.display(std::cout);

	SuperHero hClone(h);
	hClone.display(std::cout);

	SuperHero sm("Superman", 130, 5);
	sm.display(std::cout);

	std::cout << "Superman battles Hercules' clone!" << std::endl;
	sm *= hClone;

	sm.display(std::cout);
	hClone.display(std::cout);

	std::cout << "Hercules battles Superman!" << std::endl;
	h *= sm;

	sm.display(std::cout);
	hClone.display(std::cout);

	// Reflection section
	Hero o = sm;  // Why does this compile?
	o.isEmpty();
	
	// Uncomment the following two lines to see what happens. Explain the result!
	//Hero o2;
	//SuperHero sh = o2;

	return 0;
}
