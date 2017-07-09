#include <sstream>
#include <cstddef>
#include <disenum/Type2AltParameter4.h>

namespace DIS {


hashMap<int,Type2AltParameter4*> Type2AltParameter4::enumerations;

Type2AltParameter4 Type2AltParameter4::OTHER(0, "Other");
Type2AltParameter4 Type2AltParameter4::VALID(1, "Valid");
Type2AltParameter4 Type2AltParameter4::INVALID(2, "Invalid");
Type2AltParameter4 Type2AltParameter4::NO_RESPONSE(3, "No response");
Type2AltParameter4 Type2AltParameter4::MISSING_DESCRIPTION(4, "Missing Description");


Type2AltParameter4::Type2AltParameter4(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Type2AltParameter4* Type2AltParameter4::findEnumeration(int aVal) {
  Type2AltParameter4* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Type2AltParameter4::getDescriptionForValue(int aVal) {
  Type2AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Type2AltParameter4 Type2AltParameter4::getEnumerationForValue(int aVal) throw(EnumException) {
  Type2AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Type2AltParameter4";
    throw EnumException("Type2AltParameter4", aVal, ss.str());
  }
};

bool Type2AltParameter4::enumerationForValueExists(int aVal) {
  Type2AltParameter4* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Type2AltParameter4::enumContainer Type2AltParameter4::getEnumerations() {
  return (enumerations);
};

Type2AltParameter4& Type2AltParameter4::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

