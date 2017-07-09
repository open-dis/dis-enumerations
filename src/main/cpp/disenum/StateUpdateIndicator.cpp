#include <sstream>
#include <cstddef>
#include <disenum/StateUpdateIndicator.h>

namespace DIS {


hashMap<int,StateUpdateIndicator*> StateUpdateIndicator::enumerations;

StateUpdateIndicator StateUpdateIndicator::STATE_UPDATE(0, "State Update");
StateUpdateIndicator StateUpdateIndicator::CHANGED_DATA_UPDATE(1, "Changed Data Update");


StateUpdateIndicator::StateUpdateIndicator(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

StateUpdateIndicator* StateUpdateIndicator::findEnumeration(int aVal) {
  StateUpdateIndicator* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string StateUpdateIndicator::getDescriptionForValue(int aVal) {
  StateUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

StateUpdateIndicator StateUpdateIndicator::getEnumerationForValue(int aVal) throw(EnumException) {
  StateUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration StateUpdateIndicator";
    throw EnumException("StateUpdateIndicator", aVal, ss.str());
  }
};

bool StateUpdateIndicator::enumerationForValueExists(int aVal) {
  StateUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

StateUpdateIndicator::enumContainer StateUpdateIndicator::getEnumerations() {
  return (enumerations);
};

StateUpdateIndicator& StateUpdateIndicator::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

