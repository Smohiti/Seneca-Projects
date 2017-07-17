// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca
// Workshop: 3

#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace w3 {
	class Text {
		std::string* record_;
		size_t size_;
	public:
		Text();
		Text(const char* textFile);
		Text(const Text& rhs);
		Text& operator= (const Text& rhs);
		Text(Text&& rhs);
		Text&& operator= (Text&& rhs);
		~Text();
		size_t size() const;
		void setEmpty();
	};

} //namespace w3