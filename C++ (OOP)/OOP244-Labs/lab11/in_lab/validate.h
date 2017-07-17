// Date: 2016/11/29
// Author: M.Saeed Mohiti
// Validate.h
// work shop 11
/////////////////////////////////////////////
#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict {
	template <class T>
	bool validate(const T& min, const T& max, const T* testValue, int num, bool* result) {
		int i = 0;
		int c = 0;
		while (i < num){
			result[i] = ( min <= testValue[i] && max >= testValue[i]);
			if (result[i])
				c++;
			i++;
		}
		return c == num;
	}
}
#endif