#include <sstream>
#include <cstddef>
#include <disenum/ActiveEmissionParameterIndex.h>

namespace DIS {


hashMap<int,ActiveEmissionParameterIndex*> ActiveEmissionParameterIndex::enumerations;

ActiveEmissionParameterIndex ActiveEmissionParameterIndex::OTHER(0, "Other");


ActiveEmissionParameterIndex::ActiveEmissionParameterIndex(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ActiveEmissionParameterIndex* ActiveEmissionParameterIndex::findEnumeration(int aVal) {
  ActiveEmissionParameterIndex* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ActiveEmissionParameterIndex::getDescriptionForValue(int aVal) {
  ActiveEmissionParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ActiveEmissionParameterIndex ActiveEmissionParameterIndex::getEnumerationForValue(int aVal) throw(EnumException) {
  ActiveEmissionParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ActiveEmissionParameterIndex";
    throw EnumException("ActiveEmissionParameterIndex", aVal, ss.str());
  }
};

bool ActiveEmissionParameterIndex::enumerationForValueExists(int aVal) {
  ActiveEmissionParameterIndex* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ActiveEmissionParameterIndex::enumContainer ActiveEmissionParameterIndex::getEnumerations() {
  return (enumerations);
};

ActiveEmissionParameterIndex& ActiveEmissionParameterIndex::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

