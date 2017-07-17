// Date: 2016/12/07
// Author: M.Saeed Mohiti
// WPlanner.cpp
// Project: Milestone 5
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"
using namespace std;
namespace ict {

   WPlanner::WPlanner(const char* filename) {
	   if (filename) {
		   strncpy(filename_, filename, 256);
		/*   if (strlen(filename) >= 256) {
			   filename_[256 - 1] = 0;
		   }*/
		   for (int i = 0; i < MAX_NO_RECS; i++) {
			   items_[i] = nullptr;
		   }
		   noOfItems_ = 0;
		   loadRecs();
	   }
   }

   void WPlanner::saveRecs() {
	   datafile_.open(filename_, ios::out);
	   if (datafile_.is_open()){
		   for (int i = 0; i < noOfItems_; i++) {
			   items_[i]->store(datafile_);
		   }
	   }
	   datafile_.close();
   }

   void WPlanner::loadRecs() {
	   int readIndex = 0;
	   char ch;
	//   Good* Item;
     //  Item = nullptr;
	   datafile_.open(filename_, ios::in);
	   if (datafile_.fail()) {
		   datafile_.clear();
		   datafile_.close();
		   datafile_.open(filename_, ios::out);
		   datafile_.close();
	   }
	   else {
		/*   while (true) {
			   datafile_ >> ch;
			   if (datafile_.fail()) {
				   break;
			   }
			   datafile_.ignore();*/
		   while (readIndex < MAX_NO_RECS && !datafile_.fail()) {
			   ch = datafile_.get();
			   if (ch == 'C') {
				   items_[readIndex] = new CustomMade;
			   }
			   else if (ch == 'O') {
				   items_[readIndex] = new OnShelf;
			   }
			   if (ch == 'O' || ch == 'C') {
				   datafile_.ignore();
				   items_[readIndex]->load(datafile_);
				   readIndex++;
				  // datafile_.ignore(1000, '\n');
			   }
		 }
		   noOfItems_ = readIndex;
		   datafile_.close();
	   }  
   }

   void WPlanner::getSku(char* sku) {
	   cout << "Please enter the SKU: ";
	   cin.get();
	   cin.getline(sku, (MAX_SKU_LEN + 1));
	   if (cin.fail()) {
		   cin.clear();
		   cin.ignore();
	   }
   }

   void WPlanner::deleteItem() {
	   char sku[MAX_SKU_LEN + 1];
	   getSku(sku);
	   char tS = ' ';
	   int i = SearchItems(sku);
	   if (i == -1) {
		   cout << "\nItem Not found!" << endl << endl;
	   }
	   else
	   {
		   cout << "\nThe following Item will be deleted:" << endl;
		   items_[i]->display(cout, false);
		   cout << endl << endl;
		   cout << "Type (Y) to confirm or (N) to abort: ";
		   cin >> tS;
		   if (tS == 'Y' || tS == 'y') {
			   delete items_[i];
			   for (; i < noOfItems_; i++)
				   items_[i] = items_[i + 1];
			   cout << "\nItem deleted!" << endl << endl;
			   noOfItems_ = noOfItems_ - 1;
		   }
		   else
		   {
			   cout << "\nAborted!" << endl << endl;
		   }
	   }

      //cout << "Not implemented!" << endl << endl;
   }

   void WPlanner::updateQty() {
	   char* sku = new char[MAX_SKU_LEN + 1];
	   this->getSku(sku);
	   int tempGood;
	   int i = SearchItems(sku);
	   Good* good;

	   if (i == -1) {
		   cout << "Not found!" << endl << endl;
	   }
	   else {
		   good = items_[i];
		   cout << endl;
		   good->display(cout, false);
		   cout << endl << "\nPlease enter the number of purchased goods: ";
		   cin >> tempGood;
		   if (cin.fail()) {
			   cout << "Invalid Quantity value!" << endl;
		   }
		   else {
			   if (tempGood <= (items_[i]->qtyNeeded() - items_[i]->quantity())) {
				   *items_[i] += tempGood;
			   }
			   else {
				   *items_[i] += (items_[i]->qtyNeeded() - items_[i]->quantity());
				   cout << "Too many purchased, only " << items_[i]->qtyNeeded() <<
					   " needed, please return the extra " << tempGood - items_[i]->qtyNeeded()
					   << "." << endl;
			   }
			   cout << "\nUpdated!\n" << endl;
			   saveRecs();
		   }
	   }
   }

   void WPlanner::listItems()const {
	 // int calcs = 0;
	  double total = 0;
      cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
         << "-----|-----|--------------------|-------|---|----|----|----------" << endl;
	  for (int i = 0; i < noOfItems_; i++) {
		  cout << setfill(' ') << right << setw(4) << (i+1 ) << " | " << *items_[i] << endl;
		 // calcs++;
		  total += *items_[i];
		  //Good& ii = *items_[i];
		 // cout << ii << endl;
	  }
      cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl
	  << "Total cost of the Wedding: $" << fixed << setprecision(2) << showpoint << total << endl;
	  cout << endl;
   }
   int WPlanner::SearchItems(const char* sku)const {
	   int i;
	   int ii = -1;
	   for (i = 0; i < noOfItems_; i++) {
		   if (strcmp(items_[i]->sku(), sku) == 0) {
			   ii = i;
			   i = noOfItems_;
		   }
	   }
	   return ii;
   }

   void WPlanner::addItem(bool isCustomMade) {
	   Good* Item;
	   if (isCustomMade) {
	   Item = new CustomMade();
	   }
	   else {
	   Item = new OnShelf();
	   }
	   Item->conInput(cin);
	   if (!cin.fail()) {
		   items_[noOfItems_++] = Item;
		   saveRecs();
		   cout << "\nGood added\n" << endl;
	   }
	   else if (cin.fail()) {
	   Item->display(cout, false);
	   }   
   }
   
   int WPlanner::menu() {
      int selection = -1;
	  cout
		 // << endl
		  << "Wedding Planner Management Program" << endl
		  << "1 - List goods" << endl
		  << "2 - Add On Shelf Good" << endl
		  << "3 - Add Custom-Made Good" << endl
		  << "4 - Update Good quantity" << endl
		  << "5 - Delete" << endl
		  << "0 - Exit program" << endl
		  << "> ";
	  cin >> selection;
	  cout << endl;
	  if (cin.fail() || selection >= 6) {
		  cin.clear();
		  cin.ignore();
		  selection = -1;
	  }
      return selection;
   }

   int WPlanner::run() {
      bool done = false;
	 // int entry = -1;
	  int entry;
	//  char sku[MAX_SKU_LEN];
      while (!done) {
		  entry = menu();
         switch (entry) {
         case 1:
			 listItems();
            break;
         case 2:
			 addItem(false);
            break;
         case 3:
			 addItem(true);
            break;
         case 4:
			 updateQty();
            break;
         case 5:
			 deleteItem();
            break;
         case 0:
            done = true;
            cout << "Goodbye!!" << endl << endl;
            break;
         case -1:
            cout << "===Invalid Selection, try again.===" << endl <<endl ;
            break;
         }
      }
      return 0;
   } // WPlanner::run() end
}


/* outputs

Wedding Planner Management Program
1 - List goods
2 - Add On Shelf Good
3 - Add Custom-Made Good
4 - Update Good quantity
5 - Delete
0 - Exit program
>



Not found!

Please enter the number of purchased goods:

Too many purchased, only 5 needed, please return the extra 15.

Updated!

Not implemented!

*/
