//Milestone 3
// M.Saeed Mohiti
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
using namespace std;
class Order {
	std::string customer, product;
	std::vector<std::string> itemList;
public:
	Order(vector<string>field) {
		if (field.size() >= 3) {
			if (validCustomerName(field[0]))
				customer = field[0];
			else
				throw string("expected customer name, found a ") + field[0];

			if (validProductName(field[1]))
				product = field[1];
			else
				throw string("expected product name, found a ") + field[0];

			for (int i = 2; i < (int)field.size(); i++) {
				if (validItemName(field[i])) {
					itemList.push_back(field[i]);
				}
				else
					throw string("expected an item, found a ") + field[0];
			}
		}
		else {
			throw string("expected minimum 3 fields, found ") + to_string(field.size());
		}
	}

	void print() {
		cout << "customer, product, itemList = "
			<< customer << " | " << product << " | ";
		for (int i = 0; i < (int)itemList.size(); i++) {
			cout << itemList[i];
			if (i + 1 < (int)itemList.size())
				cout << " | ";
		}
		cout << endl;
	}

	void graph(ofstream& os) {
		auto f = [&os](string symbol) {os << '"' << symbol << '"'; };
		for (int i = 0; i < (int)itemList.size(); i++) {
			f(customer);
			os << "->";
			f(itemList[i]);
			os << "[color=green];" << endl;
		}
	}
};
class  OrderManager {
	std::vector<Order> OrderList;
public:
	OrderManager(vector<vector<string> > & csvdata) {
		int line = 0;
		for (auto field : csvdata) {
			try {
                line++;
				OrderList.push_back(Order(field));
			}
			catch (string& e) {
				cerr << "Problem with line " << line << endl;
				cerr << e << endl;
			}
		}
	}

	void print() {
		for (auto t : OrderList) {
			t.print();
		}
	}

	void graph(string filename) {
		ofstream of(filename + ".gv");         //save digrapgh file with .gv extension
		if (of.is_open()) {
			of << "digraph myGraph{\n";
			for (auto t : OrderList) {
				t.graph(of);
			}
			of << "}\n";
			of.close();
		}
#ifdef __unix
		string dot = "dot";
#else
		string dot = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe";
#endif
		string cmd = dot + " -Tpng " + filename + ".gv >" + filename + ".gv.png";
		cout << cmd << "\n";

		system(cmd.c_str());
	}
};
int main(int argc, char* argv[]) {
	try {
		if (argc != 3)
			throw string(argv[0]) + " need two arg the csv file name, and the csv separator";

		string taskfilename = argv[1];
		char separator = argv[2][0];
		vector<vector<string>> csvtaskdata;
		readcsv(taskfilename, separator, csvtaskdata);
		//printcsv(csvdata);  // everything is fine with csvread
		OrderManager tm(csvtaskdata);
		tm.print();
		tm.graph(taskfilename);

	}

	catch (const string& e) {
		cerr << e << "\n";
	}

}