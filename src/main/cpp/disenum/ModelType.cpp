#include <sstream>
#include <cstddef>
#include <disenum/ModelType.h>

namespace DIS {


hashMap<int,ModelType*> ModelType::enumerations;

ModelType ModelType::MISSING_DESCRIPTION(0, "Missing Description");


ModelType::ModelType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ModelType* ModelType::findEnumeration(int aVal) {
  ModelType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ModelType::getDescriptionForValue(int aVal) {
  ModelType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ModelType ModelType::getEnumerationForValue(int aVal) throw(EnumException) {
  ModelType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ModelType";
    throw EnumException("ModelType", aVal, ss.str());
  }
};

bool ModelType::enumerationForValueExists(int aVal) {
  ModelType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ModelType::enumContainer ModelType::getEnumerations() {
  return (enumerations);
};

ModelType& ModelType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

