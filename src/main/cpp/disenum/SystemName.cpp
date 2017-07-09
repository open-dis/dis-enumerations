#include <sstream>
#include <cstddef>
#include <disenum/SystemName.h>

namespace DIS {


hashMap<int,SystemName*> SystemName::enumerations;

SystemName SystemName::OTHER(0, "Other");
SystemName SystemName::MARK_X(1, "Mark X");
SystemName SystemName::MARK_XII(2, "Mark XII");
SystemName SystemName::ATCRBS(3, "ATCRBS");
SystemName SystemName::SOVIET(4, "Soviet");
SystemName SystemName::MODE_S(5, "Mode S");
SystemName SystemName::MARK_X_XII_ATCRBS(6, "Mark X/XII/ATCRBS");
SystemName SystemName::MARK_X_XII_ATCRBS_MODE_S(7, "Mark X/XII/ATCRBS/Mode S");
SystemName SystemName::ARI_5954(8, "ARI 5954");
SystemName SystemName::ARI_5983(9, "ARI 5983");


SystemName::SystemName(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SystemName* SystemName::findEnumeration(int aVal) {
  SystemName* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SystemName::getDescriptionForValue(int aVal) {
  SystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SystemName SystemName::getEnumerationForValue(int aVal) throw(EnumException) {
  SystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SystemName";
    throw EnumException("SystemName", aVal, ss.str());
  }
};

bool SystemName::enumerationForValueExists(int aVal) {
  SystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SystemName::enumContainer SystemName::getEnumerations() {
  return (enumerations);
};

SystemName& SystemName::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

