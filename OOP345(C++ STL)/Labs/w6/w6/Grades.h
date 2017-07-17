//M.Saeed Mohiti
//Workshop 6
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Grades {
	int* studNum;
	float* grade;
	int count;
public:
	Grades(char* file) {
		try {
			fstream myfile(file);
			if (!myfile.is_open()) {
				throw 99;
			}
			string strings;
			int i = 0;
			int size = 0;
			while (myfile) {
				string number;
				string mark;
				getline(myfile, number, ' ');
				getline(myfile, mark, '\n');
				size++;
			}
			count = size;
			studNum = new int[size];
			grade = new float[size];
			myfile.clear();
			myfile.seekg(0);
			while (myfile)
			{
				string number;
				string mark;
				getline(myfile, number, ' ');
				studNum[i] = atoi(number.c_str());
				getline(myfile, mark, '\n');
				grade[i] = atof(mark.c_str());
				i++;
			}
		}
		catch (int x) {
			cout << "FILE IS NOT FOUND ERROR " << x << endl;
		}
	}
	template<typename letter>
	void displayGrades(ostream& os, letter LETTER) const {
		for (int i = 0; i < count; i++) {
			os << studNum[i] << " " << grade[i] << " " << LETTER(grade[i]) << endl;
		}
	}
};