#ifndef MAJORMODULATION__H
#define MAJORMODULATION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class MajorModulation : public Enumeration {
  public:
    static MajorModulation OTHER;
    static MajorModulation AMPLITUDE;
    static MajorModulation AMPLITUDE_AND_ANGLE;
    static MajorModulation ANGLE;
    static MajorModulation COMBINATION;
    static MajorModulation PULSE;
    static MajorModulation UNMODULATED;
    static MajorModulation CARRIER_PHASE_SHIFT_MODULATION_CPSM;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static MajorModulation getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,MajorModulation*> enumContainer;
    static enumContainer getEnumerations();

    MajorModulation& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  MajorModulation(int value, std::string description);

	  static MajorModulation* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* MajorModulation */


}  /* namespace DIS */

#endif /* MAJORMODULATION__H */

