#include <sstream>
#include <cstddef>
#include <disenum/AcousticEmitters.h>

namespace DIS {


hashMap<int,AcousticEmitters*> AcousticEmitters::enumerations;

AcousticEmitters AcousticEmitters::MISSING_DESCRIPTION(40020, "Missing Description");


AcousticEmitters::AcousticEmitters(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AcousticEmitters* AcousticEmitters::findEnumeration(int aVal) {
  AcousticEmitters* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AcousticEmitters::getDescriptionForValue(int aVal) {
  AcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AcousticEmitters AcousticEmitters::getEnumerationForValue(int aVal) throw(EnumException) {
  AcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AcousticEmitters";
    throw EnumException("AcousticEmitters", aVal, ss.str());
  }
};

bool AcousticEmitters::enumerationForValueExists(int aVal) {
  AcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AcousticEmitters::enumContainer AcousticEmitters::getEnumerations() {
  return (enumerations);
};

AcousticEmitters& AcousticEmitters::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

