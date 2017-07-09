#include <sstream>
#include <cstddef>
#include <disenum/RadioNomenclature.h>

namespace DIS {


hashMap<int,RadioNomenclature*> RadioNomenclature::enumerations;

RadioNomenclature RadioNomenclature::OTHER(0, "Other");
RadioNomenclature RadioNomenclature::AN_ARN_118(1, "AN/ARN-118");
RadioNomenclature RadioNomenclature::AN_ARN_139(2, "AN/ARN-139");
RadioNomenclature RadioNomenclature::GENERIC_GROUND_FIXED_TRANSMITTER(3, "Generic Ground Fixed Transmitter");
RadioNomenclature RadioNomenclature::GENERIC_GROUND_MOBILE_TRANSMITTER(4, "Generic Ground Mobile Transmitter");


RadioNomenclature::RadioNomenclature(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

RadioNomenclature* RadioNomenclature::findEnumeration(int aVal) {
  RadioNomenclature* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string RadioNomenclature::getDescriptionForValue(int aVal) {
  RadioNomenclature* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

RadioNomenclature RadioNomenclature::getEnumerationForValue(int aVal) throw(EnumException) {
  RadioNomenclature* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration RadioNomenclature";
    throw EnumException("RadioNomenclature", aVal, ss.str());
  }
};

bool RadioNomenclature::enumerationForValueExists(int aVal) {
  RadioNomenclature* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

RadioNomenclature::enumContainer RadioNomenclature::getEnumerations() {
  return (enumerations);
};

RadioNomenclature& RadioNomenclature::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

