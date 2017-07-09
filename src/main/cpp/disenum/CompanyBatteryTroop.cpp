#include <sstream>
#include <cstddef>
#include <disenum/CompanyBatteryTroop.h>

namespace DIS {


hashMap<int,CompanyBatteryTroop*> CompanyBatteryTroop::enumerations;

CompanyBatteryTroop CompanyBatteryTroop::A_M(66, "A-M");
CompanyBatteryTroop CompanyBatteryTroop::HQ(113, "HQ");
CompanyBatteryTroop CompanyBatteryTroop::HHB(98, "HHB");
CompanyBatteryTroop CompanyBatteryTroop::HHC(99, "HHC");
CompanyBatteryTroop CompanyBatteryTroop::HHD(100, "HHD");
CompanyBatteryTroop CompanyBatteryTroop::HHT(116, "HHT");


CompanyBatteryTroop::CompanyBatteryTroop(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CompanyBatteryTroop* CompanyBatteryTroop::findEnumeration(int aVal) {
  CompanyBatteryTroop* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CompanyBatteryTroop::getDescriptionForValue(int aVal) {
  CompanyBatteryTroop* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CompanyBatteryTroop CompanyBatteryTroop::getEnumerationForValue(int aVal) throw(EnumException) {
  CompanyBatteryTroop* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CompanyBatteryTroop";
    throw EnumException("CompanyBatteryTroop", aVal, ss.str());
  }
};

bool CompanyBatteryTroop::enumerationForValueExists(int aVal) {
  CompanyBatteryTroop* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CompanyBatteryTroop::enumContainer CompanyBatteryTroop::getEnumerations() {
  return (enumerations);
};

CompanyBatteryTroop& CompanyBatteryTroop::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

