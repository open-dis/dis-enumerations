#include <sstream>
#include <cstddef>
#include <disenum/ExpendableSubsurfaceCategory.h>

namespace DIS {


hashMap<int,ExpendableSubsurfaceCategory*> ExpendableSubsurfaceCategory::enumerations;

ExpendableSubsurfaceCategory ExpendableSubsurfaceCategory::OTHER(0, "Other");
ExpendableSubsurfaceCategory ExpendableSubsurfaceCategory::ACTIVE_EMITTER(4, "Active emitter");
ExpendableSubsurfaceCategory ExpendableSubsurfaceCategory::PASSIVE_DECOY(5, "Passive decoy");


ExpendableSubsurfaceCategory::ExpendableSubsurfaceCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ExpendableSubsurfaceCategory* ExpendableSubsurfaceCategory::findEnumeration(int aVal) {
  ExpendableSubsurfaceCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ExpendableSubsurfaceCategory::getDescriptionForValue(int aVal) {
  ExpendableSubsurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ExpendableSubsurfaceCategory ExpendableSubsurfaceCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  ExpendableSubsurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ExpendableSubsurfaceCategory";
    throw EnumException("ExpendableSubsurfaceCategory", aVal, ss.str());
  }
};

bool ExpendableSubsurfaceCategory::enumerationForValueExists(int aVal) {
  ExpendableSubsurfaceCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ExpendableSubsurfaceCategory::enumContainer ExpendableSubsurfaceCategory::getEnumerations() {
  return (enumerations);
};

ExpendableSubsurfaceCategory& ExpendableSubsurfaceCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

