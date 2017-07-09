#ifndef EVENTTYPE__H
#define EVENTTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class EventType : public Enumeration {
  public:
    static EventType OTHER;
    static EventType MISSING_DESCRIPTION;
    static EventType RAN_OUT_OF_AMMUNITION;
    static EventType KILLED_IN_ACTION;
    static EventType DAMAGE;
    static EventType MOBILITY_DISABLED;
    static EventType FIRE_DISABLED;
    static EventType RAN_OUT_OF_FUEL;
    static EventType ENTITY_INITIALIZATION;
    static EventType REQUEST_FOR_INDIRECT_FIRE_OR_CAS_MISSION;
    static EventType INDIRECT_FIRE_OR_CAS_FIRE;
    static EventType MINEFIELD_ENTRY;
    static EventType MINEFIELD_DETONATION;
    static EventType VEHICLE_MASTER_POWER_ON;
    static EventType VEHICLE_MASTER_POWER_OFF;
    static EventType AGGREGATE_STATE_CHANGE_REQUESTED;
    static EventType PREVENT_COLLISION_DETONATION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static EventType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,EventType*> enumContainer;
    static enumContainer getEnumerations();

    EventType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  EventType(int value, std::string description);

	  static EventType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* EventType */


}  /* namespace DIS */

#endif /* EVENTTYPE__H */

