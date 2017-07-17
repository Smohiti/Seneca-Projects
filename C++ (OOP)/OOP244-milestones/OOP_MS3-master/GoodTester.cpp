// Final Project Milestone 3 
// Good Tester program
// File	GoodTester.cpp
// Version 1.0
// Date	2016/11/09
// Author	Fardad Soleimanloo
//
/////////////////////////////////////////////////////////////////

#include "Good.h"
#define TAB '\t'
#include <iomanip>
using namespace std;
namespace ict{
  class SGood :public Good{
  public:
    SGood() :Good("", "", 0, 0){}
    SGood(const SGood& SG) :Good(SG){};
    virtual std::fstream& store(std::fstream& file)const{
      file.open("ms3.txt", ios::out);
      file << sku() << TAB << name() << TAB << quantity() << TAB << qtyNeeded() << TAB
        << int(taxed()) << TAB << price() << endl;
      file.close();
      return file;
    }
    virtual std::fstream& load(std::fstream& file){
      file.open("ms3.txt", ios::in);
      char buf[2000];
      double dbuf;
      int ibuf;
      file >> buf;
      sku(buf);
      file >> buf;
      name(buf);
      file >> ibuf;
      quantity(ibuf);
      file >> ibuf;
      qtyNeeded(ibuf);
      file >> ibuf;
      taxed(!!ibuf);
      file >> dbuf;
      price(dbuf);
      file.close();
      return file;
    }
    virtual std::ostream& display(std::ostream& os, bool linear)const{
      return os << sku() << ": " << name() << endl
        << quantity() << "<OnHand --- Needed>" << qtyNeeded() << endl
        << "Cost:" << fixed << setprecision(2) << cost();
    }
    virtual std::istream& conInput(std::istream& is){
      char buf[2000];
      double dbuf;
      int ibuf;
      cout << "sku: ";
      is >> buf;
      sku(buf);
      cout << "name (no spaces): ";
      is >> buf;
      name(buf);
      cout << "qty: ";
      is >> ibuf;
      quantity(ibuf);
      cout << "qty Needed: ";
      is >> ibuf;
      qtyNeeded(ibuf);
      cout << "is taxed? (1/0): ";
      is >> ibuf;
      taxed(!!ibuf);
      cout << "price: ";
      is >> dbuf;
      price(dbuf);
      return is;
    }
  };
}

using namespace ict;

int main() {
   double res, val = 0.0;
   fstream F;
   SGood Cn, Ld, Gd;
   cout << "Please enter the following informartion for Good:" << endl
      << "sku: 123<ENTER>" << endl
      << "name: abcd<ENTER>" << endl
      << "qty: 10<ENTER>" << endl
      << "qty Needed: 20<ENTER>" << endl
      << "is taxed? 1<ENTER>" << endl
      << "price 10.0<ENTER>" << endl;
   cout << "Enter Good info: " << endl;
   cin >> Cn;
   cout << "Read into Cn..." << endl << "Copying Cn into Cpy..." << endl;
   SGood Cpy = Cn;
   cout << "Storing in file from Cn..." << endl;
   Cn.store(F);
   cout << "Loading from file into Ld..." << endl;
   Ld.load(F);
   cout << "Printing Ld:" << endl;
   cout << Ld << endl << endl;
   cout << "Printing Cn:" << endl;
   cout << Cn << endl << endl;
   cout << "Printing Cpy, copy of Cn:" << endl;
   cout << Cpy << endl << endl;
   cout << "Assigning Gd to Ld..." << endl;
   Gd = Ld;
   cout << "Printing Gd:" << endl;
   cout << Gd << endl;
   cout << "Testing operator==:" << endl;
   cout << "op== is " << ((Ld == "123") ? "OK" : "NOT OK") << endl << endl;
   cout << "Testing operator+=  Gd+= 20..." << endl;
   Gd += 20;
   cout << "Printing Gd:" << endl;
   cout << Gd << endl;
   cout << "Setting Gd not to be taxed..." << endl;
   Gd.taxed(false);
   cout << "Printing Gd:" << endl;
   cout << Gd << endl;
   cout << "operator+=(double, Good):" << endl;
   res = val += Gd;
   cout << res << "=" << val << endl << endl;
   return 0;
}