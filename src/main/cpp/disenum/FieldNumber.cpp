#include <sstream>
#include <cstddef>
#include <disenum/FieldNumber.h>

namespace DIS {


hashMap<int,FieldNumber*> FieldNumber::enumerations;

FieldNumber FieldNumber::MISSING_DESCRIPTION(0, "Missing Description");


FieldNumber::FieldNumber(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FieldNumber* FieldNumber::findEnumeration(int aVal) {
  FieldNumber* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FieldNumber::getDescriptionForValue(int aVal) {
  FieldNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FieldNumber FieldNumber::getEnumerationForValue(int aVal) throw(EnumException) {
  FieldNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FieldNumber";
    throw EnumException("FieldNumber", aVal, ss.str());
  }
};

bool FieldNumber::enumerationForValueExists(int aVal) {
  FieldNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FieldNumber::enumContainer FieldNumber::getEnumerations() {
  return (enumerations);
};

FieldNumber& FieldNumber::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

