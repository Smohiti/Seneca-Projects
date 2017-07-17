#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>

const int MAX = 3;

namespace w1 {
	class CString {
		char str_[MAX + 1];
	public:
		CString(char* str);
		void display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, CString cs);
}
