// Date: 2016/11/08
// Author: M.Saeed Mohiti
// Hero.cpp
/////////////////////////////////////////////
#include <iostream>
#include "Hero.h"
using namespace std;
Hero::Hero() {
	name_[0] = 0;
	strength_ = 0;
}
Hero::Hero(char name[], double strength) {
	strcpy(name_, name);
	strength_ = strength;
}
bool Hero:: isEmpty() const {
	if (name_[0] == '\0' && strength_ == 0)
		return true;
	else
		return false;
}
double Hero::getStrength() const {
	if (strength_ != 0) {
		return strength_;
	}
	return 0.0;
}
void Hero::display(std::ostream& os) const {
		if (isEmpty() == false) 
			os << name_ << " - " <<  strength_ << endl;
		
}
void Hero:: operator-=(double strength) {
	if (strength_ > strength)
		strength_ -= strength;
	else
		strength_ = 0.0;
}
void Hero:: operator+=(double strength) {
	strength_ += strength;
}
bool operator<(const Hero& a, const Hero& b) {
	bool eq;
	 eq = (a.getStrength() < b.getStrength());
	return eq;

}

