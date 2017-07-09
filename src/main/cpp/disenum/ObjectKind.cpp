#include <sstream>
#include <cstddef>
#include <disenum/ObjectKind.h>

namespace DIS {


hashMap<int,ObjectKind*> ObjectKind::enumerations;

ObjectKind ObjectKind::OTHER(0, "Other");
ObjectKind ObjectKind::OBSTACLE(1, "Obstacle");
ObjectKind ObjectKind::PREPARED_POSITION(2, "Prepared position");
ObjectKind ObjectKind::CULTURAL_FEATURE(3, "Cultural feature");
ObjectKind ObjectKind::PASSAGEWAY(4, "Passageway");
ObjectKind ObjectKind::TACTICAL_SMOKE(5, "Tactical smoke");
ObjectKind ObjectKind::OBSTACLE_MARKER(6, "Obstacle marker");
ObjectKind ObjectKind::OBSTACLE_BREACH(7, "Obstacle breach");


ObjectKind::ObjectKind(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ObjectKind* ObjectKind::findEnumeration(int aVal) {
  ObjectKind* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ObjectKind::getDescriptionForValue(int aVal) {
  ObjectKind* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ObjectKind ObjectKind::getEnumerationForValue(int aVal) throw(EnumException) {
  ObjectKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ObjectKind";
    throw EnumException("ObjectKind", aVal, ss.str());
  }
};

bool ObjectKind::enumerationForValueExists(int aVal) {
  ObjectKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ObjectKind::enumContainer ObjectKind::getEnumerations() {
  return (enumerations);
};

ObjectKind& ObjectKind::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

