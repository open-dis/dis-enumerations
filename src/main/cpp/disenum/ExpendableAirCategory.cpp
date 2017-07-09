#include <sstream>
#include <cstddef>
#include <disenum/ExpendableAirCategory.h>

namespace DIS {


hashMap<int,ExpendableAirCategory*> ExpendableAirCategory::enumerations;

ExpendableAirCategory ExpendableAirCategory::OTHER(0, "Other");
ExpendableAirCategory ExpendableAirCategory::CHAFF(1, "Chaff");
ExpendableAirCategory ExpendableAirCategory::FLARE(2, "Flare");
ExpendableAirCategory ExpendableAirCategory::COMBINED_CHAFF_AND_FLARE(3, "Combined chaff and flare");
ExpendableAirCategory ExpendableAirCategory::ACTIVE_EMITTER(4, "Active emitter");
ExpendableAirCategory ExpendableAirCategory::PASSIVE_DECOY(5, "Passive decoy");
ExpendableAirCategory ExpendableAirCategory::WINGED_DECOY(6, "Winged decoy");


ExpendableAirCategory::ExpendableAirCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ExpendableAirCategory* ExpendableAirCategory::findEnumeration(int aVal) {
  ExpendableAirCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ExpendableAirCategory::getDescriptionForValue(int aVal) {
  ExpendableAirCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ExpendableAirCategory ExpendableAirCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  ExpendableAirCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ExpendableAirCategory";
    throw EnumException("ExpendableAirCategory", aVal, ss.str());
  }
};

bool ExpendableAirCategory::enumerationForValueExists(int aVal) {
  ExpendableAirCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ExpendableAirCategory::enumContainer ExpendableAirCategory::getEnumerations() {
  return (enumerations);
};

ExpendableAirCategory& ExpendableAirCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

