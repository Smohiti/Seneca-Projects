// Date: 2016/11/14
// Author: M.Saeed Mohiti
// Good.cpp
// Project: Milestone 3
/////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict {
	//constructors
	Good::Good() {
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = false;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}
	Good::Good(const char* S, const char* N, double P, int Q, bool T) {
		sku(S);
		name(N);
		price(P);
		taxed(T);
		quantity(Q);
		qtyNeeded(0);
	}
	Good::Good(const Good& other) {
		sku(other.sku_);
		name(other.name_);
		price(other.price_);
		qtyNeeded(other.qtyNeeded_);
		taxed(other.taxed_);
		quantity(other.quantity_);
	}
	Good::~Good() {
		if (name_ != nullptr) {
			delete name_;
		}
	}
	//setters
	void Good::sku(const char*sku) {
		strncpy(sku_, sku, MAX_SKU_LEN);
	}
	void Good::price(double price){
		price_ = price;
	}	
	void Good::name(const char* name) {
		name_ = new char[strlen(name) + 1];
		if (name_ != nullptr) {
			strncpy(name_, name, strlen(name) + 1);
		}
	}
	void Good::taxed(bool taxed) {
		taxed_ = taxed;
	}
	void Good::quantity(int quantity) {
		quantity_ = quantity;
	}
	void Good::qtyNeeded(int qtyNeeded) {
		qtyNeeded_ = qtyNeeded;
	}
	//getters
	const char* Good::sku() const {
		return sku_;
	}
	double Good::price() const{
		return price_;
	}
	char* Good::name()const{
		return name_;
	}
	bool Good::taxed() const{
		return taxed_;
	}
	int Good::quantity() const{
		return quantity_;
	}
	int Good::qtyNeeded() const{
		return qtyNeeded_;
	}
	double Good::cost() const {
		double cost = price_;
		if (taxed_) {
			cost *= TAX + 1;
		}
		return cost;
	}
	//member operators
	bool Good::operator==(const char*sku){
		if (strcmp(sku_, sku) == 0)
			return true;
		else
			return false;
	}
	int Good::operator+=(const int qty){
		return quantity_ += qty;
	}

	double operator+=(double& A, const ict::Good& B) {
		A += B.cost() * B.quantity();
		return A;
	}
}

std::ostream& operator<<(std::ostream& os, const ict::Good& CO) {
	return CO.display(os, true);
}

std::istream& operator >> (std::istream& is, ict::Good& CO) {
	return CO.conInput(is);
}