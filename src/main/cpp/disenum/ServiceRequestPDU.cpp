#include <sstream>
#include <cstddef>
#include <disenum/ServiceRequestPDU.h>

namespace DIS {


hashMap<int,ServiceRequestPDU*> ServiceRequestPDU::enumerations;

ServiceRequestPDU ServiceRequestPDU::OTHER(0, "Other");
ServiceRequestPDU ServiceRequestPDU::RESUPPLY(1, "Resupply");
ServiceRequestPDU ServiceRequestPDU::REPAIR(2, "Repair");


ServiceRequestPDU::ServiceRequestPDU(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ServiceRequestPDU* ServiceRequestPDU::findEnumeration(int aVal) {
  ServiceRequestPDU* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ServiceRequestPDU::getDescriptionForValue(int aVal) {
  ServiceRequestPDU* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ServiceRequestPDU ServiceRequestPDU::getEnumerationForValue(int aVal) throw(EnumException) {
  ServiceRequestPDU* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ServiceRequestPDU";
    throw EnumException("ServiceRequestPDU", aVal, ss.str());
  }
};

bool ServiceRequestPDU::enumerationForValueExists(int aVal) {
  ServiceRequestPDU* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ServiceRequestPDU::enumContainer ServiceRequestPDU::getEnumerations() {
  return (enumerations);
};

ServiceRequestPDU& ServiceRequestPDU::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

