#include <sstream>
#include <cstddef>
#include <disenum/CISWeaponsForLifeForms.h>

namespace DIS {


hashMap<int,CISWeaponsForLifeForms*> CISWeaponsForLifeForms::enumerations;

CISWeaponsForLifeForms CISWeaponsForLifeForms::AUTOMATIC_APS_9_MM_STECHKIN(201, "Automatic (APS) 9-mm, Stechkin");
CISWeaponsForLifeForms CISWeaponsForLifeForms::PSM_545_MM(202, "PSM 5.45-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SELF_LOADING_PM_9_MM_MAKAROV(203, "Self-loading (PM) 9-mm, Makarov");
CISWeaponsForLifeForms CISWeaponsForLifeForms::TT_33_762_MM_TOKAREV(204, "TT-33 7.62-mm, Tokarev");
CISWeaponsForLifeForms CISWeaponsForLifeForms::ASSAULT_RIFLE_AK_AND_AKM_762_MM(205, "Assault rifle AK and AKM, 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::ASSAULT_RIFLE_AK_74_AND_AKS_74_545_MM(206, "Assault rifle AK-74 and AKS-74, 5.45-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SELF_LOADING_RIFLE_SKS_762_MM_SIMONOV(207, "Self-loading rifle (SKS), 7.62-mm, Simonov");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SNIPER_RIFLE_SVD_762_MM_DRAGUNOV(208, "Sniper rifle SVD 7.62-mm, Dragunov");
CISWeaponsForLifeForms CISWeaponsForLifeForms::AKSU_74_545_MM(209, "AKSU-74 5.45-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::PPS_43_762_MM(210, "PPS-43 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::PPSH_41_762_MM(211, "PPSh-41 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::GENERAL_PURPOSE_PK_762_MM(212, "General purpose PK 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::HEAVY_DSHK_38_AND_MODEL_38_46_127_MM_DEGTYAREV(213, "Heavy DShK-38 and Model 38/46 12.7-mm, Degtyarev");
CISWeaponsForLifeForms CISWeaponsForLifeForms::HEAVY_NSV_127_MM(214, "Heavy NSV 12.7-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LIGHT_RPD_762_MM(215, "Light RPD 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LIGHT_RPK_762_MM(216, "Light RPK 7.62-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LIGHT_RPK_74_545_MM(217, "Light RPK-74 5.45-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::HAND_GRENADE_M75(218, "Hand grenade M75");
CISWeaponsForLifeForms CISWeaponsForLifeForms::HAND_GRENADE_RGD_5(219, "Hand grenade RGD-5");
CISWeaponsForLifeForms CISWeaponsForLifeForms::AP_HAND_GRENADE_F1(220, "AP hand grenade F1");
CISWeaponsForLifeForms CISWeaponsForLifeForms::AT_HAND_GRENADE_RKG_3(221, "AT hand grenade RKG-3");
CISWeaponsForLifeForms CISWeaponsForLifeForms::AT_HAND_GRENADE_RKG_3M(222, "AT hand grenade RKG-3M");
CISWeaponsForLifeForms CISWeaponsForLifeForms::AT_HAND_GRENADE_RKG_3T(223, "AT hand grenade RKG-3T");
CISWeaponsForLifeForms CISWeaponsForLifeForms::FRAGMENTATION_HAND_GRENADE_RGN(224, "Fragmentation hand grenade RGN");
CISWeaponsForLifeForms CISWeaponsForLifeForms::FRAGMENTATION_HAND_GRENADE_RGO(225, "Fragmentation hand grenade RGO");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SMOKE_HAND_GRENADE_RDG_1(226, "Smoke hand grenade RDG-1");
CISWeaponsForLifeForms CISWeaponsForLifeForms::PLAMYA_LAUNCHER_30_MM_AGS_17(227, "Plamya launcher, 30-mm AGS-17");
CISWeaponsForLifeForms CISWeaponsForLifeForms::RIFLE_MOUNTED_LAUNCHER_BG_15_40_MM(228, "Rifle-mounted launcher, BG-15 40-mm");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LPO_50(229, "LPO-50");
CISWeaponsForLifeForms CISWeaponsForLifeForms::ROKS_3(230, "ROKS-3");
CISWeaponsForLifeForms CISWeaponsForLifeForms::CART_MOUNTED_TPO_50(231, "Cart-mounted TPO-50");
CISWeaponsForLifeForms CISWeaponsForLifeForms::GIMLET_SA_16(232, "Gimlet SA-16");
CISWeaponsForLifeForms CISWeaponsForLifeForms::GRAIL_SA_7(233, "Grail SA-7");
CISWeaponsForLifeForms CISWeaponsForLifeForms::GREMLIN_SA_14(234, "Gremlin SA-14");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SAGGER_AT_3_MCLOS(235, "Sagger AT-3 (MCLOS)");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SAXHORN_AT_7(236, "Saxhorn AT-7");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SPIGOT_A_B_AT_14(237, "Spigot A/B AT-14");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SA_18(238, "SA-18");
CISWeaponsForLifeForms CISWeaponsForLifeForms::SA_19(239, "SA-19");
CISWeaponsForLifeForms CISWeaponsForLifeForms::GRAD_1P_MANPORTABLE_TRIPOD_ROCKET_LAUNCHER_122_MM_FOR_SPESNATZ_AND_OTHER_SPECIALISTS_AKA_9P132(240, "Grad-1P manportable tripod rocket launcher, 122-mm (for Spesnatz and other specialists; aka 9P132)");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LIGHT_ANTI_ARMOR_WEAPON_RPG_18(241, "Light anti-armor weapon RPG-18");
CISWeaponsForLifeForms CISWeaponsForLifeForms::LIGHT_ANTITANK_WEAPON_RPG_22(242, "Light antitank weapon RPG-22");
CISWeaponsForLifeForms CISWeaponsForLifeForms::MG_RPG(243, "MG & RPG");
CISWeaponsForLifeForms CISWeaponsForLifeForms::PORTABLE_ROCKET_LAUNCHER_RPG_16(244, "Portable rocket launcher RPG-16");
CISWeaponsForLifeForms CISWeaponsForLifeForms::RECOILLESS_GUN_73_MM_SPG_9(245, "Recoilless gun 73-mm SPG-9");
CISWeaponsForLifeForms CISWeaponsForLifeForms::VAT_ROCKET_LAUNCHER_RPG_7(246, "VAT rocket launcher RPG-7");
CISWeaponsForLifeForms CISWeaponsForLifeForms::MON_50_ANTIPERSONNEL_MINE(248, "Mon-50 antipersonnel mine");


CISWeaponsForLifeForms::CISWeaponsForLifeForms(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

CISWeaponsForLifeForms* CISWeaponsForLifeForms::findEnumeration(int aVal) {
  CISWeaponsForLifeForms* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string CISWeaponsForLifeForms::getDescriptionForValue(int aVal) {
  CISWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

CISWeaponsForLifeForms CISWeaponsForLifeForms::getEnumerationForValue(int aVal) throw(EnumException) {
  CISWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration CISWeaponsForLifeForms";
    throw EnumException("CISWeaponsForLifeForms", aVal, ss.str());
  }
};

bool CISWeaponsForLifeForms::enumerationForValueExists(int aVal) {
  CISWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

CISWeaponsForLifeForms::enumContainer CISWeaponsForLifeForms::getEnumerations() {
  return (enumerations);
};

CISWeaponsForLifeForms& CISWeaponsForLifeForms::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

