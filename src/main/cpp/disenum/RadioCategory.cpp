#include <sstream>
#include <cstddef>
#include <disenum/RadioCategory.h>

namespace DIS {


hashMap<int,RadioCategory*> RadioCategory::enumerations;

RadioCategory RadioCategory::OTHER(0, "Other");
RadioCategory RadioCategory::VOICE_TRANSMISSION_RECEPTION(1, "Voice Transmission/Reception");
RadioCategory RadioCategory::DATA_LINK_TRANSMISSION_RECEPTION(2, "Data Link Transmission/Reception");
RadioCategory RadioCategory::VOICE_AND_DATA_LINK_TRANSMISSION_RECEPTION(3, "Voice and Data Link Transmission/Reception");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_GLIDESLOPE_TRANSMITTER(4, "Instrumented Landing System (ILS) Glideslope Transmitter");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_LOCALIZER_TRANSMITTER(5, "Instrumented Landing System (ILS) Localizer Transmitter");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_OUTER_MARKER_BEACON(6, "Instrumented Landing System (ILS) Outer Marker Beacon");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_MIDDLE_MARKER_BEACON(7, "Instrumented Landing System (ILS) Middle Marker Beacon");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_INNER_MARKER_BEACON(8, "Instrumented Landing System (ILS) Inner Marker Beacon");
RadioCategory RadioCategory::INSTRUMENTED_LANDING_SYSTEM_ILS_RECEIVER_PLATFORM_RADIO(9, "Instrumented Landing System (ILS) Receiver (Platform Radio)");
RadioCategory RadioCategory::TACTICAL_AIR_NAVIGATION_TACAN_TRANSMITTER_GROUND_FIXED_EQUIPMENT(10, "Tactical Air Navigation (TACAN) Transmitter (Ground Fixed Equipment)");
RadioCategory RadioCategory::TACTICAL_AIR_NAVIGATION_TACAN_RECEIVER_MOVING_PLATFORM_EQUIPMENT(11, "Tactical Air Navigation (TACAN) Receiver (Moving Platform Equipment)");
RadioCategory RadioCategory::TACTICAL_AIR_NAVIGATION_TACAN_TRANSMITTER_RECEIVER_MOVING_PLATFORM_EQUIPMENT(12, "Tactical Air Navigation (TACAN) Transmitter/Receiver (Moving Platform Equipment)");
RadioCategory RadioCategory::VARIABLE_OMNI_RANGING_VOR_TRANSMITTER_GROUND_FIXED_EQUIPMENT(13, "Variable Omni-Ranging (VOR) Transmitter (Ground Fixed Equipment)");
RadioCategory RadioCategory::VARIABLE_OMNI_RANGING_VOR_WITH_DISTANCE_MEASURING_EQUIPMENT_DME_TRANSMITTER_GROUND_FIXED_EQUIPMENT(14, "Variable Omni-Ranging (VOR) with Distance Measuring Equipment (DME) Transmitter (Ground Fixed Equipment)");
RadioCategory RadioCategory::COMBINED_VOR_ILS_RECEIVER_MOVING_PLATFORM_EQUIPMENT(15, "Combined VOR/ILS Receiver (Moving Platform Equipment)");
RadioCategory RadioCategory::COMBINED_VOR_TACAN_VORTAC_TRANSMITTER(16, "Combined VOR & TACAN (VORTAC) Transmitter");
RadioCategory RadioCategory::NON_DIRECTIONAL_BEACON_NDB_TRANSMITTER(17, "Non-Directional Beacon (NDB) Transmitter");
RadioCategory RadioCategory::NON_DIRECTIONAL_BEACON_NDB_RECEIVER(18, "Non-Directional Beacon (NDB) Receiver");
RadioCategory RadioCategory::NON_DIRECTIONAL_BEACON_NDB_WITH_DISTANCE_MEASURING_EQUIPMENT_DME_TRANSMITTER(19, "Non-Directional Beacon (NDB) with Distance Measuring Equipment (DME) Transmitter");
RadioCategory RadioCategory::DISTANCE_MEASURING_EQUIPMENT_DME(20, "Distance Measuring Equipment (DME)");


RadioCategory::RadioCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RadioCategory* RadioCategory::findEnumeration(int aVal) {
  RadioCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RadioCategory::getDescriptionForValue(int aVal) {
  RadioCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RadioCategory RadioCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  RadioCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RadioCategory";
    throw EnumException("RadioCategory", aVal, ss.str());
  }
};

bool RadioCategory::enumerationForValueExists(int aVal) {
  RadioCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RadioCategory::enumContainer RadioCategory::getEnumerations() {
  return (enumerations);
};

RadioCategory& RadioCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

