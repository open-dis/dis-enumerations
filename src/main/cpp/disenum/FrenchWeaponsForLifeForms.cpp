#include <sstream>
#include <cstddef>
#include <disenum/FrenchWeaponsForLifeForms.h>

namespace DIS {


hashMap<int,FrenchWeaponsForLifeForms*> FrenchWeaponsForLifeForms::enumerations;

FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::ACL_STRIM(1, "ACL-STRIM");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::MISTRAL_MISSILE(2, "Mistral missile");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::MILAN_AT_MISSILE(3, "Milan AT missile");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::LRAC_F1_89_MM_AT_ROCKET_LAUNCHER(4, "LRAC F1 89-mm AT rocket launcher");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::FA_MAS_RIFLE(5, "FA-MAS rifle");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::AA_52_MACHINE_GUN(6, "AA-52 machine gun");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::X_58_MM_RIFLE_GRENADE(7, "58-mm rifle grenade");
FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::FR_F1_SNIPER_RIFLE(8, "FR-F1 sniper rifle");


FrenchWeaponsForLifeForms::FrenchWeaponsForLifeForms(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FrenchWeaponsForLifeForms* FrenchWeaponsForLifeForms::findEnumeration(int aVal) {
  FrenchWeaponsForLifeForms* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FrenchWeaponsForLifeForms::getDescriptionForValue(int aVal) {
  FrenchWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FrenchWeaponsForLifeForms FrenchWeaponsForLifeForms::getEnumerationForValue(int aVal) throw(EnumException) {
  FrenchWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FrenchWeaponsForLifeForms";
    throw EnumException("FrenchWeaponsForLifeForms", aVal, ss.str());
  }
};

bool FrenchWeaponsForLifeForms::enumerationForValueExists(int aVal) {
  FrenchWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FrenchWeaponsForLifeForms::enumContainer FrenchWeaponsForLifeForms::getEnumerations() {
  return (enumerations);
};

FrenchWeaponsForLifeForms& FrenchWeaponsForLifeForms::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

