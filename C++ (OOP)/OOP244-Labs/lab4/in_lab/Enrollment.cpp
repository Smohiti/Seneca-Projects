///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     10/04/2016    workshop4
///////////////////////////////////////////////////////////
#include "Enrollment.h"
#include<string.h>
#include<iostream>
#include<iomanip>
// ict namespace 
using namespace std;
using namespace ict;


  
  //done
  bool Enrollment::isValid()const{
    return name_ && name_[0];
  }
  //done
  void Enrollment::setEmpty(){
    name_[0] = 0;
    code_[0] = 0;
    year_ = 0;
    semester_ = 0;
    slot_ = 0;
    enrolled_ = false;
  }
  // done
  bool Enrollment::isEnrolled() const{
    return enrolled_;
  }

  // done
  void Enrollment::display(bool nameOnly)const{
    if (isValid()){
      cout << name_;
      if (!nameOnly){
        cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
        cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
      }
    }
    else{
      cout << "Invalid enrollment!" << endl;
    }
  }

  Enrollment::Enrollment() {
	  setEmpty();
	  
  }

  Enrollment::Enrollment(const char* name, const char* code,  int year, int semester, int slot) {
	  
	  if ((name && name  [0]) && (code && code [0]) && year >= 2015 && semester > 0 && semester < 4 && slot > 0 && slot < 6) {
		  set(name, code, year, semester, slot);
		  
	  }
	  else {
		  setEmpty();
		 
	  }
  }

  bool Enrollment::hasConflict(const Enrollment &other) const {
	  bool r;
	  if (year_ == other.year_ && semester_ == other.semester_ &&  slot_ == other.slot_ && isValid() && other.isValid()) {
		  r = true;
	  }
	  else {
		  r = false;
	  }
	  return r;
  }

  void Enrollment::set(const char* name, const char* code,
	  int year, int semester, int slot, bool enrolled) {
	  if ((name && name[0]) && (code && code[0]) && year >= 2015 && semester > 0 && semester < 4 && slot > 0 && slot < 6) {
		  strcpy(name_, name);
		  strcpy(code_, code);
		  year_ = year;
		  semester_ = semester;
		  slot_ = slot;
		  enrolled_ = enrolled;
	  }
	  else {
		  setEmpty();
	  }
  }

