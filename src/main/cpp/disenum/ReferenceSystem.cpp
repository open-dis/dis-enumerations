#include <sstream>
#include <cstddef>
#include <disenum/ReferenceSystem.h>

namespace DIS {


hashMap<int,ReferenceSystem*> ReferenceSystem::enumerations;

ReferenceSystem ReferenceSystem::WORLD_COORDINATES(1, "World Coordinates");
ReferenceSystem ReferenceSystem::ENTITY_COORDINATES(2, "Entity Coordinates");


ReferenceSystem::ReferenceSystem(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ReferenceSystem* ReferenceSystem::findEnumeration(int aVal) {
  ReferenceSystem* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ReferenceSystem::getDescriptionForValue(int aVal) {
  ReferenceSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ReferenceSystem ReferenceSystem::getEnumerationForValue(int aVal) throw(EnumException) {
  ReferenceSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ReferenceSystem";
    throw EnumException("ReferenceSystem", aVal, ss.str());
  }
};

bool ReferenceSystem::enumerationForValueExists(int aVal) {
  ReferenceSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ReferenceSystem::enumContainer ReferenceSystem::getEnumerations() {
  return (enumerations);
};

ReferenceSystem& ReferenceSystem::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

