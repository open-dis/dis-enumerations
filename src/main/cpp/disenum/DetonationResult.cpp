#include <sstream>
#include <cstddef>
#include <disenum/DetonationResult.h>

namespace DIS {


hashMap<int,DetonationResult*> DetonationResult::enumerations;

DetonationResult DetonationResult::OTHER(0, "Other");
DetonationResult DetonationResult::ENTITY_IMPACT(1, "Entity Impact");
DetonationResult DetonationResult::ENTITY_PROXIMATE_DETONATION(2, "Entity Proximate Detonation");
DetonationResult DetonationResult::GROUND_IMPACT(3, "Ground Impact");
DetonationResult DetonationResult::GROUND_PROXIMATE_DETONATION(4, "Ground Proximate Detonation");
DetonationResult DetonationResult::DETONATION(5, "Detonation");
DetonationResult DetonationResult::NONE_OR_NO_DETONATION_DUD(6, "None or No Detonation (Dud)");
DetonationResult DetonationResult::HE_HIT_SMALL(7, "HE hit, small");
DetonationResult DetonationResult::HE_HIT_MEDIUM(8, "HE hit, medium");
DetonationResult DetonationResult::HE_HIT_LARGE(9, "HE hit, large");
DetonationResult DetonationResult::ARMOR_PIERCING_HIT(10, "Armor-piercing hit");
DetonationResult DetonationResult::DIRT_BLAST_SMALL(11, "Dirt blast, small");
DetonationResult DetonationResult::DIRT_BLAST_MEDIUM(12, "Dirt blast, medium");
DetonationResult DetonationResult::DIRT_BLAST_LARGE(13, "Dirt blast, large");
DetonationResult DetonationResult::WATER_BLAST_SMALL(14, "Water blast, small");
DetonationResult DetonationResult::WATER_BLAST_MEDIUM(15, "Water blast, medium");
DetonationResult DetonationResult::WATER_BLAST_LARGE(16, "Water blast, large");
DetonationResult DetonationResult::AIR_HIT(17, "Air hit");
DetonationResult DetonationResult::BUILDING_HIT_SMALL(18, "Building hit, small");
DetonationResult DetonationResult::BUILDING_HIT_MEDIUM(19, "Building hit, medium");
DetonationResult DetonationResult::BUILDING_HIT_LARGE(20, "Building hit, large");
DetonationResult DetonationResult::MINE_CLEARING_LINE_CHARGE(21, "Mine-clearing line charge");
DetonationResult DetonationResult::ENVIRONMENT_OBJECT_IMPACT(22, "Environment object impact");
DetonationResult DetonationResult::ENVIRONMENT_OBJECT_PROXIMATE_DETONATION(23, "Environment object proximate detonation");
DetonationResult DetonationResult::WATER_IMPACT(24, "Water Impact");
DetonationResult DetonationResult::AIR_BURST(25, "Air Burst");
DetonationResult DetonationResult::KILL_WITH_FRAGMENT_TYPE_1(26, "Kill with fragment type 1");
DetonationResult DetonationResult::KILL_WITH_FRAGMENT_TYPE_2(27, "Kill with fragment type 2");
DetonationResult DetonationResult::KILL_WITH_FRAGMENT_TYPE_3(28, "Kill with fragment type 3");
DetonationResult DetonationResult::KILL_WITH_FRAGMENT_TYPE_1_AFTER_FLY_OUT_FAILURE(29, "Kill with fragment type 1 after fly-out failure");
DetonationResult DetonationResult::KILL_WITH_FRAGMENT_TYPE_2_AFTER_FLY_OUT_FAILURE(30, "Kill with fragment type 2 after fly-out failure");
DetonationResult DetonationResult::MISS_DUE_TO_FLY_OUT_FAILURE(31, "Miss due to fly-out failure");
DetonationResult DetonationResult::MISS_DUE_TO_END_GAME_FAILURE(32, "Miss due to end-game failure");
DetonationResult DetonationResult::MISS_DUE_TO_FLY_OUT_AND_END_GAME_FAILURE(33, "Miss due to fly-out and end-game failure");


DetonationResult::DetonationResult(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetonationResult* DetonationResult::findEnumeration(int aVal) {
  DetonationResult* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetonationResult::getDescriptionForValue(int aVal) {
  DetonationResult* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetonationResult DetonationResult::getEnumerationForValue(int aVal) throw(EnumException) {
  DetonationResult* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetonationResult";
    throw EnumException("DetonationResult", aVal, ss.str());
  }
};

bool DetonationResult::enumerationForValueExists(int aVal) {
  DetonationResult* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetonationResult::enumContainer DetonationResult::getEnumerations() {
  return (enumerations);
};

DetonationResult& DetonationResult::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

