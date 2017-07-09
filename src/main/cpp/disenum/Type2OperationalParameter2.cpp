#include <sstream>
#include <cstddef>
#include <disenum/Type2OperationalParameter2.h>

namespace DIS {


hashMap<int,Type2OperationalParameter2*> Type2OperationalParameter2::enumerations;

Type2OperationalParameter2 Type2OperationalParameter2::OTHER(0, "Other");


Type2OperationalParameter2::Type2OperationalParameter2(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type2OperationalParameter2* Type2OperationalParameter2::findEnumeration(int aVal) {
  Type2OperationalParameter2* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type2OperationalParameter2::getDescriptionForValue(int aVal) {
  Type2OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type2OperationalParameter2 Type2OperationalParameter2::getEnumerationForValue(int aVal) throw(EnumException) {
  Type2OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type2OperationalParameter2";
    throw EnumException("Type2OperationalParameter2", aVal, ss.str());
  }
};

bool Type2OperationalParameter2::enumerationForValueExists(int aVal) {
  Type2OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type2OperationalParameter2::enumContainer Type2OperationalParameter2::getEnumerations() {
  return (enumerations);
};

Type2OperationalParameter2& Type2OperationalParameter2::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

