#include <sstream>
#include <cstddef>
#include <disenum/Position.h>

namespace DIS {


hashMap<int,Position*> Position::enumerations;

Position Position::OTHER(0, "Other");
Position Position::ON_TOP_OF(1, "On top of");
Position Position::INSIDE_OF(2, "Inside of");


Position::Position(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Position* Position::findEnumeration(int aVal) {
  Position* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Position::getDescriptionForValue(int aVal) {
  Position* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Position Position::getEnumerationForValue(int aVal) throw(EnumException) {
  Position* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Position";
    throw EnumException("Position", aVal, ss.str());
  }
};

bool Position::enumerationForValueExists(int aVal) {
  Position* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Position::enumContainer Position::getEnumerations() {
  return (enumerations);
};

Position& Position::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

