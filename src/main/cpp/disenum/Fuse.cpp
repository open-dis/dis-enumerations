#include <sstream>
#include <cstddef>
#include <disenum/Fuse.h>

namespace DIS {


hashMap<int,Fuse*> Fuse::enumerations;

Fuse Fuse::OTHER(0, "Other");
Fuse Fuse::INTELLIGENT_INFLUENCE(10, "Intelligent Influence");
Fuse Fuse::SENSOR(20, "Sensor");
Fuse Fuse::SELF_DESTRUCT(30, "Self-destruct");
Fuse Fuse::ULTRA_QUICK(40, "Ultra Quick");
Fuse Fuse::BODY(50, "Body");
Fuse Fuse::DEEP_INTRUSION(60, "Deep Intrusion");
Fuse Fuse::MULTIFUNCTION(100, "Multifunction");
Fuse Fuse::POINT_DETONATION_PD(200, "Point Detonation (PD)");
Fuse Fuse::BASE_DETONATION_BD(300, "Base Detonation (BD)");
Fuse Fuse::CONTACT(1000, "Contact");
Fuse Fuse::CONTACT_INSTANT_IMPACT(1100, "Contact, Instant (Impact)");
Fuse Fuse::CONTACT_DELAYED(1200, "Contact, Delayed");
Fuse Fuse::X_10_MS_DELAY(1201, "10 ms delay");
Fuse Fuse::X_20_MS_DELAY(1202, "20 ms delay");
Fuse Fuse::X_50_MS_DELAY(1205, "50 ms delay");
Fuse Fuse::X_60_MS_DELAY(1206, "60 ms delay");
Fuse Fuse::X_100_MS_DELAY(1210, "100 ms delay");
Fuse Fuse::X_125_MS_DELAY(1212, "125 ms delay");
Fuse Fuse::X_250_MS_DELAY(1225, "250 ms delay");
Fuse Fuse::CONTACT_ELECTRONIC_OBLIQUE_CONTACT(1300, "Contact, Electronic (Oblique Contact)");
Fuse Fuse::CONTACT_GRAZE(1400, "Contact, Graze");
Fuse Fuse::CONTACT_CRUSH(1500, "Contact, Crush");
Fuse Fuse::CONTACT_HYDROSTATIC(1600, "Contact, Hydrostatic");
Fuse Fuse::CONTACT_MECHANICAL(1700, "Contact, Mechanical");
Fuse Fuse::CONTACT_CHEMICAL(1800, "Contact, Chemical");
Fuse Fuse::CONTACT_PIEZOELECTRIC(1900, "Contact, Piezoelectric");
Fuse Fuse::CONTACT_POINT_INITIATING(1910, "Contact, Point Initiating");
Fuse Fuse::CONTACT_POINT_INITIATING_BASE_DETONATING(1920, "Contact, Point Initiating, Base Detonating");
Fuse Fuse::CONTACT_BASE_DETONATING(1930, "Contact, Base Detonating");
Fuse Fuse::CONTACT_BALLISTIC_CAP_AND_BASE(1940, "Contact, Ballistic Cap and Base");
Fuse Fuse::CONTACT_BASE(1950, "Contact, Base");
Fuse Fuse::CONTACT_NOSE(1960, "Contact, Nose");
Fuse Fuse::CONTACT_FITTED_IN_STANDOFF_PROBE(1970, "Contact, Fitted in Standoff Probe");
Fuse Fuse::CONTACT_NON_ALIGNED(1980, "Contact, Non-aligned");
Fuse Fuse::TIMED(2000, "Timed");
Fuse Fuse::TIMED_PROGRAMMABLE(2100, "Timed, Programmable");
Fuse Fuse::TIMED_BURNOUT(2200, "Timed, Burnout");
Fuse Fuse::TIMED_PYROTECHNIC(2300, "Timed, Pyrotechnic");
Fuse Fuse::TIMED_ELECTRONIC(2400, "Timed, Electronic");
Fuse Fuse::TIMED_BASE_DELAY(2500, "Timed, Base Delay");
Fuse Fuse::TIMED_REINFORCED_NOSE_IMPACT_DELAY(2600, "Timed, Reinforced Nose Impact Delay");
Fuse Fuse::TIMED_SHORT_DELAY_IMPACT(2700, "Timed, Short Delay Impact");
Fuse Fuse::X_10_MS_DELAY_1(2701, "10 ms delay");
Fuse Fuse::X_20_MS_DELAY_2(2702, "20 ms delay");
Fuse Fuse::X_50_MS_DELAY_3(2705, "50 ms delay");
Fuse Fuse::X_60_MS_DELAY_4(2706, "60 ms delay");
Fuse Fuse::X_100_MS_DELAY_5(2710, "100 ms delay");
Fuse Fuse::X_125_MS_DELAY_6(2712, "125 ms delay");
Fuse Fuse::X_250_MS_DELAY_7(2725, "250 ms delay");
Fuse Fuse::TIMED_NOSE_MOUNTED_VARIABLE_DELAY(2800, "Timed, Nose Mounted Variable Delay");
Fuse Fuse::TIMED_LONG_DELAY_SIDE(2900, "Timed, Long Delay Side");
Fuse Fuse::TIMED_SELECTABLE_DELAY(2910, "Timed, Selectable Delay");
Fuse Fuse::TIMED_IMPACT(2920, "Timed, Impact");
Fuse Fuse::TIMED_SEQUENCE(2930, "Timed, Sequence");
Fuse Fuse::PROXIMITY(3000, "Proximity");
Fuse Fuse::PROXIMITY_ACTIVE_LASER(3100, "Proximity, Active Laser");
Fuse Fuse::PROXIMITY_MAGNETIC_MAGPOLARITY(3200, "Proximity, Magnetic (Magpolarity)");
Fuse Fuse::PROXIMITY_ACTIVE_RADAR_DOPPLER_RADAR(3300, "Proximity, Active Radar (Doppler Radar)");
Fuse Fuse::PROXIMITY_RADIO_FREQUENCY_RF(3400, "Proximity, Radio Frequency (RF)");
Fuse Fuse::PROXIMITY_PROGRAMMABLE(3500, "Proximity, Programmable");
Fuse Fuse::PROXIMITY_PROGRAMMABLE_PREFRAGMENTED(3600, "Proximity, Programmable, Prefragmented");
Fuse Fuse::PROXIMITY_INFRARED(3700, "Proximity, Infrared");
Fuse Fuse::COMMAND(4000, "Command");
Fuse Fuse::COMMAND_ELECTRONIC_REMOTELY_SET(4100, "Command, Electronic, Remotely Set");
Fuse Fuse::ALTITUDE(5000, "Altitude");
Fuse Fuse::ALTITUDE_RADIO_ALTIMETER(5100, "Altitude, Radio Altimeter");
Fuse Fuse::ALTITUDE_AIR_BURST(5200, "Altitude, Air Burst");
Fuse Fuse::DEPTH(6000, "Depth");
Fuse Fuse::ACOUSTIC(7000, "Acoustic");
Fuse Fuse::PRESSURE(8000, "Pressure");
Fuse Fuse::PRESSURE_DELAY(8010, "Pressure, Delay");
Fuse Fuse::INERT(8100, "Inert");
Fuse Fuse::DUMMY(8110, "Dummy");
Fuse Fuse::PRACTICE(8120, "Practice");
Fuse Fuse::PLUG_REPRESENTING(8130, "Plug Representing");
Fuse Fuse::TRAINING(8150, "Training");
Fuse Fuse::PYROTECHNIC(9000, "Pyrotechnic");
Fuse Fuse::PYROTECHNIC_DELAY(9010, "Pyrotechnic, Delay");
Fuse Fuse::ELECTRO_OPTICAL(9100, "Electro-optical");
Fuse Fuse::ELECTROMECHANICAL(9110, "Electromechanical");
Fuse Fuse::ELECTROMECHANICAL_NOSE(9120, "Electromechanical, Nose");
Fuse Fuse::STRIKERLESS(9200, "Strikerless");
Fuse Fuse::STRIKERLESS_NOSE_IMPACT(9210, "Strikerless, Nose Impact");
Fuse Fuse::STRIKERLESS_COMPRESSION_IGNITION(9220, "Strikerless, Compression-Ignition");
Fuse Fuse::COMPRESSION_IGNITION(9300, "Compression-Ignition");
Fuse Fuse::COMPRESSION_IGNITION_STRIKERLESS_NOSE_IMPACT(9310, "Compression-Ignition, Strikerless, Nose Impact");
Fuse Fuse::PERCUSSION(9400, "Percussion");
Fuse Fuse::PERCUSSION_INSTANTANEOUS(9410, "Percussion, Instantaneous");
Fuse Fuse::ELECTRONIC(9500, "Electronic");
Fuse Fuse::ELECTRONIC_INTERNALLY_MOUNTED(9510, "Electronic, Internally Mounted");
Fuse Fuse::ELECTRONIC_RANGE_SETTING(9520, "Electronic, Range Setting");
Fuse Fuse::ELECTRONIC_PROGRAMMED(9530, "Electronic, Programmed");
Fuse Fuse::MECHANICAL(9600, "Mechanical");
Fuse Fuse::MECHANICAL_NOSE(9610, "Mechanical, Nose");
Fuse Fuse::MECHANICAL_TAIL(9620, "Mechanical, Tail");


Fuse::Fuse(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Fuse* Fuse::findEnumeration(int aVal) {
  Fuse* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Fuse::getDescriptionForValue(int aVal) {
  Fuse* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Fuse Fuse::getEnumerationForValue(int aVal) throw(EnumException) {
  Fuse* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Fuse";
    throw EnumException("Fuse", aVal, ss.str());
  }
};

bool Fuse::enumerationForValueExists(int aVal) {
  Fuse* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Fuse::enumContainer Fuse::getEnumerations() {
  return (enumerations);
};

Fuse& Fuse::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

