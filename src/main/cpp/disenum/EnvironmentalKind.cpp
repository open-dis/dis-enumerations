#include <sstream>
#include <cstddef>
#include <disenum/EnvironmentalKind.h>

namespace DIS {


hashMap<int,EnvironmentalKind*> EnvironmentalKind::enumerations;

EnvironmentalKind EnvironmentalKind::OTHER(0, "Other");
EnvironmentalKind EnvironmentalKind::VERY_SMALL(20, "Very Small");
EnvironmentalKind EnvironmentalKind::SMALL(40, "Small");
EnvironmentalKind EnvironmentalKind::MEDIUM(60, "Medium");
EnvironmentalKind EnvironmentalKind::LARGE(80, "Large");
EnvironmentalKind EnvironmentalKind::VERY_LARGE(100, "Very Large");


EnvironmentalKind::EnvironmentalKind(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

EnvironmentalKind* EnvironmentalKind::findEnumeration(int aVal) {
  EnvironmentalKind* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string EnvironmentalKind::getDescriptionForValue(int aVal) {
  EnvironmentalKind* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

EnvironmentalKind EnvironmentalKind::getEnumerationForValue(int aVal) throw(EnumException) {
  EnvironmentalKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration EnvironmentalKind";
    throw EnumException("EnvironmentalKind", aVal, ss.str());
  }
};

bool EnvironmentalKind::enumerationForValueExists(int aVal) {
  EnvironmentalKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

EnvironmentalKind::enumContainer EnvironmentalKind::getEnumerations() {
  return (enumerations);
};

EnvironmentalKind& EnvironmentalKind::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

