#include <sstream>
#include <cstddef>
#include <disenum/RequiredReliabilityService.h>

namespace DIS {


hashMap<int,RequiredReliabilityService*> RequiredReliabilityService::enumerations;

RequiredReliabilityService RequiredReliabilityService::ACKNOWLEDGED(0, "Acknowledged");
RequiredReliabilityService RequiredReliabilityService::UNACKNOWLEDGED(1, "Unacknowledged");


RequiredReliabilityService::RequiredReliabilityService(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RequiredReliabilityService* RequiredReliabilityService::findEnumeration(int aVal) {
  RequiredReliabilityService* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RequiredReliabilityService::getDescriptionForValue(int aVal) {
  RequiredReliabilityService* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RequiredReliabilityService RequiredReliabilityService::getEnumerationForValue(int aVal) throw(EnumException) {
  RequiredReliabilityService* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RequiredReliabilityService";
    throw EnumException("RequiredReliabilityService", aVal, ss.str());
  }
};

bool RequiredReliabilityService::enumerationForValueExists(int aVal) {
  RequiredReliabilityService* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RequiredReliabilityService::enumContainer RequiredReliabilityService::getEnumerations() {
  return (enumerations);
};

RequiredReliabilityService& RequiredReliabilityService::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

