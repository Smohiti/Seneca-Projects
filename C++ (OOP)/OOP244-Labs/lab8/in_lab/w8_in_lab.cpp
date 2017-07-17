// OOP244 Workshop 8: Derived Classes
// File	w8_in_lab.cpp
// Version 1.0
// Date	2016/11/08
// Author	M.Saeed Mohiti
// Description
//       This file demonstrates the client module of w8
/////////////////////////////////////////////////////

#include <iostream>
#include "Hero.h"

int main()
{
	Hero m("Mom", 20);
	m.display(std::cout);
	Hero d("Dad", 10);
	d.display(std::cout);

	m += 70;
	m.display(std::cout);
	d += 20;
	d.display(std::cout);

	if (m < d)
		std::cout << "Dad is stronger!" << std::endl;
	else
		std::cout << "Mom is stronger!" << std::endl;

	d -= 25;
	d.display(std::cout);
	m -= 200;
	m.display(std::cout);

	if (m < d)
		std::cout << "Dad is stronger!" << std::endl;
	else
		std::cout << "Mom is stronger!" << std::endl;
	return 0;
}
