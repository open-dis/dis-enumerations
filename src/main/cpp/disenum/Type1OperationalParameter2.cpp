#include <sstream>
#include <cstddef>
#include <disenum/Type1OperationalParameter2.h>

namespace DIS {


hashMap<int,Type1OperationalParameter2*> Type1OperationalParameter2::enumerations;

Type1OperationalParameter2 Type1OperationalParameter2::OTHER(0, "Other");


Type1OperationalParameter2::Type1OperationalParameter2(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type1OperationalParameter2* Type1OperationalParameter2::findEnumeration(int aVal) {
  Type1OperationalParameter2* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type1OperationalParameter2::getDescriptionForValue(int aVal) {
  Type1OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type1OperationalParameter2 Type1OperationalParameter2::getEnumerationForValue(int aVal) throw(EnumException) {
  Type1OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type1OperationalParameter2";
    throw EnumException("Type1OperationalParameter2", aVal, ss.str());
  }
};

bool Type1OperationalParameter2::enumerationForValueExists(int aVal) {
  Type1OperationalParameter2* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type1OperationalParameter2::enumContainer Type1OperationalParameter2::getEnumerations() {
  return (enumerations);
};

Type1OperationalParameter2& Type1OperationalParameter2::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

