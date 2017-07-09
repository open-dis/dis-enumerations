#include <sstream>
#include <cstddef>
#include <disenum/ProtocolFamily.h>

namespace DIS {


hashMap<int,ProtocolFamily*> ProtocolFamily::enumerations;

ProtocolFamily ProtocolFamily::OTHER(0, "Other");
ProtocolFamily ProtocolFamily::ENTITY_INFORMATION_INTERACTION(1, "Entity Information/Interaction");
ProtocolFamily ProtocolFamily::WARFARE(2, "Warfare");
ProtocolFamily ProtocolFamily::LOGISTICS(3, "Logistics");
ProtocolFamily ProtocolFamily::RADIO_COMMUNICATION(4, "Radio Communication");
ProtocolFamily ProtocolFamily::SIMULATION_MANAGEMENT(5, "Simulation Management");
ProtocolFamily ProtocolFamily::DISTRIBUTED_EMISSION_REGENERATION(6, "Distributed Emission Regeneration");
ProtocolFamily ProtocolFamily::ENTITY_MANAGEMENT(7, "Entity Management");
ProtocolFamily ProtocolFamily::MINEFIELD(8, "Minefield");
ProtocolFamily ProtocolFamily::SYNTHETIC_ENVIRONMENT(9, "Synthetic Environment");
ProtocolFamily ProtocolFamily::SIMULATION_MANAGEMENT_WITH_RELIABILITY(10, "Simulation Management with Reliability");
ProtocolFamily ProtocolFamily::LIVE_ENTITY(11, "Live Entity");
ProtocolFamily ProtocolFamily::NON_REAL_TIME(12, "Non-Real Time");
ProtocolFamily ProtocolFamily::EXPERIMENTAL_COMPUTER_GENERATED_FORCES(129, "Experimental - Computer Generated Forces");


ProtocolFamily::ProtocolFamily(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ProtocolFamily* ProtocolFamily::findEnumeration(int aVal) {
  ProtocolFamily* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ProtocolFamily::getDescriptionForValue(int aVal) {
  ProtocolFamily* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ProtocolFamily ProtocolFamily::getEnumerationForValue(int aVal) throw(EnumException) {
  ProtocolFamily* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ProtocolFamily";
    throw EnumException("ProtocolFamily", aVal, ss.str());
  }
};

bool ProtocolFamily::enumerationForValueExists(int aVal) {
  ProtocolFamily* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ProtocolFamily::enumContainer ProtocolFamily::getEnumerations() {
  return (enumerations);
};

ProtocolFamily& ProtocolFamily::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

