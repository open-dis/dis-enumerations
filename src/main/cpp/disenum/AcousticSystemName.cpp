#include <sstream>
#include <cstddef>
#include <disenum/AcousticSystemName.h>

namespace DIS {


hashMap<int,AcousticSystemName*> AcousticSystemName::enumerations;

AcousticSystemName AcousticSystemName::OTHER(0, "Other");
AcousticSystemName AcousticSystemName::AN_BQQ_5(1, "AN/BQQ-5");
AcousticSystemName AcousticSystemName::AN_SSQ_62(2, "AN/SSQ-62");
AcousticSystemName AcousticSystemName::AN_SQS_23(3, "AN/SQS-23");
AcousticSystemName AcousticSystemName::AN_SQS_26(4, "AN/SQS-26");
AcousticSystemName AcousticSystemName::AN_SQS_53(5, "AN/SQS-53");
AcousticSystemName AcousticSystemName::ALFS(6, "ALFS");
AcousticSystemName AcousticSystemName::LFA(7, "LFA");
AcousticSystemName AcousticSystemName::AN_AQS_901(8, "AN/AQS-901");
AcousticSystemName AcousticSystemName::AN_AQS_902(9, "AN/AQS-902");


AcousticSystemName::AcousticSystemName(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

AcousticSystemName* AcousticSystemName::findEnumeration(int aVal) {
  AcousticSystemName* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string AcousticSystemName::getDescriptionForValue(int aVal) {
  AcousticSystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

AcousticSystemName AcousticSystemName::getEnumerationForValue(int aVal) throw(EnumException) {
  AcousticSystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration AcousticSystemName";
    throw EnumException("AcousticSystemName", aVal, ss.str());
  }
};

bool AcousticSystemName::enumerationForValueExists(int aVal) {
  AcousticSystemName* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

AcousticSystemName::enumContainer AcousticSystemName::getEnumerations() {
  return (enumerations);
};

AcousticSystemName& AcousticSystemName::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

