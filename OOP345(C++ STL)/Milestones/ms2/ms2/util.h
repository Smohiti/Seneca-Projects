//Milestone 2
// M.Saeed MOhiti
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void trimspace(string& s);
void printcsv(vector<vector<string>> &csvdata);
void csvread(string& filename, char separator, vector<vector<string>> &csvdata);
bool validTask(string s);
bool validSlots(string s);





