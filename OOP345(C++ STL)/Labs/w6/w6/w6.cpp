// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}
	Grades grades(argv[1]);
	// define the lambda expression for letter
	auto letter = [](float grade)->std::string {
		std::string LETTER;
		if (grade >= 90) {
			LETTER = "A+";
		}
		else if (grade > 80) {
			LETTER = "A";
		}
		else if (grade > 75) {
			LETTER = "B+";
		}
		else if (grade > 70) {
			LETTER = "B";
		}
		else if (grade > 65) {
			LETTER = "C+";
		}
		else if (grade > 60) {
			LETTER = "C";
		}
		else if (grade > 55) {
			LETTER = "D+";
		}
		else if (grade > 50) {
			LETTER = "D";
		}
		else
			LETTER = "F";
		return LETTER;
	};
	grades.displayGrades(std::cout, letter);
	std::cout << "Press any key to continue ... ";
	std::cin.get();
}