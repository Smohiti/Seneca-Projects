// Date: 2016/11/14
// Author: M.Saeed Mohiti
// SuperHero.h
/////////////////////////////////////////////
#ifndef _SUPERHERO_H
#define _DUPERHERO_H
#include <iostream>
#include "Hero.h"
class SuperHero : public Hero {
	char name_[21];
	double strengthSH_;
	double strengthMP_;
public:
	SuperHero();
	SuperHero(const char name[], const double strengthSH,const double strengthMP);
	SuperHero(SuperHero& obj);
	double getStrength() const;
	void operator*=(SuperHero&);
	void display(std::ostream&) const;
};
#endif
