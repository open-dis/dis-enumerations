#ifndef GERMANWEAPONSFORLIFEFORMS__H
#define GERMANWEAPONSFORLIFEFORMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class GermanWeaponsForLifeForms : public Enumeration {
  public:
    static GermanWeaponsForLifeForms G3_RIFLE;
    static GermanWeaponsForLifeForms G11_RIFLE;
    static GermanWeaponsForLifeForms P1_PISTOL;
    static GermanWeaponsForLifeForms MG3_MACHINE_GUN;
    static GermanWeaponsForLifeForms MILAN_MISSILE;
    static GermanWeaponsForLifeForms MP1_UZI_SUBMACHINE_GUN;
    static GermanWeaponsForLifeForms PANZERFAUST_3_LIGHT_ANTI_TANK_WEAPON;
    static GermanWeaponsForLifeForms DM19_HAND_GRENADE;
    static GermanWeaponsForLifeForms DM29_HAND_GRENADE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static GermanWeaponsForLifeForms getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,GermanWeaponsForLifeForms*> enumContainer;
    static enumContainer getEnumerations();

    GermanWeaponsForLifeForms& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  GermanWeaponsForLifeForms(int value, std::string description);

	  static GermanWeaponsForLifeForms* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* GermanWeaponsForLifeForms */


}  /* namespace DIS */

#endif /* GERMANWEAPONSFORLIFEFORMS__H */

