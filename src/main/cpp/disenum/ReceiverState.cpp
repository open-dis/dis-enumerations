#include <sstream>
#include <cstddef>
#include <disenum/ReceiverState.h>

namespace DIS {


hashMap<int,ReceiverState*> ReceiverState::enumerations;

ReceiverState ReceiverState::OFF(0, "Off");
ReceiverState ReceiverState::ON_BUT_NOT_RECEIVING(1, "On but not receiving");
ReceiverState ReceiverState::ON_AND_RECEIVING(2, "On and receiving");


ReceiverState::ReceiverState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ReceiverState* ReceiverState::findEnumeration(int aVal) {
  ReceiverState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ReceiverState::getDescriptionForValue(int aVal) {
  ReceiverState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ReceiverState ReceiverState::getEnumerationForValue(int aVal) throw(EnumException) {
  ReceiverState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ReceiverState";
    throw EnumException("ReceiverState", aVal, ss.str());
  }
};

bool ReceiverState::enumerationForValueExists(int aVal) {
  ReceiverState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ReceiverState::enumContainer ReceiverState::getEnumerations() {
  return (enumerations);
};

ReceiverState& ReceiverState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

