#include <sstream>
#include <cstddef>
#include <disenum/AuxiliaryCraft.h>

namespace DIS {


hashMap<int,AuxiliaryCraft*> AuxiliaryCraft::enumerations;

AuxiliaryCraft AuxiliaryCraft::LIFE_BOATS(10000, "life boats");
AuxiliaryCraft AuxiliaryCraft::LANDING_CRAFT(10010, "landing craft");
AuxiliaryCraft AuxiliaryCraft::EJECTION_SEATS(10020, "ejection seats");
AuxiliaryCraft AuxiliaryCraft::MISSING_DESCRIPTION(10030, "Missing Description");


AuxiliaryCraft::AuxiliaryCraft(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AuxiliaryCraft* AuxiliaryCraft::findEnumeration(int aVal) {
  AuxiliaryCraft* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AuxiliaryCraft::getDescriptionForValue(int aVal) {
  AuxiliaryCraft* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AuxiliaryCraft AuxiliaryCraft::getEnumerationForValue(int aVal) throw(EnumException) {
  AuxiliaryCraft* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AuxiliaryCraft";
    throw EnumException("AuxiliaryCraft", aVal, ss.str());
  }
};

bool AuxiliaryCraft::enumerationForValueExists(int aVal) {
  AuxiliaryCraft* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AuxiliaryCraft::enumContainer AuxiliaryCraft::getEnumerations() {
  return (enumerations);
};

AuxiliaryCraft& AuxiliaryCraft::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

