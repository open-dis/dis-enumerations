#ifndef SENSORTYPES__H
#define SENSORTYPES__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SensorTypes : public Enumeration {
  public:
    static SensorTypes OTHER;
    static SensorTypes OPTICAL;
    static SensorTypes FLIR;
    static SensorTypes RADAR;
    static SensorTypes MAGNETIC;
    static SensorTypes LASER;
    static SensorTypes SONAR;
    static SensorTypes PHYSICAL;
    static SensorTypes MULTISPECTRAL;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SensorTypes getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SensorTypes*> enumContainer;
    static enumContainer getEnumerations();

    SensorTypes& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SensorTypes(int value, std::string description);

	  static SensorTypes* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SensorTypes */


}  /* namespace DIS */

#endif /* SENSORTYPES__H */

