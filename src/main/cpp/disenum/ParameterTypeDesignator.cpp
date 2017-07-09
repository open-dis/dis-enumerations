#include <sstream>
#include <cstddef>
#include <disenum/ParameterTypeDesignator.h>

namespace DIS {


hashMap<int,ParameterTypeDesignator*> ParameterTypeDesignator::enumerations;

ParameterTypeDesignator ParameterTypeDesignator::ARTICULATED_PART(0, "Articulated Part");
ParameterTypeDesignator ParameterTypeDesignator::ATTACHED_PART(1, "Attached Part");


ParameterTypeDesignator::ParameterTypeDesignator(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ParameterTypeDesignator* ParameterTypeDesignator::findEnumeration(int aVal) {
  ParameterTypeDesignator* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ParameterTypeDesignator::getDescriptionForValue(int aVal) {
  ParameterTypeDesignator* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ParameterTypeDesignator ParameterTypeDesignator::getEnumerationForValue(int aVal) throw(EnumException) {
  ParameterTypeDesignator* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ParameterTypeDesignator";
    throw EnumException("ParameterTypeDesignator", aVal, ss.str());
  }
};

bool ParameterTypeDesignator::enumerationForValueExists(int aVal) {
  ParameterTypeDesignator* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ParameterTypeDesignator::enumContainer ParameterTypeDesignator::getEnumerations() {
  return (enumerations);
};

ParameterTypeDesignator& ParameterTypeDesignator::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

