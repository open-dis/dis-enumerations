#include <sstream>
#include <cstddef>
#include <disenum/Laser.h>

namespace DIS {


hashMap<int,Laser*> Laser::enumerations;

Laser Laser::GENERIC(0, "Generic");
Laser Laser::ASTAMIDS(1, "ASTAMIDS");


Laser::Laser(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Laser* Laser::findEnumeration(int aVal) {
  Laser* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Laser::getDescriptionForValue(int aVal) {
  Laser* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Laser Laser::getEnumerationForValue(int aVal) throw(EnumException) {
  Laser* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Laser";
    throw EnumException("Laser", aVal, ss.str());
  }
};

bool Laser::enumerationForValueExists(int aVal) {
  Laser* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Laser::enumContainer Laser::getEnumerations() {
  return (enumerations);
};

Laser& Laser::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

