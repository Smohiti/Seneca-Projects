//Workshop 7 - STL Containers
//Sale.cpp
// M.Saeed Mohiti
#include "Sale.h"
using namespace w7;
Sale::Sale(const char* ptr) {
	std::ifstream file(ptr);
	while (file.good()) {
		iProduct* id = readProduct(file);
		products.push_back(id);
	}
}
void Sale::display(std::ostream& os) {
	float total = 0;
	os << "Product No     Cost Taxable\n";
	os << std::fixed << std::setprecision(2);
	for (auto p : products) {
		os << *p;
		total += p->getCharge();
	}
	os << " TOTAL" << std::setw(10) << std::right << total << '\n';
}