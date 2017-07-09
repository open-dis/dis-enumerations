#include <sstream>
#include <cstddef>
#include <disenum/FuelSystems.h>

namespace DIS {


hashMap<int,FuelSystems*> FuelSystems::enumerations;

FuelSystems FuelSystems::FUEL_TRANSFER_PUMP(4000, "fuel transfer pump");
FuelSystems FuelSystems::FUEL_LINES(4010, "fuel lines");
FuelSystems FuelSystems::GAUGES(4020, "gauges");
FuelSystems FuelSystems::GENERAL_FUEL_SYSTEM(4030, "general fuel system");
FuelSystems FuelSystems::MISSING_DESCRIPTION(4031, "Missing Description");


FuelSystems::FuelSystems(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FuelSystems* FuelSystems::findEnumeration(int aVal) {
  FuelSystems* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FuelSystems::getDescriptionForValue(int aVal) {
  FuelSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FuelSystems FuelSystems::getEnumerationForValue(int aVal) throw(EnumException) {
  FuelSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FuelSystems";
    throw EnumException("FuelSystems", aVal, ss.str());
  }
};

bool FuelSystems::enumerationForValueExists(int aVal) {
  FuelSystems* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FuelSystems::enumContainer FuelSystems::getEnumerations() {
  return (enumerations);
};

FuelSystems& FuelSystems::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

