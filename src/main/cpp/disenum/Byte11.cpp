#include <sstream>
#include <cstddef>
#include <disenum/Byte11.h>

namespace DIS {


hashMap<int,Byte11*> Byte11::enumerations;

Byte11 Byte11::_CARET_(94, "^");
Byte11 Byte11::_GT_(62, ">");
Byte11 Byte11::INVERTED_CARROT(86, "inverted carrot");
Byte11 Byte11::_LT_(60, "<");
Byte11 Byte11::_CARET_AND_INVERTED_CARROT(126, "^ and inverted carrot");
Byte11 Byte11::_LT_GT_(61, "< >");


Byte11::Byte11(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Byte11* Byte11::findEnumeration(int aVal) {
  Byte11* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Byte11::getDescriptionForValue(int aVal) {
  Byte11* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Byte11 Byte11::getEnumerationForValue(int aVal) throw(EnumException) {
  Byte11* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Byte11";
    throw EnumException("Byte11", aVal, ss.str());
  }
};

bool Byte11::enumerationForValueExists(int aVal) {
  Byte11* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Byte11::enumContainer Byte11::getEnumerations() {
  return (enumerations);
};

Byte11& Byte11::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

