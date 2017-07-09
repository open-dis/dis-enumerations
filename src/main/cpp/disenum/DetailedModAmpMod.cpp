#include <sstream>
#include <cstddef>
#include <disenum/DetailedModAmpMod.h>

namespace DIS {


hashMap<int,DetailedModAmpMod*> DetailedModAmpMod::enumerations;

DetailedModAmpMod DetailedModAmpMod::OTHER(0, "Other");
DetailedModAmpMod DetailedModAmpMod::AFSK_AUDIO_FREQUENCY_SHIFT_KEYING(1, "AFSK (Audio Frequency Shift Keying)");
DetailedModAmpMod DetailedModAmpMod::AM_AMPLITUDE_MODULATION(2, "AM (Amplitude Modulation)");
DetailedModAmpMod DetailedModAmpMod::CW_CONTINUOUS_WAVE_MODULATION(3, "CW (Continuous Wave Modulation)");
DetailedModAmpMod DetailedModAmpMod::DSB_DOUBLE_SIDEBAND(4, "DSB (Double Sideband)");
DetailedModAmpMod DetailedModAmpMod::ISB_INDEPENDENT_SIDEBAND(5, "ISB (Independent Sideband)");
DetailedModAmpMod DetailedModAmpMod::LSB_SINGLE_BAND_SUPPRESSED_CARRIER_LOWER_SIDEBAND_MODE(6, "LSB (Single Band Suppressed Carrier, Lower Sideband Mode)");
DetailedModAmpMod DetailedModAmpMod::SSB_FULL_SINGLE_SIDEBAND_FULL_CARRIER(7, "SSB-Full (Single Sideband Full Carrier)");
DetailedModAmpMod DetailedModAmpMod::SSB_REDUC_SINGLE_BAND_REDUCED_CARRIER(8, "SSB-Reduc (Single Band Reduced Carrier)");
DetailedModAmpMod DetailedModAmpMod::USB_SINGLE_BAND_SUPPRESSED_CARRIER_UPPER_SIDEBAND_MODE(9, "USB (Single Band Suppressed Carrier, Upper Sideband Mode)");
DetailedModAmpMod DetailedModAmpMod::VSB_VESTIGIAL_SIDEBAND(10, "VSB (Vestigial Sideband)");


DetailedModAmpMod::DetailedModAmpMod(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModAmpMod* DetailedModAmpMod::findEnumeration(int aVal) {
  DetailedModAmpMod* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModAmpMod::getDescriptionForValue(int aVal) {
  DetailedModAmpMod* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModAmpMod DetailedModAmpMod::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModAmpMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModAmpMod";
    throw EnumException("DetailedModAmpMod", aVal, ss.str());
  }
};

bool DetailedModAmpMod::enumerationForValueExists(int aVal) {
  DetailedModAmpMod* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModAmpMod::enumContainer DetailedModAmpMod::getEnumerations() {
  return (enumerations);
};

DetailedModAmpMod& DetailedModAmpMod::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

