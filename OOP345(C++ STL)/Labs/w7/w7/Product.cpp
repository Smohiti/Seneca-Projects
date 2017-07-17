//Workshop 7 - STL Containers
//Product.cpp
// M.Saeed Mohiti
#include "iProduct.h"

namespace w7 {
	Product::Product(const int x, const double z) {
		id = x;
		price = z;
	}

	double Product::getCharge() const {
		return price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << std::right;
		os << id;
		os << std::setw(10) << std::right;
		os << price << '\n';
	}

	TaxableProduct::TaxableProduct(const int x, const double z, const char y) {
		id = x;
		price = z;
		tax = y;
	}

	double TaxableProduct::getCharge() const {
		double tax = 0;
		if (tax == 'H') {
			tax = 1.13;
		}

		if (tax == 'P') {
			tax = 1.08;
		}
		return price*tax;
	}

	void TaxableProduct::display(std::ostream& os) const {
		os << std::setw(10) << std::right << id << std::setw(10) << std::right << price;
		os << ' ';
		if (tax == 'H') {
			os << "HST";
		}

		if (tax == 'P') {
			os << "PST";
		}
		os << '\n';
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& z) {
		z.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream& is) {
		int ID;
		double PRICE;
		char TAX;
		iProduct* ptr;

		is >> ID >> PRICE;
		if (is.get() != '\n') {
			is.get(TAX);
			ptr = new TaxableProduct(ID, PRICE, TAX);
		}
		else {
			ptr = new Product(ID, PRICE);
		}
		return ptr;
	}
}