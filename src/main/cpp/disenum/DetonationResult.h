#ifndef DETONATIONRESULT__H
#define DETONATIONRESULT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetonationResult : public Enumeration {
  public:
    static DetonationResult OTHER;
    static DetonationResult ENTITY_IMPACT;
    static DetonationResult ENTITY_PROXIMATE_DETONATION;
    static DetonationResult GROUND_IMPACT;
    static DetonationResult GROUND_PROXIMATE_DETONATION;
    static DetonationResult DETONATION;
    static DetonationResult NONE_OR_NO_DETONATION_DUD;
    static DetonationResult HE_HIT_SMALL;
    static DetonationResult HE_HIT_MEDIUM;
    static DetonationResult HE_HIT_LARGE;
    static DetonationResult ARMOR_PIERCING_HIT;
    static DetonationResult DIRT_BLAST_SMALL;
    static DetonationResult DIRT_BLAST_MEDIUM;
    static DetonationResult DIRT_BLAST_LARGE;
    static DetonationResult WATER_BLAST_SMALL;
    static DetonationResult WATER_BLAST_MEDIUM;
    static DetonationResult WATER_BLAST_LARGE;
    static DetonationResult AIR_HIT;
    static DetonationResult BUILDING_HIT_SMALL;
    static DetonationResult BUILDING_HIT_MEDIUM;
    static DetonationResult BUILDING_HIT_LARGE;
    static DetonationResult MINE_CLEARING_LINE_CHARGE;
    static DetonationResult ENVIRONMENT_OBJECT_IMPACT;
    static DetonationResult ENVIRONMENT_OBJECT_PROXIMATE_DETONATION;
    static DetonationResult WATER_IMPACT;
    static DetonationResult AIR_BURST;
    static DetonationResult KILL_WITH_FRAGMENT_TYPE_1;
    static DetonationResult KILL_WITH_FRAGMENT_TYPE_2;
    static DetonationResult KILL_WITH_FRAGMENT_TYPE_3;
    static DetonationResult KILL_WITH_FRAGMENT_TYPE_1_AFTER_FLY_OUT_FAILURE;
    static DetonationResult KILL_WITH_FRAGMENT_TYPE_2_AFTER_FLY_OUT_FAILURE;
    static DetonationResult MISS_DUE_TO_FLY_OUT_FAILURE;
    static DetonationResult MISS_DUE_TO_END_GAME_FAILURE;
    static DetonationResult MISS_DUE_TO_FLY_OUT_AND_END_GAME_FAILURE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetonationResult getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetonationResult*> enumContainer;
    static enumContainer getEnumerations();

    DetonationResult& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetonationResult(int value, std::string description);

	  static DetonationResult* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetonationResult */


}  /* namespace DIS */

#endif /* DETONATIONRESULT__H */

