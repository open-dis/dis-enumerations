#include <sstream>
#include <cstddef>
#include <disenum/TransmitState.h>

namespace DIS {


hashMap<int,TransmitState*> TransmitState::enumerations;

TransmitState TransmitState::OFF(0, "Off");
TransmitState TransmitState::ON_BUT_NOT_TRANSMITTING(1, "On but not transmitting");
TransmitState TransmitState::ON_AND_TRANSMITTING(2, "On and transmitting");


TransmitState::TransmitState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

TransmitState* TransmitState::findEnumeration(int aVal) {
  TransmitState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string TransmitState::getDescriptionForValue(int aVal) {
  TransmitState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

TransmitState TransmitState::getEnumerationForValue(int aVal) throw(EnumException) {
  TransmitState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration TransmitState";
    throw EnumException("TransmitState", aVal, ss.str());
  }
};

bool TransmitState::enumerationForValueExists(int aVal) {
  TransmitState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

TransmitState::enumContainer TransmitState::getEnumerations() {
  return (enumerations);
};

TransmitState& TransmitState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

