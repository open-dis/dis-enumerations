#ifndef UKWEAPONSFORLIFEFORMS__H
#define UKWEAPONSFORLIFEFORMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class UKWeaponsForLifeForms : public Enumeration {
  public:
    static UKWeaponsForLifeForms LAW_80;
    static UKWeaponsForLifeForms BLOWPIPE;
    static UKWeaponsForLifeForms JAVELIN;
    static UKWeaponsForLifeForms X_51_MM_MORTAR;
    static UKWeaponsForLifeForms SLR_762_MM_RIFLE;
    static UKWeaponsForLifeForms STERLING_9_MM_SUBMACHINE_GUN;
    static UKWeaponsForLifeForms L7A2_GENERAL_PURPOSE_MG;
    static UKWeaponsForLifeForms L6_WOMBAT_RECOILLESS_RIFLE;
    static UKWeaponsForLifeForms CARL_GUSTAV_89_MM_RECOILLESS_RIFLE;
    static UKWeaponsForLifeForms SA80_INDIVIDUAL_LIGHT_SUPPORT_WEAPON;
    static UKWeaponsForLifeForms TRIGAT;
    static UKWeaponsForLifeForms MILAN_AT_MISSILE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static UKWeaponsForLifeForms getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,UKWeaponsForLifeForms*> enumContainer;
    static enumContainer getEnumerations();

    UKWeaponsForLifeForms& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  UKWeaponsForLifeForms(int value, std::string description);

	  static UKWeaponsForLifeForms* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* UKWeaponsForLifeForms */


}  /* namespace DIS */

#endif /* UKWEAPONSFORLIFEFORMS__H */

