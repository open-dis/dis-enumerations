#include <sstream>
#include <cstddef>
#include <disenum/AttachedParts.h>

namespace DIS {


hashMap<int,AttachedParts*> AttachedParts::enumerations;

AttachedParts AttachedParts::NOTHING_EMPTY(0, "Nothing, Empty");
AttachedParts AttachedParts::SEQUENTIAL_IDS_FOR_MODEL_SPECIFIC_STATIONS(1, "Sequential IDs for model-specific stations");
AttachedParts AttachedParts::FUSELAGE_STATIONS(512, "Fuselage Stations");
AttachedParts AttachedParts::LEFT_WING_STATIONS(640, "Left-wing Stations");
AttachedParts AttachedParts::RIGHT_WING_STATIONS(768, "Right-wing Stations");
AttachedParts AttachedParts::M16A42_RIFLE(896, "M16A42 rifle");
AttachedParts AttachedParts::M249_SAW(897, "M249 SAW");
AttachedParts AttachedParts::M60_MACHINE_GUN(898, "M60 Machine gun");
AttachedParts AttachedParts::M203_GRENADE_LAUNCHER(899, "M203 Grenade Launcher");
AttachedParts AttachedParts::M136_AT4(900, "M136 AT4");
AttachedParts AttachedParts::M47_DRAGON(901, "M47 Dragon");
AttachedParts AttachedParts::AAWS_M_JAVELIN(902, "AAWS-M Javelin");
AttachedParts AttachedParts::M18A1_CLAYMORE_MINE(903, "M18A1 Claymore Mine");
AttachedParts AttachedParts::MK19_GRENADE_LAUNCHER(904, "MK19 Grenade Launcher");
AttachedParts AttachedParts::M2_MACHINE_GUN(905, "M2 Machine Gun");
AttachedParts AttachedParts::OTHER_ATTACHED_PARTS(906, "Other attached parts");


AttachedParts::AttachedParts(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AttachedParts* AttachedParts::findEnumeration(int aVal) {
  AttachedParts* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AttachedParts::getDescriptionForValue(int aVal) {
  AttachedParts* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AttachedParts AttachedParts::getEnumerationForValue(int aVal) throw(EnumException) {
  AttachedParts* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AttachedParts";
    throw EnumException("AttachedParts", aVal, ss.str());
  }
};

bool AttachedParts::enumerationForValueExists(int aVal) {
  AttachedParts* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AttachedParts::enumContainer AttachedParts::getEnumerations() {
  return (enumerations);
};

AttachedParts& AttachedParts::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

