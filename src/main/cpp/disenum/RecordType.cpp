#include <sstream>
#include <cstddef>
#include <disenum/RecordType.h>

namespace DIS {


hashMap<int,RecordType*> RecordType::enumerations;

RecordType RecordType::ENTITY_DESTINATION_RECORD(1, "Entity Destination record");
RecordType RecordType::GROUP_DESTINATION_RECORD(2, "Group Destination record");
RecordType RecordType::GROUP_ASSIGNMENT_RECORD(3, "Group Assignment record");


RecordType::RecordType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RecordType* RecordType::findEnumeration(int aVal) {
  RecordType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RecordType::getDescriptionForValue(int aVal) {
  RecordType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RecordType RecordType::getEnumerationForValue(int aVal) throw(EnumException) {
  RecordType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RecordType";
    throw EnumException("RecordType", aVal, ss.str());
  }
};

bool RecordType::enumerationForValueExists(int aVal) {
  RecordType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RecordType::enumContainer RecordType::getEnumerations() {
  return (enumerations);
};

RecordType& RecordType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

