#include <sstream>
#include <cstddef>
#include <disenum/HullAirframeBody.h>

namespace DIS {


hashMap<int,HullAirframeBody*> HullAirframeBody::enumerations;

HullAirframeBody HullAirframeBody::HULL(1000, "hull");
HullAirframeBody HullAirframeBody::AIRFRAME(1010, "airframe");
HullAirframeBody HullAirframeBody::TRUCK_BODY(1020, "truck body");
HullAirframeBody HullAirframeBody::TANK_BODY(1030, "tank body");
HullAirframeBody HullAirframeBody::TRAILER_BODY(1040, "trailer body");
HullAirframeBody HullAirframeBody::TURRET(1050, "turret");
HullAirframeBody HullAirframeBody::MISSING_DESCRIPTION(1060, "Missing Description");


HullAirframeBody::HullAirframeBody(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

HullAirframeBody* HullAirframeBody::findEnumeration(int aVal) {
  HullAirframeBody* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string HullAirframeBody::getDescriptionForValue(int aVal) {
  HullAirframeBody* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

HullAirframeBody HullAirframeBody::getEnumerationForValue(int aVal) throw(EnumException) {
  HullAirframeBody* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration HullAirframeBody";
    throw EnumException("HullAirframeBody", aVal, ss.str());
  }
};

bool HullAirframeBody::enumerationForValueExists(int aVal) {
  HullAirframeBody* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

HullAirframeBody::enumContainer HullAirframeBody::getEnumerations() {
  return (enumerations);
};

HullAirframeBody& HullAirframeBody::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

