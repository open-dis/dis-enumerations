#include <sstream>
#include <cstddef>
#include <disenum/USWeaponsForLifeForms.h>

namespace DIS {


hashMap<int,USWeaponsForLifeForms*> USWeaponsForLifeForms::enumerations;

USWeaponsForLifeForms USWeaponsForLifeForms::ASSAULT_MACHINE_PISTOL_KF_AMP(1, "Assault machine pistol, KF-AMP");
USWeaponsForLifeForms USWeaponsForLifeForms::AUTOMATIC_MODEL_1911A1_45(2, "Automatic model 1911A1 .45");
USWeaponsForLifeForms USWeaponsForLifeForms::COMBAT_MASTER_MARK_VI_45_DETRONICS(3, "Combat Master Mark VI .45, Detronics");
USWeaponsForLifeForms USWeaponsForLifeForms::DE_COCKER_KP90DC_45(4, "De-cocker KP90DC .45");
USWeaponsForLifeForms USWeaponsForLifeForms::DE_COCKER_KP91DC_40(5, "De-cocker KP91DC .40");
USWeaponsForLifeForms USWeaponsForLifeForms::GENERAL_OFFICERS_MODEL_15_45(6, "General officer's Model 15 .45");
USWeaponsForLifeForms USWeaponsForLifeForms::NOVA_9_MM_LAFRANCE(7, "Nova 9-mm, LaFrance");
USWeaponsForLifeForms USWeaponsForLifeForms::PERSONAL_DEFENSE_WEAPON_MP5K_PDW_9_MM(8, "Personal Defense Weapon MP5K-PDW 9-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::SILENCED_COLT_45_LAFRANCE(9, "Silenced Colt .45, LaFrance");
USWeaponsForLifeForms USWeaponsForLifeForms::X_5900_SERIES_9_MM_SMITH_WESSON_SW(10, "5900-series 9-mm, Smith & Wesson (S&W)");
USWeaponsForLifeForms USWeaponsForLifeForms::M9(11, "M9");
USWeaponsForLifeForms USWeaponsForLifeForms::MODEL_1911A1_SPRINGFIELD_ARMORY(12, "Model 1911A1, Springfield Armory");
USWeaponsForLifeForms USWeaponsForLifeForms::MODEL_2000_9_MM(13, "Model 2000 9-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::P_9_9_MM_SPRINGFIELD_ARMORY(14, "P-9 9-mm, Springfield Armory");
USWeaponsForLifeForms USWeaponsForLifeForms::P_12_9_MM(15, "P-12 9-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::P_85_MARK_II_9_MM_RUGER(16, "P-85 Mark II 9-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::ADVANCED_COMBAT_RIFLE_556_MM_AAI(17, "Advanced Combat Rifle 5.56-mm, AAI");
USWeaponsForLifeForms USWeaponsForLifeForms::COMMANDO_ASSAULT_RIFLE_MODEL_733_556_MM_COLT(18, "Commando assault rifle, Model 733 5.56-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::INFANTRY_RIFLE_MINI_14_20_GB_556_MM_RUGER(19, "Infantry rifle, Mini-14/20 GB 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::MINI_14_556_MM_RUGER(20, "Mini-14 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::MINI_THIRTY_762_MM_RUGER(21, "Mini Thirty 7.62-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::SEMI_AUTOMATIC_MODEL_82A2_50_BARRETT(22, "Semi-automatic model 82A2 .50, Barrett");
USWeaponsForLifeForms USWeaponsForLifeForms::SNIPER_WEAPON_SYSTEM_M24_762_MM(23, "Sniper Weapon System M24 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::SNIPING_RIFLE_M21_SPRINGFIELD_ARMORY(24, "Sniping rifle M21, Springfield Armory");
USWeaponsForLifeForms USWeaponsForLifeForms::SNIPING_RIFLE_M40A1_762_MM(25, "Sniping rifle M40A1 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::SNIPING_RIFLE_M600_762_MM(26, "Sniping rifle M600 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::AR_15_M16_556_MM(27, "AR-15 (M16) 5.56-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::M1_30(28, "M1 .30");
USWeaponsForLifeForms USWeaponsForLifeForms::M14_762_MM_NATO(29, "M14 7.62-mm, NATO");
USWeaponsForLifeForms USWeaponsForLifeForms::M14_M1A_M1A1_A1_SPRINGFIELD_ARMORY(30, "M14 (M1A, M1A1-A1), Springfield Armory");
USWeaponsForLifeForms USWeaponsForLifeForms::M14K_ASSAULT_RIFLE_LAFRANCE(31, "M14K assault rifle, LaFrance");
USWeaponsForLifeForms USWeaponsForLifeForms::M16A2_ASSAULT_RIFLE_556_MM_COLT(32, "M16A2 assault rifle 5.56-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::M21_762_MM_US(33, "M21 7.62-mm, U.S.");
USWeaponsForLifeForms USWeaponsForLifeForms::M77_MARK_II_556_MM_RUGER(34, "M77 Mark II 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::M77V_762_MM_RUGER(35, "M77V 7.62-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::S_16_762_X_36_MM_GRENDEL(36, "S-16 7.62 x 36-mm, Grendel");
USWeaponsForLifeForms USWeaponsForLifeForms::SAR_8_762_MM(37, "SAR-8 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::SAR_4800_762_MM(38, "SAR-4800 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::ASSAULT_CARBINE_M16K_LAFRANCE(39, "Assault carbine M16K, LaFrance");
USWeaponsForLifeForms USWeaponsForLifeForms::M1_30_1(40, "M1 .30");
USWeaponsForLifeForms USWeaponsForLifeForms::M4_MODEL_720_556_MM_COLT(41, "M4 (Model 720) 5.56-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::M_900_9_MM_CALICO(42, "M-900 9-mm, Calico");
USWeaponsForLifeForms USWeaponsForLifeForms::AC_556F_556_MM_RUGER(43, "AC-556F 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::M3_45(44, "M3 .45");
USWeaponsForLifeForms USWeaponsForLifeForms::M11_COBRAY(45, "M11, Cobray");
USWeaponsForLifeForms USWeaponsForLifeForms::M951_9_MM_CALICO(46, "M951 9-mm, Calico");
USWeaponsForLifeForms USWeaponsForLifeForms::MP5_10_10_MM(47, "MP5/10 10-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::X_9_MM_COLT(48, "9-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::INGRAM(49, "Ingram");
USWeaponsForLifeForms USWeaponsForLifeForms::EXTERNALLY_POWERED_EPG_762_MM_ARES(50, "Externally powered (EPG) 7.62-mm, Ares");
USWeaponsForLifeForms USWeaponsForLifeForms::GECAL_50(51, "GECAL 50");
USWeaponsForLifeForms USWeaponsForLifeForms::GENERAL_PURPOSE_M60_762_MM(52, "General purpose M60 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::HEAVY_M2HB_QCB_50_RAMO(53, "Heavy M2HB-QCB .50, RAMO");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHT_ASSAULT_M60E3_ENHANCED_762_MM(54, "Light assault M60E3 (Enhanced) 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHT_M16A2_556_MM_COLT(55, "Light M16A2 5.56-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHT_556_MM_ARES(56, "Light 5.56-mm, Ares");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHTWEIGHT_M2_50_RAMO(57, "Lightweight M2 .50, RAMO");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHTWEIGHT_ASSAULT_M60E3_762_MM(58, "Lightweight assault M60E3 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MINIGUN_M134_762_MM_GENERAL_ELECTRIC(59, "Minigun M134 7.62-mm, General Electric");
USWeaponsForLifeForms USWeaponsForLifeForms::MG_SYSTEM_MK19_MOD_3_40_MM(60, "MG system MK19 Mod 3, 40-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MG_SYSTEM_OR_KIT_M2HB_QCB_50_SACO_DEFENSE(61, "MG system (or kit) M2HB QCB .50, Saco Defense");
USWeaponsForLifeForms USWeaponsForLifeForms::M1919A4_30_CAL_BROWNING(62, "M1919A4 .30-cal, Browning");
USWeaponsForLifeForms USWeaponsForLifeForms::X_50_CAL_BROWNING(63, ".50-cal, Browning");
USWeaponsForLifeForms USWeaponsForLifeForms::COLORED_SMOKE_HAND_GRENADE_M18(64, "Colored-smoke hand grenade M18");
USWeaponsForLifeForms USWeaponsForLifeForms::COLORED_SMOKE_GRENADES_FEDERAL_LABORATORIES(65, "Colored-smoke grenades, Federal Laboratories");
USWeaponsForLifeForms USWeaponsForLifeForms::INFRARED_SMOKE_GRENADE_M76(66, "Infrared smoke grenade M76");
USWeaponsForLifeForms USWeaponsForLifeForms::SMOKE_HAND_GRENADE_AN_M8_HC(67, "Smoke hand grenade AN-M8 HC");
USWeaponsForLifeForms USWeaponsForLifeForms::DELAY_FRAGMENTATION_HAND_GRENADE_M61(68, "Delay fragmentation hand grenade M61");
USWeaponsForLifeForms USWeaponsForLifeForms::DELAY_FRAGMENTATION_HAND_GRENADE_M67(69, "Delay fragmentation hand grenade M67");
USWeaponsForLifeForms USWeaponsForLifeForms::IMPACT_FRAGMENTATION_HAND_GRENADE_M57(70, "Impact fragmentation hand grenade M57");
USWeaponsForLifeForms USWeaponsForLifeForms::IMPACT_FRAGMENTATION_HAND_GRENADE_M68(71, "Impact fragmentation hand grenade M68");
USWeaponsForLifeForms USWeaponsForLifeForms::INCENDIARY_HAND_GRENADE_AN_M14_TH3(72, "Incendiary hand grenade AN-M14 TH3");
USWeaponsForLifeForms USWeaponsForLifeForms::LAUNCHER_I_M203_40_MM(73, "Launcher I-M203 40-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::LAUNCHER_M79_40_MM(74, "Launcher M79 40-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MULTIPLE_GRENADE_LAUNCHER_MM_1_40_MM(75, "Multiple grenade launcher MM-1 40-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MULTI_SHOT_PORTABLE_FLAME_WEAPON_M202A2_66_MM(76, "Multi-shot portable flame weapon M202A2 66-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::PORTABLE_ABC_M9_7(77, "Portable ABC-M9-7");
USWeaponsForLifeForms USWeaponsForLifeForms::PORTABLE_M2A1_7(78, "Portable M2A1-7");
USWeaponsForLifeForms USWeaponsForLifeForms::PORTABLE_M9E1_7(79, "Portable M9E1-7");
USWeaponsForLifeForms USWeaponsForLifeForms::DRAGON_MEDIUM_ANTI_ARMOR_MISSILE_M47_FGM_77A(80, "Dragon medium anti-armor missile, M47, FGM-77A");
USWeaponsForLifeForms USWeaponsForLifeForms::JAVELIN_AAWS_M(81, "Javelin AAWS-M");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHT_ANTITANK_WEAPON_M72_LAW_II(82, "Light Antitank Weapon M72 (LAW II)");
USWeaponsForLifeForms USWeaponsForLifeForms::REDEYE_FIM_43_GENERAL_DYNAMICS(83, "Redeye, FIM-43, General Dynamics");
USWeaponsForLifeForms USWeaponsForLifeForms::SABER_DUAL_PURPOSE_MISSILE_SYSTEM(84, "Saber dual-purpose missile system");
USWeaponsForLifeForms USWeaponsForLifeForms::STINGER_FIM_92_GENERAL_DYNAMICS(85, "Stinger, FIM-92, General Dynamics");
USWeaponsForLifeForms USWeaponsForLifeForms::TOW_HEAVY_ANTITANK_WEAPON(86, "TOW heavy antitank weapon");
USWeaponsForLifeForms USWeaponsForLifeForms::BEAR_TRAP_AP_DEVICE_PANCOR(87, "Bear Trap AP device, Pancor");
USWeaponsForLifeForms USWeaponsForLifeForms::CHAIN_GUN_AUTOMATIC_WEAPON_EX_34_762_MM(88, "Chain Gun automatic weapon EX-34 7.62-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::CLOSE_ASSAULT_WEAPON_SYSTEM_CAWS_AAI(89, "Close Assault Weapon System (CAWS), AAI");
USWeaponsForLifeForms USWeaponsForLifeForms::CAWS_OLIN_HECKLER_AND_KOCH(90, "CAWS, Olin/Heckler and Koch");
USWeaponsForLifeForms USWeaponsForLifeForms::CROSSFIRE_SAM_MODEL_88(91, "Crossfire SAM Model 88");
USWeaponsForLifeForms USWeaponsForLifeForms::DRAGON_AND_M16(92, "Dragon and M16");
USWeaponsForLifeForms USWeaponsForLifeForms::FIRING_PORT_WEAPON_M231_556_MM_COLT(93, "Firing port weapon M231, 5.56-mm, Colt");
USWeaponsForLifeForms USWeaponsForLifeForms::FOXHOLE_DIGGER_EXPLOSIVE_KIT_EXFODA(94, "Foxhole Digger Explosive Kit (EXFODA)");
USWeaponsForLifeForms USWeaponsForLifeForms::INFANTRY_SUPPORT_WEAPON_ASP_30_RM_30_MM(95, "Infantry Support Weapon ASP-30 {RM} 30-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::JACKHAMMER_MK_3_A2_PANCOR(96, "Jackhammer Mk 3-A2, Pancor");
USWeaponsForLifeForms USWeaponsForLifeForms::LIGHT_ANTI_ARMOR_WEAPON_M136_AT4(97, "Light anti-armor weapon M136 (AT4)");
USWeaponsForLifeForms USWeaponsForLifeForms::M26A2(98, "M26A2");
USWeaponsForLifeForms USWeaponsForLifeForms::MASTER_KEY_S(99, "Master Key S");
USWeaponsForLifeForms USWeaponsForLifeForms::MINIGUN_556_MM(100, "Minigun 5.56-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MULTIPURPOSE_INDIVIDUAL_MUNITION_MPIM_MARQUARDT(101, "Multipurpose Individual Munition (MPIM), Marquardt");
USWeaponsForLifeForms USWeaponsForLifeForms::MULTIPURPOSE_WEAPON_AT8(102, "Multipurpose weapon AT8");
USWeaponsForLifeForms USWeaponsForLifeForms::RECOILLESS_RIFLE_M40_M40A2_AND_M40A4_106_MM(103, "Recoilless rifle M40, M40A2, and M40A4; 106-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::RECOILLESS_RIFLE_M67_90_MM(104, "Recoilless rifle M67, 90-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::REVOLVER_SP_101(105, "Revolver, SP 101");
USWeaponsForLifeForms USWeaponsForLifeForms::REVOLVER_SUPER_REDHAWK_44_MAGNUM_RUGER(106, "Revolver, Super Redhawk .44 magnum, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::RAW_ROCKET_140_MM_BRUNSWICK(107, "RAW rocket, 140-mm, Brunswick");
USWeaponsForLifeForms USWeaponsForLifeForms::RIFLE_LAUNCHER_ANTI_ARMOR_MUNITION_RAAM_OLIN(108, "Rifle-launcher Anti-Armor Munition (RAAM), Olin");
USWeaponsForLifeForms USWeaponsForLifeForms::ROCKET_LAUNCHER_M_20_35_IN(109, "Rocket launcher M-20 3.5-in");
USWeaponsForLifeForms USWeaponsForLifeForms::ROCKET_LAUNCHER_ENHANCED_M72_E_SERIES_HEAT_66_MM(110, "Rocket launcher, Enhanced M72 E series HEAT, 66-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::SELECTIVE_FIRE_WEAPON_AC_556_556_MM_RUGER(111, "Selective fire weapon AC-556 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::SELECTIVE_FIRE_WEAPON_AC_556F_556_MM_RUGER(112, "Selective fire weapon AC-556F 5.56-mm, Ruger");
USWeaponsForLifeForms USWeaponsForLifeForms::SHOTGUN_M870_MK_1_US_MARINE_CORPS_REMINGTON(113, "Shotgun M870 Mk 1 (U.S. Marine Corps), Remington");
USWeaponsForLifeForms USWeaponsForLifeForms::SMAW_MK_193_83_MM_MCDONNELL_DOUGLAS(114, "SMAW Mk 193, 83-mm, McDonnell-Douglas");
USWeaponsForLifeForms USWeaponsForLifeForms::SMAW_D_DISPOSABLE_SMAW(115, "SMAW-D: Disposable SMAW");
USWeaponsForLifeForms USWeaponsForLifeForms::SQUAD_AUTOMATIC_WEAPON_SAW_M249_556_MM(116, "Squad Automatic Weapon (SAW) M249 5.56-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::TACTICAL_SUPPORT_WEAPON_50_12_50_CAL_PEREGRINE(117, "Tactical Support Weapon 50/12, .50-cal, Peregrine");
USWeaponsForLifeForms USWeaponsForLifeForms::TELESCOPED_AMMUNITION_REVOLVER_GUN_TARG_50_CAL_ARES(118, "Telescoped Ammunition Revolver Gun (TARG) .50-cal, Ares");
USWeaponsForLifeForms USWeaponsForLifeForms::ULTIMATE_OVER_UNDER_COMBINATION_CIENER(119, "Ultimate over-under combination, Ciener");
USWeaponsForLifeForms USWeaponsForLifeForms::M18A1_CLAYMORE_MINE(120, "M18A1 Claymore mine");
USWeaponsForLifeForms USWeaponsForLifeForms::MORTAR_81_MM(121, "Mortar 81-mm");
USWeaponsForLifeForms USWeaponsForLifeForms::MACHINEGUN_M240_762MM(134, "Machinegun M240 7.62mm");


USWeaponsForLifeForms::USWeaponsForLifeForms(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

USWeaponsForLifeForms* USWeaponsForLifeForms::findEnumeration(int aVal) {
  USWeaponsForLifeForms* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string USWeaponsForLifeForms::getDescriptionForValue(int aVal) {
  USWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

USWeaponsForLifeForms USWeaponsForLifeForms::getEnumerationForValue(int aVal) throw(EnumException) {
  USWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration USWeaponsForLifeForms";
    throw EnumException("USWeaponsForLifeForms", aVal, ss.str());
  }
};

bool USWeaponsForLifeForms::enumerationForValueExists(int aVal) {
  USWeaponsForLifeForms* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

USWeaponsForLifeForms::enumContainer USWeaponsForLifeForms::getEnumerations() {
  return (enumerations);
};

USWeaponsForLifeForms& USWeaponsForLifeForms::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

