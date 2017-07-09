#include <sstream>
#include <cstddef>
#include <disenum/ArticulatedPartsOffsetNumber.h>

namespace DIS {


hashMap<int,ArticulatedPartsOffsetNumber*> ArticulatedPartsOffsetNumber::enumerations;

ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::POSITION(1, "Position");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::POSITION_RATE(2, "Position Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::EXTENSION(3, "Extension");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::EXTENSION_RATE(4, "Extension Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::X(5, "X");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::X_RATE(6, "X Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::Y(7, "Y");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::Y_RATE(8, "Y Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::Z(9, "Z");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::Z_RATE(10, "Z Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::AZIMUTH(11, "Azimuth");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::AZIMUTH_RATE(12, "Azimuth Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::ELEVATION(13, "Elevation");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::ELEVATION_RATE(14, "Elevation Rate");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::ROTATION(15, "Rotation");
ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::ROTATION_RATE(16, "Rotation Rate");


ArticulatedPartsOffsetNumber::ArticulatedPartsOffsetNumber(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ArticulatedPartsOffsetNumber* ArticulatedPartsOffsetNumber::findEnumeration(int aVal) {
  ArticulatedPartsOffsetNumber* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ArticulatedPartsOffsetNumber::getDescriptionForValue(int aVal) {
  ArticulatedPartsOffsetNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ArticulatedPartsOffsetNumber ArticulatedPartsOffsetNumber::getEnumerationForValue(int aVal) throw(EnumException) {
  ArticulatedPartsOffsetNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ArticulatedPartsOffsetNumber";
    throw EnumException("ArticulatedPartsOffsetNumber", aVal, ss.str());
  }
};

bool ArticulatedPartsOffsetNumber::enumerationForValueExists(int aVal) {
  ArticulatedPartsOffsetNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ArticulatedPartsOffsetNumber::enumContainer ArticulatedPartsOffsetNumber::getEnumerations() {
  return (enumerations);
};

ArticulatedPartsOffsetNumber& ArticulatedPartsOffsetNumber::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

