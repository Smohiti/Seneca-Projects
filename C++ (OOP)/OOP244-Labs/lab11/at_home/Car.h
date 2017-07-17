#include "Displayable.h"
#ifndef SICT_CAR_H_
#define SICT_CAR_H_

namespace sict{
  class Car :public Displayable{
    char _plate[9];
    char _makeModel[41];
    void set(const char* plate, const char* makeModel);
  public:
    Car(const char* plate, const char* makeModel = "no name");
    std::ostream& display(std::ostream& os)const;
    bool operator<=(const Car& C)const;
    bool operator>=(const Car& C)const;
    operator const char*()const;
  };
}


#endif
