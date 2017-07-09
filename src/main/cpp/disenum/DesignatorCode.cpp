#include <sstream>
#include <cstddef>
#include <disenum/DesignatorCode.h>

namespace DIS {


hashMap<int,DesignatorCode*> DesignatorCode::enumerations;

DesignatorCode DesignatorCode::OTHER(0, "Other");
DesignatorCode DesignatorCode::MISSING_DESCRIPTION(1, "Missing Description");


DesignatorCode::DesignatorCode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DesignatorCode* DesignatorCode::findEnumeration(int aVal) {
  DesignatorCode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DesignatorCode::getDescriptionForValue(int aVal) {
  DesignatorCode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DesignatorCode DesignatorCode::getEnumerationForValue(int aVal) throw(EnumException) {
  DesignatorCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DesignatorCode";
    throw EnumException("DesignatorCode", aVal, ss.str());
  }
};

bool DesignatorCode::enumerationForValueExists(int aVal) {
  DesignatorCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DesignatorCode::enumContainer DesignatorCode::getEnumerations() {
  return (enumerations);
};

DesignatorCode& DesignatorCode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

