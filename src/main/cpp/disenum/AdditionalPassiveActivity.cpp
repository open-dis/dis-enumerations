#include <sstream>
#include <cstddef>
#include <disenum/AdditionalPassiveActivity.h>

namespace DIS {


hashMap<int,AdditionalPassiveActivity*> AdditionalPassiveActivity::enumerations;

AdditionalPassiveActivity AdditionalPassiveActivity::OTHER(0, "Other");
AdditionalPassiveActivity AdditionalPassiveActivity::GRAHAMS_MKV_COFFEE_MAKER(1, "Graham's MKV Coffee Maker");
AdditionalPassiveActivity AdditionalPassiveActivity::RESERVED_FOR_CLASSIFIED_ENUMERATIONS(32769, "Reserved for classified enumerations");


AdditionalPassiveActivity::AdditionalPassiveActivity(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AdditionalPassiveActivity* AdditionalPassiveActivity::findEnumeration(int aVal) {
  AdditionalPassiveActivity* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AdditionalPassiveActivity::getDescriptionForValue(int aVal) {
  AdditionalPassiveActivity* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AdditionalPassiveActivity AdditionalPassiveActivity::getEnumerationForValue(int aVal) throw(EnumException) {
  AdditionalPassiveActivity* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AdditionalPassiveActivity";
    throw EnumException("AdditionalPassiveActivity", aVal, ss.str());
  }
};

bool AdditionalPassiveActivity::enumerationForValueExists(int aVal) {
  AdditionalPassiveActivity* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AdditionalPassiveActivity::enumContainer AdditionalPassiveActivity::getEnumerations() {
  return (enumerations);
};

AdditionalPassiveActivity& AdditionalPassiveActivity::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

