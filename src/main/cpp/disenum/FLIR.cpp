#include <sstream>
#include <cstddef>
#include <disenum/FLIR.h>

namespace DIS {


hashMap<int,FLIR*> FLIR::enumerations;

FLIR FLIR::GENERIC_3_5(0, "Generic 3-5");
FLIR FLIR::GENERIC_8_12(1, "Generic 8-12");
FLIR FLIR::ASTAMIDS_I(2, "ASTAMIDS I");
FLIR FLIR::ASTAMIDS_II(3, "ASTAMIDS II");
FLIR FLIR::GSTAMIDS_3_5(4, "GSTAMIDS 3-5");
FLIR FLIR::GSTAMIDS_8_12(5, "GSTAMIDS 8-12");
FLIR FLIR::HSTAMIDS_3_5(6, "HSTAMIDS 3-5");
FLIR FLIR::HSTAMIDS_8_12(7, "HSTAMIDS 8-12");
FLIR FLIR::COBRA_3_5(8, "COBRA 3-5");
FLIR FLIR::COBRA_8_12(9, "COBRA 8-12");


FLIR::FLIR(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FLIR* FLIR::findEnumeration(int aVal) {
  FLIR* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FLIR::getDescriptionForValue(int aVal) {
  FLIR* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FLIR FLIR::getEnumerationForValue(int aVal) throw(EnumException) {
  FLIR* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FLIR";
    throw EnumException("FLIR", aVal, ss.str());
  }
};

bool FLIR::enumerationForValueExists(int aVal) {
  FLIR* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FLIR::enumContainer FLIR::getEnumerations() {
  return (enumerations);
};

FLIR& FLIR::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

