#include <sstream>
#include <cstddef>
#include <disenum/Type5OperationalParameter2.h>

namespace DIS {


hashMap<int,Type5OperationalParameter2*> Type5OperationalParameter2::enumerations;

Type5OperationalParameter2 Type5OperationalParameter2::OTHER(0, "Other");


Type5OperationalParameter2::Type5OperationalParameter2(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type5OperationalParameter2* Type5OperationalParameter2::findEnumeration(int aVal) {
  Type5OperationalParameter2* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type5OperationalParameter2::getDescriptionForValue(int aVal) {
  Type5OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type5OperationalParameter2 Type5OperationalParameter2::getEnumerationForValue(int aVal) throw(EnumException) {
  Type5OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type5OperationalParameter2";
    throw EnumException("Type5OperationalParameter2", aVal, ss.str());
  }
};

bool Type5OperationalParameter2::enumerationForValueExists(int aVal) {
  Type5OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type5OperationalParameter2::enumContainer Type5OperationalParameter2::getEnumerations() {
  return (enumerations);
};

Type5OperationalParameter2& Type5OperationalParameter2::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

