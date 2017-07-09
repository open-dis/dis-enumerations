#ifndef HYDRAULICSYSTEMSANDACTUATORS__H
#define HYDRAULICSYSTEMSANDACTUATORS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class HydraulicSystemsAndActuators : public Enumeration {
  public:
    static HydraulicSystemsAndActuators WATER_SUPPLY;
    static HydraulicSystemsAndActuators COOLING_SYSTEM;
    static HydraulicSystemsAndActuators WINCHES;
    static HydraulicSystemsAndActuators CATAPULTS;
    static HydraulicSystemsAndActuators CRANES;
    static HydraulicSystemsAndActuators LAUNCHERS;
    static HydraulicSystemsAndActuators MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static HydraulicSystemsAndActuators getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,HydraulicSystemsAndActuators*> enumContainer;
    static enumContainer getEnumerations();

    HydraulicSystemsAndActuators& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  HydraulicSystemsAndActuators(int value, std::string description);

	  static HydraulicSystemsAndActuators* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* HydraulicSystemsAndActuators */


}  /* namespace DIS */

#endif /* HYDRAULICSYSTEMSANDACTUATORS__H */

