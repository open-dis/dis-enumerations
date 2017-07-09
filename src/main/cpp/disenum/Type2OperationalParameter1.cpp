#include <sstream>
#include <cstddef>
#include <disenum/Type2OperationalParameter1.h>

namespace DIS {


hashMap<int,Type2OperationalParameter1*> Type2OperationalParameter1::enumerations;

Type2OperationalParameter1 Type2OperationalParameter1::OTHER(0, "Other");


Type2OperationalParameter1::Type2OperationalParameter1(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type2OperationalParameter1* Type2OperationalParameter1::findEnumeration(int aVal) {
  Type2OperationalParameter1* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type2OperationalParameter1::getDescriptionForValue(int aVal) {
  Type2OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type2OperationalParameter1 Type2OperationalParameter1::getEnumerationForValue(int aVal) throw(EnumException) {
  Type2OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type2OperationalParameter1";
    throw EnumException("Type2OperationalParameter1", aVal, ss.str());
  }
};

bool Type2OperationalParameter1::enumerationForValueExists(int aVal) {
  Type2OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type2OperationalParameter1::enumContainer Type2OperationalParameter1::getEnumerations() {
  return (enumerations);
};

Type2OperationalParameter1& Type2OperationalParameter1::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

