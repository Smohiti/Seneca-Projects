// Date: 2016/12/01
// Author: M.Saeed Mohiti
// Onshelf.h
// Project: Milestone 4
/////////////////////////////////////////////
#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__
#include<iostream>
#include "Good.h"
#include "Error.h"

namespace ict {
   class OnShelf : public Good{
   private:
	   char recTag_;
   protected:
	   Error err_;
   public:
	   OnShelf(char fileTag='O');
	   std::fstream& store(std::fstream& file, bool addNewLine = true )const;
	   std::fstream& load(std::fstream& file);
	   virtual std::ostream& display(std::ostream& os, bool linear)const;
	   std::istream& conInput(std::istream& is) ;
   };
}
#endif