// Date: 2016/12/07
// Author: M.Saeed Mohiti
// WPlanner.h
// Project: Milestone 5
/////////////////////////////////////////////
#ifndef ICT_WPlanner_H__
#define ICT_WPlanner_H__
#include "Good.h"

namespace ict {
   class WPlanner {
      char filename_[256];
      Good* items_[MAX_NO_RECS];
      std::fstream datafile_;
      int noOfItems_;
      int menu();
      void loadRecs();
      void saveRecs();
      void listItems()const;
      int SearchItems(const char* sku)const;
      void updateQty();
      void addItem(bool isCustomMade);
      void deleteItem();
      void getSku(char* sku);
   public:
      //Copy and assignment prevention goes here:
	  WPlanner& operator=(const WPlanner& filename)=delete;

      WPlanner(const char* filename);
      int run();
   };
}
#endif
