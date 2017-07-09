#ifndef SENSOREMITTERCATEGORY__H
#define SENSOREMITTERCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SensorEmitterCategory : public Enumeration {
  public:
    static SensorEmitterCategory OTHER;
    static SensorEmitterCategory MULTI_SPECTRAL;
    static SensorEmitterCategory RF_ACTIVE;
    static SensorEmitterCategory RF_PASSIVE_INTERCEPT_AND_DF;
    static SensorEmitterCategory OPTICAL_DIRECT_VIEWING_WITH_OR_WITHOUT_OPTICS;
    static SensorEmitterCategory ELECTRO_OPTICAL;
    static SensorEmitterCategory SEISMIC;
    static SensorEmitterCategory CHEMICAL_POINT_DETECTOR;
    static SensorEmitterCategory CHEMICAL_STANDOFF;
    static SensorEmitterCategory THERMAL_TEMPERATURE_SENSING;
    static SensorEmitterCategory ACOUSTIC_ACTIVE;
    static SensorEmitterCategory ACOUSTIC_PASSIVE;
    static SensorEmitterCategory CONTACT_PRESSURE_PHYSICAL_HYDROSTATIC_BAROMETRIC;
    static SensorEmitterCategory ELECTRO_MAGNETIC_RADIATION_GAMMA_RADIATION;
    static SensorEmitterCategory PARTICLE_RADIATION_NEUTRONS_ALPHA_BETA_PARTICLES;
    static SensorEmitterCategory MAGNETIC;
    static SensorEmitterCategory GRAVITATIONAL;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SensorEmitterCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SensorEmitterCategory*> enumContainer;
    static enumContainer getEnumerations();

    SensorEmitterCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SensorEmitterCategory(int value, std::string description);

	  static SensorEmitterCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SensorEmitterCategory */


}  /* namespace DIS */

#endif /* SENSOREMITTERCATEGORY__H */

