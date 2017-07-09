#include <sstream>
#include <cstddef>
#include <disenum/DetailedModCombinationMod.h>

namespace DIS {


hashMap<int,DetailedModCombinationMod*> DetailedModCombinationMod::enumerations;

DetailedModCombinationMod DetailedModCombinationMod::OTHER(0, "Other");
DetailedModCombinationMod DetailedModCombinationMod::AMPLITUDE_ANGLE_PULSE(1, "Amplitude-Angle-Pulse");


DetailedModCombinationMod::DetailedModCombinationMod(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModCombinationMod* DetailedModCombinationMod::findEnumeration(int aVal) {
  DetailedModCombinationMod* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModCombinationMod::getDescriptionForValue(int aVal) {
  DetailedModCombinationMod* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModCombinationMod DetailedModCombinationMod::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModCombinationMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModCombinationMod";
    throw EnumException("DetailedModCombinationMod", aVal, ss.str());
  }
};

bool DetailedModCombinationMod::enumerationForValueExists(int aVal) {
  DetailedModCombinationMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModCombinationMod::enumContainer DetailedModCombinationMod::getEnumerations() {
  return (enumerations);
};

DetailedModCombinationMod& DetailedModCombinationMod::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

