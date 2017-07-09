#include <sstream>
#include <cstddef>
#include <disenum/DestLineState.h>

namespace DIS {


hashMap<int,DestLineState*> DestLineState::enumerations;

DestLineState DestLineState::NONE(0, "None");
DestLineState DestLineState::SET_LINE_STATE_TRANSMITTING(1, "Set Line State - Transmitting");
DestLineState DestLineState::SET_LINE_STATE_NOT_TRANSMITTING(2, "Set Line State - Not Transmitting");
DestLineState DestLineState::RETURN_TO_LOCAL_LINE_STATE_CONTROL(3, "Return to Local Line State Control");
DestLineState DestLineState::MISSING_DESCRIPTION(4, "Missing Description");


DestLineState::DestLineState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DestLineState* DestLineState::findEnumeration(int aVal) {
  DestLineState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DestLineState::getDescriptionForValue(int aVal) {
  DestLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DestLineState DestLineState::getEnumerationForValue(int aVal) throw(EnumException) {
  DestLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DestLineState";
    throw EnumException("DestLineState", aVal, ss.str());
  }
};

bool DestLineState::enumerationForValueExists(int aVal) {
  DestLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DestLineState::enumContainer DestLineState::getEnumerations() {
  return (enumerations);
};

DestLineState& DestLineState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

