#include <sstream>
#include <cstddef>
#include <disenum/SensorEmitterCategory.h>

namespace DIS {


hashMap<int,SensorEmitterCategory*> SensorEmitterCategory::enumerations;

SensorEmitterCategory SensorEmitterCategory::OTHER(0, "Other");
SensorEmitterCategory SensorEmitterCategory::MULTI_SPECTRAL(1, "Multi-spectral");
SensorEmitterCategory SensorEmitterCategory::RF_ACTIVE(2, "RF Active");
SensorEmitterCategory SensorEmitterCategory::RF_PASSIVE_INTERCEPT_AND_DF(3, "RF Passive (intercept and DF)");
SensorEmitterCategory SensorEmitterCategory::OPTICAL_DIRECT_VIEWING_WITH_OR_WITHOUT_OPTICS(4, "Optical (direct viewing with or without optics)");
SensorEmitterCategory SensorEmitterCategory::ELECTRO_OPTICAL(5, "Electro-Optical");
SensorEmitterCategory SensorEmitterCategory::SEISMIC(6, "Seismic");
SensorEmitterCategory SensorEmitterCategory::CHEMICAL_POINT_DETECTOR(7, "Chemical, point detector");
SensorEmitterCategory SensorEmitterCategory::CHEMICAL_STANDOFF(8, "Chemical, standoff");
SensorEmitterCategory SensorEmitterCategory::THERMAL_TEMPERATURE_SENSING(9, "Thermal (temperature sensing)");
SensorEmitterCategory SensorEmitterCategory::ACOUSTIC_ACTIVE(10, "Acoustic, Active");
SensorEmitterCategory SensorEmitterCategory::ACOUSTIC_PASSIVE(11, "Acoustic, Passive");
SensorEmitterCategory SensorEmitterCategory::CONTACT_PRESSURE_PHYSICAL_HYDROSTATIC_BAROMETRIC(12, "Contact/Pressure (physical, hydrostatic, barometric)");
SensorEmitterCategory SensorEmitterCategory::ELECTRO_MAGNETIC_RADIATION_GAMMA_RADIATION(13, "Electro-Magnetic Radiation (gamma radiation)");
SensorEmitterCategory SensorEmitterCategory::PARTICLE_RADIATION_NEUTRONS_ALPHA_BETA_PARTICLES(14, "Particle Radiation (Neutrons, alpha, beta particles)");
SensorEmitterCategory SensorEmitterCategory::MAGNETIC(15, "Magnetic");
SensorEmitterCategory SensorEmitterCategory::GRAVITATIONAL(16, "Gravitational");


SensorEmitterCategory::SensorEmitterCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SensorEmitterCategory* SensorEmitterCategory::findEnumeration(int aVal) {
  SensorEmitterCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SensorEmitterCategory::getDescriptionForValue(int aVal) {
  SensorEmitterCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SensorEmitterCategory SensorEmitterCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  SensorEmitterCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SensorEmitterCategory";
    throw EnumException("SensorEmitterCategory", aVal, ss.str());
  }
};

bool SensorEmitterCategory::enumerationForValueExists(int aVal) {
  SensorEmitterCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SensorEmitterCategory::enumContainer SensorEmitterCategory::getEnumerations() {
  return (enumerations);
};

SensorEmitterCategory& SensorEmitterCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

