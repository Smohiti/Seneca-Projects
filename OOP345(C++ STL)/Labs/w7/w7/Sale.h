//Workshop 7 - STL Containers
// M.Saeed Mohiti
#pragma once
#include <vector>
#include <iomanip>
#include "iProduct.h"

namespace w7 {
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(const char*);
		void display(std::ostream&);
	};
}