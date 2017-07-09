#include <sstream>
#include <cstddef>
#include <disenum/Nature.h>

namespace DIS {


hashMap<int,Nature*> Nature::enumerations;

Nature Nature::OTHER(0, "Other");
Nature Nature::HOST_FIREABLE_MUNITION(1, "Host-fireable munition");
Nature Nature::MUNITION_CARRIED_AS_CARGO(2, "Munition carried as cargo");
Nature Nature::FUEL_CARRIED_AS_CARGO(3, "Fuel carried as cargo");
Nature Nature::GUNMOUNT_ATTACHED_TO_HOST(4, "Gunmount attached to host");
Nature Nature::COMPUTER_GENERATED_FORCES_CARRIED_AS_CARGO(5, "Computer generated forces carried as cargo");
Nature Nature::VEHICLE_CARRIED_AS_CARGO(6, "Vehicle carried as cargo");
Nature Nature::EMITTER_MOUNTED_ON_HOST(7, "Emitter mounted on host");
Nature Nature::MOBILE_COMMAND_AND_CONTROL_ENTITY_CARRIED_ABOARD_HOST(8, "Mobile command and control entity carried aboard host");
Nature Nature::ENTITY_STATIONED_AT_POSITION_WITH_RESPECT_TO_HOST(9, "Entity stationed at position with respect to host");
Nature Nature::TEAM_MEMBER_IN_FORMATION_WITH(10, "Team member in formation with");


Nature::Nature(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Nature* Nature::findEnumeration(int aVal) {
  Nature* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Nature::getDescriptionForValue(int aVal) {
  Nature* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Nature Nature::getEnumerationForValue(int aVal) throw(EnumException) {
  Nature* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Nature";
    throw EnumException("Nature", aVal, ss.str());
  }
};

bool Nature::enumerationForValueExists(int aVal) {
  Nature* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Nature::enumContainer Nature::getEnumerations() {
  return (enumerations);
};

Nature& Nature::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

