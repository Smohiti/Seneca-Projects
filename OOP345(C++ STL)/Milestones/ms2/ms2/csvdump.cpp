//Milestone 2
// M.Saeed MOhiti
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "util.h"
using namespace std;

int main(int argc, char* argv[]) {
	try {
		if (argc != 3)
			throw string(argv[0]) + "need two arg the csv file name, and the csv separator";

		string filename = argv[1];
		char separator = argv[2][0];
		vector<vector<string>> csvdata;
		csvread(filename, separator, csvdata);
		//printcsv(csvdata);
	}

	catch (const string& e) {
		cerr << e << "\n";
	}

}