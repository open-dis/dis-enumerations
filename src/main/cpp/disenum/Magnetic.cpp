#include <sstream>
#include <cstddef>
#include <disenum/Magnetic.h>

namespace DIS {


hashMap<int,Magnetic*> Magnetic::enumerations;

Magnetic Magnetic::GENERIC(0, "Generic");
Magnetic Magnetic::AN_PSS_11(1, "AN-PSS-11");
Magnetic Magnetic::AN_PSS_12(2, "AN-PSS-12");
Magnetic Magnetic::GSTAMIDS(3, "GSTAMIDS");


Magnetic::Magnetic(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Magnetic* Magnetic::findEnumeration(int aVal) {
  Magnetic* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Magnetic::getDescriptionForValue(int aVal) {
  Magnetic* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Magnetic Magnetic::getEnumerationForValue(int aVal) throw(EnumException) {
  Magnetic* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Magnetic";
    throw EnumException("Magnetic", aVal, ss.str());
  }
};

bool Magnetic::enumerationForValueExists(int aVal) {
  Magnetic* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Magnetic::enumContainer Magnetic::getEnumerations() {
  return (enumerations);
};

Magnetic& Magnetic::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

