#include <sstream>
#include <cstddef>
#include <disenum/SynchronizationState.h>

namespace DIS {


hashMap<int,SynchronizationState*> SynchronizationState::enumerations;

SynchronizationState SynchronizationState::COARSE_SYNCHRONIZATION(1, "Coarse Synchronization");
SynchronizationState SynchronizationState::FINE_SYNCHRONIZATION(2, "Fine Synchronization");


SynchronizationState::SynchronizationState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SynchronizationState* SynchronizationState::findEnumeration(int aVal) {
  SynchronizationState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SynchronizationState::getDescriptionForValue(int aVal) {
  SynchronizationState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SynchronizationState SynchronizationState::getEnumerationForValue(int aVal) throw(EnumException) {
  SynchronizationState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SynchronizationState";
    throw EnumException("SynchronizationState", aVal, ss.str());
  }
};

bool SynchronizationState::enumerationForValueExists(int aVal) {
  SynchronizationState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SynchronizationState::enumContainer SynchronizationState::getEnumerations() {
  return (enumerations);
};

SynchronizationState& SynchronizationState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

