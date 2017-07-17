// Author: M.Saeed Mohiti
///////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stations.h"

using namespace std;

namespace w2 {

	Stations::Stations(const char* filename) : _numStation(0), _stations(nullptr) {

		ifstream fs(filename);

		if (!fs.is_open()) {
			cerr << "\nFile is not open" << std::endl;
		}

		char c;
		fs >> _numStation;
		fs.ignore(2000, '\n');
		_stations = new Station[_numStation];

		for (int i = 0; i < _numStation; i++) {

			string name;
			int numStudent, numAdult;
			getline(fs, name, ';');
			fs >> numStudent;
			fs >> numAdult;
			_stations[i].set(name, numStudent, numAdult);
		}

		fs.close();
	}

	Stations::~Stations() {
		delete[] _stations;
	}

	void Stations::restock() const {

		cout << endl;
		cout << "Passes Added :\n";
		cout << "-------------\n";

		for (int i = 0; i < _numStation; i++) {

			int numStudent, numAdult;

			cout << _stations[i].getName() << endl << " Student Passes added : ";
			cin >> numStudent;

			cout << " Adult   Passes added : ";
			cin >> numAdult;

			_stations[i].update(STUDENT_PASS, numStudent);
			_stations[i].update(ADULT_PASS, numAdult);
		}
	}

	void Stations::update() const {

		cout << "Passes Sold :\n";
		cout << "-------------\n";

		for (int i = 0; i < _numStation; i++) {

			int numStudent, numAdult;

			cout << _stations[i].getName() << endl;
			cout << " Student Passes sold : ";
			cin >> numStudent;
			cout << " Adult   Passes sold : ";
			cin >> numAdult;

			_stations[i].update(STUDENT_PASS, -numStudent);
			_stations[i].update(ADULT_PASS, -numAdult);
		}

	}

	void Stations::report() const {

		cout << endl;
		cout << "Passes in Stock : Student Adult\n";
		cout << "-------------------------------\n";

		for (int i = 0; i < _numStation; i++) {
			cout << setw(19) << left << _stations[i].getName(); // 19
			cout << setw(6) << right << _stations[i].inStock(STUDENT_PASS);
			cout << setw(6) << right << _stations[i].inStock(ADULT_PASS);
			cout << endl;
		}
	}
} // namespace w2