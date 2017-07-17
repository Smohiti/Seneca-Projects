// Date: 2016/11/09
// Author: M.Saeed Mohiti
// Error.cpp
// Project: Milestone 2
/////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "Error.h"
using namespace std;
namespace ict{
	Error::Error() {
		message_ = nullptr;
	}
	Error::Error(const char* Error) {
		message_ = nullptr;
		message(Error);
	}
	Error& Error::operator=(const char* errorMessage) {
		delete[]message_;
		message_ = new char [strlen(errorMessage) + 1];
		strcpy(message_, errorMessage);
		clear();
		message(errorMessage);
		return *this;
	}
	Error::~Error() {
		delete[]message_;
	}
	void Error::clear() {
		delete[]message_;
		message_ = nullptr;
	}
	bool Error::isClear()const {
		return message_ == nullptr;
	}
	void Error::message(const char* value) {
		delete[]message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}
	const char* Error::message()const {
		return message_;
	}
	std::ostream& operator<<(std::ostream& os, const Error& S) {
		if (S.isClear())
			os << "";
		else
			os << S.message();
                return os;
	}
}
