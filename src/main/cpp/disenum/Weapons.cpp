#include <sstream>
#include <cstddef>
#include <disenum/Weapons.h>

namespace DIS {


hashMap<int,Weapons*> Weapons::enumerations;

Weapons Weapons::GUN_ELEVATION_DRIVE(2000, "gun elevation drive");
Weapons Weapons::GUN_STABILIZATION_SYSTEM(2010, "gun stabilization system");
Weapons Weapons::GUNNERS_PRIMARY_SIGHT_GPS(2020, "gunner's primary sight (GPS)");
Weapons Weapons::COMMANDERS_EXTENSION_TO_THE_GPS(2030, "commander's extension to the GPS");
Weapons Weapons::LOADING_MECHANISM(2040, "loading mechanism");
Weapons Weapons::GUNNERS_AUXILIARY_SIGHT(2050, "gunner's auxiliary sight");
Weapons Weapons::GUNNERS_CONTROL_PANEL(2060, "gunner's control panel");
Weapons Weapons::GUNNERS_CONTROL_ASSEMBLY_HANDLES(2070, "gunner's control assembly handle(s)");
Weapons Weapons::COMMANDERS_CONTROL_HANDLES_ASSEMBLY(2090, "commander's control handles/assembly");
Weapons Weapons::COMMANDERS_WEAPON_STATION(2100, "commander's weapon station");
Weapons Weapons::COMMANDERS_INDEPENDENT_THERMAL_VIEWER_CITV(2110, "commander's independent thermal viewer (CITV)");
Weapons Weapons::GENERAL_WEAPONS(2120, "general weapons");
Weapons Weapons::MISSING_DESCRIPTION(2121, "Missing Description");


Weapons::Weapons(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Weapons* Weapons::findEnumeration(int aVal) {
  Weapons* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Weapons::getDescriptionForValue(int aVal) {
  Weapons* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Weapons Weapons::getEnumerationForValue(int aVal) throw(EnumException) {
  Weapons* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Weapons";
    throw EnumException("Weapons", aVal, ss.str());
  }
};

bool Weapons::enumerationForValueExists(int aVal) {
  Weapons* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Weapons::enumContainer Weapons::getEnumerations() {
  return (enumerations);
};

Weapons& Weapons::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

