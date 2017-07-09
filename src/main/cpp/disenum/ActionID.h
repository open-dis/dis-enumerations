#ifndef ACTIONID__H
#define ACTIONID__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ActionID : public Enumeration {
  public:
    static ActionID OTHER;
    static ActionID LOCAL_STORAGE_OF_THE_REQUESTED_INFORMATION;
    static ActionID INFORM_SM_OF_EVENT_RAN_OUT_OF_AMMUNITION;
    static ActionID INFORM_SM_OF_EVENT_KILLED_IN_ACTION;
    static ActionID INFORM_SM_OF_EVENT_DAMAGE;
    static ActionID INFORM_SM_OF_EVENT_MOBILITY_DISABLED;
    static ActionID INFORM_SM_OF_EVENT_FIRE_DISABLED;
    static ActionID INFORM_SM_OF_EVENT_RAN_OUT_OF_FUEL;
    static ActionID RECALL_CHECKPOINT_DATA;
    static ActionID RECALL_INITIAL_PARAMETERS;
    static ActionID INITIATE_TETHER_LEAD;
    static ActionID INITIATE_TETHER_FOLLOW;
    static ActionID UNTHETHER;
    static ActionID INITIATE_SERVICE_STATION_RESUPPLY;
    static ActionID INITIATE_TAILGATE_RESUPPLY;
    static ActionID INITIATE_HITCH_LEAD;
    static ActionID INITIATE_HITCH_FOLLOW;
    static ActionID UNHITCH;
    static ActionID MOUNT;
    static ActionID DISMOUNT;
    static ActionID START_DRC_DAILY_READINESS_CHECK;
    static ActionID STOP_DRC;
    static ActionID DATA_QUERY;
    static ActionID STATUS_REQUEST;
    static ActionID SEND_OBJECT_STATE_DATA;
    static ActionID RECONSTITUTE;
    static ActionID LOCK_SITE_CONFIGURATION;
    static ActionID UNLOCK_SITE_CONFIGURATION;
    static ActionID UPDATE_SITE_CONFIGURATION;
    static ActionID QUERY_SITE_CONFIGURATION;
    static ActionID TETHERING_INFORMATION;
    static ActionID MOUNT_INTENT;
    static ActionID ACCEPT_SUBSCRIPTION;
    static ActionID UNSUBSCRIBE;
    static ActionID TELEPORT_ENTITY;
    static ActionID CHANGE_AGGREGATE_STATE;
    static ActionID REQUEST_START_PDU;
    static ActionID WAKEUP_GET_READY_FOR_INITIALIZATION;
    static ActionID INITIALIZE_INTERNAL_PARAMETERS;
    static ActionID SEND_PLAN_DATA;
    static ActionID SYNCHRONIZE_INTERNAL_CLOCKS;
    static ActionID RUN;
    static ActionID SAVE_INTERNAL_PARAMETERS;
    static ActionID SIMULATE_MALFUNCTION;
    static ActionID JOIN_EXERCISE;
    static ActionID RESIGN_EXERCISE;
    static ActionID TIME_ADVANCE;
    static ActionID TACCSF_LOS_REQUEST_TYPE_1;
    static ActionID TACCSF_LOS_REQUEST_TYPE_2;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ActionID getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ActionID*> enumContainer;
    static enumContainer getEnumerations();

    ActionID& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ActionID(int value, std::string description);

	  static ActionID* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ActionID */


}  /* namespace DIS */

#endif /* ACTIONID__H */

