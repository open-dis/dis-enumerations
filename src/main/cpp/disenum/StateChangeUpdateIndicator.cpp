#include <sstream>
#include <cstddef>
#include <disenum/StateChangeUpdateIndicator.h>

namespace DIS {


hashMap<int,StateChangeUpdateIndicator*> StateChangeUpdateIndicator::enumerations;

StateChangeUpdateIndicator StateChangeUpdateIndicator::STATE_UPDATE(0, "State Update");
StateChangeUpdateIndicator StateChangeUpdateIndicator::CHANGED_DATA_UPDATE(1, "Changed Data Update");


StateChangeUpdateIndicator::StateChangeUpdateIndicator(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

StateChangeUpdateIndicator* StateChangeUpdateIndicator::findEnumeration(int aVal) {
  StateChangeUpdateIndicator* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string StateChangeUpdateIndicator::getDescriptionForValue(int aVal) {
  StateChangeUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

StateChangeUpdateIndicator StateChangeUpdateIndicator::getEnumerationForValue(int aVal) throw(EnumException) {
  StateChangeUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration StateChangeUpdateIndicator";
    throw EnumException("StateChangeUpdateIndicator", aVal, ss.str());
  }
};

bool StateChangeUpdateIndicator::enumerationForValueExists(int aVal) {
  StateChangeUpdateIndicator* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

StateChangeUpdateIndicator::enumContainer StateChangeUpdateIndicator::getEnumerations() {
  return (enumerations);
};

StateChangeUpdateIndicator& StateChangeUpdateIndicator::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

