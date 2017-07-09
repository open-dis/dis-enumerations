#include <sstream>
#include <cstddef>
#include <disenum/DetailedModAngleMod.h>

namespace DIS {


hashMap<int,DetailedModAngleMod*> DetailedModAngleMod::enumerations;

DetailedModAngleMod DetailedModAngleMod::OTHER(0, "Other");
DetailedModAngleMod DetailedModAngleMod::FM_FREQUENCY_MODULATION(1, "FM (Frequency Modulation)");
DetailedModAngleMod DetailedModAngleMod::FSK_FREQUENCY_SHIFT_KEYING(2, "FSK (Frequency Shift Keying)");
DetailedModAngleMod DetailedModAngleMod::PM_PHASE_MODULATION(3, "PM (Phase Modulation)");


DetailedModAngleMod::DetailedModAngleMod(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModAngleMod* DetailedModAngleMod::findEnumeration(int aVal) {
  DetailedModAngleMod* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModAngleMod::getDescriptionForValue(int aVal) {
  DetailedModAngleMod* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModAngleMod DetailedModAngleMod::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModAngleMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModAngleMod";
    throw EnumException("DetailedModAngleMod", aVal, ss.str());
  }
};

bool DetailedModAngleMod::enumerationForValueExists(int aVal) {
  DetailedModAngleMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModAngleMod::enumContainer DetailedModAngleMod::getEnumerations() {
  return (enumerations);
};

DetailedModAngleMod& DetailedModAngleMod::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

