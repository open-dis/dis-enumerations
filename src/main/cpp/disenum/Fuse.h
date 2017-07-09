#ifndef FUSE__H
#define FUSE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Fuse : public Enumeration {
  public:
    static Fuse OTHER;
    static Fuse INTELLIGENT_INFLUENCE;
    static Fuse SENSOR;
    static Fuse SELF_DESTRUCT;
    static Fuse ULTRA_QUICK;
    static Fuse BODY;
    static Fuse DEEP_INTRUSION;
    static Fuse MULTIFUNCTION;
    static Fuse POINT_DETONATION_PD;
    static Fuse BASE_DETONATION_BD;
    static Fuse CONTACT;
    static Fuse CONTACT_INSTANT_IMPACT;
    static Fuse CONTACT_DELAYED;
    static Fuse X_10_MS_DELAY;
    static Fuse X_20_MS_DELAY;
    static Fuse X_50_MS_DELAY;
    static Fuse X_60_MS_DELAY;
    static Fuse X_100_MS_DELAY;
    static Fuse X_125_MS_DELAY;
    static Fuse X_250_MS_DELAY;
    static Fuse CONTACT_ELECTRONIC_OBLIQUE_CONTACT;
    static Fuse CONTACT_GRAZE;
    static Fuse CONTACT_CRUSH;
    static Fuse CONTACT_HYDROSTATIC;
    static Fuse CONTACT_MECHANICAL;
    static Fuse CONTACT_CHEMICAL;
    static Fuse CONTACT_PIEZOELECTRIC;
    static Fuse CONTACT_POINT_INITIATING;
    static Fuse CONTACT_POINT_INITIATING_BASE_DETONATING;
    static Fuse CONTACT_BASE_DETONATING;
    static Fuse CONTACT_BALLISTIC_CAP_AND_BASE;
    static Fuse CONTACT_BASE;
    static Fuse CONTACT_NOSE;
    static Fuse CONTACT_FITTED_IN_STANDOFF_PROBE;
    static Fuse CONTACT_NON_ALIGNED;
    static Fuse TIMED;
    static Fuse TIMED_PROGRAMMABLE;
    static Fuse TIMED_BURNOUT;
    static Fuse TIMED_PYROTECHNIC;
    static Fuse TIMED_ELECTRONIC;
    static Fuse TIMED_BASE_DELAY;
    static Fuse TIMED_REINFORCED_NOSE_IMPACT_DELAY;
    static Fuse TIMED_SHORT_DELAY_IMPACT;
    static Fuse X_10_MS_DELAY_1;
    static Fuse X_20_MS_DELAY_2;
    static Fuse X_50_MS_DELAY_3;
    static Fuse X_60_MS_DELAY_4;
    static Fuse X_100_MS_DELAY_5;
    static Fuse X_125_MS_DELAY_6;
    static Fuse X_250_MS_DELAY_7;
    static Fuse TIMED_NOSE_MOUNTED_VARIABLE_DELAY;
    static Fuse TIMED_LONG_DELAY_SIDE;
    static Fuse TIMED_SELECTABLE_DELAY;
    static Fuse TIMED_IMPACT;
    static Fuse TIMED_SEQUENCE;
    static Fuse PROXIMITY;
    static Fuse PROXIMITY_ACTIVE_LASER;
    static Fuse PROXIMITY_MAGNETIC_MAGPOLARITY;
    static Fuse PROXIMITY_ACTIVE_RADAR_DOPPLER_RADAR;
    static Fuse PROXIMITY_RADIO_FREQUENCY_RF;
    static Fuse PROXIMITY_PROGRAMMABLE;
    static Fuse PROXIMITY_PROGRAMMABLE_PREFRAGMENTED;
    static Fuse PROXIMITY_INFRARED;
    static Fuse COMMAND;
    static Fuse COMMAND_ELECTRONIC_REMOTELY_SET;
    static Fuse ALTITUDE;
    static Fuse ALTITUDE_RADIO_ALTIMETER;
    static Fuse ALTITUDE_AIR_BURST;
    static Fuse DEPTH;
    static Fuse ACOUSTIC;
    static Fuse PRESSURE;
    static Fuse PRESSURE_DELAY;
    static Fuse INERT;
    static Fuse DUMMY;
    static Fuse PRACTICE;
    static Fuse PLUG_REPRESENTING;
    static Fuse TRAINING;
    static Fuse PYROTECHNIC;
    static Fuse PYROTECHNIC_DELAY;
    static Fuse ELECTRO_OPTICAL;
    static Fuse ELECTROMECHANICAL;
    static Fuse ELECTROMECHANICAL_NOSE;
    static Fuse STRIKERLESS;
    static Fuse STRIKERLESS_NOSE_IMPACT;
    static Fuse STRIKERLESS_COMPRESSION_IGNITION;
    static Fuse COMPRESSION_IGNITION;
    static Fuse COMPRESSION_IGNITION_STRIKERLESS_NOSE_IMPACT;
    static Fuse PERCUSSION;
    static Fuse PERCUSSION_INSTANTANEOUS;
    static Fuse ELECTRONIC;
    static Fuse ELECTRONIC_INTERNALLY_MOUNTED;
    static Fuse ELECTRONIC_RANGE_SETTING;
    static Fuse ELECTRONIC_PROGRAMMED;
    static Fuse MECHANICAL;
    static Fuse MECHANICAL_NOSE;
    static Fuse MECHANICAL_TAIL;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Fuse getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Fuse*> enumContainer;
    static enumContainer getEnumerations();

    Fuse& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Fuse(int value, std::string description);

	  static Fuse* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Fuse */


}  /* namespace DIS */

#endif /* FUSE__H */

