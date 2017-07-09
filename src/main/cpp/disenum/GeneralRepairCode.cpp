#include <sstream>
#include <cstddef>
#include <disenum/GeneralRepairCode.h>

namespace DIS {


hashMap<int,GeneralRepairCode*> GeneralRepairCode::enumerations;

GeneralRepairCode GeneralRepairCode::NO_REPAIRS_PERFORMED(0, "no repairs performed");
GeneralRepairCode GeneralRepairCode::ALL_REQUESTED_REPAIRS_PERFORMED(1, "all requested repairs performed");


GeneralRepairCode::GeneralRepairCode(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

GeneralRepairCode* GeneralRepairCode::findEnumeration(int aVal) {
  GeneralRepairCode* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string GeneralRepairCode::getDescriptionForValue(int aVal) {
  GeneralRepairCode* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

GeneralRepairCode GeneralRepairCode::getEnumerationForValue(int aVal) throw(EnumException) {
  GeneralRepairCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration GeneralRepairCode";
    throw EnumException("GeneralRepairCode", aVal, ss.str());
  }
};

bool GeneralRepairCode::enumerationForValueExists(int aVal) {
  GeneralRepairCode* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

GeneralRepairCode::enumContainer GeneralRepairCode::getEnumerations() {
  return (enumerations);
};

GeneralRepairCode& GeneralRepairCode::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

