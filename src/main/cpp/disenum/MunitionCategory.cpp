#include <sstream>
#include <cstddef>
#include <disenum/MunitionCategory.h>

namespace DIS {


hashMap<int,MunitionCategory*> MunitionCategory::enumerations;

MunitionCategory MunitionCategory::OTHER(0, "Other");
MunitionCategory MunitionCategory::GUIDED(1, "Guided");
MunitionCategory MunitionCategory::BALLISTIC(2, "Ballistic");
MunitionCategory MunitionCategory::FIXED(3, "Fixed");


MunitionCategory::MunitionCategory(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

MunitionCategory* MunitionCategory::findEnumeration(int aVal) {
  MunitionCategory* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string MunitionCategory::getDescriptionForValue(int aVal) {
  MunitionCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

MunitionCategory MunitionCategory::getEnumerationForValue(int aVal) throw(EnumException) {
  MunitionCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration MunitionCategory";
    throw EnumException("MunitionCategory", aVal, ss.str());
  }
};

bool MunitionCategory::enumerationForValueExists(int aVal) {
  MunitionCategory* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

MunitionCategory::enumContainer MunitionCategory::getEnumerations() {
  return (enumerations);
};

MunitionCategory& MunitionCategory::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

