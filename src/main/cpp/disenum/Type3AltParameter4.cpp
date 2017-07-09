#include <sstream>
#include <cstddef>
#include <disenum/Type3AltParameter4.h>

namespace DIS {


hashMap<int,Type3AltParameter4*> Type3AltParameter4::enumerations;

Type3AltParameter4 Type3AltParameter4::MISSING_DESCRIPTION(0, "Missing Description");


Type3AltParameter4::Type3AltParameter4(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type3AltParameter4* Type3AltParameter4::findEnumeration(int aVal) {
  Type3AltParameter4* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type3AltParameter4::getDescriptionForValue(int aVal) {
  Type3AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type3AltParameter4 Type3AltParameter4::getEnumerationForValue(int aVal) throw(EnumException) {
  Type3AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type3AltParameter4";
    throw EnumException("Type3AltParameter4", aVal, ss.str());
  }
};

bool Type3AltParameter4::enumerationForValueExists(int aVal) {
  Type3AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type3AltParameter4::enumContainer Type3AltParameter4::getEnumerations() {
  return (enumerations);
};

Type3AltParameter4& Type3AltParameter4::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

