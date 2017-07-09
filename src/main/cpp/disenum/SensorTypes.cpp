#include <sstream>
#include <cstddef>
#include <disenum/SensorTypes.h>

namespace DIS {


hashMap<int,SensorTypes*> SensorTypes::enumerations;

SensorTypes SensorTypes::OTHER(0, "Other");
SensorTypes SensorTypes::OPTICAL(1, "Optical");
SensorTypes SensorTypes::FLIR(2, "FLIR");
SensorTypes SensorTypes::RADAR(3, "RADAR");
SensorTypes SensorTypes::MAGNETIC(4, "Magnetic");
SensorTypes SensorTypes::LASER(5, "Laser");
SensorTypes SensorTypes::SONAR(6, "SONAR");
SensorTypes SensorTypes::PHYSICAL(7, "Physical");
SensorTypes SensorTypes::MULTISPECTRAL(8, "Multispectral");


SensorTypes::SensorTypes(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SensorTypes* SensorTypes::findEnumeration(int aVal) {
  SensorTypes* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SensorTypes::getDescriptionForValue(int aVal) {
  SensorTypes* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SensorTypes SensorTypes::getEnumerationForValue(int aVal) throw(EnumException) {
  SensorTypes* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SensorTypes";
    throw EnumException("SensorTypes", aVal, ss.str());
  }
};

bool SensorTypes::enumerationForValueExists(int aVal) {
  SensorTypes* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SensorTypes::enumContainer SensorTypes::getEnumerations() {
  return (enumerations);
};

SensorTypes& SensorTypes::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

