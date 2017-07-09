#ifndef WEAPONS__H
#define WEAPONS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Weapons : public Enumeration {
  public:
    static Weapons GUN_ELEVATION_DRIVE;
    static Weapons GUN_STABILIZATION_SYSTEM;
    static Weapons GUNNERS_PRIMARY_SIGHT_GPS;
    static Weapons COMMANDERS_EXTENSION_TO_THE_GPS;
    static Weapons LOADING_MECHANISM;
    static Weapons GUNNERS_AUXILIARY_SIGHT;
    static Weapons GUNNERS_CONTROL_PANEL;
    static Weapons GUNNERS_CONTROL_ASSEMBLY_HANDLES;
    static Weapons COMMANDERS_CONTROL_HANDLES_ASSEMBLY;
    static Weapons COMMANDERS_WEAPON_STATION;
    static Weapons COMMANDERS_INDEPENDENT_THERMAL_VIEWER_CITV;
    static Weapons GENERAL_WEAPONS;
    static Weapons MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Weapons getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Weapons*> enumContainer;
    static enumContainer getEnumerations();

    Weapons& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Weapons(int value, std::string description);

	  static Weapons* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Weapons */


}  /* namespace DIS */

#endif /* WEAPONS__H */

