// Date: 2016/11/29
// Author: M.Saeed Mohiti
// Validate.h
// work shop 11
/////////////////////////////////////////////
#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict {
	template <typename T>
	bool validate(const T min,const T max, const T* testValue, int num, bool* result) {
		int i = 0;
		int c = 0;
		while (i < num) {
			result[i] = (min <= testValue[i] && max >= testValue[i]);
			if (result[i])
				c++;
			i++;
		}
		return c == num;
	}
	template <>
	bool validate<char>(const char min, const char max, const char* testValue, int num, bool* result) {
		int i =0;
		int c = 0;
		while (i < num) {
			result[i] = (min <= toupper(testValue[i]) && max >= toupper(testValue[i]));
			if (result[i]) {
				c++;
			}
			i++;
		}
		return c == num;
	}
	template <>
	bool validate<Car>(const Car min, const Car max, const Car* testValue, int num, bool* result) {
		int i = 0;
		int c = 0;
		while (i < num) {
			result[i] = (min <= testValue[i] ) && ( max >= testValue[i] ) && strlen((const char*)testValue[i]) == 6;
			if (result[i]) {
				c++;
			}
			i++;
		}
		return c == num;
		return true;
	}
}
#endif