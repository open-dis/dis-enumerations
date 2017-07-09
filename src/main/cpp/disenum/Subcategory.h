#ifndef SUBCATEGORY__H
#define SUBCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Subcategory : public Enumeration {
  public:
    static Subcategory OTHER;
    static Subcategory CAVALRY_TROOP;
    static Subcategory ARMOR;
    static Subcategory INFANTRY;
    static Subcategory MECHANIZED_INFANTRY;
    static Subcategory CAVALRY;
    static Subcategory ARMORED_CAVALRY;
    static Subcategory ARTILLERY;
    static Subcategory SELF_PROPELLED_ARTILLERY;
    static Subcategory CLOSE_AIR_SUPPORT;
    static Subcategory ENGINEER;
    static Subcategory AIR_DEFENSE_ARTILLERY;
    static Subcategory ANTI_TANK;
    static Subcategory ARMY_AVIATION_FIXED_WING;
    static Subcategory ARMY_AVIATION_ROTARY_WING;
    static Subcategory ARMY_ATTACK_HELICOPTER;
    static Subcategory AIR_CAVALRY;
    static Subcategory ARMOR_HEAVY_TASK_FORCE;
    static Subcategory MOTORIZED_RIFLE;
    static Subcategory MECHANIZED_HEAVY_TASK_FORCE;
    static Subcategory COMMAND_POST;
    static Subcategory CEWI;
    static Subcategory TANK_ONLY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Subcategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Subcategory*> enumContainer;
    static enumContainer getEnumerations();

    Subcategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Subcategory(int value, std::string description);

	  static Subcategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Subcategory */


}  /* namespace DIS */

#endif /* SUBCATEGORY__H */

