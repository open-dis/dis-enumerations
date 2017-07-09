#include <sstream>
#include <cstddef>
#include <disenum/Formation.h>

namespace DIS {


hashMap<int,Formation*> Formation::enumerations;

Formation Formation::OTHER(0, "Other");
Formation Formation::ASSEMBLY(1, "Assembly");
Formation Formation::VEE(2, "Vee");
Formation Formation::WEDGE(3, "Wedge");
Formation Formation::LINE(4, "Line");
Formation Formation::COLUMN(5, "Column");


Formation::Formation(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Formation* Formation::findEnumeration(int aVal) {
  Formation* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Formation::getDescriptionForValue(int aVal) {
  Formation* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Formation Formation::getEnumerationForValue(int aVal) throw(EnumException) {
  Formation* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Formation";
    throw EnumException("Formation", aVal, ss.str());
  }
};

bool Formation::enumerationForValueExists(int aVal) {
  Formation* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Formation::enumContainer Formation::getEnumerations() {
  return (enumerations);
};

Formation& Formation::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

