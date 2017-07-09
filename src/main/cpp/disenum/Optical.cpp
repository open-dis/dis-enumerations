#include <sstream>
#include <cstddef>
#include <disenum/Optical.h>

namespace DIS {


hashMap<int,Optical*> Optical::enumerations;

Optical Optical::UNAIDED_EYE_ACTIVELY_SEARCHING(0, "Unaided Eye, Actively Searching");
Optical Optical::UNAIDED_EYE_NOT_ACTIVELY_SEARCHING(1, "Unaided Eye, Not Actively Searching");
Optical Optical::BINOCULARS(2, "Binoculars");
Optical Optical::IMAGE_INTENSIFIER(3, "Image Intensifier");
Optical Optical::HMMWV_OCCUPANT_ACTIVELY_SEARCHING(4, "HMMWV occupant, Actively Searching");
Optical Optical::HMMWV_OCCUPANT_NOT_ACTIVELY_SEARCHING(5, "HMMWV occupant, Not Actively Searching");
Optical Optical::TRUCK_OCCUPANT_ACTIVELY_SEARCHING(6, "Truck occupant, Actively Searching");
Optical Optical::TRUCK_OCCUPANT_NOT_ACTIVELY_SEARCHING(7, "Truck occupant, Not Actively Searching");
Optical Optical::TRACKED_VEHICLE_OCCUPANT_CLOSED_HATCH_ACTIVELY_SEARCHING(8, "Tracked vehicle occupant, closed hatch, Actively Searching");
Optical Optical::TRACKED_VEHICLE_OCCUPANT_CLOSED_HATCH_NOT_ACTIVELY_SEARCHING(9, "Tracked vehicle occupant, closed hatch, Not Actively Searching");
Optical Optical::TRACKED_VEHICLE_OCCUPANT_OPEN_HATCH_ACTIVELY_SEARCHING(10, "Tracked vehicle occupant, open hatch, Actively Searching");
Optical Optical::TRACKED_VEHICLE_OCCUPANT_OPEN_HATCH_NOT_ACTIVELY_SEARCHING(11, "Tracked vehicle occupant, open hatch, Not Actively Searching");


Optical::Optical(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Optical* Optical::findEnumeration(int aVal) {
  Optical* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Optical::getDescriptionForValue(int aVal) {
  Optical* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Optical Optical::getEnumerationForValue(int aVal) throw(EnumException) {
  Optical* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Optical";
    throw EnumException("Optical", aVal, ss.str());
  }
};

bool Optical::enumerationForValueExists(int aVal) {
  Optical* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Optical::enumContainer Optical::getEnumerations() {
  return (enumerations);
};

Optical& Optical::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

