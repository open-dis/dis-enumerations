#include <sstream>
#include <cstddef>
#include <disenum/PlatformSpace.h>

namespace DIS {


hashMap<int,PlatformSpace*> PlatformSpace::enumerations;

PlatformSpace PlatformSpace::OTHER(0, "Other");
PlatformSpace PlatformSpace::MANNED(1, "Manned");
PlatformSpace PlatformSpace::UNMANNED(2, "Unmanned");
PlatformSpace PlatformSpace::BOOSTER(3, "Booster");


PlatformSpace::PlatformSpace(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatformSpace* PlatformSpace::findEnumeration(int aVal) {
  PlatformSpace* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatformSpace::getDescriptionForValue(int aVal) {
  PlatformSpace* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatformSpace PlatformSpace::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatformSpace* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatformSpace";
    throw EnumException("PlatformSpace", aVal, ss.str());
  }
};

bool PlatformSpace::enumerationForValueExists(int aVal) {
  PlatformSpace* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatformSpace::enumContainer PlatformSpace::getEnumerations() {
  return (enumerations);
};

PlatformSpace& PlatformSpace::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

