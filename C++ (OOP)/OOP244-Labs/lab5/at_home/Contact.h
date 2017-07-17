// OOP244 Workshop 5: Classes with resources 
// File: Contact.h
// Version: 1.0
// Date: 2016/10/14
// Author: M.Saeed Mohiti
/////////////////////////////////////////////

#ifndef ICT_CONTACT_H_
#define ICT_CONTACT_H_
#include "PhoneNumber.h"

namespace ict {
	class Contact {
		char name_[41];
		PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();

	public:

		void read();		
		bool isEmpty()const;
		Contact();
		Contact(const char* name, int phnum);
		~Contact();
		void display () const;
		Contact(const Contact& source);
		Contact& operator=(const Contact& C);
	};

}
#endif
