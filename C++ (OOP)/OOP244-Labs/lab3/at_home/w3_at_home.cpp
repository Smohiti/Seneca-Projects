// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date	
// Author	
// Description

///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     10/02/2016    workshop3
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Weather.h"
using namespace std;
using namespace ict;
double findLow(const char* date, const Weather *data, int dataSize) {
	int i, o;
	for (i = 0; i < dataSize; i++) {
	//	o = strcmp(data[i].date(), date); //testing
	//	cout << o << ' ' << data[i].date() << date << endl;  //testing
		if (strcmp(data[i].date(), date) == 0)
			return data[i].low();
	}
	return 0.0;
}
int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  Weather* weather;// create the weather pointer here

  cout << "Weather Data\n";
  cout << "=====================" << endl;
  cout << "Days of Weather: ";
  cin >> n;
  cin.ignore();
  // allocate dynamic memory here
  weather = new Weather[n];
  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;
    // ... add code to accept user input for
    //weather
	cout << "Enter date: ";
	cin >> date_description;
	cout << "Enter high: ";
	cin >> high;
	cout << "Enter low : ";
	cin >> low;
	weather[i].set(date_description, high, low);
  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++){
    weather[i].display();
  }

  char query[7];
  cout << endl << "Enter the date you are looking for: ";
  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.
  cin >> query;
 // cin.getline(query, 7, '\n');
  double low = findLow(query, weather, n);
  cout << "Low temperature: " << low << endl;
  // deallocate dynamic memory here
  delete[] weather;
  weather = nullptr;
  return 0;

}


