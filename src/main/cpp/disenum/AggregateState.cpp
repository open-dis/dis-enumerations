#include <sstream>
#include <cstddef>
#include <disenum/AggregateState.h>

namespace DIS {


hashMap<int,AggregateState*> AggregateState::enumerations;

AggregateState AggregateState::OTHER(0, "Other");
AggregateState AggregateState::AGGREGATED(1, "Aggregated");
AggregateState AggregateState::DISAGGREGATED(2, "Disaggregated");
AggregateState AggregateState::FULLY_DISAGGREGATED(3, "Fully disaggregated");
AggregateState AggregateState::PSEUDO_DISAGGREGATED(4, "Pseudo-disaggregated");
AggregateState AggregateState::PARTIALLY_DISAGGREGATED(5, "Partially-disaggregated");


AggregateState::AggregateState(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AggregateState* AggregateState::findEnumeration(int aVal) {
  AggregateState* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AggregateState::getDescriptionForValue(int aVal) {
  AggregateState* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AggregateState AggregateState::getEnumerationForValue(int aVal) throw(EnumException) {
  AggregateState* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AggregateState";
    throw EnumException("AggregateState", aVal, ss.str());
  }
};

bool AggregateState::enumerationForValueExists(int aVal) {
  AggregateState* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AggregateState::enumContainer AggregateState::getEnumerations() {
  return (enumerations);
};

AggregateState& AggregateState::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

