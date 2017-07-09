#include <sstream>
#include <cstddef>
#include <disenum/CodeName.h>

namespace DIS {


hashMap<int,CodeName*> CodeName::enumerations;

CodeName CodeName::OTHER(0, "Other");
CodeName CodeName::MISSING_DESCRIPTION(1, "Missing Description");


CodeName::CodeName(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CodeName* CodeName::findEnumeration(int aVal) {
  CodeName* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CodeName::getDescriptionForValue(int aVal) {
  CodeName* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CodeName CodeName::getEnumerationForValue(int aVal) throw(EnumException) {
  CodeName* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CodeName";
    throw EnumException("CodeName", aVal, ss.str());
  }
};

bool CodeName::enumerationForValueExists(int aVal) {
  CodeName* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CodeName::enumContainer CodeName::getEnumerations() {
  return (enumerations);
};

CodeName& CodeName::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

