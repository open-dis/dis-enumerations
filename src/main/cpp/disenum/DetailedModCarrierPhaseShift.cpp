#include <sstream>
#include <cstddef>
#include <disenum/DetailedModCarrierPhaseShift.h>

namespace DIS {


hashMap<int,DetailedModCarrierPhaseShift*> DetailedModCarrierPhaseShift::enumerations;

DetailedModCarrierPhaseShift DetailedModCarrierPhaseShift::OTHER(0, "Other");


DetailedModCarrierPhaseShift::DetailedModCarrierPhaseShift(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DetailedModCarrierPhaseShift* DetailedModCarrierPhaseShift::findEnumeration(int aVal) {
  DetailedModCarrierPhaseShift* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DetailedModCarrierPhaseShift::getDescriptionForValue(int aVal) {
  DetailedModCarrierPhaseShift* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DetailedModCarrierPhaseShift DetailedModCarrierPhaseShift::getEnumerationForValue(int aVal) throw(EnumException) {
  DetailedModCarrierPhaseShift* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DetailedModCarrierPhaseShift";
    throw EnumException("DetailedModCarrierPhaseShift", aVal, ss.str());
  }
};

bool DetailedModCarrierPhaseShift::enumerationForValueExists(int aVal) {
  DetailedModCarrierPhaseShift* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DetailedModCarrierPhaseShift::enumContainer DetailedModCarrierPhaseShift::getEnumerations() {
  return (enumerations);
};

DetailedModCarrierPhaseShift& DetailedModCarrierPhaseShift::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

