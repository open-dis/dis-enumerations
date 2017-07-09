#include <sstream>
#include <cstddef>
#include <disenum/RadioNomenclatureVersion.h>

namespace DIS {


hashMap<int,RadioNomenclatureVersion*> RadioNomenclatureVersion::enumerations;

RadioNomenclatureVersion RadioNomenclatureVersion::OTHER(0, "Other");
RadioNomenclatureVersion RadioNomenclatureVersion::JOINT_ELECTRONICS_TYPE_DESIGNATION_SYSTEM_JETDS_NOMENCLATURE_AN_PER_MIL_STD_196(1, "Joint Electronics Type Designation System (JETDS) Nomenclature (AN/ per Mil-STD-196)");
RadioNomenclatureVersion RadioNomenclatureVersion::MANUFACTURER_DESIGNATION(2, "Manufacturer Designation");
RadioNomenclatureVersion RadioNomenclatureVersion::NATIONAL_DESIGNATION(3, "National Designation");


RadioNomenclatureVersion::RadioNomenclatureVersion(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RadioNomenclatureVersion* RadioNomenclatureVersion::findEnumeration(int aVal) {
  RadioNomenclatureVersion* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RadioNomenclatureVersion::getDescriptionForValue(int aVal) {
  RadioNomenclatureVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RadioNomenclatureVersion RadioNomenclatureVersion::getEnumerationForValue(int aVal) throw(EnumException) {
  RadioNomenclatureVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RadioNomenclatureVersion";
    throw EnumException("RadioNomenclatureVersion", aVal, ss.str());
  }
};

bool RadioNomenclatureVersion::enumerationForValueExists(int aVal) {
  RadioNomenclatureVersion* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RadioNomenclatureVersion::enumContainer RadioNomenclatureVersion::getEnumerations() {
  return (enumerations);
};

RadioNomenclatureVersion& RadioNomenclatureVersion::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

