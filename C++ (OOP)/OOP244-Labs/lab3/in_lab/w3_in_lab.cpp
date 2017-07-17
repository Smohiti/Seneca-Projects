// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     09/27/2016    workshop3
///////////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"
using namespace std;
using namespace ict;
int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  // initialize the weather pointer here
Weather *weather;

  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  // allocate dynamic memory here

  weather = new Weather[n];
  for (i = 0; i < n; i++){
    char date_description[7];
    double high=0.0;
    double low=0.0;
		cout<<"Enter date: ";
		cin>>date_description;
		cout<<"Enter high: ";
		cin>> high;
		cout<<"Enter low : ";
		cin>>low;
	     // ... add code to accept the user input
		// for the weather array
		weather[i].set(date_description,high,low);
  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++){
    weather[i].display();
  }

  // deallocate dynamic memory here

  return 0;
}
