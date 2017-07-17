// Date: 2016/11/14
// Author: M.Saeed Mohiti
// Good.h
// Project: Milestone 3
/////////////////////////////////////////////
#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict{
	class Good : public ReadWritable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Good();
		Good(const char*, const char*, double, int, bool = true);
		Good(const Good&);
		~Good();
		void sku(const char*);
		void price(double);
		void name(const char*);
		void taxed(bool);
		void quantity(int);
		void qtyNeeded(int);

		const char* sku()const;
		double price() const;
		char* name()const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool operator==(const char*);
		int operator+=(const int);
	};
	 double operator+=(double&, const Good&);
}
std::ostream& operator<<(std::ostream& os, const ict::Good& CO);
std::istream& operator >> (std::istream& is, ict::Good& CO);


#endif