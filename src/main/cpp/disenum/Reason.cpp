#include <sstream>
#include <cstddef>
#include <disenum/Reason.h>

namespace DIS {


hashMap<int,Reason*> Reason::enumerations;

Reason Reason::OTHER(0, "Other");
Reason Reason::RECESS(1, "Recess");
Reason Reason::TERMINATION(2, "Termination");
Reason Reason::SYSTEM_FAILURE(3, "System Failure");
Reason Reason::SECURITY_VIOLATION(4, "Security Violation");
Reason Reason::ENTITY_RECONSTITUTION(5, "Entity Reconstitution");
Reason Reason::STOP_FOR_RESET(6, "Stop for reset");
Reason Reason::STOP_FOR_RESTART(7, "Stop for restart");
Reason Reason::ABORT_TRAINING_RETURN_TO_TACTICAL_OPERATIONS(8, "Abort Training Return to Tactical Operations");


Reason::Reason(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Reason* Reason::findEnumeration(int aVal) {
  Reason* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Reason::getDescriptionForValue(int aVal) {
  Reason* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Reason Reason::getEnumerationForValue(int aVal) throw(EnumException) {
  Reason* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Reason";
    throw EnumException("Reason", aVal, ss.str());
  }
};

bool Reason::enumerationForValueExists(int aVal) {
  Reason* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Reason::enumContainer Reason::getEnumerations() {
  return (enumerations);
};

Reason& Reason::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

