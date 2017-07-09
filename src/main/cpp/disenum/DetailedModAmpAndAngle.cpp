#include <sstream>
#include <cstddef>
#include <disenum/DetailedModAmpAndAngle.h>

namespace DIS {


hashMap<int,DetailedModAmpAndAngle*> DetailedModAmpAndAngle::enumerations;

DetailedModAmpAndAngle DetailedModAmpAndAngle::OTHER(0, "Other");
DetailedModAmpAndAngle DetailedModAmpAndAngle::AMPLITUDE_AND_ANGLE(1, "Amplitude and Angle");


DetailedModAmpAndAngle::DetailedModAmpAndAngle(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModAmpAndAngle* DetailedModAmpAndAngle::findEnumeration(int aVal) {
  DetailedModAmpAndAngle* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModAmpAndAngle::getDescriptionForValue(int aVal) {
  DetailedModAmpAndAngle* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModAmpAndAngle DetailedModAmpAndAngle::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModAmpAndAngle* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModAmpAndAngle";
    throw EnumException("DetailedModAmpAndAngle", aVal, ss.str());
  }
};

bool DetailedModAmpAndAngle::enumerationForValueExists(int aVal) {
  DetailedModAmpAndAngle* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModAmpAndAngle::enumContainer DetailedModAmpAndAngle::getEnumerations() {
  return (enumerations);
};

DetailedModAmpAndAngle& DetailedModAmpAndAngle::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

