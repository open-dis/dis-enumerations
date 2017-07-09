#ifndef NATURE__H
#define NATURE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Nature : public Enumeration {
  public:
    static Nature OTHER;
    static Nature HOST_FIREABLE_MUNITION;
    static Nature MUNITION_CARRIED_AS_CARGO;
    static Nature FUEL_CARRIED_AS_CARGO;
    static Nature GUNMOUNT_ATTACHED_TO_HOST;
    static Nature COMPUTER_GENERATED_FORCES_CARRIED_AS_CARGO;
    static Nature VEHICLE_CARRIED_AS_CARGO;
    static Nature EMITTER_MOUNTED_ON_HOST;
    static Nature MOBILE_COMMAND_AND_CONTROL_ENTITY_CARRIED_ABOARD_HOST;
    static Nature ENTITY_STATIONED_AT_POSITION_WITH_RESPECT_TO_HOST;
    static Nature TEAM_MEMBER_IN_FORMATION_WITH;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Nature getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Nature*> enumContainer;
    static enumContainer getEnumerations();

    Nature& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Nature(int value, std::string description);

	  static Nature* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Nature */


}  /* namespace DIS */

#endif /* NATURE__H */

