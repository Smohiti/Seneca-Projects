// Date: 2016/11/14
// Author: M.Saeed Mohiti
// SuperHero.cpp
/////////////////////////////////////////////
#include <iostream>
#include<string>
#include<cstring>
#include "SuperHero.h"
using namespace std;
SuperHero::SuperHero() {
	name_[0] = 0;
	strengthSH_ = 0;
	strengthMP_ = 0;
}
SuperHero::SuperHero(const char name[], const double strengthSH, const double strengthMP) {
	if (name[0] != '\0'&& strengthSH >= 0 && strengthMP >= 0) {
		strncpy(name_, name, 21);
		strengthSH_ = strengthSH;
		strengthMP_ = strengthMP;
	}
	else{
		name_[0] = 0;
		strengthSH_ = 0;
		strengthMP_ = 0;
	}
}
SuperHero::SuperHero(SuperHero& obj) {
	strncpy(name_, obj.name_, 21);
	strengthSH_ = obj.strengthSH_;
	strengthMP_ = obj.strengthMP_;
}
double SuperHero::getStrength() const {
	double x= strengthMP_ * strengthSH_;
	return x;
}
void SuperHero::operator*=(SuperHero& obj2) {
	if (strengthSH_ > obj2.strengthSH_)
	{
		strengthSH_ += obj2.strengthSH_;
		obj2.strengthSH_ = 0.0;
	}
	else
	{
		obj2.strengthSH_ += strengthSH_;
		strengthSH_ = 0.0;
	}
}
void SuperHero::display(std::ostream& os) const {
	if (name_[0] != '\0' && strengthSH_ != 0)
		os << "living superhero!" << " "<< name_ << " - " << strengthSH_ << endl;
	else
		os << "deceased superhero!" << endl;

}