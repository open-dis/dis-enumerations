#include <sstream>
#include <cstddef>
#include <disenum/MajorModulation.h>

namespace DIS {


hashMap<int,MajorModulation*> MajorModulation::enumerations;

MajorModulation MajorModulation::OTHER(0, "Other");
MajorModulation MajorModulation::AMPLITUDE(1, "Amplitude");
MajorModulation MajorModulation::AMPLITUDE_AND_ANGLE(2, "Amplitude and Angle");
MajorModulation MajorModulation::ANGLE(3, "Angle");
MajorModulation MajorModulation::COMBINATION(4, "Combination");
MajorModulation MajorModulation::PULSE(5, "Pulse");
MajorModulation MajorModulation::UNMODULATED(6, "Unmodulated");
MajorModulation MajorModulation::CARRIER_PHASE_SHIFT_MODULATION_CPSM(7, "Carrier Phase Shift Modulation (CPSM)");


MajorModulation::MajorModulation(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

MajorModulation* MajorModulation::findEnumeration(int aVal) {
  MajorModulation* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string MajorModulation::getDescriptionForValue(int aVal) {
  MajorModulation* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

MajorModulation MajorModulation::getEnumerationForValue(int aVal) throw(EnumException) {
  MajorModulation* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration MajorModulation";
    throw EnumException("MajorModulation", aVal, ss.str());
  }
};

bool MajorModulation::enumerationForValueExists(int aVal) {
  MajorModulation* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

MajorModulation::enumContainer MajorModulation::getEnumerations() {
  return (enumerations);
};

MajorModulation& MajorModulation::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

