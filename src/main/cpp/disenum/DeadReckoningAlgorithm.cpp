#include <sstream>
#include <cstddef>
#include <disenum/DeadReckoningAlgorithm.h>

namespace DIS {


hashMap<int,DeadReckoningAlgorithm*> DeadReckoningAlgorithm::enumerations;

DeadReckoningAlgorithm DeadReckoningAlgorithm::OTHER(0, "Other");
DeadReckoningAlgorithm DeadReckoningAlgorithm::STATIC_ENTITY_DOES_NOT_MOVE(1, "Static (Entity does not move.)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMF_P_W(2, "DRM(F, P, W)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMR_P_W(3, "DRM(R, P, W)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMR_V_W(4, "DRM(R, V, W)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMF_V_W(5, "DRM(F, V, W)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMF_P_B(6, "DRM(F, P, B)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMR_P_B(7, "DRM(R, P, B)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMR_V_B(8, "DRM(R, V, B)");
DeadReckoningAlgorithm DeadReckoningAlgorithm::DRMF_V_B(9, "DRM(F, V, B)");


DeadReckoningAlgorithm::DeadReckoningAlgorithm(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DeadReckoningAlgorithm* DeadReckoningAlgorithm::findEnumeration(int aVal) {
  DeadReckoningAlgorithm* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DeadReckoningAlgorithm::getDescriptionForValue(int aVal) {
  DeadReckoningAlgorithm* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DeadReckoningAlgorithm DeadReckoningAlgorithm::getEnumerationForValue(int aVal) throw(EnumException) {
  DeadReckoningAlgorithm* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DeadReckoningAlgorithm";
    throw EnumException("DeadReckoningAlgorithm", aVal, ss.str());
  }
};

bool DeadReckoningAlgorithm::enumerationForValueExists(int aVal) {
  DeadReckoningAlgorithm* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DeadReckoningAlgorithm::enumContainer DeadReckoningAlgorithm::getEnumerations() {
  return (enumerations);
};

DeadReckoningAlgorithm& DeadReckoningAlgorithm::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

