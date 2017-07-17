#ifndef ICT_READWRITABLE_H__
#define ICT_READWRITABLE_H__

#include <iostream>
#include <fstream>
namespace ict {
   class ReadWritable {
   public:
      virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
      virtual std::fstream& load(std::fstream& file) = 0;
      virtual std::ostream& display(std::ostream& os, bool linear)const = 0;
      virtual std::istream& conInput(std::istream& is) = 0;
   };
}

#endif // ICT_READWRITABLE
