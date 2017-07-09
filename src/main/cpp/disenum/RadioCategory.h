#ifndef RADIOCATEGORY__H
#define RADIOCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RadioCategory : public Enumeration {
  public:
    static RadioCategory OTHER;
    static RadioCategory VOICE_TRANSMISSION_RECEPTION;
    static RadioCategory DATA_LINK_TRANSMISSION_RECEPTION;
    static RadioCategory VOICE_AND_DATA_LINK_TRANSMISSION_RECEPTION;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_GLIDESLOPE_TRANSMITTER;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_LOCALIZER_TRANSMITTER;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_OUTER_MARKER_BEACON;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_MIDDLE_MARKER_BEACON;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_INNER_MARKER_BEACON;
    static RadioCategory INSTRUMENTED_LANDING_SYSTEM_ILS_RECEIVER_PLATFORM_RADIO;
    static RadioCategory TACTICAL_AIR_NAVIGATION_TACAN_TRANSMITTER_GROUND_FIXED_EQUIPMENT;
    static RadioCategory TACTICAL_AIR_NAVIGATION_TACAN_RECEIVER_MOVING_PLATFORM_EQUIPMENT;
    static RadioCategory TACTICAL_AIR_NAVIGATION_TACAN_TRANSMITTER_RECEIVER_MOVING_PLATFORM_EQUIPMENT;
    static RadioCategory VARIABLE_OMNI_RANGING_VOR_TRANSMITTER_GROUND_FIXED_EQUIPMENT;
    static RadioCategory VARIABLE_OMNI_RANGING_VOR_WITH_DISTANCE_MEASURING_EQUIPMENT_DME_TRANSMITTER_GROUND_FIXED_EQUIPMENT;
    static RadioCategory COMBINED_VOR_ILS_RECEIVER_MOVING_PLATFORM_EQUIPMENT;
    static RadioCategory COMBINED_VOR_TACAN_VORTAC_TRANSMITTER;
    static RadioCategory NON_DIRECTIONAL_BEACON_NDB_TRANSMITTER;
    static RadioCategory NON_DIRECTIONAL_BEACON_NDB_RECEIVER;
    static RadioCategory NON_DIRECTIONAL_BEACON_NDB_WITH_DISTANCE_MEASURING_EQUIPMENT_DME_TRANSMITTER;
    static RadioCategory DISTANCE_MEASURING_EQUIPMENT_DME;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RadioCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RadioCategory*> enumContainer;
    static enumContainer getEnumerations();

    RadioCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RadioCategory(int value, std::string description);

	  static RadioCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RadioCategory */


}  /* namespace DIS */

#endif /* RADIOCATEGORY__H */

