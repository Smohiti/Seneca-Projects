//workshop 3
//M.Saeed Mohiti
#pragma once
#ifndef _TEXT_H
#define _TEXT_H
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
namespace w3 {

	class Text {
		size_t count;
		string* goodtable;
	public:
		Text();
		~Text();
		Text(char* f);
		Text& operator = (const Text& rhs);
		Text&& operator = (Text&& rhs);
		Text(const Text& rhs);
		Text(Text&& rhs);
		size_t size()const;
	};
}// ending namespace
#endif // _TEXT_H