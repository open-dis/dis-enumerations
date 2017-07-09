#include <sstream>
#include <cstddef>
#include <disenum/ProtocolVersion.h>

namespace DIS {


hashMap<int,ProtocolVersion*> ProtocolVersion::enumerations;

ProtocolVersion ProtocolVersion::OTHER(0, "Other");
ProtocolVersion ProtocolVersion::DIS_PDU_VERSION_10_MAY_92(1, "DIS PDU version 1.0 (May 92)");
ProtocolVersion ProtocolVersion::IEEE_1278_1993(2, "IEEE 1278-1993");
ProtocolVersion ProtocolVersion::DIS_PDU_VERSION_20_THIRD_DRAFT_MAY_93(3, "DIS PDU version 2.0 - third draft (May 93)");
ProtocolVersion ProtocolVersion::DIS_PDU_VERSION_20_FOURTH_DRAFT_REVISED_MARCH_16_1994(4, "DIS PDU version 2.0 - fourth draft (revised) March 16, 1994");
ProtocolVersion ProtocolVersion::IEEE_12781_1995(5, "IEEE 1278.1-1995");
ProtocolVersion ProtocolVersion::IEEE_12781A_1998(6, "IEEE 1278.1A-1998");


ProtocolVersion::ProtocolVersion(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ProtocolVersion* ProtocolVersion::findEnumeration(int aVal) {
  ProtocolVersion* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ProtocolVersion::getDescriptionForValue(int aVal) {
  ProtocolVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ProtocolVersion ProtocolVersion::getEnumerationForValue(int aVal) throw(EnumException) {
  ProtocolVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ProtocolVersion";
    throw EnumException("ProtocolVersion", aVal, ss.str());
  }
};

bool ProtocolVersion::enumerationForValueExists(int aVal) {
  ProtocolVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ProtocolVersion::enumContainer ProtocolVersion::getEnumerations() {
  return (enumerations);
};

ProtocolVersion& ProtocolVersion::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

