#pragma once
#include <string>
#include<fstream>
#include<iostream>

namespace w5 {
	class Message {
	public:
		Message() {
		};
		~Message() {
			name.clear();
			reply.clear();
			tweet.clear();

		};
		std::string name, reply, tweet;
		Message(std::ifstream& in, char c) {
			std::string line;
			getline(in, line, c);
			//std::cout << "message read-->" << line << "<--\n";

			size_t index = 0;
			while (index < line.size()) {
				if (line[index] == ' ')break;
				name += line[index];
				index++;
			}
			//std::cout << "name-->" << name << "<--\n";
			index++; // skip the space
			if (index < line.size() && line[index] == '@') {// process reply
				index++; // skip the @
				while (index < line.size()) {
					if (line[index] == ' ')break;
					reply += line[index];
					index++;
				}
				//std::cout << "reply-->" << reply << "<--\n";
				index++;// skip space
			}
			while (index < line.size()) {
				if (line[index] == ' ')break;
				tweet += line[index];
				index++;
			}
			//std::cout << "tweet-->" << tweet << "<--\n";
		}//- constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
		bool empty() const {
			if(tweet.empty());// message in safe state if tweet is empty
			return true; // message in safe if tweet is empty
		}//- returns true if the object is in a safe empty state
		void display(std::ostream& os) const {
			os << "\n";
			os << "Message\n";
				if(! reply.empty())
			os << "User : " << name << "\n";
			os << "Reply :" << reply << "\n";
			os << "Tweet :" << tweet << "\n";
		
		} //- displays the Message objects within the container
	};// class message
} // namespace w5
