#include <sstream>
#include <cstddef>
#include <disenum/ResponseFlag.h>

namespace DIS {


hashMap<int,ResponseFlag*> ResponseFlag::enumerations;

ResponseFlag ResponseFlag::OTHER(0, "Other");
ResponseFlag ResponseFlag::ABLE_TO_COMPLY(1, "Able to comply");
ResponseFlag ResponseFlag::UNABLE_TO_COMPLY(2, "Unable to comply");


ResponseFlag::ResponseFlag(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ResponseFlag* ResponseFlag::findEnumeration(int aVal) {
  ResponseFlag* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ResponseFlag::getDescriptionForValue(int aVal) {
  ResponseFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ResponseFlag ResponseFlag::getEnumerationForValue(int aVal) throw(EnumException) {
  ResponseFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ResponseFlag";
    throw EnumException("ResponseFlag", aVal, ss.str());
  }
};

bool ResponseFlag::enumerationForValueExists(int aVal) {
  ResponseFlag* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ResponseFlag::enumContainer ResponseFlag::getEnumerations() {
  return (enumerations);
};

ResponseFlag& ResponseFlag::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

