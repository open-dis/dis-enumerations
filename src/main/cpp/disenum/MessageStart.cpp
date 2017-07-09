#include <sstream>
#include <cstddef>
#include <disenum/MessageStart.h>

namespace DIS {


hashMap<int,MessageStart*> MessageStart::enumerations;

MessageStart MessageStart::NOT_START_OF_MESSAGE(0, "Not start of message");
MessageStart MessageStart::START_OF_MESSAGE(1, "Start of Message");


MessageStart::MessageStart(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

MessageStart* MessageStart::findEnumeration(int aVal) {
  MessageStart* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string MessageStart::getDescriptionForValue(int aVal) {
  MessageStart* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

MessageStart MessageStart::getEnumerationForValue(int aVal) throw(EnumException) {
  MessageStart* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration MessageStart";
    throw EnumException("MessageStart", aVal, ss.str());
  }
};

bool MessageStart::enumerationForValueExists(int aVal) {
  MessageStart* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

MessageStart::enumContainer MessageStart::getEnumerations() {
  return (enumerations);
};

MessageStart& MessageStart::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

