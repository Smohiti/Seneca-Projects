// Date: 2016/12/01
// Author: M.Saeed Mohiti
// CustomMade.cpp
// Project: Milestone 4
/////////////////////////////////////////////
	#include<iostream>
	#include<iomanip>
	#include<fstream>
	#include "CustomMade.h"
	#include "OnShelf.h"
	using namespace std;
	namespace ict{
	CustomMade::CustomMade():OnShelf('C'){
	}
	const Date& CustomMade::delivery()const{
		return delivery_;
	}
	void CustomMade::delivery(const Date &value){
		delivery_ = value;	
	}
	fstream& CustomMade::store(fstream& file, bool addNewLine)const{
		OnShelf::store(file, false);
	file << "," << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_<<endl;
		return file;
	}
	fstream& CustomMade:: load(fstream& file){
		OnShelf::load(file);
		file.ignore();
		file >> delivery_;
		Date(delivery_);
		return file;
	}
	ostream& CustomMade::display(ostream& ostr, bool linear)const{
		OnShelf::display(ostr, linear);
		if (err_.isClear()){
			if (linear){
				ostr << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
			}
			else{
				ostr << endl << "delivery date: " << delivery_;
			//	ostr << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
			}
		}
		return ostr;
	}
	istream& CustomMade::conInput(istream& istr){
		OnShelf::conInput(istr);
		if (err_.isClear() && !istr.fail()){
			Date tDate;
			cout << "delivery date (YYYY/MM/DD) : ";
			istr >> tDate;
			if (tDate.bad()){
				switch (tDate.errCode()){
				case CIN_FAILED:
					err_ = "Invalid Date Entry";
					break;
				case YEAR_ERROR:
					err_ = "Invalid Year in Date Entry";
					break;
				case MON_ERROR:
					err_ = "Invalid Month in Date Entry";
					break;
				case DAY_ERROR:
					err_ = "Invalid Day in Date Entry";
					break;
				}
				istr.setstate(ios::failbit);
			}
			else{
				delivery(tDate);
			}
		}
		return istr;
	}
}
