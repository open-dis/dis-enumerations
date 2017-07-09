#ifndef ELECTRONICS__H
#define ELECTRONICS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Electronics : public Enumeration {
  public:
    static Electronics ELECTRONIC_WARFARE_SYSTEMS;
    static Electronics DETECTION_SYSTEMS;
    static Electronics RADIO_FREQUENCY;
    static Electronics MICROWAVE;
    static Electronics INFRARED;
    static Electronics LASER;
    static Electronics RANGE_FINDERS;
    static Electronics RANGE_ONLY_RADAR;
    static Electronics LASER_RANGE_FINDER;
    static Electronics ELECTRONIC_SYSTEMS;
    static Electronics RADIO_FREQUENCY_1;
    static Electronics MICROWAVE_2;
    static Electronics INFRARED_3;
    static Electronics LASER_4;
    static Electronics RADIOS;
    static Electronics COMMUNICATION_SYSTEMS;
    static Electronics INTERCOMS;
    static Electronics ENCODERS;
    static Electronics ENCRYPTION_DEVICES;
    static Electronics DECODERS;
    static Electronics DECRYPTION_DEVICES;
    static Electronics COMPUTERS;
    static Electronics NAVIGATION_AND_CONTROL_SYSTEMS;
    static Electronics FIRE_CONTROL_SYSTEMS;
    static Electronics MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Electronics getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Electronics*> enumContainer;
    static enumContainer getEnumerations();

    Electronics& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Electronics(int value, std::string description);

	  static Electronics* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Electronics */


}  /* namespace DIS */

#endif /* ELECTRONICS__H */

