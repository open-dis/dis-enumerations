#include <sstream>
#include <cstddef>
#include <disenum/SystemType.h>

namespace DIS {


hashMap<int,SystemType*> SystemType::enumerations;

SystemType SystemType::OTHER(0, "Other");
SystemType SystemType::MARK_X_XII_ATCRBS_MODE_S_TRANSPONDER(1, "Mark X/XII/ATCRBS/Mode S Transponder");
SystemType SystemType::MARK_X_XII_ATCRBS_MODE_S_INTERROGATOR(2, "Mark X/XII/ATCRBS/Mode S Interrogator");
SystemType SystemType::SOVIET_TRANSPONDER(3, "Soviet Transponder");
SystemType SystemType::SOVIET_INTERROGATOR(4, "Soviet Interrogator");
SystemType SystemType::RRB_TRANSPONDER(5, "RRB Transponder");


SystemType::SystemType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SystemType* SystemType::findEnumeration(int aVal) {
  SystemType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SystemType::getDescriptionForValue(int aVal) {
  SystemType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SystemType SystemType::getEnumerationForValue(int aVal) throw(EnumException) {
  SystemType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SystemType";
    throw EnumException("SystemType", aVal, ss.str());
  }
};

bool SystemType::enumerationForValueExists(int aVal) {
  SystemType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SystemType::enumContainer SystemType::getEnumerations() {
  return (enumerations);
};

SystemType& SystemType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

