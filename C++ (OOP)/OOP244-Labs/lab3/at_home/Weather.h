///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     10/02/2016    workshop3
///////////////////////////////////////////////////////////
// compilation safegaurds
#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_
/*Weather.h*/

 // ict namespace
namespace ict {
	class Weather {
		char _dateDescription[7];
		double _high_temp;
		double _low_temp;
	public:
		void set(const char*dt, double ht, double lt);
		void display() const;
		const char* date() const;
		double low() const;
	};
}
#endif
