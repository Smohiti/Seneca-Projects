//Milestone 2
// M.Saeed MOhiti
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "util.h"
using namespace std;
void trimspace(string& s) {
	string in = s;
	//return;
	// delete the fisrt char if is a space
	while (!s.empty() && s[0] == ' ') {
		s.erase(0, 1);
	}
	cout << "trimspace : in.out: -" << in << "-" << s << "-\n";
	//dlete the last char if is space
	while (!s.empty() && s[s.size() - 1] == ' ') {
		s.erase(s.size() - 1, 1);
	}
	cout << "trimspace : in.out: -" << in << "-" << s << "-\n";
}
void printcsv(vector<vector<string>> &csvdata) {
	for (auto row : csvdata) {
		for (auto column : row) {
			cout << "<" << column << ">";
		}
		cout << "\n";
	}

	for (size_t row = 0; row < csvdata.size(); row++) {
		for (size_t column = 0; column < csvdata[row].size(); column++) {
			cout << "[" << csvdata[row][column] << "]";
		}
		cout << "\n";
	}


	for (auto row = csvdata.begin(); row != csvdata.end(); row++) {
		for (auto column = row->begin(); column != row->end(); column++) {
			cout << "{" << *column << "}";
		}
		cout << "\n";
	}

}
void csvread(string& filename, char separator, vector<vector<string>> &csvdata) {
	vector<vector<string>> csvread;
	cout << "filename='" << filename << "\n'";
	cout << "separator='" << separator << "\n'";
	fstream is(filename, ios::in);
	if (!is.is_open()) {
		throw string("cant open file'") + filename + "'";

	}
	string line;
	while (getline(is, line)) {
		auto cr = line.find('\r');
		if (cr != string::npos)
			line.erase(cr);
		//cout << line << "\n";

		vector<string> fields;
		string field;
		int fieldcount = 0;
		size_t index = 0;
		while (index < line.size()) {
			while (index < line.size() && line[index] != separator) {
				field += line[index];
				index++;
			}
			index++; // skip the sparator 
					 //cout << "field='" << field << "\n'";
			trimspace(field);
			fieldcount++;
			fields.push_back(move(field)); // turns filed in to zombi
		}

		csvdata.push_back(move(fields));// turn vector fields into a zombie
	}
	is.close();

}
bool validTask(string s) {
	for (auto c : s) {
		if ( ! (isalnum(c) || c == ' ') ) 
			return false;
	}
	return true;
}

bool validSlots(string s) {
	for (auto c : s) {
		if (! isdigit(c))
			return false;
	}
	return true;
}



