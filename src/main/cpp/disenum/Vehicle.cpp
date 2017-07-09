#include <sstream>
#include <cstddef>
#include <disenum/Vehicle.h>

namespace DIS {


hashMap<int,Vehicle*> Vehicle::enumerations;

Vehicle Vehicle::X_0_9(0, "0-9");
Vehicle Vehicle::BLANK(32, "Blank");


Vehicle::Vehicle(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Vehicle* Vehicle::findEnumeration(int aVal) {
  Vehicle* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Vehicle::getDescriptionForValue(int aVal) {
  Vehicle* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Vehicle Vehicle::getEnumerationForValue(int aVal) throw(EnumException) {
  Vehicle* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Vehicle";
    throw EnumException("Vehicle", aVal, ss.str());
  }
};

bool Vehicle::enumerationForValueExists(int aVal) {
  Vehicle* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Vehicle::enumContainer Vehicle::getEnumerations() {
  return (enumerations);
};

Vehicle& Vehicle::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

