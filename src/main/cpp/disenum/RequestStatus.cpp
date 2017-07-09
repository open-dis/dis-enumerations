#include <sstream>
#include <cstddef>
#include <disenum/RequestStatus.h>

namespace DIS {


hashMap<int,RequestStatus*> RequestStatus::enumerations;

RequestStatus RequestStatus::OTHER(0, "Other");
RequestStatus RequestStatus::PENDING(1, "Pending");
RequestStatus RequestStatus::EXECUTING(2, "Executing");
RequestStatus RequestStatus::PARTIALLY_COMPLETE(3, "Partially Complete");
RequestStatus RequestStatus::COMPLETE(4, "Complete");
RequestStatus RequestStatus::REQUEST_REJECTED(5, "Request rejected");
RequestStatus RequestStatus::RETRANSMIT_REQUEST_NOW(6, "Retransmit request now");
RequestStatus RequestStatus::RETRANSMIT_REQUEST_LATER(7, "Retransmit request later");
RequestStatus RequestStatus::INVALID_TIME_PARAMETERS(8, "Invalid time parameters");
RequestStatus RequestStatus::SIMULATION_TIME_EXCEEDED(9, "Simulation time exceeded");
RequestStatus RequestStatus::REQUEST_DONE(10, "Request done");
RequestStatus RequestStatus::TACCSF_LOS_REPLY_TYPE_1(100, "TACCSF LOS Reply-Type 1");
RequestStatus RequestStatus::TACCSF_LOS_REPLY_TYPE_2(101, "TACCSF LOS Reply-Type 2");
RequestStatus RequestStatus::JOIN_EXERCISE_REQUEST_REJECTED(201, "Join Exercise Request Rejected");


RequestStatus::RequestStatus(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RequestStatus* RequestStatus::findEnumeration(int aVal) {
  RequestStatus* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RequestStatus::getDescriptionForValue(int aVal) {
  RequestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RequestStatus RequestStatus::getEnumerationForValue(int aVal) throw(EnumException) {
  RequestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RequestStatus";
    throw EnumException("RequestStatus", aVal, ss.str());
  }
};

bool RequestStatus::enumerationForValueExists(int aVal) {
  RequestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RequestStatus::enumContainer RequestStatus::getEnumerations() {
  return (enumerations);
};

RequestStatus& RequestStatus::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

