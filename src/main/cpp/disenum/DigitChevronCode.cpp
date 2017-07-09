#include <sstream>
#include <cstddef>
#include <disenum/DigitChevronCode.h>

namespace DIS {


hashMap<int,DigitChevronCode*> DigitChevronCode::enumerations;

DigitChevronCode DigitChevronCode::X_0_9(0, "0-9");
DigitChevronCode DigitChevronCode::UNDERSCORE_0_9(10, "Underscore 0-9");
DigitChevronCode DigitChevronCode::E(69, "E");
DigitChevronCode DigitChevronCode::UNDERSCORE_E(101, "Underscore E");
DigitChevronCode DigitChevronCode::S(83, "S");
DigitChevronCode DigitChevronCode::UNDERSCORE_S(115, "Underscore S");
DigitChevronCode DigitChevronCode::X(88, "X");
DigitChevronCode DigitChevronCode::UNDERSCORE_X(120, "Underscore X");
DigitChevronCode DigitChevronCode::BLANK(32, "Blank");
DigitChevronCode DigitChevronCode::_CARET_(94, "^");
DigitChevronCode DigitChevronCode::_GT_(62, ">");
DigitChevronCode DigitChevronCode::INVERTED_CARROT(86, "inverted carrot");
DigitChevronCode DigitChevronCode::_LT_(60, "<");
DigitChevronCode DigitChevronCode::_CARET_AND_INVERTED_CARROT(126, "^ and inverted carrot");
DigitChevronCode DigitChevronCode::_LT_GT_(61, "< >");


DigitChevronCode::DigitChevronCode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DigitChevronCode* DigitChevronCode::findEnumeration(int aVal) {
  DigitChevronCode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DigitChevronCode::getDescriptionForValue(int aVal) {
  DigitChevronCode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DigitChevronCode DigitChevronCode::getEnumerationForValue(int aVal) throw(EnumException) {
  DigitChevronCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DigitChevronCode";
    throw EnumException("DigitChevronCode", aVal, ss.str());
  }
};

bool DigitChevronCode::enumerationForValueExists(int aVal) {
  DigitChevronCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DigitChevronCode::enumContainer DigitChevronCode::getEnumerations() {
  return (enumerations);
};

DigitChevronCode& DigitChevronCode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

