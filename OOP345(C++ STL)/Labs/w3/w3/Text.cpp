//workshop 3
//M.Saeed Mohiti
#include<fstream>
#include<string>
#include<iostream>
#include"Text.h"
using namespace std;
namespace w3 {

		Text::~Text() {
			delete[] goodtable;
		}
		Text::Text() : count(0), goodtable(nullptr) { //ctor default for line 24

		}

		Text::Text(char* f) : count(0), goodtable(nullptr) {// ctor for line 30
			fstream in(f, ios::in);
			if (in.is_open()) {
				string line;
				while (getline(in, line)) {
					count++;
				}
				cout << "file" << f << "contains" << count << "lines";
				goodtable = new string[count];
				in.clear();
				in.seekg(0); //positin the file at the begining(start)
				for (size_t i = 0; i < count; i++) {
					getline(in, goodtable[i]);
					auto cr = goodtable[i].find('\r');
					if (cr != string::npos) {
						goodtable[i].erase(cr);
					}
				}
				in.close();
				size_t num = count;
				if (num > 1) num = 10;
				for (size_t i = 0; i < count; i++) {
					cout << " Line" << i + 1 << ": '" << goodtable[i] << "'\n";
					auto cr = goodtable[i].find('\r');
					if (cr != string::npos)
						goodtable[i].erase(cr);
				}
			}
			else {
				cerr << "cant open file --> " << f << " <--\n";
				exit(3);
			}
		}

		Text& Text::operator = (const Text& rhs) { // copy assing oper  for line 36
			if (this != &rhs) {
				delete[] goodtable;
				if (rhs.count) {

					count = rhs.count;
					goodtable = new string[count];
					for (size_t i = 0; i < count; i++) {
						goodtable[i] = rhs.goodtable[i];
					}
				}
				else {
					count = 0;
					goodtable = nullptr;
				}
			}
			return *this;
		}

		Text&& Text::operator = (Text&& rhs) { //move assing oper for line 42
			if (this != &rhs) {
				delete[] goodtable;
				count = rhs.count;
				goodtable = rhs.goodtable;
				rhs.count = 0;
				rhs.goodtable = nullptr;
			}
			return move(*this);
		}

		Text::Text(const Text& rhs) : count(0), goodtable(nullptr) {// copy ctor  for line 48
			*this = rhs;
		}

		Text::Text(Text&& rhs) : count(0), goodtable(nullptr) {
			//move for line 54
			*this = std::move(rhs);
		}
		size_t Text::size()const {
			return count;
		}

} // ending namespace