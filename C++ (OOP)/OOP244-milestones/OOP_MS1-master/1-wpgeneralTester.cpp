#include <iostream>
#include "wpgeneral.h"
using namespace std;
int main() {
   bool ok = true;
   if (ok) {
      cout << "Checking defined values, wpgeneral.h: " << endl;
   }
   if (ok && MIN_YEAR != 2000) {
      cout << "MIN_YEAR must be 2000" << endl;
      ok = false;
   }
   if (ok && MAX_YEAR != 2030) {
      cout << "MAX_YEAR must be 2030" << endl;
      ok = false;
   }
   if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)) {
      cout << "TAX must be 0.13" << endl;
      ok = false;
   }
   if (ok && MAX_UPC_LEN != 7) {
      cout << "MAX_UPC_LEN must be 7" << endl;
      ok = false;
   }
   if (ok && MAX_NO_RECS != 2000) {
      cout << "MAX_NO_RECS must be 2000" << endl;
      ok = false;
   }
   if (ok) {
      cout << "Passed!" << endl;
   }
   return 0;
}