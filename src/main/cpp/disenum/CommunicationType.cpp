#include <sstream>
#include <cstddef>
#include <disenum/CommunicationType.h>

namespace DIS {


hashMap<int,CommunicationType*> CommunicationType::enumerations;

CommunicationType CommunicationType::RESERVED(0, "Reserved");
CommunicationType CommunicationType::CONNECTION_FDX(1, "Connection FDX");
CommunicationType CommunicationType::CONNECTION_HDX_DESTINATION_IS_RECEIVE_ONLY(2, "Connection HDX - Destination is Receive Only");
CommunicationType CommunicationType::CONNECTION_HDX_DESTINATION_IS_TRANSMIT_ONLY(3, "Connection HDX - Destination is Transmit Only");
CommunicationType CommunicationType::CONNECTION_HDX(4, "Connection HDX");
CommunicationType CommunicationType::MISSING_DESCRIPTION(5, "Missing Description");


CommunicationType::CommunicationType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CommunicationType* CommunicationType::findEnumeration(int aVal) {
  CommunicationType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CommunicationType::getDescriptionForValue(int aVal) {
  CommunicationType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CommunicationType CommunicationType::getEnumerationForValue(int aVal) throw(EnumException) {
  CommunicationType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CommunicationType";
    throw EnumException("CommunicationType", aVal, ss.str());
  }
};

bool CommunicationType::enumerationForValueExists(int aVal) {
  CommunicationType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CommunicationType::enumContainer CommunicationType::getEnumerations() {
  return (enumerations);
};

CommunicationType& CommunicationType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

