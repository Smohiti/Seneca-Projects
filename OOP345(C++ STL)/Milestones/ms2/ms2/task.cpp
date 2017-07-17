//Milestone 2
// M.Saeed MOhiti
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "util.h"
using namespace std;
class Task;
class TaskManager;

class Task {
	string taskName, taskSlots, taskPass, taskFail;
public:
	Task(vector<string>&row)
		:taskSlots("1")
	{
		for (auto e : row)
			cout << "~" << e << "~";
		cout << "\n";
		switch (row.size()) {
		case 4:
			if (validTask(row[3]))
				taskFail = row[3];
			else
				throw string("expected a fail task name '") + row[3] + "'";
			//fall through to 3 field case
		case 3:
			if (validTask(row[2]))
				taskPass = row[2];
			else
				throw string("expected a pass task name '") + row[2] + "'";
			//fall through to 2 field case
		case 2:
			if (validSlots(row[1]))
				taskSlots = row[1];
			else
				throw string("expected a slot '") + row[1] + "'";
		case 1:
			if (validTask(row[0]))
				taskName = row[0];
			else
				throw string("expected a task name '") + row[0] + "'";
			break;
		default: throw string("found") + to_string(row.size()) + "fields, expected 1,2,3 or 4";

		}
	}
	void print() {
		cout << "task: name/slots/pass/fail ="
			<< taskName << "/"
			<< taskSlots << "/"
			<< taskPass << "/"
			<< taskFail << "/"
			<< "\n";
	}
	void graph(std::fstream &os) {
		if (!taskFail.empty())
			os << '"' << taskName << '"' << "->" << '"' << taskFail << '"' << " [color=red];" << std::endl;
			//os << "'"<< taskName + "' ->" + taskFail + "[color=red]\n";
		if (!taskPass.empty())
			os << '"' << taskName << '"' << "->" << '"' << taskPass << '"' << " [color=green];" << std::endl;
			//os << taskName + " ->" + taskPass + "[color=green]\n";
		if (taskPass.empty() && taskFail.empty())
			os << taskName << std::endl;
	}

};

class TaskManager {
	vector<Task>tasks;
public:
	TaskManager(){}
	TaskManager(vector<vector<string>> &csvdata){
		for (auto row : csvdata) {
			try {
				tasks.push_back(move(Task(row)));
			}catch (const string& e) {
				cerr << "TaskManagr: problem" << e << "\n";
			}
	}
	}
	void print() {
		for (auto t : tasks)
			t.print();
	}
	void graph(string &filename) {
		string dotFile = filename + ".gv";
		std::fstream os(dotFile, std::ios::out | std::ios::trunc);
		if (!os.is_open()) {
			cerr << "TaskManager::graph -> Cannot create " << dotFile << "\n";
			cerr << "filename='" << filename << "'\n";
			return;
		}
		os << "digraph taskGraph {\n";
		for (auto t : tasks)
			t.graph(os);
		os << "}\n";
		os.close();
#ifdef __unix
		string dot = "dot";
#else
		string dot = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe";
#endif
	    string cmd = dot + " -Tpng " + filename + ".gv >" + filename +".gv.png";
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
		csvread(taskfilename, separator, csvtaskdata);
		//printcsv(csvdata);  // everything is fine with csvread
		TaskManager tm(csvtaskdata);
		tm.print();
		tm.graph(taskfilename);

	}

	catch (const string& e) {
		cerr << e << "\n";
	}

}