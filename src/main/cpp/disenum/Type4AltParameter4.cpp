#include <sstream>
#include <cstddef>
#include <disenum/Type4AltParameter4.h>

namespace DIS {


hashMap<int,Type4AltParameter4*> Type4AltParameter4::enumerations;

Type4AltParameter4 Type4AltParameter4::MISSING_DESCRIPTION(0, "Missing Description");


Type4AltParameter4::Type4AltParameter4(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type4AltParameter4* Type4AltParameter4::findEnumeration(int aVal) {
  Type4AltParameter4* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type4AltParameter4::getDescriptionForValue(int aVal) {
  Type4AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type4AltParameter4 Type4AltParameter4::getEnumerationForValue(int aVal) throw(EnumException) {
  Type4AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type4AltParameter4";
    throw EnumException("Type4AltParameter4", aVal, ss.str());
  }
};

bool Type4AltParameter4::enumerationForValueExists(int aVal) {
  Type4AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type4AltParameter4::enumContainer Type4AltParameter4::getEnumerations() {
  return (enumerations);
};

Type4AltParameter4& Type4AltParameter4::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

