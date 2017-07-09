#include <sstream>
#include <cstddef>
#include <disenum/PassiveParameterIndex.h>

namespace DIS {


hashMap<int,PassiveParameterIndex*> PassiveParameterIndex::enumerations;

PassiveParameterIndex PassiveParameterIndex::OTHER(0, "Other");


PassiveParameterIndex::PassiveParameterIndex(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PassiveParameterIndex* PassiveParameterIndex::findEnumeration(int aVal) {
  PassiveParameterIndex* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PassiveParameterIndex::getDescriptionForValue(int aVal) {
  PassiveParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PassiveParameterIndex PassiveParameterIndex::getEnumerationForValue(int aVal) throw(EnumException) {
  PassiveParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PassiveParameterIndex";
    throw EnumException("PassiveParameterIndex", aVal, ss.str());
  }
};

bool PassiveParameterIndex::enumerationForValueExists(int aVal) {
  PassiveParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PassiveParameterIndex::enumContainer PassiveParameterIndex::getEnumerations() {
  return (enumerations);
};

PassiveParameterIndex& PassiveParameterIndex::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

