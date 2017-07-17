//Milestone 3
// M.Saeed Mohiti
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
using namespace std;
class Item {
	std::string itemName, installer, remover, code, description;
	bool Item::validCode(string code) {
		//if (!slots.size()) return 0;
		bool result = false;
		for (int i = 0; i < (int)code.size(); i++) {
			if (code.size() && isdigit(code[i]))
				result = true;
		}
		return result;
	}

public:
	Item(vector<string>field) {
		switch (field.size()) {
		case 5:
			description = field[4];
		case 4:
			if (validCode(field[3])) {
				code = field[3];
			}
			else {
				throw string("expected a code , found a ") + field[3];
			}

			if (validTaskName(field[2]))
				remover = field[2];
			else
				throw string("expected a remover, found a ") + field[2];

			if (validTaskName(field[1]))
				installer = field[1];
			else
				throw string("expected a installer, found a ") + field[1];

			if (validItemName(field[0]))
				itemName = field[0];
			else
				throw string("expected a name, found a ") + field[0];
			break;

		default:
			throw string("expected 4 or 5 fields, found ") + to_string(field.size());
		}
	}

	void print() {
		cout << "itemName, installer, remover, code, [description] = "
			<< itemName << ","
			<< installer << ","
			<< remover << ","
			<< code << ",";
		if (!description.empty())
			cout << description << ",";
		cout << endl;
	}

	void graph(ofstream& os) {
		auto f = [&os](string symbol) {os << '"' << symbol << '"'; };
		f("Item: " + itemName);
		os << "->";
		f(installer);
		os << "[color=green];" << endl;
		f("Item: " + itemName);
		os << "->";
		f(remover);
		os << "[color=red];" << endl;
	}
};
class ItemManager {
	vector<Item> ItemList;
public:

	ItemManager(vector<vector<string> > & csvdata) {
		int line = 0;
		for (auto field : csvdata) {
			try {
				line++;
				ItemList.push_back(Item(field));
			}
			catch (string& e) {
				cerr << "Problem with line " << line << endl;
				cerr << e << endl;
			}
		}
	}

	void print() {
		for (auto t : ItemList) {
			t.print();
		}
	}

	void graph(string filename) {
		ofstream of(filename + ".gv");         //save digrapgh file with .gv extension
		if (of.is_open()) {
			of << "digraph myGraph{\n";
			for (auto t : ItemList) {
				t.graph(of);
			}
			of << "}\n";
			of.close();
		}
		//string cmd = "dot -Tpng " + filename + ".gv > " + filename + ".gv.png";       // create a graphic file and save it to a new file with extension .gv.png
#ifdef __unix
		string dot = "dot";
#else
		string dot = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe";
#endif
		string cmd = dot + " -Tpng " + filename + ".gv >" + filename + ".gv.png";
		cout << cmd << "\n";

		system(cmd.c_str());
	}

	/*Item* find(std::string nameKey) {
		for (unsigned int i = 0; i < ItemList.size(); i++) {
			if (ItemList[i].getName() == nameKey)
				return &ItemList[i];
		}
		return nullptr;
	}*/
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
		ItemManager tm(csvtaskdata);
		tm.print();
		tm.graph(taskfilename);

	}

	catch (const string& e) {
		cerr << e << "\n";
	}

}