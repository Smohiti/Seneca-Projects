
// OOP244 Workshop 5: Classes with resources 
// File: Contact.cpp
// Version: 1.0
// Date: 2016/10/11
// Author: M.Saeed Mohiti
/////////////////////////////////////////////
#include "Contact.h"  
#include <cstring>
#include <iostream>     
#include <iomanip>

using namespace std;
namespace ict{

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << noPN_ << " phone numbers: " << endl;
    for (int i = 0; i < noPN_; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }

  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }

  void Contact::setEmpty(){
    name_[0] = 0;
    noPN_ = 0;
	phoneNumber_ = nullptr;
  }
  Contact::Contact() {
	 // phoneNumber_ = nullptr;
	  setEmpty();
  }

  Contact::Contact(const char* name, int phnum) {
	  phoneNumber_ = new PhoneNumber[phnum];
	 
	  name_[40] = '\0';
	  strncpy(name_, name,40);
	  noPN_ = phnum;
	 
  }
  Contact::~Contact() {
	  delete[] phoneNumber_;
	  //setEmpty();

	  
  }
  void Contact::display()const {
	  cout << name_ << endl;
	  for (int i = 0; i < noPN_; i++) {
		//  if (isEmpty() != true);
		  phoneNumber_[i].display();
	  }
	  cout << "----------------------------------------" << endl;
  }
}