///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     10/02/2016    workshop3
///////////////////////////////////////////////////////////
/*Weather.cpp*/
//  includes go here
#include "Weather.h"
#include<string.h>
#include<iostream>
#include<iomanip>
// ict namespace 
using namespace std;
using namespace ict;
  // set method 
void Weather::set(const char*dt, double ht, double lt)
{
	strcpy(_dateDescription, dt);
	_high_temp = ht;
	_low_temp = lt;
}
  // date method (query)
const char* Weather::date() const {
	return _dateDescription;
}
  // low method (query)
double Weather::low() const {
	return _low_temp;
}
  // display
void Weather::display() const
{
	//cout<<date<<"_______"<<high_temp<<"____"<<low_temp<<endl;
	cout << setprecision(1) << fixed;
	cout << setfill('_') << left << setw(10) << _dateDescription << right << setw(6) << _high_temp << setw(6) << _low_temp << endl;
}
