// Date: 2016/12/01
// Author: M.Saeed Mohiti
// CustomMade.h
// Project: Milestone 4
/////////////////////////////////////////////
#ifndef ICT_OnShelf_H__
#define ICT_OnShelf_H__
#include "OnShelf.h"
#include "Date.h"
#include"Error.h"
namespace ict{

	class CustomMade : public OnShelf {
	private:
		Date delivery_;

	public:
		CustomMade();
		const Date& delivery() const;
		void delivery(const Date&);
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& display(std::ostream& os, bool linear) const;
		std::istream& conInput(std::istream& is);
	};

}

#endif
