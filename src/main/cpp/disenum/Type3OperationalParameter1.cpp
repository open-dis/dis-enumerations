#include <sstream>
#include <cstddef>
#include <disenum/Type3OperationalParameter1.h>

namespace DIS {


hashMap<int,Type3OperationalParameter1*> Type3OperationalParameter1::enumerations;

Type3OperationalParameter1 Type3OperationalParameter1::OTHER(0, "Other");


Type3OperationalParameter1::Type3OperationalParameter1(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type3OperationalParameter1* Type3OperationalParameter1::findEnumeration(int aVal) {
  Type3OperationalParameter1* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type3OperationalParameter1::getDescriptionForValue(int aVal) {
  Type3OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type3OperationalParameter1 Type3OperationalParameter1::getEnumerationForValue(int aVal) throw(EnumException) {
  Type3OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type3OperationalParameter1";
    throw EnumException("Type3OperationalParameter1", aVal, ss.str());
  }
};

bool Type3OperationalParameter1::enumerationForValueExists(int aVal) {
  Type3OperationalParameter1* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type3OperationalParameter1::enumContainer Type3OperationalParameter1::getEnumerations() {
  return (enumerations);
};

Type3OperationalParameter1& Type3OperationalParameter1::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

