#include <sstream>
#include <cstddef>
#include <disenum/AntennaPatternType.h>

namespace DIS {


hashMap<int,AntennaPatternType*> AntennaPatternType::enumerations;

AntennaPatternType AntennaPatternType::OMNI_DIRECTIONAL(0, "Omni-directional");
AntennaPatternType AntennaPatternType::BEAM(1, "Beam");
AntennaPatternType AntennaPatternType::SPHERICAL_HARMONIC(2, "Spherical harmonic");


AntennaPatternType::AntennaPatternType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AntennaPatternType* AntennaPatternType::findEnumeration(int aVal) {
  AntennaPatternType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AntennaPatternType::getDescriptionForValue(int aVal) {
  AntennaPatternType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AntennaPatternType AntennaPatternType::getEnumerationForValue(int aVal) throw(EnumException) {
  AntennaPatternType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AntennaPatternType";
    throw EnumException("AntennaPatternType", aVal, ss.str());
  }
};

bool AntennaPatternType::enumerationForValueExists(int aVal) {
  AntennaPatternType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AntennaPatternType::enumContainer AntennaPatternType::getEnumerations() {
  return (enumerations);
};

AntennaPatternType& AntennaPatternType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

