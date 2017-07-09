#include <sstream>
#include <cstddef>
#include <disenum/MunitionDomain.h>

namespace DIS {


hashMap<int,MunitionDomain*> MunitionDomain::enumerations;

MunitionDomain MunitionDomain::OTHER(0, "Other");
MunitionDomain MunitionDomain::ANTI_AIR(1, "Anti-Air");
MunitionDomain MunitionDomain::ANTI_ARMOR(2, "Anti-Armor");
MunitionDomain MunitionDomain::ANTI_GUIDED_WEAPON(3, "Anti-Guided Weapon");
MunitionDomain MunitionDomain::ANTIRADAR(4, "Antiradar");
MunitionDomain MunitionDomain::ANTISATELLITE(5, "Antisatellite");
MunitionDomain MunitionDomain::ANTISHIP(6, "Antiship");
MunitionDomain MunitionDomain::ANTISUBMARINE(7, "Antisubmarine");
MunitionDomain MunitionDomain::ANTIPERSONNEL(8, "Antipersonnel");
MunitionDomain MunitionDomain::BATTLEFIELD_SUPPORT(9, "Battlefield Support");
MunitionDomain MunitionDomain::STRATEGIC(10, "Strategic");
MunitionDomain MunitionDomain::TACTICAL(11, "Tactical");
MunitionDomain MunitionDomain::DIRECTED_ENERGY_DE_WEAPON(12, "Directed Energy (DE) Weapon");


MunitionDomain::MunitionDomain(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

MunitionDomain* MunitionDomain::findEnumeration(int aVal) {
  MunitionDomain* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string MunitionDomain::getDescriptionForValue(int aVal) {
  MunitionDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

MunitionDomain MunitionDomain::getEnumerationForValue(int aVal) throw(EnumException) {
  MunitionDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration MunitionDomain";
    throw EnumException("MunitionDomain", aVal, ss.str());
  }
};

bool MunitionDomain::enumerationForValueExists(int aVal) {
  MunitionDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

MunitionDomain::enumContainer MunitionDomain::getEnumerations() {
  return (enumerations);
};

MunitionDomain& MunitionDomain::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

