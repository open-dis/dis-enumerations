#include <sstream>
#include <cstddef>
#include <disenum/DivisionCorpsDesignation.h>

namespace DIS {


hashMap<int,DivisionCorpsDesignation*> DivisionCorpsDesignation::enumerations;

DivisionCorpsDesignation DivisionCorpsDesignation::NA_CASE(0, "NA case");
DivisionCorpsDesignation DivisionCorpsDesignation::X_1ST_CAVALRY(1, "1st Cavalry");
DivisionCorpsDesignation DivisionCorpsDesignation::X_1ST_INFANTRY(2, "1st Infantry");
DivisionCorpsDesignation DivisionCorpsDesignation::CORPS_ASSETS(3, "Corps Assets");


DivisionCorpsDesignation::DivisionCorpsDesignation(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DivisionCorpsDesignation* DivisionCorpsDesignation::findEnumeration(int aVal) {
  DivisionCorpsDesignation* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DivisionCorpsDesignation::getDescriptionForValue(int aVal) {
  DivisionCorpsDesignation* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DivisionCorpsDesignation DivisionCorpsDesignation::getEnumerationForValue(int aVal) throw(EnumException) {
  DivisionCorpsDesignation* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DivisionCorpsDesignation";
    throw EnumException("DivisionCorpsDesignation", aVal, ss.str());
  }
};

bool DivisionCorpsDesignation::enumerationForValueExists(int aVal) {
  DivisionCorpsDesignation* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DivisionCorpsDesignation::enumContainer DivisionCorpsDesignation::getEnumerations() {
  return (enumerations);
};

DivisionCorpsDesignation& DivisionCorpsDesignation::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

