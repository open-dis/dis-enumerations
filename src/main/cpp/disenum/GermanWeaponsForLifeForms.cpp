#include <sstream>
#include <cstddef>
#include <disenum/GermanWeaponsForLifeForms.h>

namespace DIS {


hashMap<int,GermanWeaponsForLifeForms*> GermanWeaponsForLifeForms::enumerations;

GermanWeaponsForLifeForms GermanWeaponsForLifeForms::G3_RIFLE(1, "G3 rifle");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::G11_RIFLE(2, "G11 rifle");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::P1_PISTOL(3, "P1 pistol");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::MG3_MACHINE_GUN(4, "MG3 machine gun");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::MILAN_MISSILE(5, "Milan missile");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::MP1_UZI_SUBMACHINE_GUN(6, "MP1 Uzi submachine gun");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::PANZERFAUST_3_LIGHT_ANTI_TANK_WEAPON(7, "Panzerfaust 3 Light Anti-Tank Weapon");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::DM19_HAND_GRENADE(8, "DM19 hand grenade");
GermanWeaponsForLifeForms GermanWeaponsForLifeForms::DM29_HAND_GRENADE(9, "DM29 hand grenade");


GermanWeaponsForLifeForms::GermanWeaponsForLifeForms(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

GermanWeaponsForLifeForms* GermanWeaponsForLifeForms::findEnumeration(int aVal) {
  GermanWeaponsForLifeForms* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string GermanWeaponsForLifeForms::getDescriptionForValue(int aVal) {
  GermanWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

GermanWeaponsForLifeForms GermanWeaponsForLifeForms::getEnumerationForValue(int aVal) throw(EnumException) {
  GermanWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration GermanWeaponsForLifeForms";
    throw EnumException("GermanWeaponsForLifeForms", aVal, ss.str());
  }
};

bool GermanWeaponsForLifeForms::enumerationForValueExists(int aVal) {
  GermanWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

GermanWeaponsForLifeForms::enumContainer GermanWeaponsForLifeForms::getEnumerations() {
  return (enumerations);
};

GermanWeaponsForLifeForms& GermanWeaponsForLifeForms::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

