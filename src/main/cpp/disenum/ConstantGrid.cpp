#include <sstream>
#include <cstddef>
#include <disenum/ConstantGrid.h>

namespace DIS {


hashMap<int,ConstantGrid*> ConstantGrid::enumerations;

ConstantGrid ConstantGrid::CONSTANT_GRID(0, "Constant grid");
ConstantGrid ConstantGrid::UPDATED_GRID(1, "Updated grid");


ConstantGrid::ConstantGrid(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ConstantGrid* ConstantGrid::findEnumeration(int aVal) {
  ConstantGrid* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ConstantGrid::getDescriptionForValue(int aVal) {
  ConstantGrid* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ConstantGrid ConstantGrid::getEnumerationForValue(int aVal) throw(EnumException) {
  ConstantGrid* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ConstantGrid";
    throw EnumException("ConstantGrid", aVal, ss.str());
  }
};

bool ConstantGrid::enumerationForValueExists(int aVal) {
  ConstantGrid* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ConstantGrid::enumContainer ConstantGrid::getEnumerations() {
  return (enumerations);
};

ConstantGrid& ConstantGrid::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

