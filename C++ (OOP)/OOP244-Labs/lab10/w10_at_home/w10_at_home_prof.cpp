#include <iostream>
#include "String.h"

using namespace std;
using namespace ict;

// prints a string and its properties
ostream& operator~(String& str)
{
   return cout << "->" << str << "<- len: " << str.getLength() << ", mem: " << str.getMemSize() << endl;
}

int main(){
   int i;
   char str[500] = "One";
   String S1;
   String S2("Two", 10);
   String S3("Three", 4);
   String S31(S3);
   String tmp;
   ~S1;
   ~S2;
   ~S3;
   ~S31;
   S31 = "Thirty One";
   ~S31;
   cout << (const char*)S31 << endl;
   S1 += str;
   ~S1;
   S1 += " ";
   ~S1;
   S1 += S2;
   ~S1;
   tmp = S1++;
   ~tmp;
   tmp = S1 + S3;
   ~tmp;
   ++tmp;
   ~tmp;
   cout << '>';
   for (i = 0; i < (int)tmp; i++)
   {
      cout << tmp[i];
   }
   cout << '<' << endl;
   tmp[0] = tmp[4] = tmp[8] = 'X';
   ~tmp;
   return 0;
}
