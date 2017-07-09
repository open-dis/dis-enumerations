#include <sstream>
#include <cstddef>
#include <disenum/Electronics.h>

namespace DIS {


hashMap<int,Electronics*> Electronics::enumerations;

Electronics Electronics::ELECTRONIC_WARFARE_SYSTEMS(4500, "electronic warfare systems");
Electronics Electronics::DETECTION_SYSTEMS(4600, "detection systems");
Electronics Electronics::RADIO_FREQUENCY(4610, "radio frequency");
Electronics Electronics::MICROWAVE(4620, "microwave");
Electronics Electronics::INFRARED(4630, "infrared");
Electronics Electronics::LASER(4640, "laser");
Electronics Electronics::RANGE_FINDERS(4700, "range finders");
Electronics Electronics::RANGE_ONLY_RADAR(4710, "range-only radar");
Electronics Electronics::LASER_RANGE_FINDER(4720, "laser range finder");
Electronics Electronics::ELECTRONIC_SYSTEMS(4800, "electronic systems");
Electronics Electronics::RADIO_FREQUENCY_1(4810, "radio frequency");
Electronics Electronics::MICROWAVE_2(4820, "microwave");
Electronics Electronics::INFRARED_3(4830, "infrared");
Electronics Electronics::LASER_4(4840, "laser");
Electronics Electronics::RADIOS(5000, "radios");
Electronics Electronics::COMMUNICATION_SYSTEMS(5010, "communication systems");
Electronics Electronics::INTERCOMS(5100, "intercoms");
Electronics Electronics::ENCODERS(5200, "encoders");
Electronics Electronics::ENCRYPTION_DEVICES(5250, "encryption devices");
Electronics Electronics::DECODERS(5300, "decoders");
Electronics Electronics::DECRYPTION_DEVICES(5350, "decryption devices");
Electronics Electronics::COMPUTERS(5500, "computers");
Electronics Electronics::NAVIGATION_AND_CONTROL_SYSTEMS(6000, "navigation and control systems");
Electronics Electronics::FIRE_CONTROL_SYSTEMS(6500, "fire control systems");
Electronics Electronics::MISSING_DESCRIPTION(6501, "Missing Description");


Electronics::Electronics(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Electronics* Electronics::findEnumeration(int aVal) {
  Electronics* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Electronics::getDescriptionForValue(int aVal) {
  Electronics* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Electronics Electronics::getEnumerationForValue(int aVal) throw(EnumException) {
  Electronics* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Electronics";
    throw EnumException("Electronics", aVal, ss.str());
  }
};

bool Electronics::enumerationForValueExists(int aVal) {
  Electronics* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Electronics::enumContainer Electronics::getEnumerations() {
  return (enumerations);
};

Electronics& Electronics::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

