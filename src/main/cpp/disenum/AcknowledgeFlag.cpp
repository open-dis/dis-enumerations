#include <sstream>
#include <cstddef>
#include <disenum/AcknowledgeFlag.h>

namespace DIS {


hashMap<int,AcknowledgeFlag*> AcknowledgeFlag::enumerations;

AcknowledgeFlag AcknowledgeFlag::CREATE_ENTITY(1, "Create Entity");
AcknowledgeFlag AcknowledgeFlag::REMOVE_ENTITY(2, "Remove Entity");
AcknowledgeFlag AcknowledgeFlag::START_RESUME(3, "Start/Resume");
AcknowledgeFlag AcknowledgeFlag::STOP_FREEZE(4, "Stop/Freeze");
AcknowledgeFlag AcknowledgeFlag::TRANSFER_CONTROL_REQUEST(5, "Transfer Control Request");


AcknowledgeFlag::AcknowledgeFlag(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AcknowledgeFlag* AcknowledgeFlag::findEnumeration(int aVal) {
  AcknowledgeFlag* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AcknowledgeFlag::getDescriptionForValue(int aVal) {
  AcknowledgeFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AcknowledgeFlag AcknowledgeFlag::getEnumerationForValue(int aVal) throw(EnumException) {
  AcknowledgeFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AcknowledgeFlag";
    throw EnumException("AcknowledgeFlag", aVal, ss.str());
  }
};

bool AcknowledgeFlag::enumerationForValueExists(int aVal) {
  AcknowledgeFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AcknowledgeFlag::enumContainer AcknowledgeFlag::getEnumerations() {
  return (enumerations);
};

AcknowledgeFlag& AcknowledgeFlag::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

