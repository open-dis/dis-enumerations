#include <sstream>
#include <cstddef>
#include <disenum/ForceID.h>

namespace DIS {


hashMap<int,ForceID*> ForceID::enumerations;

ForceID ForceID::OTHER(0, "Other");
ForceID ForceID::FRIENDLY(1, "Friendly");
ForceID ForceID::OPPOSING(2, "Opposing");
ForceID ForceID::NEUTRAL(3, "Neutral");
ForceID ForceID::FRIENDLY_2(4, "Friendly 2");
ForceID ForceID::OPPOSING_2(5, "Opposing 2");
ForceID ForceID::NEUTRAL_2(6, "Neutral 2");
ForceID ForceID::FRIENDLY_3(7, "Friendly 3");
ForceID ForceID::OPPOSING_3(8, "Opposing 3");
ForceID ForceID::NEUTRAL_3(9, "Neutral 3");
ForceID ForceID::FRIENDLY_4(10, "Friendly 4");
ForceID ForceID::OPPOSING_4(11, "Opposing 4");
ForceID ForceID::NEUTRAL_4(12, "Neutral 4");
ForceID ForceID::FRIENDLY_5(13, "Friendly 5");
ForceID ForceID::OPPOSING_5(14, "Opposing 5");
ForceID ForceID::NEUTRAL_5(15, "Neutral 5");
ForceID ForceID::FRIENDLY_6(16, "Friendly 6");
ForceID ForceID::OPPOSING_6(17, "Opposing 6");
ForceID ForceID::NEUTRAL_6(18, "Neutral 6");
ForceID ForceID::FRIENDLY_7(19, "Friendly 7");
ForceID ForceID::OPPOSING_7(20, "Opposing 7");
ForceID ForceID::NEUTRAL_7(21, "Neutral 7");
ForceID ForceID::FRIENDLY_8(22, "Friendly 8");
ForceID ForceID::OPPOSING_8(23, "Opposing 8");
ForceID ForceID::NEUTRAL_8(24, "Neutral 8");
ForceID ForceID::FRIENDLY_9(25, "Friendly 9");
ForceID ForceID::OPPOSING_9(26, "Opposing 9");
ForceID ForceID::NEUTRAL_9(27, "Neutral 9");
ForceID ForceID::FRIENDLY_10(28, "Friendly 10");
ForceID ForceID::OPPOSING_10(29, "Opposing 10");
ForceID ForceID::NEUTRAL_10(30, "Neutral 10");


ForceID::ForceID(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ForceID* ForceID::findEnumeration(int aVal) {
  ForceID* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ForceID::getDescriptionForValue(int aVal) {
  ForceID* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ForceID ForceID::getEnumerationForValue(int aVal) throw(EnumException) {
  ForceID* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ForceID";
    throw EnumException("ForceID", aVal, ss.str());
  }
};

bool ForceID::enumerationForValueExists(int aVal) {
  ForceID* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ForceID::enumContainer ForceID::getEnumerations() {
  return (enumerations);
};

ForceID& ForceID::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

