#include <sstream>
#include <cstddef>
#include <disenum/Warhead.h>

namespace DIS {


hashMap<int,Warhead*> Warhead::enumerations;

Warhead Warhead::OTHER(0, "Other");
Warhead Warhead::CARGO_VARIABLE_SUBMUNITIONS(10, "Cargo (Variable Submunitions)");
Warhead Warhead::FUEL_AIR_EXPLOSIVE(20, "Fuel/Air Explosive");
Warhead Warhead::GLASS_BEADS(30, "Glass Beads");
Warhead Warhead::X_1_UM(31, "1 um");
Warhead Warhead::X_5_UM(32, "5 um");
Warhead Warhead::X_10_UM(33, "10 um");
Warhead Warhead::HIGH_EXPLOSIVE_HE(1000, "High Explosive (HE)");
Warhead Warhead::HE_PLASTIC(1100, "HE, Plastic");
Warhead Warhead::HE_INCENDIARY(1200, "HE, Incendiary");
Warhead Warhead::HE_FRAGMENTATION(1300, "HE, Fragmentation");
Warhead Warhead::HE_ANTITANK(1400, "HE, Antitank");
Warhead Warhead::HE_BOMBLETS(1500, "HE, Bomblets");
Warhead Warhead::HE_SHAPED_CHARGE(1600, "HE, Shaped Charge");
Warhead Warhead::HE_CONTINUOUS_ROD(1610, "HE, Continuous Rod");
Warhead Warhead::HE_TUNGSTEN_BALL(1615, "HE, Tungsten Ball");
Warhead Warhead::HE_BLAST_FRAGMENTATION(1620, "HE, Blast Fragmentation");
Warhead Warhead::HE_STEERABLE_DARTS_WITH_HE(1625, "HE, Steerable Darts with HE");
Warhead Warhead::HE_DARTS(1630, "HE, Darts");
Warhead Warhead::HE_FLECHETTES(1635, "HE, Flechettes");
Warhead Warhead::HE_DIRECTED_FRAGMENTATION(1640, "HE, Directed Fragmentation");
Warhead Warhead::HE_SEMI_ARMOR_PIERCING_SAP(1645, "HE, Semi-Armor Piercing (SAP)");
Warhead Warhead::HE_SHAPED_CHARGE_FRAGMENTATION(1650, "HE, Shaped Charge Fragmentation");
Warhead Warhead::HE_SEMI_ARMOR_PIERCING_FRAGMENTATION(1655, "HE, Semi-Armor Piercing, Fragmentation");
Warhead Warhead::HE_HOLLOW_CHARGE(1660, "HE, Hollow Charge");
Warhead Warhead::HE_DOUBLE_HOLLOW_CHARGE(1665, "HE, Double Hollow Charge");
Warhead Warhead::HE_GENERAL_PURPOSE(1670, "HE, General Purpose");
Warhead Warhead::HE_BLAST_PENETRATOR(1675, "HE, Blast Penetrator");
Warhead Warhead::HE_ROD_PENETRATOR(1680, "HE, Rod Penetrator");
Warhead Warhead::HE_ANTIPERSONNEL(1685, "HE, Antipersonnel");
Warhead Warhead::SMOKE(2000, "Smoke");
Warhead Warhead::ILLUMINATION(3000, "Illumination");
Warhead Warhead::PRACTICE(4000, "Practice");
Warhead Warhead::KINETIC(5000, "Kinetic");
Warhead Warhead::MINES(6000, "Mines");
Warhead Warhead::NUCLEAR(7000, "Nuclear");
Warhead Warhead::NUCLEAR_IMT(7010, "Nuclear, IMT");
Warhead Warhead::CHEMICAL_GENERAL(8000, "Chemical, General");
Warhead Warhead::CHEMICAL_BLISTER_AGENT(8100, "Chemical, Blister Agent");
Warhead Warhead::HD_MUSTARD(8110, "HD (Mustard)");
Warhead Warhead::THICKENED_HD_MUSTARD(8115, "Thickened HD (Mustard)");
Warhead Warhead::DUSTY_HD_MUSTARD(8120, "Dusty HD (Mustard)");
Warhead Warhead::CHEMICAL_BLOOD_AGENT(8200, "Chemical, Blood Agent");
Warhead Warhead::AC_HCN(8210, "AC (HCN)");
Warhead Warhead::CK_CNCI(8215, "CK (CNCI)");
Warhead Warhead::CG_PHOSGENE(8220, "CG (Phosgene)");
Warhead Warhead::CHEMICAL_NERVE_AGENT(8300, "Chemical, Nerve Agent");
Warhead Warhead::VX(8310, "VX");
Warhead Warhead::THICKENED_VX(8315, "Thickened VX");
Warhead Warhead::DUSTY_VX(8320, "Dusty VX");
Warhead Warhead::GA_TABUN(8325, "GA (Tabun)");
Warhead Warhead::THICKENED_GA_TABUN(8330, "Thickened GA (Tabun)");
Warhead Warhead::DUSTY_GA_TABUN(8335, "Dusty GA (Tabun)");
Warhead Warhead::GB_SARIN(8340, "GB (Sarin)");
Warhead Warhead::THICKENED_GB_SARIN(8345, "Thickened GB (Sarin)");
Warhead Warhead::DUSTY_GB_SARIN(8350, "Dusty GB (Sarin)");
Warhead Warhead::GD_SOMAN(8355, "GD (Soman)");
Warhead Warhead::THICKENED_GD_SOMAN(8360, "Thickened GD (Soman)");
Warhead Warhead::DUSTY_GD_SOMAN(8365, "Dusty GD (Soman)");
Warhead Warhead::GF(8370, "GF");
Warhead Warhead::THICKENED_GF(8375, "Thickened GF");
Warhead Warhead::DUSTY_GF(8380, "Dusty GF");
Warhead Warhead::BIOLOGICAL(9000, "Biological");
Warhead Warhead::BIOLOGICAL_VIRUS(9100, "Biological, Virus");
Warhead Warhead::BIOLOGICAL_BACTERIA(9200, "Biological, Bacteria");
Warhead Warhead::BIOLOGICAL_RICKETTSIA(9300, "Biological, Rickettsia");
Warhead Warhead::BIOLOGICAL_GENETICALLY_MODIFIED_MICRO_ORGANISMS(9400, "Biological, Genetically Modified Micro-organisms");
Warhead Warhead::BIOLOGICAL_TOXIN(9500, "Biological, Toxin");


Warhead::Warhead(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

Warhead* Warhead::findEnumeration(int aVal) {
  Warhead* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string Warhead::getDescriptionForValue(int aVal) {
  Warhead* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

Warhead Warhead::getEnumerationForValue(int aVal) throw(EnumException) {
  Warhead* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration Warhead";
    throw EnumException("Warhead", aVal, ss.str());
  }
};

bool Warhead::enumerationForValueExists(int aVal) {
  Warhead* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

Warhead::enumContainer Warhead::getEnumerations() {
  return (enumerations);
};

Warhead& Warhead::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

