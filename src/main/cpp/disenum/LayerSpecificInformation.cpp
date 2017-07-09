#include <sstream>
#include <cstddef>
#include <disenum/LayerSpecificInformation.h>

namespace DIS {


hashMap<int,LayerSpecificInformation*> LayerSpecificInformation::enumerations;

LayerSpecificInformation LayerSpecificInformation::OTHER(0, "Other");


LayerSpecificInformation::LayerSpecificInformation(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

LayerSpecificInformation* LayerSpecificInformation::findEnumeration(int aVal) {
  LayerSpecificInformation* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string LayerSpecificInformation::getDescriptionForValue(int aVal) {
  LayerSpecificInformation* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

LayerSpecificInformation LayerSpecificInformation::getEnumerationForValue(int aVal) throw(EnumException) {
  LayerSpecificInformation* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration LayerSpecificInformation";
    throw EnumException("LayerSpecificInformation", aVal, ss.str());
  }
};

bool LayerSpecificInformation::enumerationForValueExists(int aVal) {
  LayerSpecificInformation* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

LayerSpecificInformation::enumContainer LayerSpecificInformation::getEnumerations() {
  return (enumerations);
};

LayerSpecificInformation& LayerSpecificInformation::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

