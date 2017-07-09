#include <sstream>
#include <cstddef>
#include <disenum/SampleType.h>

namespace DIS {


hashMap<int,SampleType*> SampleType::enumerations;

SampleType SampleType::MISSING_DESCRIPTION(0, "Missing Description");


SampleType::SampleType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

SampleType* SampleType::findEnumeration(int aVal) {
  SampleType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string SampleType::getDescriptionForValue(int aVal) {
  SampleType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

SampleType SampleType::getEnumerationForValue(int aVal) throw(EnumException) {
  SampleType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration SampleType";
    throw EnumException("SampleType", aVal, ss.str());
  }
};

bool SampleType::enumerationForValueExists(int aVal) {
  SampleType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

SampleType::enumContainer SampleType::getEnumerations() {
  return (enumerations);
};

SampleType& SampleType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

