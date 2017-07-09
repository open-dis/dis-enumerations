#include <sstream>
#include <cstddef>
#include <disenum/EntityMarking.h>

namespace DIS {


hashMap<int,EntityMarking*> EntityMarking::enumerations;

EntityMarking EntityMarking::MISSING_DESCRIPTION(0, "Missing Description");
EntityMarking EntityMarking::ASCII(1, "ASCII");
EntityMarking EntityMarking::ARMY_MARKING_CCTT(2, "Army Marking (CCTT)");
EntityMarking EntityMarking::DIGIT_CHEVRON(3, "Digit Chevron");


EntityMarking::EntityMarking(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

EntityMarking* EntityMarking::findEnumeration(int aVal) {
  EntityMarking* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string EntityMarking::getDescriptionForValue(int aVal) {
  EntityMarking* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

EntityMarking EntityMarking::getEnumerationForValue(int aVal) throw(EnumException) {
  EntityMarking* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration EntityMarking";
    throw EnumException("EntityMarking", aVal, ss.str());
  }
};

bool EntityMarking::enumerationForValueExists(int aVal) {
  EntityMarking* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

EntityMarking::enumContainer EntityMarking::getEnumerations() {
  return (enumerations);
};

EntityMarking& EntityMarking::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

