#include <sstream>
#include <cstddef>
#include <disenum/OtherAcousticEmitters.h>

namespace DIS {


hashMap<int,OtherAcousticEmitters*> OtherAcousticEmitters::enumerations;

OtherAcousticEmitters OtherAcousticEmitters::MISSING_DESCRIPTION(62020, "Missing Description");


OtherAcousticEmitters::OtherAcousticEmitters(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

OtherAcousticEmitters* OtherAcousticEmitters::findEnumeration(int aVal) {
  OtherAcousticEmitters* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string OtherAcousticEmitters::getDescriptionForValue(int aVal) {
  OtherAcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

OtherAcousticEmitters OtherAcousticEmitters::getEnumerationForValue(int aVal) throw(EnumException) {
  OtherAcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration OtherAcousticEmitters";
    throw EnumException("OtherAcousticEmitters", aVal, ss.str());
  }
};

bool OtherAcousticEmitters::enumerationForValueExists(int aVal) {
  OtherAcousticEmitters* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

OtherAcousticEmitters::enumContainer OtherAcousticEmitters::getEnumerations() {
  return (enumerations);
};

OtherAcousticEmitters& OtherAcousticEmitters::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

