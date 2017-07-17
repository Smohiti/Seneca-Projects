// Date: 2016/12/01
// Author: M.Saeed Mohiti
// Onshelf.cpp
// Project: Milestone 4
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "OnShelf.h"

namespace ict {
	OnShelf::OnShelf(char fileTag) {
		recTag_ = fileTag;
	}
	std::fstream& OnShelf::store(std::fstream& file, bool addNewLine)const {
		//if(addNewLine==true)
			file << recTag_ << ',' << sku() << ',' << name() << ',' << price() << ',' << taxed()
			<< ',' << quantity() << ',' << qtyNeeded();
			if (addNewLine == true)
				file << std::endl;
		//else
			//file << sku() << ',' << name() << ',' << price() << ',' << taxed()
			//<< ',' << quantity() << ',' << qtyNeeded();
		return file;
	}
	std::fstream& OnShelf::load(std::fstream& file) {
		char u[MAX_SKU_LEN +1];
		char n[256];
		double p;
		bool t;
		int q;
		int qn;

		file.getline(u, MAX_SKU_LEN + 1, ',');
		sku(u);
		file.getline(n, 256, ',');
		name(n);
		file >> p;
		price(p);
		file.ignore();
		file >> t;
		taxed(bool(t));
		file.ignore();
		file >> q;
		quantity(q);
		file.ignore();
		file >> qn;
		qtyNeeded(qn);
		//file.ignore();

		//Call Setters
/*
		sku(u);
		name(n);
		price(p);
		if (t) {
			taxed(true);
		}
		else {
			taxed(false);
		}
		quantity(q);
		qtyNeeded(qn);
		*/
		return file;
	}
	std::ostream& OnShelf::display(std::ostream& os, bool linear) const {
		if (err_.isClear() == false) {
			os << err_.message();
		}
		else if (linear) {
			os << std::setfill(' ')<< std::right << std::setw(4) << sku() << '|'
				<< std::setw(20) << std::left << name() << '|'
				<< std::right << std::setw(7) << std::fixed << std::showpoint << std::setprecision(2) << cost() << '|';
			if (taxed()) {
				os << " t |";
			}
			else {
				os << "   |";
			}
			os << std::setw(4) << quantity() << '|'
				<< std::setw(4) << qtyNeeded() << '|';
		}
		else {
			os << "Sku: " << sku() << std::endl
				<< "Name: " << name() << std::endl
				<< "Price: " << price() << std::endl;
			if (taxed() == true) {
				os << "Price after tax: " << (TAX + 1) * price() << std::endl;
			}
			else {
				os << "Price after tax: N/A" << std::endl;
			}
			os << "Quantity On Hand: " << quantity() << std::endl
				<< "Quantity Needed: " << qtyNeeded() ;
		}
		return os;
	}
	std::istream& OnShelf::conInput(std::istream& is) {
		char u[256];
		char n[256];
		double p;
		char t;
		int q;
		int qn;
		if (is.fail() == false) {
			err_.clear();
			std::cout << "Sku: ";
			is >> u;
			if (is.fail() == false) {
				sku(u);
			}
			std::cout << "Name: ";
			is >> n;
			if (is.fail() == false) {
				name(n);
			}
			std::cout << "Price: ";
			is >> p;
			if (is.fail()) {
				err_.message("Invalid Price Entry");
			}
			else {
				price(p);
			}
			if (err_.isClear()) {
				std::cout << "Taxed: ";
				is >> t;
				if (t == 'Y' || t == 'y') {
					taxed(true);
				}
				else if (t == 'N' || t == 'n') {
					taxed(false);
				}
				else {
					err_.message("Only (Y)es or (N)o are acceptable");
					is.setstate(std::ios::failbit);
				}
			}
			if (err_.isClear()) {
				std::cout << "Quantity On hand: ";
				is >> q;
				if (is.fail()) {
					err_.message("Invalid Quantity Entry");
				}
				else {
					quantity(q);
				}
			}
			if (err_.isClear()) {
				std::cout << "Quantity Needed: ";
				is >> qn;
				if (is.fail()) {
					err_.message("Invalid Quantity Needed Entry");
				}
				else {
					qtyNeeded(qn);
				}
			}
		}
		return is;
	}
}
