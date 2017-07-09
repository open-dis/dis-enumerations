#include <sstream>
#include <cstddef>
#include <disenum/EventType.h>

namespace DIS {


hashMap<int,EventType*> EventType::enumerations;

EventType EventType::OTHER(0, "Other");
EventType EventType::MISSING_DESCRIPTION(1, "Missing Description");
EventType EventType::RAN_OUT_OF_AMMUNITION(2, "Ran out of ammunition");
EventType EventType::KILLED_IN_ACTION(3, "Killed in action");
EventType EventType::DAMAGE(4, "Damage");
EventType EventType::MOBILITY_DISABLED(5, "Mobility disabled");
EventType EventType::FIRE_DISABLED(6, "Fire disabled");
EventType EventType::RAN_OUT_OF_FUEL(7, "Ran out of fuel");
EventType EventType::ENTITY_INITIALIZATION(8, "Entity initialization");
EventType EventType::REQUEST_FOR_INDIRECT_FIRE_OR_CAS_MISSION(9, "Request for indirect fire or CAS mission");
EventType EventType::INDIRECT_FIRE_OR_CAS_FIRE(10, "Indirect fire or CAS fire");
EventType EventType::MINEFIELD_ENTRY(11, "Minefield entry");
EventType EventType::MINEFIELD_DETONATION(12, "Minefield detonation");
EventType EventType::VEHICLE_MASTER_POWER_ON(13, "Vehicle master power on");
EventType EventType::VEHICLE_MASTER_POWER_OFF(14, "Vehicle master power off");
EventType EventType::AGGREGATE_STATE_CHANGE_REQUESTED(15, "Aggregate state change requested");
EventType EventType::PREVENT_COLLISION_DETONATION(16, "Prevent Collision / Detonation");


EventType::EventType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

EventType* EventType::findEnumeration(int aVal) {
  EventType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string EventType::getDescriptionForValue(int aVal) {
  EventType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

EventType EventType::getEnumerationForValue(int aVal) throw(EnumException) {
  EventType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration EventType";
    throw EnumException("EventType", aVal, ss.str());
  }
};

bool EventType::enumerationForValueExists(int aVal) {
  EventType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

EventType::enumContainer EventType::getEnumerations() {
  return (enumerations);
};

EventType& EventType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

