#include <sstream>
#include <cstddef>
#include <disenum/Specific.h>

namespace DIS {


hashMap<int,Specific*> Specific::enumerations;

Specific Specific::NO_HEADQUARTERS(0, "No headquarters");
Specific Specific::YES_AGGREGATE_UNIT_CONTAINS_A_HEADQUARTERS(1, "Yes aggregate unit contains a headquarters");


Specific::Specific(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Specific* Specific::findEnumeration(int aVal) {
  Specific* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Specific::getDescriptionForValue(int aVal) {
  Specific* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Specific Specific::getEnumerationForValue(int aVal) throw(EnumException) {
  Specific* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Specific";
    throw EnumException("Specific", aVal, ss.str());
  }
};

bool Specific::enumerationForValueExists(int aVal) {
  Specific* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Specific::enumContainer Specific::getEnumerations() {
  return (enumerations);
};

Specific& Specific::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

