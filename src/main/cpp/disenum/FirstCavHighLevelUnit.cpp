#include <sstream>
#include <cstddef>
#include <disenum/FirstCavHighLevelUnit.h>

namespace DIS {


hashMap<int,FirstCavHighLevelUnit*> FirstCavHighLevelUnit::enumerations;

FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_7CAV(1, "1-7CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_2_5CAV(2, "2-5CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_2_8CAV(3, "2-8CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_3_32AR(4, "3-32AR");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_5CAV(5, "1-5CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_8CAV(6, "1-8CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_32AR(7, "1-32AR");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_67AR(8, "1-67AR");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_3_67AR(9, "3-67AR");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_3_41INF(10, "3-41INF");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_82F(20, "1-82F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_3_82F(21, "3-82F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_3F(22, "1-3F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_21F(23, "21F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_92F(24, "92F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_8E(30, "8E");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_20E(31, "20E");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_91E(32, "91E");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1_227AVN(34, "1-227AVN");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_4_227AVN(35, "4-227AVN");
FirstCavHighLevelUnit FirstCavHighLevelUnit::F_227AVN(36, "F-227AVN");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_4_5ADA(37, "4-5ADA");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_15MSB(40, "15MSB");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_27FSB(41, "27FSB");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_115FSB(42, "115FSB");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_215FSB(43, "215FSB");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_312MI(45, "312MI");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_13S(46, "13S");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_545MP(47, "545MP");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_68CML(48, "68CML");
FirstCavHighLevelUnit FirstCavHighLevelUnit::X_1CAV(50, "1CAV");
FirstCavHighLevelUnit FirstCavHighLevelUnit::XBDE(51, "XBDE");
FirstCavHighLevelUnit FirstCavHighLevelUnit::AVNBDE(55, "AVNBDE");
FirstCavHighLevelUnit FirstCavHighLevelUnit::E(56, "E");
FirstCavHighLevelUnit FirstCavHighLevelUnit::F(57, "F");
FirstCavHighLevelUnit FirstCavHighLevelUnit::DSC(58, "DSC");


FirstCavHighLevelUnit::FirstCavHighLevelUnit(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

FirstCavHighLevelUnit* FirstCavHighLevelUnit::findEnumeration(int aVal) {
  FirstCavHighLevelUnit* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string FirstCavHighLevelUnit::getDescriptionForValue(int aVal) {
  FirstCavHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

FirstCavHighLevelUnit FirstCavHighLevelUnit::getEnumerationForValue(int aVal) throw(EnumException) {
  FirstCavHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration FirstCavHighLevelUnit";
    throw EnumException("FirstCavHighLevelUnit", aVal, ss.str());
  }
};

bool FirstCavHighLevelUnit::enumerationForValueExists(int aVal) {
  FirstCavHighLevelUnit* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

FirstCavHighLevelUnit::enumContainer FirstCavHighLevelUnit::getEnumerations() {
  return (enumerations);
};

FirstCavHighLevelUnit& FirstCavHighLevelUnit::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

