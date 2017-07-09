#include <sstream>
#include <cstddef>
#include <disenum/SystemMode.h>

namespace DIS {


hashMap<int,SystemMode*> SystemMode::enumerations;

SystemMode SystemMode::OTHER(0, "Other");


SystemMode::SystemMode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SystemMode* SystemMode::findEnumeration(int aVal) {
  SystemMode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SystemMode::getDescriptionForValue(int aVal) {
  SystemMode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SystemMode SystemMode::getEnumerationForValue(int aVal) throw(EnumException) {
  SystemMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SystemMode";
    throw EnumException("SystemMode", aVal, ss.str());
  }
};

bool SystemMode::enumerationForValueExists(int aVal) {
  SystemMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SystemMode::enumContainer SystemMode::getEnumerations() {
  return (enumerations);
};

SystemMode& SystemMode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

