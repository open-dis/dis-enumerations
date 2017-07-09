#include <sstream>
#include <cstddef>
#include <disenum/ExpendableSurfaceCategory.h>

namespace DIS {


hashMap<int,ExpendableSurfaceCategory*> ExpendableSurfaceCategory::enumerations;

ExpendableSurfaceCategory ExpendableSurfaceCategory::OTHER(0, "Other");
ExpendableSurfaceCategory ExpendableSurfaceCategory::FLARE(2, "Flare");
ExpendableSurfaceCategory ExpendableSurfaceCategory::ACTIVE_EMITTER(4, "Active emitter");
ExpendableSurfaceCategory ExpendableSurfaceCategory::PASSIVE_DECOY(5, "Passive decoy");


ExpendableSurfaceCategory::ExpendableSurfaceCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ExpendableSurfaceCategory* ExpendableSurfaceCategory::findEnumeration(int aVal) {
  ExpendableSurfaceCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ExpendableSurfaceCategory::getDescriptionForValue(int aVal) {
  ExpendableSurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ExpendableSurfaceCategory ExpendableSurfaceCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  ExpendableSurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ExpendableSurfaceCategory";
    throw EnumException("ExpendableSurfaceCategory", aVal, ss.str());
  }
};

bool ExpendableSurfaceCategory::enumerationForValueExists(int aVal) {
  ExpendableSurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ExpendableSurfaceCategory::enumContainer ExpendableSurfaceCategory::getEnumerations() {
  return (enumerations);
};

ExpendableSurfaceCategory& ExpendableSurfaceCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

