#include <sstream>
#include <cstddef>
#include <disenum/Type4OperationalParameter2.h>

namespace DIS {


hashMap<int,Type4OperationalParameter2*> Type4OperationalParameter2::enumerations;

Type4OperationalParameter2 Type4OperationalParameter2::OTHER(0, "Other");


Type4OperationalParameter2::Type4OperationalParameter2(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type4OperationalParameter2* Type4OperationalParameter2::findEnumeration(int aVal) {
  Type4OperationalParameter2* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type4OperationalParameter2::getDescriptionForValue(int aVal) {
  Type4OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type4OperationalParameter2 Type4OperationalParameter2::getEnumerationForValue(int aVal) throw(EnumException) {
  Type4OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type4OperationalParameter2";
    throw EnumException("Type4OperationalParameter2", aVal, ss.str());
  }
};

bool Type4OperationalParameter2::enumerationForValueExists(int aVal) {
  Type4OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type4OperationalParameter2::enumContainer Type4OperationalParameter2::getEnumerations() {
  return (enumerations);
};

Type4OperationalParameter2& Type4OperationalParameter2::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

