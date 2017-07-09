#include <sstream>
#include <cstddef>
#include <disenum/ActionID.h>

namespace DIS {


hashMap<int,ActionID*> ActionID::enumerations;

ActionID ActionID::OTHER(0, "Other");
ActionID ActionID::LOCAL_STORAGE_OF_THE_REQUESTED_INFORMATION(1, "Local storage of the requested information");
ActionID ActionID::INFORM_SM_OF_EVENT_RAN_OUT_OF_AMMUNITION(2, "Inform SM of event ran out of ammunition");
ActionID ActionID::INFORM_SM_OF_EVENT_KILLED_IN_ACTION(3, "Inform SM of event killed in action");
ActionID ActionID::INFORM_SM_OF_EVENT_DAMAGE(4, "Inform SM of event damage");
ActionID ActionID::INFORM_SM_OF_EVENT_MOBILITY_DISABLED(5, "Inform SM of event mobility disabled");
ActionID ActionID::INFORM_SM_OF_EVENT_FIRE_DISABLED(6, "Inform SM of event fire disabled");
ActionID ActionID::INFORM_SM_OF_EVENT_RAN_OUT_OF_FUEL(7, "Inform SM of event ran out of fuel");
ActionID ActionID::RECALL_CHECKPOINT_DATA(8, "Recall checkpoint data");
ActionID ActionID::RECALL_INITIAL_PARAMETERS(9, "Recall initial parameters");
ActionID ActionID::INITIATE_TETHER_LEAD(10, "Initiate tether-lead");
ActionID ActionID::INITIATE_TETHER_FOLLOW(11, "Initiate tether-follow");
ActionID ActionID::UNTHETHER(12, "Unthether");
ActionID ActionID::INITIATE_SERVICE_STATION_RESUPPLY(13, "Initiate service station resupply");
ActionID ActionID::INITIATE_TAILGATE_RESUPPLY(14, "Initiate tailgate resupply");
ActionID ActionID::INITIATE_HITCH_LEAD(15, "Initiate hitch lead");
ActionID ActionID::INITIATE_HITCH_FOLLOW(16, "Initiate hitch follow");
ActionID ActionID::UNHITCH(17, "Unhitch");
ActionID ActionID::MOUNT(18, "Mount");
ActionID ActionID::DISMOUNT(19, "Dismount");
ActionID ActionID::START_DRC_DAILY_READINESS_CHECK(20, "Start DRC (Daily Readiness Check)");
ActionID ActionID::STOP_DRC(21, "Stop DRC");
ActionID ActionID::DATA_QUERY(22, "Data Query");
ActionID ActionID::STATUS_REQUEST(23, "Status Request");
ActionID ActionID::SEND_OBJECT_STATE_DATA(24, "Send Object State Data");
ActionID ActionID::RECONSTITUTE(25, "Reconstitute");
ActionID ActionID::LOCK_SITE_CONFIGURATION(26, "Lock Site Configuration");
ActionID ActionID::UNLOCK_SITE_CONFIGURATION(27, "Unlock Site Configuration");
ActionID ActionID::UPDATE_SITE_CONFIGURATION(28, "Update Site Configuration");
ActionID ActionID::QUERY_SITE_CONFIGURATION(29, "Query Site Configuration");
ActionID ActionID::TETHERING_INFORMATION(30, "Tethering Information");
ActionID ActionID::MOUNT_INTENT(31, "Mount Intent");
ActionID ActionID::ACCEPT_SUBSCRIPTION(33, "Accept Subscription");
ActionID ActionID::UNSUBSCRIBE(34, "Unsubscribe");
ActionID ActionID::TELEPORT_ENTITY(35, "Teleport entity");
ActionID ActionID::CHANGE_AGGREGATE_STATE(36, "Change aggregate state");
ActionID ActionID::REQUEST_START_PDU(37, "Request Start PDU");
ActionID ActionID::WAKEUP_GET_READY_FOR_INITIALIZATION(38, "Wakeup get ready for initialization");
ActionID ActionID::INITIALIZE_INTERNAL_PARAMETERS(39, "Initialize internal parameters");
ActionID ActionID::SEND_PLAN_DATA(40, "Send plan data");
ActionID ActionID::SYNCHRONIZE_INTERNAL_CLOCKS(41, "Synchronize internal clocks");
ActionID ActionID::RUN(42, "Run");
ActionID ActionID::SAVE_INTERNAL_PARAMETERS(43, "Save internal parameters");
ActionID ActionID::SIMULATE_MALFUNCTION(44, "Simulate malfunction");
ActionID ActionID::JOIN_EXERCISE(45, "Join exercise");
ActionID ActionID::RESIGN_EXERCISE(46, "Resign exercise");
ActionID ActionID::TIME_ADVANCE(47, "Time advance");
ActionID ActionID::TACCSF_LOS_REQUEST_TYPE_1(100, "TACCSF LOS Request-Type 1");
ActionID ActionID::TACCSF_LOS_REQUEST_TYPE_2(101, "TACCSF LOS Request-Type 2");


ActionID::ActionID(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ActionID* ActionID::findEnumeration(int aVal) {
  ActionID* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ActionID::getDescriptionForValue(int aVal) {
  ActionID* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ActionID ActionID::getEnumerationForValue(int aVal) throw(EnumException) {
  ActionID* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ActionID";
    throw EnumException("ActionID", aVal, ss.str());
  }
};

bool ActionID::enumerationForValueExists(int aVal) {
  ActionID* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ActionID::enumContainer ActionID::getEnumerations() {
  return (enumerations);
};

ActionID& ActionID::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

