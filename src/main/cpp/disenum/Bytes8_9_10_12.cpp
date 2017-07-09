#include <sstream>
#include <cstddef>
#include <disenum/Bytes8_9_10_12.h>

namespace DIS {


hashMap<int,Bytes8_9_10_12*> Bytes8_9_10_12::enumerations;

Bytes8_9_10_12 Bytes8_9_10_12::X_0_9(0, "0-9");
Bytes8_9_10_12 Bytes8_9_10_12::X_0_9_1(10, "0-9");
Bytes8_9_10_12 Bytes8_9_10_12::E(69, "E");
Bytes8_9_10_12 Bytes8_9_10_12::UNDERSCORE_E(101, "Underscore E");
Bytes8_9_10_12 Bytes8_9_10_12::S(83, "S");
Bytes8_9_10_12 Bytes8_9_10_12::UNDERSCORE_S(115, "Underscore S");
Bytes8_9_10_12 Bytes8_9_10_12::X(88, "X");
Bytes8_9_10_12 Bytes8_9_10_12::UNDERSCORE_X(120, "Underscore X");
Bytes8_9_10_12 Bytes8_9_10_12::BLANK(32, "Blank");


Bytes8_9_10_12::Bytes8_9_10_12(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Bytes8_9_10_12* Bytes8_9_10_12::findEnumeration(int aVal) {
  Bytes8_9_10_12* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Bytes8_9_10_12::getDescriptionForValue(int aVal) {
  Bytes8_9_10_12* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Bytes8_9_10_12 Bytes8_9_10_12::getEnumerationForValue(int aVal) throw(EnumException) {
  Bytes8_9_10_12* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Bytes8_9_10_12";
    throw EnumException("Bytes8_9_10_12", aVal, ss.str());
  }
};

bool Bytes8_9_10_12::enumerationForValueExists(int aVal) {
  Bytes8_9_10_12* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Bytes8_9_10_12::enumContainer Bytes8_9_10_12::getEnumerations() {
  return (enumerations);
};

Bytes8_9_10_12& Bytes8_9_10_12::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

