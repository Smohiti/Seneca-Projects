// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca
// Workshop: 3

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace w3 {
	//Default Constructor
	Text::Text() {
		setEmpty();
	}

	//Constructor with argument
	Text::Text(const char* textFile) {
		int count = 0;
		string temp;
		fstream file(textFile, ios::in);
		if (file.is_open()) {
			while (getline(file, temp)) {           //count the number of lines and assign to size_
				size_ = ++count;
			}
			record_ = new string[count];           //creates dynamic memory
			file.clear();						   //clear the error state of fstream
			file.seekg(0);						   //position the pointer at the beginning of the file
			for (int i = 0; i < count; i++) {
				getline(file, record_[i]);          //copy records from file
				auto cr = record_[i].find('\r');
				if (cr != string::npos) {
					record_[i].erase(cr);
				}
			}
			file.close();
		}
		else {
			setEmpty();
			cerr << "Cannot open the file " << textFile << "!" << endl;
			exit(1);

		}
	}

	//return number of records
	size_t Text::size() const {
		return size_;
	}

	//Destructor
	Text::~Text() {
		delete[] record_;
	}

	//Copy Assignment Operator
	Text& Text::operator= (const Text& rhs) {
		if (this != &rhs) {
			if (record_) {
				delete[] record_;
				setEmpty();
			}
			size_ = rhs.size_;
			if (size_) {
				record_ = new string[size_];
				for (int i = 0; i < (int)size_; i++) {
					record_[i] = rhs.record_[i];
				}
			}
		}
		return *this;
	}

	//Move Assignment Operator
	Text&& Text::operator= (Text&& rhs) {
		if (this != &rhs) {
			if (record_) {
				delete[] record_;
				setEmpty();
			}
			size_ = rhs.size();
			record_ = rhs.record_;
			rhs.setEmpty();
		}
		return move(*this);
	}

	//Copy Constructor
	Text::Text(const Text& rhs) {
		setEmpty();
		*this = rhs;                                //call copy assignment operator
	}

	//Move Constructor
	Text::Text(Text&& rhs) {
		setEmpty();
		*this = move(rhs);                         //call move assignment operator
	}

	//sets object to empty state
	void Text::setEmpty() {
		record_ = nullptr;
		size_ = 0;
	}

	//total lines: 124456


}