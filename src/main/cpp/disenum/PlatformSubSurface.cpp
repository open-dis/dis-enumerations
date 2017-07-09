#include <sstream>
#include <cstddef>
#include <disenum/PlatformSubSurface.h>

namespace DIS {


hashMap<int,PlatformSubSurface*> PlatformSubSurface::enumerations;

PlatformSubSurface PlatformSubSurface::OTHER(0, "Other");
PlatformSubSurface PlatformSubSurface::SSBN_NUCLEAR_BALLISTIC_MISSILE(1, "SSBN (Nuclear Ballistic Missile)");
PlatformSubSurface PlatformSubSurface::SSGN_NUCLEAR_GUIDED_MISSILE(2, "SSGN (Nuclear Guided Missile)");
PlatformSubSurface PlatformSubSurface::SSN_NUCLEAR_ATTACK_TORPEDO(3, "SSN (Nuclear Attack - Torpedo)");
PlatformSubSurface PlatformSubSurface::SSG_CONVENTIONAL_GUIDED_MISSILE(4, "SSG (Conventional Guided Missile)");
PlatformSubSurface PlatformSubSurface::SS_CONVENTIONAL_ATTACK_TORPEDO_PATROL(5, "SS (Conventional Attack - Torpedo, Patrol)");
PlatformSubSurface PlatformSubSurface::SSAN_NUCLEAR_AUXILIARY(6, "SSAN (Nuclear Auxiliary)");
PlatformSubSurface PlatformSubSurface::SSA_CONVENTIONAL_AUXILIARY(7, "SSA (Conventional Auxiliary)");


PlatformSubSurface::PlatformSubSurface(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatformSubSurface* PlatformSubSurface::findEnumeration(int aVal) {
  PlatformSubSurface* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatformSubSurface::getDescriptionForValue(int aVal) {
  PlatformSubSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatformSubSurface PlatformSubSurface::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatformSubSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatformSubSurface";
    throw EnumException("PlatformSubSurface", aVal, ss.str());
  }
};

bool PlatformSubSurface::enumerationForValueExists(int aVal) {
  PlatformSubSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatformSubSurface::enumContainer PlatformSubSurface::getEnumerations() {
  return (enumerations);
};

PlatformSubSurface& PlatformSubSurface::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

