#ifndef DETAILEDMODAMPMOD__H
#define DETAILEDMODAMPMOD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModAmpMod : public Enumeration {
  public:
    static DetailedModAmpMod OTHER;
    static DetailedModAmpMod AFSK_AUDIO_FREQUENCY_SHIFT_KEYING;
    static DetailedModAmpMod AM_AMPLITUDE_MODULATION;
    static DetailedModAmpMod CW_CONTINUOUS_WAVE_MODULATION;
    static DetailedModAmpMod DSB_DOUBLE_SIDEBAND;
    static DetailedModAmpMod ISB_INDEPENDENT_SIDEBAND;
    static DetailedModAmpMod LSB_SINGLE_BAND_SUPPRESSED_CARRIER_LOWER_SIDEBAND_MODE;
    static DetailedModAmpMod SSB_FULL_SINGLE_SIDEBAND_FULL_CARRIER;
    static DetailedModAmpMod SSB_REDUC_SINGLE_BAND_REDUCED_CARRIER;
    static DetailedModAmpMod USB_SINGLE_BAND_SUPPRESSED_CARRIER_UPPER_SIDEBAND_MODE;
    static DetailedModAmpMod VSB_VESTIGIAL_SIDEBAND;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModAmpMod getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModAmpMod*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModAmpMod& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModAmpMod(int value, std::string description);

	  static DetailedModAmpMod* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModAmpMod */


}  /* namespace DIS */

#endif /* DETAILEDMODAMPMOD__H */

