#include <sstream>
#include <cstddef>
#include <disenum/RestStatus.h>

namespace DIS {


hashMap<int,RestStatus*> RestStatus::enumerations;

RestStatus RestStatus::NOT_RESTED_HAS_NOT_SLEPT_IN_THE_LAST_THREE_DAYS(0, "Not rested (Has not slept in the last three days)");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_1_HOUR_PER_DAY_IN_THE_LAST_THREE_DAYS(1, "Has slept an average of 1 hour per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_2_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(2, "Has slept an average of 2 hours per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_3_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(3, "Has slept an average of 3 hours per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_4_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(4, "Has slept an average of 4 hours per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_5_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(5, "Has slept an average of 5 hours per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_6_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(6, "Has slept an average of 6 hours per day in the last three days.");
RestStatus RestStatus::HAS_SLEPT_AN_AVERAGE_OF_7_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(7, "Has slept an average of 7 hours per day in the last three days.");
RestStatus RestStatus::FULLY_RESTED_HAS_SLEPT_AN_AVERAGE_OF_8_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS(8, "Fully rested (Has slept an average of 8 hours per day in the last three days)");


RestStatus::RestStatus(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RestStatus* RestStatus::findEnumeration(int aVal) {
  RestStatus* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RestStatus::getDescriptionForValue(int aVal) {
  RestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RestStatus RestStatus::getEnumerationForValue(int aVal) throw(EnumException) {
  RestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RestStatus";
    throw EnumException("RestStatus", aVal, ss.str());
  }
};

bool RestStatus::enumerationForValueExists(int aVal) {
  RestStatus* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RestStatus::enumContainer RestStatus::getEnumerations() {
  return (enumerations);
};

RestStatus& RestStatus::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

