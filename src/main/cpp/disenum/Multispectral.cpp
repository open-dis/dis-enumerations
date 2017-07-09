#include <sstream>
#include <cstddef>
#include <disenum/Multispectral.h>

namespace DIS {


hashMap<int,Multispectral*> Multispectral::enumerations;

Multispectral Multispectral::GENERIC(0, "Generic");


Multispectral::Multispectral(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Multispectral* Multispectral::findEnumeration(int aVal) {
  Multispectral* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Multispectral::getDescriptionForValue(int aVal) {
  Multispectral* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Multispectral Multispectral::getEnumerationForValue(int aVal) throw(EnumException) {
  Multispectral* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Multispectral";
    throw EnumException("Multispectral", aVal, ss.str());
  }
};

bool Multispectral::enumerationForValueExists(int aVal) {
  Multispectral* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Multispectral::enumContainer Multispectral::getEnumerations() {
  return (enumerations);
};

Multispectral& Multispectral::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

