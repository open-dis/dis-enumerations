#include <sstream>
#include <cstddef>
#include <disenum/Type1OperationalParameter1.h>

namespace DIS {


hashMap<int,Type1OperationalParameter1*> Type1OperationalParameter1::enumerations;

Type1OperationalParameter1 Type1OperationalParameter1::OTHER(0, "Other");


Type1OperationalParameter1::Type1OperationalParameter1(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type1OperationalParameter1* Type1OperationalParameter1::findEnumeration(int aVal) {
  Type1OperationalParameter1* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type1OperationalParameter1::getDescriptionForValue(int aVal) {
  Type1OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type1OperationalParameter1 Type1OperationalParameter1::getEnumerationForValue(int aVal) throw(EnumException) {
  Type1OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type1OperationalParameter1";
    throw EnumException("Type1OperationalParameter1", aVal, ss.str());
  }
};

bool Type1OperationalParameter1::enumerationForValueExists(int aVal) {
  Type1OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type1OperationalParameter1::enumContainer Type1OperationalParameter1::getEnumerations() {
  return (enumerations);
};

Type1OperationalParameter1& Type1OperationalParameter1::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

