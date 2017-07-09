#include <sstream>
#include <cstddef>
#include <disenum/Tanks.h>

namespace DIS {


hashMap<int,Tanks*> Tanks::enumerations;

Tanks Tanks::ENGINE_OFF(-100, "Engine Off");
Tanks Tanks::IDLE_POWER(0, "Idle Power");
Tanks Tanks::MAX_POWER(100, "Max. Power");


Tanks::Tanks(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Tanks* Tanks::findEnumeration(int aVal) {
  Tanks* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Tanks::getDescriptionForValue(int aVal) {
  Tanks* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Tanks Tanks::getEnumerationForValue(int aVal) throw(EnumException) {
  Tanks* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Tanks";
    throw EnumException("Tanks", aVal, ss.str());
  }
};

bool Tanks::enumerationForValueExists(int aVal) {
  Tanks* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Tanks::enumContainer Tanks::getEnumerations() {
  return (enumerations);
};

Tanks& Tanks::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

