#include <sstream>
#include <cstddef>
#include <disenum/StationName.h>

namespace DIS {


hashMap<int,StationName*> StationName::enumerations;

StationName StationName::OTHER(0, "Other");
StationName StationName::AIRCRAFT_WINGSTATION(1, "Aircraft wingstation");
StationName StationName::SHIPS_FORWARD_GUNMOUNT_STARBOARD(2, "Ship's forward gunmount (starboard)");
StationName StationName::SHIPS_FORWARD_GUNMOUNT_PORT(3, "Ship's forward gunmount (port)");
StationName StationName::SHIPS_FORWARD_GUNMOUNT_CENTERLINE(4, "Ship's forward gunmount (centerline)");
StationName StationName::SHIPS_AFT_GUNMOUNT_STARBOARD(5, "Ship's aft gunmount (starboard)");
StationName StationName::SHIPS_AFT_GUNMOUNT_PORT(6, "Ship's aft gunmount (port)");
StationName StationName::SHIPS_AFT_GUNMOUNT_CENTERLINE(7, "Ship's aft gunmount (centerline)");
StationName StationName::FORWARD_TORPEDO_TUBE(8, "Forward torpedo tube");
StationName StationName::AFT_TORPEDO_TUBE(9, "Aft torpedo tube");
StationName StationName::BOMB_BAY(10, "Bomb bay");
StationName StationName::CARGO_BAY(11, "Cargo bay");
StationName StationName::TRUCK_BED(12, "Truck bed");
StationName StationName::TRAILER_BED(13, "Trailer bed");
StationName StationName::WELL_DECK(14, "Well deck");
StationName StationName::ON_STATION_RNG_BRG(15, "On station - (RNG/BRG)");
StationName StationName::ON_STATION_XYZ(16, "On station - (x,y,z)");


StationName::StationName(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

StationName* StationName::findEnumeration(int aVal) {
  StationName* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string StationName::getDescriptionForValue(int aVal) {
  StationName* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

StationName StationName::getEnumerationForValue(int aVal) throw(EnumException) {
  StationName* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration StationName";
    throw EnumException("StationName", aVal, ss.str());
  }
};

bool StationName::enumerationForValueExists(int aVal) {
  StationName* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

StationName::enumContainer StationName::getEnumerations() {
  return (enumerations);
};

StationName& StationName::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

