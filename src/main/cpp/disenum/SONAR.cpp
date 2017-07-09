#include <sstream>
#include <cstddef>
#include <disenum/SONAR.h>

namespace DIS {


hashMap<int,SONAR*> SONAR::enumerations;

SONAR SONAR::GENERIC(0, "Generic");


SONAR::SONAR(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SONAR* SONAR::findEnumeration(int aVal) {
  SONAR* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SONAR::getDescriptionForValue(int aVal) {
  SONAR* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SONAR SONAR::getEnumerationForValue(int aVal) throw(EnumException) {
  SONAR* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SONAR";
    throw EnumException("SONAR", aVal, ss.str());
  }
};

bool SONAR::enumerationForValueExists(int aVal) {
  SONAR* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SONAR::enumContainer SONAR::getEnumerations() {
  return (enumerations);
};

SONAR& SONAR::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

