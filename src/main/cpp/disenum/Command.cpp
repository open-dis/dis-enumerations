#include <sstream>
#include <cstddef>
#include <disenum/Command.h>

namespace DIS {


hashMap<int,Command*> Command::enumerations;

Command Command::NO_COMMAND(0, "No Command");
Command Command::STATUS(1, "Status");
Command Command::CONNECT(2, "Connect");
Command Command::DISCONNECT(3, "Disconnect");
Command Command::RESET(4, "Reset");
Command Command::ON(5, "On");
Command Command::OFF(6, "Off");
Command Command::MISSING_DESCRIPTION(7, "Missing Description");


Command::Command(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Command* Command::findEnumeration(int aVal) {
  Command* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Command::getDescriptionForValue(int aVal) {
  Command* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Command Command::getEnumerationForValue(int aVal) throw(EnumException) {
  Command* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Command";
    throw EnumException("Command", aVal, ss.str());
  }
};

bool Command::enumerationForValueExists(int aVal) {
  Command* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Command::enumContainer Command::getEnumerations() {
  return (enumerations);
};

Command& Command::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

