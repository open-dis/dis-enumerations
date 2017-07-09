#include <sstream>
#include <cstddef>
#include <disenum/XmitLineState.h>

namespace DIS {


hashMap<int,XmitLineState*> XmitLineState::enumerations;

XmitLineState XmitLineState::TRANSMIT_LINE_STATE_NOT_APPLICABLE(0, "Transmit Line State not applicable");
XmitLineState XmitLineState::NOT_TRANSMITTING(1, "Not Transmitting");
XmitLineState XmitLineState::TRANSMITTING(2, "Transmitting");
XmitLineState XmitLineState::MISSING_DESCRIPTION(3, "Missing Description");


XmitLineState::XmitLineState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

XmitLineState* XmitLineState::findEnumeration(int aVal) {
  XmitLineState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string XmitLineState::getDescriptionForValue(int aVal) {
  XmitLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

XmitLineState XmitLineState::getEnumerationForValue(int aVal) throw(EnumException) {
  XmitLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration XmitLineState";
    throw EnumException("XmitLineState", aVal, ss.str());
  }
};

bool XmitLineState::enumerationForValueExists(int aVal) {
  XmitLineState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

XmitLineState::enumContainer XmitLineState::getEnumerations() {
  return (enumerations);
};

XmitLineState& XmitLineState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

