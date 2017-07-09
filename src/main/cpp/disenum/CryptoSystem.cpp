#include <sstream>
#include <cstddef>
#include <disenum/CryptoSystem.h>

namespace DIS {


hashMap<int,CryptoSystem*> CryptoSystem::enumerations;

CryptoSystem CryptoSystem::OTHER(0, "Other");
CryptoSystem CryptoSystem::KY_28(1, "KY-28");
CryptoSystem CryptoSystem::VINSON_KY_57_KY_58_SINCGARS_ICOM(2, "VINSON (KY-57, KY-58, SINCGARS ICOM)");
CryptoSystem CryptoSystem::NARROW_SPECTRUM_SECURE_VOICE_NSVE(3, "Narrow Spectrum Secure Voice (NSVE)");
CryptoSystem CryptoSystem::WIDE_SPECTRUM_SECURE_VOICE_WSVE(4, "Wide Spectrum Secure Voice (WSVE)");
CryptoSystem CryptoSystem::MISSING_DESCRIPTION(5, "Missing Description");


CryptoSystem::CryptoSystem(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CryptoSystem* CryptoSystem::findEnumeration(int aVal) {
  CryptoSystem* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CryptoSystem::getDescriptionForValue(int aVal) {
  CryptoSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CryptoSystem CryptoSystem::getEnumerationForValue(int aVal) throw(EnumException) {
  CryptoSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CryptoSystem";
    throw EnumException("CryptoSystem", aVal, ss.str());
  }
};

bool CryptoSystem::enumerationForValueExists(int aVal) {
  CryptoSystem* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CryptoSystem::enumContainer CryptoSystem::getEnumerations() {
  return (enumerations);
};

CryptoSystem& CryptoSystem::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

