// Author: M.Saeed Mohiti
///////////////////////////////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef _STATION_H
#define _STATION_H

#ifndef nullptr
#define nullptr 0
#endif

namespace w2
{
	enum PassType {
		STUDENT_PASS = 0, ADULT_PASS, MAX_PASSTYPE
	};

	class Station {
		std::string _name;
		unsigned int _passes[MAX_PASSTYPE];

	public:

		Station();
		void set(const std::string&, unsigned, unsigned);
		void update(PassType, int);
		unsigned inStock(PassType) const;
		const std::string& getName() const;
	};
}

#endif // _STATION_H
