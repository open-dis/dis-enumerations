#include <sstream>
#include <cstddef>
#include <disenum/CoordinateSystem.h>

namespace DIS {


hashMap<int,CoordinateSystem*> CoordinateSystem::enumerations;

CoordinateSystem CoordinateSystem::RIGHT_HANDED_CARTESIAN_LOCAL_TOPOGRAPHIC_PROJECTION_EAST_NORTH_UP(0, "Right handed Cartesian (local topographic projection: east, north, up)");
CoordinateSystem CoordinateSystem::LEFT_HANDED_CARTESIAN_LOCAL_TOPOGRAPHIC_PROJECTION_EAST_NORTH_DOWN(1, "Left handed Cartesian (local topographic projection: east, north, down)");
CoordinateSystem CoordinateSystem::LATITUDE_LONGITUDE_HEIGHT(2, "Latitude, Longitude, Height");
CoordinateSystem CoordinateSystem::LATITUDE_LONGITUDE_DEPTH(3, "Latitude, Longitude, Depth");


CoordinateSystem::CoordinateSystem(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CoordinateSystem* CoordinateSystem::findEnumeration(int aVal) {
  CoordinateSystem* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CoordinateSystem::getDescriptionForValue(int aVal) {
  CoordinateSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CoordinateSystem CoordinateSystem::getEnumerationForValue(int aVal) throw(EnumException) {
  CoordinateSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CoordinateSystem";
    throw EnumException("CoordinateSystem", aVal, ss.str());
  }
};

bool CoordinateSystem::enumerationForValueExists(int aVal) {
  CoordinateSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CoordinateSystem::enumContainer CoordinateSystem::getEnumerations() {
  return (enumerations);
};

CoordinateSystem& CoordinateSystem::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

