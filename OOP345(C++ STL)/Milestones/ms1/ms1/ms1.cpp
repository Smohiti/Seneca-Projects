//M.Saeed Mohiti
// Milestone 1
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
void trimSpaces(string& s) {
	//delete the first character if it is a space
	while (!s.empty() && s[0] == ' ')
		s.erase(0, 1);

	//delete the last character if it is a space
	while (!s.empty() && s[s.size() - 1] == ' ')
		s.erase(s.size() - 1, 1);
}
void printCsv(vector<vector<string>> &csvData) {
	for (auto row : csvData) {
		for (auto column : row) {
			cout << "< " << column << "> ";
		}
		cout << "\n";
	}
	for (size_t row = 0; row < csvData.size(); row++) {
		for (size_t column = 0; column < csvData[row].size(); column++) {
			cout << "[ " << csvData[row][column] << "] ";
		}
		cout << "\n";
	}
	for (auto row = csvData.begin(); row != csvData.end(); row++) {
		for (auto column = row->begin(); column != row->end(); column++) {
			cout << "{ " << *column << "}";
		}
		cout << "\n";
	}
}
void csvRead(string& filename, char separator, vector<vector<string>> &csvData) {
	cout << "filename= " << filename << "\n";
	cout << "separator= " << separator << "\n";
	fstream is(filename, ios::in);
	if (!is.is_open()) {
		throw string("cannot open file '") + filename + "'";
	}
	string line;
	while (getline(is, line)) {
		auto cr = line.find('\r');
		if (cr != string::npos)
			line.erase(cr);
		vector<string> fields;
		string field;
		size_t index = 0;
		int fieldCount = 0;
		while (index < line.size()) {
			while (index < line.size() && line[index] != separator) {
				field += line[index];
				index++;
			}
			index++;
			fieldCount++;
			trimSpaces(field);
			fields.push_back(move(field));
		}
		csvData.push_back(move(fields));
	}
	is.close();
	for (auto row : csvData) {
		for (auto column : row) {
			cout << "< " << column << "> ";
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) {
	try {
		if (argc != 3)
			throw string(argv[0]) + " needs two arguments , the csv file name , and csv separator character";

		string filename = argv[1];
		char separator = argv[2][0];
		cout << "filename= " << filename << "\n";
		cout << "separator= " << separator << "\n";
		vector<vector<string>> csvData;
		csvRead(filename, separator, csvData);
		printCsv(csvData);
	}
	catch (const string& e) {
		cerr << e << "\n";
	}
}