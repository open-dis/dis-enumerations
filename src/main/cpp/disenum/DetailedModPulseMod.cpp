#include <sstream>
#include <cstddef>
#include <disenum/DetailedModPulseMod.h>

namespace DIS {


hashMap<int,DetailedModPulseMod*> DetailedModPulseMod::enumerations;

DetailedModPulseMod DetailedModPulseMod::OTHER(0, "Other");
DetailedModPulseMod DetailedModPulseMod::PULSE(1, "Pulse");
DetailedModPulseMod DetailedModPulseMod::X_BAND_TACAN_PULSE(2, "X Band TACAN Pulse");
DetailedModPulseMod DetailedModPulseMod::Y_BAND_TACAN_PULSE(3, "Y Band TACAN Pulse");


DetailedModPulseMod::DetailedModPulseMod(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModPulseMod* DetailedModPulseMod::findEnumeration(int aVal) {
  DetailedModPulseMod* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModPulseMod::getDescriptionForValue(int aVal) {
  DetailedModPulseMod* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModPulseMod DetailedModPulseMod::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModPulseMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModPulseMod";
    throw EnumException("DetailedModPulseMod", aVal, ss.str());
  }
};

bool DetailedModPulseMod::enumerationForValueExists(int aVal) {
  DetailedModPulseMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModPulseMod::enumContainer DetailedModPulseMod::getEnumerations() {
  return (enumerations);
};

DetailedModPulseMod& DetailedModPulseMod::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

