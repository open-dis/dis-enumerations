#include <sstream>
#include <cstddef>
#include <disenum/XmitTermPriMode.h>

namespace DIS {


hashMap<int,XmitTermPriMode*> XmitTermPriMode::enumerations;

XmitTermPriMode XmitTermPriMode::NTR(1, "NTR");
XmitTermPriMode XmitTermPriMode::JTIDS_UNIT_PARTICIPANT(2, "JTIDS Unit Participant");


XmitTermPriMode::XmitTermPriMode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

XmitTermPriMode* XmitTermPriMode::findEnumeration(int aVal) {
  XmitTermPriMode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string XmitTermPriMode::getDescriptionForValue(int aVal) {
  XmitTermPriMode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

XmitTermPriMode XmitTermPriMode::getEnumerationForValue(int aVal) throw(EnumException) {
  XmitTermPriMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration XmitTermPriMode";
    throw EnumException("XmitTermPriMode", aVal, ss.str());
  }
};

bool XmitTermPriMode::enumerationForValueExists(int aVal) {
  XmitTermPriMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

XmitTermPriMode::enumContainer XmitTermPriMode::getEnumerations() {
  return (enumerations);
};

XmitTermPriMode& XmitTermPriMode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

