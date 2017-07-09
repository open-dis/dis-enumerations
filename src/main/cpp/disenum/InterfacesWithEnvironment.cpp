#include <sstream>
#include <cstddef>
#include <disenum/InterfacesWithEnvironment.h>

namespace DIS {


hashMap<int,InterfacesWithEnvironment*> InterfacesWithEnvironment::enumerations;

InterfacesWithEnvironment InterfacesWithEnvironment::PROPELLER(1500, "propeller");
InterfacesWithEnvironment InterfacesWithEnvironment::FILTERS(1520, "filters");
InterfacesWithEnvironment InterfacesWithEnvironment::WHEELS(1540, "wheels");
InterfacesWithEnvironment InterfacesWithEnvironment::TIRE(1550, "tire");
InterfacesWithEnvironment InterfacesWithEnvironment::TRACK(1560, "track");
InterfacesWithEnvironment InterfacesWithEnvironment::MISSING_DESCRIPTION(1570, "Missing Description");


InterfacesWithEnvironment::InterfacesWithEnvironment(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

InterfacesWithEnvironment* InterfacesWithEnvironment::findEnumeration(int aVal) {
  InterfacesWithEnvironment* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string InterfacesWithEnvironment::getDescriptionForValue(int aVal) {
  InterfacesWithEnvironment* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

InterfacesWithEnvironment InterfacesWithEnvironment::getEnumerationForValue(int aVal) throw(EnumException) {
  InterfacesWithEnvironment* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration InterfacesWithEnvironment";
    throw EnumException("InterfacesWithEnvironment", aVal, ss.str());
  }
};

bool InterfacesWithEnvironment::enumerationForValueExists(int aVal) {
  InterfacesWithEnvironment* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

InterfacesWithEnvironment::enumContainer InterfacesWithEnvironment::getEnumerations() {
  return (enumerations);
};

InterfacesWithEnvironment& InterfacesWithEnvironment::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

