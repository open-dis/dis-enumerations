#ifndef PLATFORMAIR__H
#define PLATFORMAIR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PlatformAir : public Enumeration {
  public:
    static PlatformAir OTHER;
    static PlatformAir FIGHTER_AIR_DEFENSE;
    static PlatformAir ATTACK_STRIKE;
    static PlatformAir BOMBER;
    static PlatformAir CARGO_TANKER;
    static PlatformAir ASW_PATROL_OBSERVATION;
    static PlatformAir ELECTRONIC_WARFARE_EW;
    static PlatformAir RECONNAISSANCE;
    static PlatformAir SURVEILLANCE_C2_AIRBORNE_EARLY_WARNING;
    static PlatformAir ATTACK_HELICOPTER;
    static PlatformAir UTILITY_HELICOPTER;
    static PlatformAir ANTISUBMARINE_WARFARE_PATROL_HELICOPTER;
    static PlatformAir CARGO_HELICOPTER;
    static PlatformAir OBSERVATION_HELICOPTER;
    static PlatformAir SPECIAL_OPERATIONS_HELICOPTER;
    static PlatformAir TRAINER;
    static PlatformAir UNMANNED;
    static PlatformAir NON_COMBATANT_COMMERCIAL_AIRCRAFT;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PlatformAir getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PlatformAir*> enumContainer;
    static enumContainer getEnumerations();

    PlatformAir& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PlatformAir(int value, std::string description);

	  static PlatformAir* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PlatformAir */


}  /* namespace DIS */

#endif /* PLATFORMAIR__H */

