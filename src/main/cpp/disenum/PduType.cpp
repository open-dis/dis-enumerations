#include <sstream>
#include <cstddef>
#include <disenum/PduType.h>

namespace DIS {


hashMap<int,PduType*> PduType::enumerations;

PduType PduType::OTHER(0, "Other");
PduType PduType::ENTITY_STATE(1, "Entity State");
PduType PduType::FIRE(2, "Fire");
PduType PduType::DETONATION(3, "Detonation");
PduType PduType::COLLISION(4, "Collision");
PduType PduType::SERVICE_REQUEST(5, "Service Request");
PduType PduType::RESUPPLY_OFFER(6, "Resupply Offer");
PduType PduType::RESUPPLY_RECEIVED(7, "Resupply Received");
PduType PduType::RESUPPLY_CANCEL(8, "Resupply Cancel");
PduType PduType::REPAIR_COMPLETE(9, "Repair Complete");
PduType PduType::REPAIR_RESPONSE(10, "Repair Response");
PduType PduType::CREATE_ENTITY(11, "Create Entity");
PduType PduType::REMOVE_ENTITY(12, "Remove Entity");
PduType PduType::START_RESUME(13, "Start/Resume");
PduType PduType::STOP_FREEZE(14, "Stop/Freeze");
PduType PduType::ACKNOWLEDGE(15, "Acknowledge");
PduType PduType::ACTION_REQUEST(16, "Action Request");
PduType PduType::ACTION_RESPONSE(17, "Action Response");
PduType PduType::DATA_QUERY(18, "Data Query");
PduType PduType::SET_DATA(19, "Set Data");
PduType PduType::DATA(20, "Data");
PduType PduType::EVENT_REPORT(21, "Event Report");
PduType PduType::COMMENT(22, "Comment");
PduType PduType::ELECTROMAGNETIC_EMISSION(23, "Electromagnetic Emission");
PduType PduType::DESIGNATOR(24, "Designator");
PduType PduType::TRANSMITTER(25, "Transmitter");
PduType PduType::SIGNAL(26, "Signal");
PduType PduType::RECEIVER(27, "Receiver");
PduType PduType::IFF_ATC_NAVAIDS(28, "IFF/ATC/NAVAIDS");
PduType PduType::UNDERWATER_ACOUSTIC(29, "Underwater Acoustic");
PduType PduType::SUPPLEMENTAL_EMISSION_ENTITY_STATE(30, "Supplemental Emission / Entity State");
PduType PduType::INTERCOM_SIGNAL(31, "Intercom Signal");
PduType PduType::INTERCOM_CONTROL(32, "Intercom Control");
PduType PduType::AGGREGATE_STATE(33, "Aggregate State");
PduType PduType::ISGROUPOF(34, "IsGroupOf");
PduType PduType::TRANSFER_CONTROL(35, "Transfer Control");
PduType PduType::ISPARTOF(36, "IsPartOf");
PduType PduType::MINEFIELD_STATE(37, "Minefield State");
PduType PduType::MINEFIELD_QUERY(38, "Minefield Query");
PduType PduType::MINEFIELD_DATA(39, "Minefield Data");
PduType PduType::MINEFIELD_RESPONSE_NAK(40, "Minefield Response NAK");
PduType PduType::ENVIRONMENTAL_PROCESS(41, "Environmental Process");
PduType PduType::GRIDDED_DATA(42, "Gridded Data");
PduType PduType::POINT_OBJECT_STATE(43, "Point Object State");
PduType PduType::LINEAR_OBJECT_STATE(44, "Linear Object State");
PduType PduType::AREAL_OBJECT_STATE(45, "Areal Object State");
PduType PduType::TSPI(46, "TSPI");
PduType PduType::APPEARANCE(47, "Appearance");
PduType PduType::ARTICULATED_PARTS(48, "Articulated Parts");
PduType PduType::LE_FIRE(49, "LE Fire");
PduType PduType::LE_DETONATION(50, "LE Detonation");
PduType PduType::CREATE_ENTITY_R(51, "Create Entity-R");
PduType PduType::REMOVE_ENTITY_R(52, "Remove Entity-R");
PduType PduType::START_RESUME_R(53, "Start/Resume-R");
PduType PduType::STOP_FREEZE_R(54, "Stop/Freeze-R");
PduType PduType::ACKNOWLEDGE_R(55, "Acknowledge-R");
PduType PduType::ACTION_REQUEST_R(56, "Action Request-R");
PduType PduType::ACTION_RESPONSE_R(57, "Action Response-R");
PduType PduType::DATA_QUERY_R(58, "Data Query-R");
PduType PduType::SET_DATA_R(59, "Set Data-R");
PduType PduType::DATA_R(60, "Data-R");
PduType PduType::EVENT_REPORT_R(61, "Event Report-R");
PduType PduType::COMMENT_R(62, "Comment-R");
PduType PduType::RECORD_R(63, "Record-R");
PduType PduType::SET_RECORD_R(64, "Set Record-R");
PduType PduType::RECORD_QUERY_R(65, "Record Query-R");
PduType PduType::COLLISION_ELASTIC(66, "Collision-Elastic");
PduType PduType::ENTITY_STATE_UPDATE(67, "Entity State Update");


PduType::PduType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PduType* PduType::findEnumeration(int aVal) {
  PduType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PduType::getDescriptionForValue(int aVal) {
  PduType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PduType PduType::getEnumerationForValue(int aVal) throw(EnumException) {
  PduType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PduType";
    throw EnumException("PduType", aVal, ss.str());
  }
};

bool PduType::enumerationForValueExists(int aVal) {
  PduType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PduType::enumContainer PduType::getEnumerations() {
  return (enumerations);
};

PduType& PduType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

