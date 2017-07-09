#include <sstream>
#include <cstddef>
#include <disenum/Physical.h>

namespace DIS {


hashMap<int,Physical*> Physical::enumerations;

Physical Physical::GENERIC_PROBE(0, "Generic Probe");
Physical Physical::PROBE_METAL_CONTENT(1, "Probe, metal content");
Physical Physical::PROBE_NO_METAL_CONTENT(2, "Probe, no metal content");


Physical::Physical(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Physical* Physical::findEnumeration(int aVal) {
  Physical* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Physical::getDescriptionForValue(int aVal) {
  Physical* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Physical Physical::getEnumerationForValue(int aVal) throw(EnumException) {
  Physical* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Physical";
    throw EnumException("Physical", aVal, ss.str());
  }
};

bool Physical::enumerationForValueExists(int aVal) {
  Physical* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Physical::enumContainer Physical::getEnumerations() {
  return (enumerations);
};

Physical& Physical::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

