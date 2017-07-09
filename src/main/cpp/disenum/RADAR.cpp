#include <sstream>
#include <cstddef>
#include <disenum/RADAR.h>

namespace DIS {


hashMap<int,RADAR*> RADAR::enumerations;

RADAR RADAR::GENERIC(0, "Generic");
RADAR RADAR::GENERIC_GPR(1, "Generic GPR");
RADAR RADAR::GSTAMIDS_I(2, "GSTAMIDS I");
RADAR RADAR::GSTAMIDS_II(3, "GSTAMIDS II");
RADAR RADAR::HSTAMIDS_I(4, "HSTAMIDS I");
RADAR RADAR::HSTAMIDS_II(5, "HSTAMIDS II");


RADAR::RADAR(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RADAR* RADAR::findEnumeration(int aVal) {
  RADAR* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RADAR::getDescriptionForValue(int aVal) {
  RADAR* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RADAR RADAR::getEnumerationForValue(int aVal) throw(EnumException) {
  RADAR* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RADAR";
    throw EnumException("RADAR", aVal, ss.str());
  }
};

bool RADAR::enumerationForValueExists(int aVal) {
  RADAR* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RADAR::enumContainer RADAR::getEnumerations() {
  return (enumerations);
};

RADAR& RADAR::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

