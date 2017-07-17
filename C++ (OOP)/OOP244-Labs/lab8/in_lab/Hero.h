// Date: 2016/11/08
// Author: M.Saeed Mohiti
// Hero.h
/////////////////////////////////////////////
#ifndef _HERO_H
#define _HERO_H
#include <iostream>
class Hero{

	char name_[21];
	double strength_;
public:
	Hero();
	Hero(char name[], double strength);
	bool isEmpty() const;
	double getStrength() const;
	void display(std::ostream&) const;
	void operator-=(double strength);
	void operator+=(double strength);
};
bool operator<(const Hero&, const Hero&);

#endif