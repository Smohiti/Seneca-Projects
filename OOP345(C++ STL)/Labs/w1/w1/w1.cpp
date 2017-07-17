#include <iostream>
#include <cstring>
#include "CString.h"
#include "process.h"
using namespace std;
//const int MAX = 3;

int main(int argc, char* argv[]) {

	cout << "Command Line : ";
	for (int arg = 0; arg < argc; arg++) {
		cout << " " << argv[arg];
	}
	cout << "\n";
	if (argc == 1) {
		cout << "Insufficient number of arguments (min 1)\n";
		return 1;
	}
	cout << "Maximum number of characters stored : " << MAX << "\n";
	for (int arg = 1; arg < argc; arg++) {
		process(argv[arg]);
	}
	return 0;
}