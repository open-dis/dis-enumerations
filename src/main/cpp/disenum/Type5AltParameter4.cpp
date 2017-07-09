#include <sstream>
#include <cstddef>
#include <disenum/Type5AltParameter4.h>

namespace DIS {


hashMap<int,Type5AltParameter4*> Type5AltParameter4::enumerations;

Type5AltParameter4 Type5AltParameter4::MISSING_DESCRIPTION(0, "Missing Description");


Type5AltParameter4::Type5AltParameter4(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type5AltParameter4* Type5AltParameter4::findEnumeration(int aVal) {
  Type5AltParameter4* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type5AltParameter4::getDescriptionForValue(int aVal) {
  Type5AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type5AltParameter4 Type5AltParameter4::getEnumerationForValue(int aVal) throw(EnumException) {
  Type5AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type5AltParameter4";
    throw EnumException("Type5AltParameter4", aVal, ss.str());
  }
};

bool Type5AltParameter4::enumerationForValueExists(int aVal) {
  Type5AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type5AltParameter4::enumContainer Type5AltParameter4::getEnumerations() {
  return (enumerations);
};

Type5AltParameter4& Type5AltParameter4::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

