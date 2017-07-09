#include <sstream>
#include <cstddef>
#include <disenum/Subcategory.h>

namespace DIS {


hashMap<int,Subcategory*> Subcategory::enumerations;

Subcategory Subcategory::OTHER(0, "Other");
Subcategory Subcategory::CAVALRY_TROOP(1, "Cavalry Troop");
Subcategory Subcategory::ARMOR(2, "Armor");
Subcategory Subcategory::INFANTRY(3, "Infantry");
Subcategory Subcategory::MECHANIZED_INFANTRY(4, "Mechanized Infantry");
Subcategory Subcategory::CAVALRY(5, "Cavalry");
Subcategory Subcategory::ARMORED_CAVALRY(6, "Armored Cavalry");
Subcategory Subcategory::ARTILLERY(7, "Artillery");
Subcategory Subcategory::SELF_PROPELLED_ARTILLERY(8, "Self-propelled Artillery");
Subcategory Subcategory::CLOSE_AIR_SUPPORT(9, "Close Air Support");
Subcategory Subcategory::ENGINEER(10, "Engineer");
Subcategory Subcategory::AIR_DEFENSE_ARTILLERY(11, "Air Defense Artillery");
Subcategory Subcategory::ANTI_TANK(12, "Anti-tank");
Subcategory Subcategory::ARMY_AVIATION_FIXED_WING(13, "Army Aviation Fixed-wing");
Subcategory Subcategory::ARMY_AVIATION_ROTARY_WING(14, "Army Aviation Rotary-wing");
Subcategory Subcategory::ARMY_ATTACK_HELICOPTER(15, "Army Attack Helicopter");
Subcategory Subcategory::AIR_CAVALRY(16, "Air Cavalry");
Subcategory Subcategory::ARMOR_HEAVY_TASK_FORCE(17, "Armor Heavy Task Force");
Subcategory Subcategory::MOTORIZED_RIFLE(18, "Motorized Rifle");
Subcategory Subcategory::MECHANIZED_HEAVY_TASK_FORCE(19, "Mechanized Heavy Task Force");
Subcategory Subcategory::COMMAND_POST(20, "Command Post");
Subcategory Subcategory::CEWI(21, "CEWI");
Subcategory Subcategory::TANK_ONLY(22, "Tank only");


Subcategory::Subcategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Subcategory* Subcategory::findEnumeration(int aVal) {
  Subcategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Subcategory::getDescriptionForValue(int aVal) {
  Subcategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Subcategory Subcategory::getEnumerationForValue(int aVal) throw(EnumException) {
  Subcategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Subcategory";
    throw EnumException("Subcategory", aVal, ss.str());
  }
};

bool Subcategory::enumerationForValueExists(int aVal) {
  Subcategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Subcategory::enumContainer Subcategory::getEnumerations() {
  return (enumerations);
};

Subcategory& Subcategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

