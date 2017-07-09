#include <sstream>
#include <cstddef>
#include <disenum/ClearChannel.h>

namespace DIS {


hashMap<int,ClearChannel*> ClearChannel::enumerations;

ClearChannel ClearChannel::NOT_CLEAR_CHANNEL(0, "Not clear channel");
ClearChannel ClearChannel::CLEAR_CHANNEL(1, "Clear channel");


ClearChannel::ClearChannel(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ClearChannel* ClearChannel::findEnumeration(int aVal) {
  ClearChannel* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ClearChannel::getDescriptionForValue(int aVal) {
  ClearChannel* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ClearChannel ClearChannel::getEnumerationForValue(int aVal) throw(EnumException) {
  ClearChannel* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ClearChannel";
    throw EnumException("ClearChannel", aVal, ss.str());
  }
};

bool ClearChannel::enumerationForValueExists(int aVal) {
  ClearChannel* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ClearChannel::enumContainer ClearChannel::getEnumerations() {
  return (enumerations);
};

ClearChannel& ClearChannel::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

