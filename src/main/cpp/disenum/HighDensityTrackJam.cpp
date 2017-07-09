#include <sstream>
#include <cstddef>
#include <disenum/HighDensityTrackJam.h>

namespace DIS {


hashMap<int,HighDensityTrackJam*> HighDensityTrackJam::enumerations;

HighDensityTrackJam HighDensityTrackJam::NOT_SELECTED(0, "Not Selected");
HighDensityTrackJam HighDensityTrackJam::SELECTED(1, "Selected");


HighDensityTrackJam::HighDensityTrackJam(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

HighDensityTrackJam* HighDensityTrackJam::findEnumeration(int aVal) {
  HighDensityTrackJam* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string HighDensityTrackJam::getDescriptionForValue(int aVal) {
  HighDensityTrackJam* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

HighDensityTrackJam HighDensityTrackJam::getEnumerationForValue(int aVal) throw(EnumException) {
  HighDensityTrackJam* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration HighDensityTrackJam";
    throw EnumException("HighDensityTrackJam", aVal, ss.str());
  }
};

bool HighDensityTrackJam::enumerationForValueExists(int aVal) {
  HighDensityTrackJam* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

HighDensityTrackJam::enumContainer HighDensityTrackJam::getEnumerations() {
  return (enumerations);
};

HighDensityTrackJam& HighDensityTrackJam::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

