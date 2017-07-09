#include <sstream>
#include <cstddef>
#include <disenum/CollisionType.h>

namespace DIS {


hashMap<int,CollisionType*> CollisionType::enumerations;

CollisionType CollisionType::INELASTIC(0, "Inelastic");
CollisionType CollisionType::ELASTIC(1, "Elastic");


CollisionType::CollisionType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CollisionType* CollisionType::findEnumeration(int aVal) {
  CollisionType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CollisionType::getDescriptionForValue(int aVal) {
  CollisionType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CollisionType CollisionType::getEnumerationForValue(int aVal) throw(EnumException) {
  CollisionType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CollisionType";
    throw EnumException("CollisionType", aVal, ss.str());
  }
};

bool CollisionType::enumerationForValueExists(int aVal) {
  CollisionType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CollisionType::enumContainer CollisionType::getEnumerations() {
  return (enumerations);
};

CollisionType& CollisionType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

