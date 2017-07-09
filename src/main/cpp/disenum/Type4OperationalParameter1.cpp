#include <sstream>
#include <cstddef>
#include <disenum/Type4OperationalParameter1.h>

namespace DIS {


hashMap<int,Type4OperationalParameter1*> Type4OperationalParameter1::enumerations;

Type4OperationalParameter1 Type4OperationalParameter1::OTHER(0, "Other");


Type4OperationalParameter1::Type4OperationalParameter1(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type4OperationalParameter1* Type4OperationalParameter1::findEnumeration(int aVal) {
  Type4OperationalParameter1* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type4OperationalParameter1::getDescriptionForValue(int aVal) {
  Type4OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type4OperationalParameter1 Type4OperationalParameter1::getEnumerationForValue(int aVal) throw(EnumException) {
  Type4OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type4OperationalParameter1";
    throw EnumException("Type4OperationalParameter1", aVal, ss.str());
  }
};

bool Type4OperationalParameter1::enumerationForValueExists(int aVal) {
  Type4OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type4OperationalParameter1::enumContainer Type4OperationalParameter1::getEnumerations() {
  return (enumerations);
};

Type4OperationalParameter1& Type4OperationalParameter1::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

