//Milestone 3
// M.Saeed Mohiti
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

class Task {
	string taskName, taskSlots, taskPass, taskFail;
public:
	//Task(): taskSlots("1") {}
	Task(vector <string> & row) {
		switch (row.size())
		{
		case 4:
			if (validTask(row[3]))
			{
				taskFail = row[3];
			}
			else
			{
				throw string("Expected a fail task name, found >") + row[3] + "<";
			}

		case 3:
			if ( validTask(row[2]))
			{
				taskPass = row[2];
			}
			else
			{
				throw string("Expected a pass task name, found >") + row[2] + "<";
			}
		case 2:
			if (validSlots(row[1]))
			{
				taskSlots = row[1];
			}
			else
			{
				throw string("Expected a slot task name, found >") + row[1] + "<";
			}
		case 1:
			if (validTask(row[0]))
			{
				taskName = row[0];
			}
			else
			{
				throw string("Expected a name task name, found >") + row[0] + "<";
			}

			break;
		default:
			throw string("Expected 1,2,3 or 4 fields, but found ") + to_string(row.size());
		}
	}
	void Print() {
		cout << "[" << taskName << "] "
			<< "[" << taskSlots << "] "
			<< "[" << taskPass << "] "
			<< "[" << taskFail << "] "
			<< "\n";
	}
	void Graph(fstream& os) {
		if (!taskPass.empty())
		{
			os << '"' << taskName << '"' << "->" << '"' << taskPass << '"' << "[color=green]" << ";\n";
		}
		if (!taskFail.empty())
		{
			os << '"' << taskName << '"' << "->" << '"' << taskFail << '"' << "[color=red]" << ";\n";
		}
		if (taskPass.empty() && taskFail.empty()) {
			os << '"' << taskName << '"' << "\n";
		}
	}

};

class TaskManager {
	vector <Task> taskList;
public:
	TaskManager(vector <vector<string>>& csvTask) {
		int lineNumber = 0;
		for (auto &row : csvTask) {
			try {
				lineNumber++;
				taskList.push_back(move(Task(row)));
			}
			catch (const string& e) {
				cerr << "Error on line " << lineNumber << ":" << e << "\n";
			}
		}
	}
	void Print() {
		for (auto t : taskList) {
			t.Print();
		}
	}
	void Graph(string& filename) {
		fstream os(filename, ios::out | ios::trunc);
		if (os.is_open()) {
			os << "digraph task {\n";
			for (auto t : taskList) {
				t.Graph(os);
			}
			os << "}\n";
			os.close();

			string cmd = "dot -Tpng " + filename + " > " + filename + ".png";

			//string cmd = "C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe -Tpng " + filename + " > " + filename + ".png";
			cout << "running -->" << cmd << "\n";
			cout << "command returned " << system(cmd.c_str()) << " (zero is good)\n";
		}
	}
};


int main(int argc, char* argv[]) {
	try {
		if (argc != 3) {
			throw string("Usage ") + argv[0] + string(" filename delimiter-char");
		}
		string filename = argv[1]; // First arg is file name
		char delimiter = argv[2][0]; // Second arg, 1st char is delimiter

		vector <vector<string>> csvData;
		csvread(filename, delimiter, csvData);

		//csvPrint(csvData);
		TaskManager tm(csvData);
		tm.Print();
		string graphLine = filename + ".gv";
		tm.Graph(graphLine);
	}
	catch (const string& e) {
		cerr << e << "\n";
	}
}