#include <sstream>
#include <cstddef>
#include <disenum/LifeSupportSystems.h>

namespace DIS {


hashMap<int,LifeSupportSystems*> LifeSupportSystems::enumerations;

LifeSupportSystems LifeSupportSystems::AIR_SUPPLY(8000, "air supply");
LifeSupportSystems LifeSupportSystems::FILTERS(8010, "filters");
LifeSupportSystems LifeSupportSystems::WATER_SUPPLY(8020, "water supply");
LifeSupportSystems LifeSupportSystems::REFRIGERATION_SYSTEM(8030, "refrigeration system");
LifeSupportSystems LifeSupportSystems::CHEMICAL_BIOLOGICAL_AND_RADIOLOGICAL_PROTECTION(8040, "chemical, biological, and radiological protection");
LifeSupportSystems LifeSupportSystems::WATER_WASH_DOWN_SYSTEMS(8050, "water wash down systems");
LifeSupportSystems LifeSupportSystems::DECONTAMINATION_SYSTEMS(8060, "decontamination systems");
LifeSupportSystems LifeSupportSystems::MISSING_DESCRIPTION(8070, "Missing Description");


LifeSupportSystems::LifeSupportSystems(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

LifeSupportSystems* LifeSupportSystems::findEnumeration(int aVal) {
  LifeSupportSystems* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string LifeSupportSystems::getDescriptionForValue(int aVal) {
  LifeSupportSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

LifeSupportSystems LifeSupportSystems::getEnumerationForValue(int aVal) throw(EnumException) {
  LifeSupportSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration LifeSupportSystems";
    throw EnumException("LifeSupportSystems", aVal, ss.str());
  }
};

bool LifeSupportSystems::enumerationForValueExists(int aVal) {
  LifeSupportSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

LifeSupportSystems::enumContainer LifeSupportSystems::getEnumerations() {
  return (enumerations);
};

LifeSupportSystems& LifeSupportSystems::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

