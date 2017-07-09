#include <sstream>
#include <cstddef>
#include <disenum/RepairResponsePDU.h>

namespace DIS {


hashMap<int,RepairResponsePDU*> RepairResponsePDU::enumerations;

RepairResponsePDU RepairResponsePDU::OTHER(0, "other");
RepairResponsePDU RepairResponsePDU::REPAIR_ENDED(1, "repair ended");
RepairResponsePDU RepairResponsePDU::INVALID_REPAIR(2, "invalid repair");
RepairResponsePDU RepairResponsePDU::REPAIR_INTERRUPTED(3, "repair interrupted");
RepairResponsePDU RepairResponsePDU::SERVICE_CANCELED_BY_THE_SUPPLIER(4, "service canceled by the supplier");


RepairResponsePDU::RepairResponsePDU(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RepairResponsePDU* RepairResponsePDU::findEnumeration(int aVal) {
  RepairResponsePDU* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RepairResponsePDU::getDescriptionForValue(int aVal) {
  RepairResponsePDU* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RepairResponsePDU RepairResponsePDU::getEnumerationForValue(int aVal) throw(EnumException) {
  RepairResponsePDU* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RepairResponsePDU";
    throw EnumException("RepairResponsePDU", aVal, ss.str());
  }
};

bool RepairResponsePDU::enumerationForValueExists(int aVal) {
  RepairResponsePDU* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RepairResponsePDU::enumContainer RepairResponsePDU::getEnumerations() {
  return (enumerations);
};

RepairResponsePDU& RepairResponsePDU::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

