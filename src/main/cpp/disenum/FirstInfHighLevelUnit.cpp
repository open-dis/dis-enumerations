#include <sstream>
#include <cstddef>
#include <disenum/FirstInfHighLevelUnit.h>

namespace DIS {


hashMap<int,FirstInfHighLevelUnit*> FirstInfHighLevelUnit::enumerations;

FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_16INF(1, "1-16INF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_2_16INF(2, "2-16INF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_34AR(3, "1-34AR");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_2_34AR(4, "2-34AR");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_3_37AR(5, "3-37AR");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_4_37AR(6, "4-37AR");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_118INF(7, "1-118INF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_4_118INF(8, "4-118INF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_2_265AR(9, "2-265AR");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_2_136IF(10, "2-136IF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_5F(20, "1-5F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_4_5F(21, "4-5F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_178F(22, "1-178F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_6F(23, "6F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_25F(24, "25F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1E(30, "1E");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_70E(31, "70E");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_4_1AVN(32, "4-1AVN");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_1AVN(33, "1-1AVN");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_2_3ADA(34, "2-3ADA");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1_4CAV(35, "1-4CAV");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_701MSB(40, "701MSB");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_101FSB(41, "101FSB");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_201FSB(42, "201FSB");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_163FSB(43, "163FSB");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_101MI(45, "101MI");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_121S(46, "121S");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1MP(47, "1MP");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_12CML(48, "12CML");
FirstInfHighLevelUnit FirstInfHighLevelUnit::X_1INF(50, "1INF");
FirstInfHighLevelUnit FirstInfHighLevelUnit::XBDE(51, "XBDE");
FirstInfHighLevelUnit FirstInfHighLevelUnit::AVNBDE(55, "AVNBDE");
FirstInfHighLevelUnit FirstInfHighLevelUnit::E(56, "E");
FirstInfHighLevelUnit FirstInfHighLevelUnit::F(57, "F");
FirstInfHighLevelUnit FirstInfHighLevelUnit::DSC(58, "DSC");


FirstInfHighLevelUnit::FirstInfHighLevelUnit(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FirstInfHighLevelUnit* FirstInfHighLevelUnit::findEnumeration(int aVal) {
  FirstInfHighLevelUnit* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FirstInfHighLevelUnit::getDescriptionForValue(int aVal) {
  FirstInfHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FirstInfHighLevelUnit FirstInfHighLevelUnit::getEnumerationForValue(int aVal) throw(EnumException) {
  FirstInfHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FirstInfHighLevelUnit";
    throw EnumException("FirstInfHighLevelUnit", aVal, ss.str());
  }
};

bool FirstInfHighLevelUnit::enumerationForValueExists(int aVal) {
  FirstInfHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FirstInfHighLevelUnit::enumContainer FirstInfHighLevelUnit::getEnumerations() {
  return (enumerations);
};

FirstInfHighLevelUnit& FirstInfHighLevelUnit::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

