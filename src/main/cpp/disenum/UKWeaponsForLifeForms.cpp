#include <sstream>
#include <cstddef>
#include <disenum/UKWeaponsForLifeForms.h>

namespace DIS {


hashMap<int,UKWeaponsForLifeForms*> UKWeaponsForLifeForms::enumerations;

UKWeaponsForLifeForms UKWeaponsForLifeForms::LAW_80(1, "LAW 80");
UKWeaponsForLifeForms UKWeaponsForLifeForms::BLOWPIPE(2, "Blowpipe");
UKWeaponsForLifeForms UKWeaponsForLifeForms::JAVELIN(3, "Javelin");
UKWeaponsForLifeForms UKWeaponsForLifeForms::X_51_MM_MORTAR(4, "51-mm mortar");
UKWeaponsForLifeForms UKWeaponsForLifeForms::SLR_762_MM_RIFLE(5, "SLR 7.62-mm rifle");
UKWeaponsForLifeForms UKWeaponsForLifeForms::STERLING_9_MM_SUBMACHINE_GUN(6, "Sterling 9-mm submachine gun");
UKWeaponsForLifeForms UKWeaponsForLifeForms::L7A2_GENERAL_PURPOSE_MG(7, "L7A2 general purpose MG");
UKWeaponsForLifeForms UKWeaponsForLifeForms::L6_WOMBAT_RECOILLESS_RIFLE(8, "L6 Wombat Recoilless rifle,");
UKWeaponsForLifeForms UKWeaponsForLifeForms::CARL_GUSTAV_89_MM_RECOILLESS_RIFLE(9, "Carl Gustav 89-mm recoilless rifle");
UKWeaponsForLifeForms UKWeaponsForLifeForms::SA80_INDIVIDUAL_LIGHT_SUPPORT_WEAPON(10, "SA80 Individual/light support weapon");
UKWeaponsForLifeForms UKWeaponsForLifeForms::TRIGAT(11, "Trigat");
UKWeaponsForLifeForms UKWeaponsForLifeForms::MILAN_AT_MISSILE(12, "Milan AT missile");


UKWeaponsForLifeForms::UKWeaponsForLifeForms(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

UKWeaponsForLifeForms* UKWeaponsForLifeForms::findEnumeration(int aVal) {
  UKWeaponsForLifeForms* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string UKWeaponsForLifeForms::getDescriptionForValue(int aVal) {
  UKWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

UKWeaponsForLifeForms UKWeaponsForLifeForms::getEnumerationForValue(int aVal) throw(EnumException) {
  UKWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration UKWeaponsForLifeForms";
    throw EnumException("UKWeaponsForLifeForms", aVal, ss.str());
  }
};

bool UKWeaponsForLifeForms::enumerationForValueExists(int aVal) {
  UKWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

UKWeaponsForLifeForms::enumContainer UKWeaponsForLifeForms::getEnumerations() {
  return (enumerations);
};

UKWeaponsForLifeForms& UKWeaponsForLifeForms::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

