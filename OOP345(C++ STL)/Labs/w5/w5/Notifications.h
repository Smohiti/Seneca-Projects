#pragma once
#include<iostream>
#include<fstream>
namespace w5 {
	class Notifications{
		const int MAX_MESSAGE = 10;
		int messageCount;
		Message* messageTable;
	public:
		Notifications() : messageCount(0), messageTable(nullptr) {
			std::cout << "copt =op: this/msgTable= " << (void*)this << "/n" << (void*)messageTable << "/n";
			//cout << "rhs this/msgTable= " << (void*)&rhs << "/n" << (void*)rhs.msgTable << "/n";
		}//- default constructor - empty
		
			Notifications(const Notifications& rhs) : messageCount(rhs.messageCount), messageTable(nullptr) {
				if (rhs.messageTable) {
					messageTable = new Message[MAX_MESSAGE];
					for (int i = 0; i < messageCount; i++)
						messageTable[i] = rhs.messageTable[i];

				}
			}//-copy constructor
			Notifications& operator=(const Notifications& rhs) {
				if (rhs.messageTable) {
					messageTable = new Message[MAX_MESSAGE];
					for (int i = 0; i < messageCount; i++)
						messageTable[i] = rhs.messageTable[i];

				}
				delete[] messageTable;
				messageTable = nullptr;
				messageCount = 0;
				
			} //-copy assignment operator
			Notifications(Notifications&&rhs) : messageCount(rhs.messageCount), messageTable(rhs.messageTable) {//steal brain
				// turn into th zombi
				rhs.messageCount = 0;
				rhs.messageTable = 0;
			} //- move constructor
			Notifications&& operator=(Notifications&& rhs) {
				delete[] messageTable;
				messageTable = nullptr;
				messageCount = 0;

				//steal brain
				messageCount = rhs.messageCount;
				messageTable = rhs.messageTable;

				// turn into th zompbi
				rhs.messageCount = 0;
				rhs.messageTable = nullptr;

			} //-move assignment operator
			~Notifications() {
				delete[] messageTable;
			}// - destructor
			void operator+=(const Message& msg) {
				if (messageTable == nullptr)
					messageTable = new Message[MAX_MESSAGE];
				if (messageCount < MAX_MESSAGE) {
					messageTable[messageCount] = msg;
					messageCount++;
				}
			} //- adds msg to the set
			void display(std::ostream& os) const {

				//os << "Notifications\n";
				//os << "== == == == == == =\n";
				for (int i = 0; i < messageCount; i++)
					messageTable[i].display(os);
			
			} //- inserts the Message objects to the os output stream

	}; // class Notifications
} // namespace w5