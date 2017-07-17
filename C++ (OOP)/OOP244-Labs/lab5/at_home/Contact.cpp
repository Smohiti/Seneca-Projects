
// OOP244 Workshop 5: Classes with resources 
// File: Contact.cpp
// Version: 1.0
// Date: 2016/10/14
// Author: M.Saeed Mohiti
/////////////////////////////////////////////
 
#include <iostream>  
#include <iomanip>
#include <cstring>
#include "Contact.h" 
#include"PhoneNumber.h"

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

  Contact::Contact(const Contact& source) {
	  if (source.isEmpty()) {
		  setEmpty();
	  }
	  else {
		  strncpy(name_, source.name_,40); 
		  name_[40] = '\0';
		  phoneNumber_ = new PhoneNumber[source.noPN_];
		  for (int i = 0; i < source.noPN_; i++)
			  phoneNumber_[i] = source.phoneNumber_[i];
	  }
  }

  Contact& Contact::operator=(const Contact& C) {
	  if (this != &C) { 
		  return *this;
	  }
	  else {
		  delete[] phoneNumber_;
		  for (int i = 0; i < 41; i++)
			  name_[i] = C.name_[i];
		  phoneNumber_ = new PhoneNumber[C.noPN_];
		  for (int i = 0; i < C.noPN_; i++)
			  phoneNumber_[i] = C.phoneNumber_[i];
		  return *this;
	  }

  }
}