#include <sstream>
#include <cstddef>
#include <disenum/GroupedEntityCategory.h>

namespace DIS {


hashMap<int,GroupedEntityCategory*> GroupedEntityCategory::enumerations;

GroupedEntityCategory GroupedEntityCategory::UNDEFINED(0, "Undefined");
GroupedEntityCategory GroupedEntityCategory::BASIC_GROUND_COMBAT_VEHICLE(1, "Basic Ground Combat Vehicle");
GroupedEntityCategory GroupedEntityCategory::ENHANCED_GROUND_COMBAT_VEHICLE(2, "Enhanced Ground Combat Vehicle");
GroupedEntityCategory GroupedEntityCategory::BASIC_GROUND_COMBAT_SOLDIER(3, "Basic Ground Combat Soldier");
GroupedEntityCategory GroupedEntityCategory::ENHANCED_GROUND_COMBAT_SOLDIER(4, "Enhanced Ground Combat Soldier");
GroupedEntityCategory GroupedEntityCategory::BASIC_ROTOR_WING_AIRCRAFT(5, "Basic Rotor Wing Aircraft");
GroupedEntityCategory GroupedEntityCategory::ENHANCED_ROTOR_WING_AIRCRAFT(6, "Enhanced Rotor Wing Aircraft");
GroupedEntityCategory GroupedEntityCategory::BASIC_FIXED_WING_AIRCRAFT(7, "Basic Fixed Wing Aircraft");
GroupedEntityCategory GroupedEntityCategory::ENHANCED_FIXED_WING_AIRCRAFT(8, "Enhanced Fixed Wing Aircraft");
GroupedEntityCategory GroupedEntityCategory::GROUND_LOGISTICS_VEHICLE(9, "Ground Logistics Vehicle");


GroupedEntityCategory::GroupedEntityCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

GroupedEntityCategory* GroupedEntityCategory::findEnumeration(int aVal) {
  GroupedEntityCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string GroupedEntityCategory::getDescriptionForValue(int aVal) {
  GroupedEntityCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

GroupedEntityCategory GroupedEntityCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  GroupedEntityCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration GroupedEntityCategory";
    throw EnumException("GroupedEntityCategory", aVal, ss.str());
  }
};

bool GroupedEntityCategory::enumerationForValueExists(int aVal) {
  GroupedEntityCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

GroupedEntityCategory::enumContainer GroupedEntityCategory::getEnumerations() {
  return (enumerations);
};

GroupedEntityCategory& GroupedEntityCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

