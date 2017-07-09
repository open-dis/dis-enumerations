#include <sstream>
#include <cstddef>
#include <disenum/@ENUMERATIONNAME.h>

namespace DIS {


hashMap<int,@ENUMERATIONNAME*> @ENUMERATIONNAME::enumerations;

@ENUMSINIT

@ENUMERATIONNAME::@ENUMERATIONNAME(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

@ENUMERATIONNAME* @ENUMERATIONNAME::findEnumeration(int aVal) {
  @ENUMERATIONNAME* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string @ENUMERATIONNAME::getDescriptionForValue(int aVal) {
  @ENUMERATIONNAME* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

@ENUMERATIONNAME @ENUMERATIONNAME::getEnumerationForValue(int aVal) throw(EnumException) {
  @ENUMERATIONNAME* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration @ENUMERATIONNAME";
    throw EnumException("@ENUMERATIONNAME", aVal, ss.str());
  }
};

bool @ENUMERATIONNAME::enumerationForValueExists(int aVal) {
  @ENUMERATIONNAME* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

@ENUMERATIONNAME::enumContainer @ENUMERATIONNAME::getEnumerations() {
  return (enumerations);
};

@ENUMERATIONNAME& @ENUMERATIONNAME::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

