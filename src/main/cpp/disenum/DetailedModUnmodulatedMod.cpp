#include <sstream>
#include <cstddef>
#include <disenum/DetailedModUnmodulatedMod.h>

namespace DIS {


hashMap<int,DetailedModUnmodulatedMod*> DetailedModUnmodulatedMod::enumerations;

DetailedModUnmodulatedMod DetailedModUnmodulatedMod::OTHER(0, "Other");
DetailedModUnmodulatedMod DetailedModUnmodulatedMod::CONTINUOUS_WAVE_EMISSION_OF_AN_UNMODULATED_CARRIER(1, "Continuous Wave emission of an unmodulated carrier");


DetailedModUnmodulatedMod::DetailedModUnmodulatedMod(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModUnmodulatedMod* DetailedModUnmodulatedMod::findEnumeration(int aVal) {
  DetailedModUnmodulatedMod* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModUnmodulatedMod::getDescriptionForValue(int aVal) {
  DetailedModUnmodulatedMod* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModUnmodulatedMod DetailedModUnmodulatedMod::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModUnmodulatedMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModUnmodulatedMod";
    throw EnumException("DetailedModUnmodulatedMod", aVal, ss.str());
  }
};

bool DetailedModUnmodulatedMod::enumerationForValueExists(int aVal) {
  DetailedModUnmodulatedMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModUnmodulatedMod::enumContainer DetailedModUnmodulatedMod::getEnumerations() {
  return (enumerations);
};

DetailedModUnmodulatedMod& DetailedModUnmodulatedMod::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

