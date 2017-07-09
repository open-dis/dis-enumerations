#include <sstream>
#include <cstddef>
#include <disenum/ControlType.h>

namespace DIS {


hashMap<int,ControlType*> ControlType::enumerations;

ControlType ControlType::RESERVED(0, "Reserved");
ControlType ControlType::STATUS(1, "Status");
ControlType ControlType::REQUEST_ACKNOWLEDGE_REQUIRED(2, "Request - Acknowledge Required");
ControlType ControlType::REQUEST_NO_ACKNOWLEDGE(3, "Request - No Acknowledge");
ControlType ControlType::ACK_REQUEST_GRANTED(4, "Ack - Request Granted");
ControlType ControlType::NACK_REQUEST_DENIED(5, "Nack - Request Denied");
ControlType ControlType::MISSING_DESCRIPTION(6, "Missing Description");


ControlType::ControlType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ControlType* ControlType::findEnumeration(int aVal) {
  ControlType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ControlType::getDescriptionForValue(int aVal) {
  ControlType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ControlType ControlType::getEnumerationForValue(int aVal) throw(EnumException) {
  ControlType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ControlType";
    throw EnumException("ControlType", aVal, ss.str());
  }
};

bool ControlType::enumerationForValueExists(int aVal) {
  ControlType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ControlType::enumContainer ControlType::getEnumerations() {
  return (enumerations);
};

ControlType& ControlType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

