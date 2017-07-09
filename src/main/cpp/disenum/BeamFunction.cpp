#include <sstream>
#include <cstddef>
#include <disenum/BeamFunction.h>

namespace DIS {


hashMap<int,BeamFunction*> BeamFunction::enumerations;

BeamFunction BeamFunction::OTHER(0, "Other");
BeamFunction BeamFunction::SEARCH(1, "Search");
BeamFunction BeamFunction::HEIGHT_FINDER(2, "Height finder");
BeamFunction BeamFunction::ACQUISITION(3, "Acquisition");
BeamFunction BeamFunction::TRACKING(4, "Tracking");
BeamFunction BeamFunction::ACQUISITION_AND_TRACKING(5, "Acquisition and tracking");
BeamFunction BeamFunction::COMMAND_GUIDANCE(6, "Command guidance");
BeamFunction BeamFunction::ILLUMINATION(7, "Illumination");
BeamFunction BeamFunction::RANGE_ONLY_RADAR(8, "Range only radar");
BeamFunction BeamFunction::MISSILE_BEACON(9, "Missile beacon");
BeamFunction BeamFunction::MISSILE_FUZE(10, "Missile fuze");
BeamFunction BeamFunction::ACTIVE_RADAR_MISSILE_SEEKER(11, "Active radar missile seeker");
BeamFunction BeamFunction::JAMMER(12, "Jammer");
BeamFunction BeamFunction::IFF(13, "IFF");
BeamFunction BeamFunction::NAVIGATIONAL_WEATHER(14, "Navigational / Weather");
BeamFunction BeamFunction::METEOROLOGICAL(15, "Meteorological");
BeamFunction BeamFunction::DATA_TRANSMISSION(16, "Data transmission");
BeamFunction BeamFunction::NAVIGATIONAL_DIRECTIONAL_BEACON(17, "Navigational directional beacon");


BeamFunction::BeamFunction(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

BeamFunction* BeamFunction::findEnumeration(int aVal) {
  BeamFunction* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string BeamFunction::getDescriptionForValue(int aVal) {
  BeamFunction* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

BeamFunction BeamFunction::getEnumerationForValue(int aVal) throw(EnumException) {
  BeamFunction* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration BeamFunction";
    throw EnumException("BeamFunction", aVal, ss.str());
  }
};

bool BeamFunction::enumerationForValueExists(int aVal) {
  BeamFunction* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

BeamFunction::enumContainer BeamFunction::getEnumerations() {
  return (enumerations);
};

BeamFunction& BeamFunction::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

