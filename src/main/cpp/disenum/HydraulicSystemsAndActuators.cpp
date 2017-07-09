#include <sstream>
#include <cstddef>
#include <disenum/HydraulicSystemsAndActuators.h>

namespace DIS {


hashMap<int,HydraulicSystemsAndActuators*> HydraulicSystemsAndActuators::enumerations;

HydraulicSystemsAndActuators HydraulicSystemsAndActuators::WATER_SUPPLY(9000, "water supply");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::COOLING_SYSTEM(9010, "cooling system");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::WINCHES(9020, "winches");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::CATAPULTS(9030, "catapults");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::CRANES(9040, "cranes");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::LAUNCHERS(9050, "launchers");
HydraulicSystemsAndActuators HydraulicSystemsAndActuators::MISSING_DESCRIPTION(9060, "Missing Description");


HydraulicSystemsAndActuators::HydraulicSystemsAndActuators(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

HydraulicSystemsAndActuators* HydraulicSystemsAndActuators::findEnumeration(int aVal) {
  HydraulicSystemsAndActuators* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string HydraulicSystemsAndActuators::getDescriptionForValue(int aVal) {
  HydraulicSystemsAndActuators* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

HydraulicSystemsAndActuators HydraulicSystemsAndActuators::getEnumerationForValue(int aVal) throw(EnumException) {
  HydraulicSystemsAndActuators* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration HydraulicSystemsAndActuators";
    throw EnumException("HydraulicSystemsAndActuators", aVal, ss.str());
  }
};

bool HydraulicSystemsAndActuators::enumerationForValueExists(int aVal) {
  HydraulicSystemsAndActuators* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

HydraulicSystemsAndActuators::enumContainer HydraulicSystemsAndActuators::getEnumerations() {
  return (enumerations);
};

HydraulicSystemsAndActuators& HydraulicSystemsAndActuators::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

