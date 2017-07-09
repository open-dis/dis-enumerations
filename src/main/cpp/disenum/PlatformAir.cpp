#include <sstream>
#include <cstddef>
#include <disenum/PlatformAir.h>

namespace DIS {


hashMap<int,PlatformAir*> PlatformAir::enumerations;

PlatformAir PlatformAir::OTHER(0, "Other");
PlatformAir PlatformAir::FIGHTER_AIR_DEFENSE(1, "Fighter/Air Defense");
PlatformAir PlatformAir::ATTACK_STRIKE(2, "Attack/Strike");
PlatformAir PlatformAir::BOMBER(3, "Bomber");
PlatformAir PlatformAir::CARGO_TANKER(4, "Cargo/Tanker");
PlatformAir PlatformAir::ASW_PATROL_OBSERVATION(5, "ASW/Patrol/Observation");
PlatformAir PlatformAir::ELECTRONIC_WARFARE_EW(6, "Electronic Warfare (EW)");
PlatformAir PlatformAir::RECONNAISSANCE(7, "Reconnaissance");
PlatformAir PlatformAir::SURVEILLANCE_C2_AIRBORNE_EARLY_WARNING(8, "Surveillance/C2 (Airborne Early Warning)");
PlatformAir PlatformAir::ATTACK_HELICOPTER(20, "Attack Helicopter");
PlatformAir PlatformAir::UTILITY_HELICOPTER(21, "Utility Helicopter");
PlatformAir PlatformAir::ANTISUBMARINE_WARFARE_PATROL_HELICOPTER(22, "Antisubmarine Warfare/Patrol Helicopter");
PlatformAir PlatformAir::CARGO_HELICOPTER(23, "Cargo Helicopter");
PlatformAir PlatformAir::OBSERVATION_HELICOPTER(24, "Observation Helicopter");
PlatformAir PlatformAir::SPECIAL_OPERATIONS_HELICOPTER(25, "Special Operations Helicopter");
PlatformAir PlatformAir::TRAINER(40, "Trainer");
PlatformAir PlatformAir::UNMANNED(50, "Unmanned");
PlatformAir PlatformAir::NON_COMBATANT_COMMERCIAL_AIRCRAFT(57, "Non-Combatant Commercial Aircraft");


PlatformAir::PlatformAir(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatformAir* PlatformAir::findEnumeration(int aVal) {
  PlatformAir* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatformAir::getDescriptionForValue(int aVal) {
  PlatformAir* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatformAir PlatformAir::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatformAir* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatformAir";
    throw EnumException("PlatformAir", aVal, ss.str());
  }
};

bool PlatformAir::enumerationForValueExists(int aVal) {
  PlatformAir* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatformAir::enumContainer PlatformAir::getEnumerations() {
  return (enumerations);
};

PlatformAir& PlatformAir::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

