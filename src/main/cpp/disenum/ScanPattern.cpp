#include <sstream>
#include <cstddef>
#include <disenum/ScanPattern.h>

namespace DIS {


hashMap<int,ScanPattern*> ScanPattern::enumerations;

ScanPattern ScanPattern::SCAN_PATTERN_NOT_USED(0, "Scan pattern not used");
ScanPattern ScanPattern::CONICAL(1, "Conical");
ScanPattern ScanPattern::HELICAL(2, "Helical");
ScanPattern ScanPattern::RASTER(3, "Raster");
ScanPattern ScanPattern::SECTOR_SEARCH(4, "Sector search");
ScanPattern ScanPattern::CONTINUOUS_SEARCH(5, "Continuous search");


ScanPattern::ScanPattern(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ScanPattern* ScanPattern::findEnumeration(int aVal) {
  ScanPattern* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ScanPattern::getDescriptionForValue(int aVal) {
  ScanPattern* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ScanPattern ScanPattern::getEnumerationForValue(int aVal) throw(EnumException) {
  ScanPattern* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ScanPattern";
    throw EnumException("ScanPattern", aVal, ss.str());
  }
};

bool ScanPattern::enumerationForValueExists(int aVal) {
  ScanPattern* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ScanPattern::enumContainer ScanPattern::getEnumerations() {
  return (enumerations);
};

ScanPattern& ScanPattern::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

