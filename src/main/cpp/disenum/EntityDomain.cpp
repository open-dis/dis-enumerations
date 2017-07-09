#include <sstream>
#include <cstddef>
#include <disenum/EntityDomain.h>

namespace DIS {


hashMap<int,EntityDomain*> EntityDomain::enumerations;

EntityDomain EntityDomain::OTHER(0, "Other");
EntityDomain EntityDomain::LAND(1, "Land");
EntityDomain EntityDomain::AIR(2, "Air");
EntityDomain EntityDomain::SURFACE(3, "Surface");
EntityDomain EntityDomain::SUBSURFACE(4, "Subsurface");
EntityDomain EntityDomain::SPACE(5, "Space");


EntityDomain::EntityDomain(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

EntityDomain* EntityDomain::findEnumeration(int aVal) {
  EntityDomain* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string EntityDomain::getDescriptionForValue(int aVal) {
  EntityDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

EntityDomain EntityDomain::getEnumerationForValue(int aVal) throw(EnumException) {
  EntityDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration EntityDomain";
    throw EnumException("EntityDomain", aVal, ss.str());
  }
};

bool EntityDomain::enumerationForValueExists(int aVal) {
  EntityDomain* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

EntityDomain::enumContainer EntityDomain::getEnumerations() {
  return (enumerations);
};

EntityDomain& EntityDomain::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

