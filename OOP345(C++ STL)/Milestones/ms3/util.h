//Milestone 3
// M.Saeed Mohiti

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool validTaskName(std::string name);
bool validItemName(std::string name);
bool validCustomerName(std::string name);
bool validProductName(std::string name);
void printcsv(std::vector <std::vector<std::string>>& csvdata);
void trimSpaces(std::string& s);
void readcsv(std::string& filename, char delimeter, std::vector <std::vector<std::string>>& csvdata);