#include <sstream>
#include <cstddef>
#include <disenum/PlatoonSection.h>

namespace DIS {


hashMap<int,PlatoonSection*> PlatoonSection::enumerations;

PlatoonSection PlatoonSection::X_0_9(0, "0-9");


PlatoonSection::PlatoonSection(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatoonSection* PlatoonSection::findEnumeration(int aVal) {
  PlatoonSection* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatoonSection::getDescriptionForValue(int aVal) {
  PlatoonSection* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatoonSection PlatoonSection::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatoonSection* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatoonSection";
    throw EnumException("PlatoonSection", aVal, ss.str());
  }
};

bool PlatoonSection::enumerationForValueExists(int aVal) {
  PlatoonSection* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatoonSection::enumContainer PlatoonSection::getEnumerations() {
  return (enumerations);
};

PlatoonSection& PlatoonSection::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

