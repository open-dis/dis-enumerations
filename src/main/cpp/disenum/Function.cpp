#include <sstream>
#include <cstddef>
#include <disenum/Function.h>

namespace DIS {


hashMap<int,Function*> Function::enumerations;

Function Function::OTHER(0, "Other");
Function Function::PLATFORM_SEARCH_DETECT_TRACK(1, "Platform search/detect/track");
Function Function::NAVIGATION(2, "Navigation");
Function Function::MINE_HUNTING(3, "Mine hunting");
Function Function::WEAPON_SEARCH_DETECT_TRACK_DETECT(4, "Weapon search/detect/track/detect");


Function::Function(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Function* Function::findEnumeration(int aVal) {
  Function* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Function::getDescriptionForValue(int aVal) {
  Function* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Function Function::getEnumerationForValue(int aVal) throw(EnumException) {
  Function* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Function";
    throw EnumException("Function", aVal, ss.str());
  }
};

bool Function::enumerationForValueExists(int aVal) {
  Function* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Function::enumContainer Function::getEnumerations() {
  return (enumerations);
};

Function& Function::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

