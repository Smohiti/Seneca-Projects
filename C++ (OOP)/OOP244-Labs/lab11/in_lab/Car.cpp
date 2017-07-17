#include <cstring>
#include "Car.h"
namespace sict{
  void Car::set(const char* plate, const char* makeModel){
    std::strncpy(_plate, plate, 8);
    _plate[8] = 0;
    std::strncpy(_makeModel, makeModel, 40);
    _makeModel[40] = 0;;
  }
  Car::Car(const char* plate, const char* makeModel){
    set(plate, makeModel);
  }
  std::ostream& Car::display(std::ostream& os)const{
    return os << _plate << " " << _makeModel;
  }
  bool Car::operator<=(const Car& C)const{
    return std::strcmp(_plate, C._plate) <= 0;
  }
  bool Car::operator>=(const Car& C)const{
    return std::strcmp(_plate, C._plate) >= 0;
  }
  Car::operator const char*()const{
    return _plate;
  }
}
