#include <sstream>
#include <cstddef>
#include <disenum/Type1AltParameter4.h>

namespace DIS {


hashMap<int,Type1AltParameter4*> Type1AltParameter4::enumerations;

Type1AltParameter4 Type1AltParameter4::OTHER(0, "Other");
Type1AltParameter4 Type1AltParameter4::VALID(1, "Valid");
Type1AltParameter4 Type1AltParameter4::INVALID(2, "Invalid");
Type1AltParameter4 Type1AltParameter4::NO_RESPONSE(3, "No response");
Type1AltParameter4 Type1AltParameter4::MISSING_DESCRIPTION(4, "Missing Description");


Type1AltParameter4::Type1AltParameter4(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type1AltParameter4* Type1AltParameter4::findEnumeration(int aVal) {
  Type1AltParameter4* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type1AltParameter4::getDescriptionForValue(int aVal) {
  Type1AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type1AltParameter4 Type1AltParameter4::getEnumerationForValue(int aVal) throw(EnumException) {
  Type1AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type1AltParameter4";
    throw EnumException("Type1AltParameter4", aVal, ss.str());
  }
};

bool Type1AltParameter4::enumerationForValueExists(int aVal) {
  Type1AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type1AltParameter4::enumContainer Type1AltParameter4::getEnumerations() {
  return (enumerations);
};

Type1AltParameter4& Type1AltParameter4::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

