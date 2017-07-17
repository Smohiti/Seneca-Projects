//Milestone 3
// M.Saeed Mohiti
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "util.h" // which is gonna have every prototypes and anything

int main(int argc, char* argv[])
{
	try { // WHAT IS TRY?
		if (argc != 3)
			throw string(argv[0]) + "needs two arguments, the csv file name, and the csv separator character";

		string filename = argv[1];
		char separator = argv[2][0];

		vector< vector<string> > csvData;

		csvread(filename, separator, csvData);
	}
	catch (const string& e) {
		cerr << e << "\n";
	}
}