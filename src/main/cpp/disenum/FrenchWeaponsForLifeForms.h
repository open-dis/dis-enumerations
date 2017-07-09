#ifndef FRENCHWEAPONSFORLIFEFORMS__H
#define FRENCHWEAPONSFORLIFEFORMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class FrenchWeaponsForLifeForms : public Enumeration {
  public:
    static FrenchWeaponsForLifeForms ACL_STRIM;
    static FrenchWeaponsForLifeForms MISTRAL_MISSILE;
    static FrenchWeaponsForLifeForms MILAN_AT_MISSILE;
    static FrenchWeaponsForLifeForms LRAC_F1_89_MM_AT_ROCKET_LAUNCHER;
    static FrenchWeaponsForLifeForms FA_MAS_RIFLE;
    static FrenchWeaponsForLifeForms AA_52_MACHINE_GUN;
    static FrenchWeaponsForLifeForms X_58_MM_RIFLE_GRENADE;
    static FrenchWeaponsForLifeForms FR_F1_SNIPER_RIFLE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static FrenchWeaponsForLifeForms getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,FrenchWeaponsForLifeForms*> enumContainer;
    static enumContainer getEnumerations();

    FrenchWeaponsForLifeForms& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  FrenchWeaponsForLifeForms(int value, std::string description);

	  static FrenchWeaponsForLifeForms* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* FrenchWeaponsForLifeForms */


}  /* namespace DIS */

#endif /* FRENCHWEAPONSFORLIFEFORMS__H */

