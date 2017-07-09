#include <sstream>
#include <cstddef>
#include <disenum/Helicopters.h>

namespace DIS {


hashMap<int,Helicopters*> Helicopters::enumerations;

Helicopters Helicopters::ENGINE_OFF(-100, "Engine Off");
Helicopters Helicopters::IDLE_POWER(0, "Idle Power");
Helicopters Helicopters::MAX_POWER(100, "Max. Power");


Helicopters::Helicopters(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Helicopters* Helicopters::findEnumeration(int aVal) {
  Helicopters* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Helicopters::getDescriptionForValue(int aVal) {
  Helicopters* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Helicopters Helicopters::getEnumerationForValue(int aVal) throw(EnumException) {
  Helicopters* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Helicopters";
    throw EnumException("Helicopters", aVal, ss.str());
  }
};

bool Helicopters::enumerationForValueExists(int aVal) {
  Helicopters* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Helicopters::enumContainer Helicopters::getEnumerations() {
  return (enumerations);
};

Helicopters& Helicopters::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

