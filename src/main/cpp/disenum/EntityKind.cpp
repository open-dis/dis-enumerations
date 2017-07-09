#include <sstream>
#include <cstddef>
#include <disenum/EntityKind.h>

namespace DIS {


hashMap<int,EntityKind*> EntityKind::enumerations;

EntityKind EntityKind::OTHER(0, "Other");
EntityKind EntityKind::PLATFORM(1, "Platform");
EntityKind EntityKind::MUNITION(2, "Munition");
EntityKind EntityKind::LIFE_FORM(3, "Life form");
EntityKind EntityKind::ENVIRONMENTAL(4, "Environmental");
EntityKind EntityKind::CULTURAL_FEATURE(5, "Cultural feature");
EntityKind EntityKind::SUPPLY(6, "Supply");
EntityKind EntityKind::RADIO(7, "Radio");
EntityKind EntityKind::EXPENDABLE(8, "Expendable");
EntityKind EntityKind::SENSOR_EMITTER(9, "Sensor/Emitter");


EntityKind::EntityKind(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

EntityKind* EntityKind::findEnumeration(int aVal) {
  EntityKind* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string EntityKind::getDescriptionForValue(int aVal) {
  EntityKind* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

EntityKind EntityKind::getEnumerationForValue(int aVal) throw(EnumException) {
  EntityKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration EntityKind";
    throw EnumException("EntityKind", aVal, ss.str());
  }
};

bool EntityKind::enumerationForValueExists(int aVal) {
  EntityKind* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

EntityKind::enumContainer EntityKind::getEnumerations() {
  return (enumerations);
};

EntityKind& EntityKind::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

