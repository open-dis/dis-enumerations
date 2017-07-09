#include <sstream>
#include <cstddef>
#include <disenum/DriveTrain.h>

namespace DIS {


hashMap<int,DriveTrain*> DriveTrain::enumerations;

DriveTrain DriveTrain::MOTOR_ENGINE(10, "motor / engine");
DriveTrain DriveTrain::STARTER(20, "starter");
DriveTrain DriveTrain::ALTERNATOR(30, "alternator");
DriveTrain DriveTrain::GENERATOR(40, "generator");
DriveTrain DriveTrain::BATTERY(50, "battery");
DriveTrain DriveTrain::ENGINE_COOLANT_LEAK(60, "engine-coolant leak");
DriveTrain DriveTrain::FUEL_FILTER(70, "fuel filter");
DriveTrain DriveTrain::TRANSMISSION_OIL_LEAK(80, "transmission-oil leak");
DriveTrain DriveTrain::ENGINE_OIL_LEAK(90, "engine-oil leak");
DriveTrain DriveTrain::PUMPS(100, "pumps");
DriveTrain DriveTrain::FILTERS(110, "filters");
DriveTrain DriveTrain::TRANSMISSION(120, "transmission");
DriveTrain DriveTrain::BRAKES(130, "brakes");
DriveTrain DriveTrain::SUSPENSION_SYSTEM(140, "suspension system");
DriveTrain DriveTrain::OIL_FILTER(150, "oil filter");
DriveTrain DriveTrain::MISSING_DESCRIPTION(160, "Missing Description");


DriveTrain::DriveTrain(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DriveTrain* DriveTrain::findEnumeration(int aVal) {
  DriveTrain* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DriveTrain::getDescriptionForValue(int aVal) {
  DriveTrain* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DriveTrain DriveTrain::getEnumerationForValue(int aVal) throw(EnumException) {
  DriveTrain* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DriveTrain";
    throw EnumException("DriveTrain", aVal, ss.str());
  }
};

bool DriveTrain::enumerationForValueExists(int aVal) {
  DriveTrain* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DriveTrain::enumContainer DriveTrain::getEnumerations() {
  return (enumerations);
};

DriveTrain& DriveTrain::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

