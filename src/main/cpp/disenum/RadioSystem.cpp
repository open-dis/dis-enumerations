#include <sstream>
#include <cstddef>
#include <disenum/RadioSystem.h>

namespace DIS {


hashMap<int,RadioSystem*> RadioSystem::enumerations;

RadioSystem RadioSystem::OTHER(0, "Other");
RadioSystem RadioSystem::GENERIC(1, "Generic");
RadioSystem RadioSystem::HQ(2, "HQ");
RadioSystem RadioSystem::HQII(3, "HQII");
RadioSystem RadioSystem::HQIIA(4, "HQIIA");
RadioSystem RadioSystem::SINCGARS(5, "SINCGARS");
RadioSystem RadioSystem::CCTT_SINCGARS(6, "CCTT SINCGARS");
RadioSystem RadioSystem::EPLRS_ENHANCED_POSITION_LOCATION_REPORTING_SYSTEM(7, "EPLRS (Enhanced Position Location Reporting System)");
RadioSystem RadioSystem::JTIDS_MIDS(8, "JTIDS/MIDS");


RadioSystem::RadioSystem(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RadioSystem* RadioSystem::findEnumeration(int aVal) {
  RadioSystem* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RadioSystem::getDescriptionForValue(int aVal) {
  RadioSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RadioSystem RadioSystem::getEnumerationForValue(int aVal) throw(EnumException) {
  RadioSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RadioSystem";
    throw EnumException("RadioSystem", aVal, ss.str());
  }
};

bool RadioSystem::enumerationForValueExists(int aVal) {
  RadioSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RadioSystem::enumContainer RadioSystem::getEnumerations() {
  return (enumerations);
};

RadioSystem& RadioSystem::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

