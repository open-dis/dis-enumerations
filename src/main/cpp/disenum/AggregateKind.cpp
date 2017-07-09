#include <sstream>
#include <cstddef>
#include <disenum/AggregateKind.h>

namespace DIS {


hashMap<int,AggregateKind*> AggregateKind::enumerations;

AggregateKind AggregateKind::OTHER(0, "Other");
AggregateKind AggregateKind::MILITARY_HIERARCHY(1, "Military Hierarchy");
AggregateKind AggregateKind::COMMON_TYPE(2, "Common Type");
AggregateKind AggregateKind::COMMON_MISSION(3, "Common Mission");
AggregateKind AggregateKind::SIMILAR_CAPABILITIES(4, "Similar Capabilities");
AggregateKind AggregateKind::COMMON_LOCATION(5, "Common Location");


AggregateKind::AggregateKind(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AggregateKind* AggregateKind::findEnumeration(int aVal) {
  AggregateKind* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AggregateKind::getDescriptionForValue(int aVal) {
  AggregateKind* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AggregateKind AggregateKind::getEnumerationForValue(int aVal) throw(EnumException) {
  AggregateKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AggregateKind";
    throw EnumException("AggregateKind", aVal, ss.str());
  }
};

bool AggregateKind::enumerationForValueExists(int aVal) {
  AggregateKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AggregateKind::enumContainer AggregateKind::getEnumerations() {
  return (enumerations);
};

AggregateKind& AggregateKind::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

