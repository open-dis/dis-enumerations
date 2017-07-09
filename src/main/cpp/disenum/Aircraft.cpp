#include <sstream>
#include <cstddef>
#include <disenum/Aircraft.h>

namespace DIS {


hashMap<int,Aircraft*> Aircraft::enumerations;

Aircraft Aircraft::ENGINE_OFF(-100, "Engine Off");
Aircraft Aircraft::IDLE_POWER(0, "Idle Power");
Aircraft Aircraft::MIL_POWER(50, "Mil. Power");
Aircraft Aircraft::MIN_A_B(51, "Min. A/B");
Aircraft Aircraft::MAX_A_B(100, "Max. A/B");


Aircraft::Aircraft(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Aircraft* Aircraft::findEnumeration(int aVal) {
  Aircraft* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Aircraft::getDescriptionForValue(int aVal) {
  Aircraft* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Aircraft Aircraft::getEnumerationForValue(int aVal) throw(EnumException) {
  Aircraft* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Aircraft";
    throw EnumException("Aircraft", aVal, ss.str());
  }
};

bool Aircraft::enumerationForValueExists(int aVal) {
  Aircraft* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Aircraft::enumContainer Aircraft::getEnumerations() {
  return (enumerations);
};

Aircraft& Aircraft::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

