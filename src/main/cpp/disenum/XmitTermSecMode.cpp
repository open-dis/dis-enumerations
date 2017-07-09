#include <sstream>
#include <cstddef>
#include <disenum/XmitTermSecMode.h>

namespace DIS {


hashMap<int,XmitTermSecMode*> XmitTermSecMode::enumerations;

XmitTermSecMode XmitTermSecMode::NONE(0, "None");
XmitTermSecMode XmitTermSecMode::NET_POSITION_REFERENCE(1, "Net Position Reference");
XmitTermSecMode XmitTermSecMode::PRIMARY_NAVIGATION_CONTROLLER(2, "Primary Navigation Controller");
XmitTermSecMode XmitTermSecMode::SECONDARY_NAVIGATION_CONTROLLER(3, "Secondary Navigation Controller");


XmitTermSecMode::XmitTermSecMode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

XmitTermSecMode* XmitTermSecMode::findEnumeration(int aVal) {
  XmitTermSecMode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string XmitTermSecMode::getDescriptionForValue(int aVal) {
  XmitTermSecMode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

XmitTermSecMode XmitTermSecMode::getEnumerationForValue(int aVal) throw(EnumException) {
  XmitTermSecMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration XmitTermSecMode";
    throw EnumException("XmitTermSecMode", aVal, ss.str());
  }
};

bool XmitTermSecMode::enumerationForValueExists(int aVal) {
  XmitTermSecMode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

XmitTermSecMode::enumContainer XmitTermSecMode::getEnumerations() {
  return (enumerations);
};

XmitTermSecMode& XmitTermSecMode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

