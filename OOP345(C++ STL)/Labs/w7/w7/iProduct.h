#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
//Workshop 7 - STL Containers
// M.Saeed Mohiti
#include <iostream>
#include <fstream>
#include <iomanip>

namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

	class Product : public iProduct {
		double price;
		int id;
	public:
		Product(const int, const double);
		double getCharge() const;
		void display(std::ostream&) const;
	};

	class TaxableProduct : public iProduct {
		double price;
		int id;
		char tax;
	public:
		TaxableProduct(const int, const double, const char);
		double getCharge() const;
		void display(std::ostream&) const;
	};

}
#endif