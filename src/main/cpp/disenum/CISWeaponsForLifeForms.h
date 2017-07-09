#ifndef CISWEAPONSFORLIFEFORMS__H
#define CISWEAPONSFORLIFEFORMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CISWeaponsForLifeForms : public Enumeration {
  public:
    static CISWeaponsForLifeForms AUTOMATIC_APS_9_MM_STECHKIN;
    static CISWeaponsForLifeForms PSM_545_MM;
    static CISWeaponsForLifeForms SELF_LOADING_PM_9_MM_MAKAROV;
    static CISWeaponsForLifeForms TT_33_762_MM_TOKAREV;
    static CISWeaponsForLifeForms ASSAULT_RIFLE_AK_AND_AKM_762_MM;
    static CISWeaponsForLifeForms ASSAULT_RIFLE_AK_74_AND_AKS_74_545_MM;
    static CISWeaponsForLifeForms SELF_LOADING_RIFLE_SKS_762_MM_SIMONOV;
    static CISWeaponsForLifeForms SNIPER_RIFLE_SVD_762_MM_DRAGUNOV;
    static CISWeaponsForLifeForms AKSU_74_545_MM;
    static CISWeaponsForLifeForms PPS_43_762_MM;
    static CISWeaponsForLifeForms PPSH_41_762_MM;
    static CISWeaponsForLifeForms GENERAL_PURPOSE_PK_762_MM;
    static CISWeaponsForLifeForms HEAVY_DSHK_38_AND_MODEL_38_46_127_MM_DEGTYAREV;
    static CISWeaponsForLifeForms HEAVY_NSV_127_MM;
    static CISWeaponsForLifeForms LIGHT_RPD_762_MM;
    static CISWeaponsForLifeForms LIGHT_RPK_762_MM;
    static CISWeaponsForLifeForms LIGHT_RPK_74_545_MM;
    static CISWeaponsForLifeForms HAND_GRENADE_M75;
    static CISWeaponsForLifeForms HAND_GRENADE_RGD_5;
    static CISWeaponsForLifeForms AP_HAND_GRENADE_F1;
    static CISWeaponsForLifeForms AT_HAND_GRENADE_RKG_3;
    static CISWeaponsForLifeForms AT_HAND_GRENADE_RKG_3M;
    static CISWeaponsForLifeForms AT_HAND_GRENADE_RKG_3T;
    static CISWeaponsForLifeForms FRAGMENTATION_HAND_GRENADE_RGN;
    static CISWeaponsForLifeForms FRAGMENTATION_HAND_GRENADE_RGO;
    static CISWeaponsForLifeForms SMOKE_HAND_GRENADE_RDG_1;
    static CISWeaponsForLifeForms PLAMYA_LAUNCHER_30_MM_AGS_17;
    static CISWeaponsForLifeForms RIFLE_MOUNTED_LAUNCHER_BG_15_40_MM;
    static CISWeaponsForLifeForms LPO_50;
    static CISWeaponsForLifeForms ROKS_3;
    static CISWeaponsForLifeForms CART_MOUNTED_TPO_50;
    static CISWeaponsForLifeForms GIMLET_SA_16;
    static CISWeaponsForLifeForms GRAIL_SA_7;
    static CISWeaponsForLifeForms GREMLIN_SA_14;
    static CISWeaponsForLifeForms SAGGER_AT_3_MCLOS;
    static CISWeaponsForLifeForms SAXHORN_AT_7;
    static CISWeaponsForLifeForms SPIGOT_A_B_AT_14;
    static CISWeaponsForLifeForms SA_18;
    static CISWeaponsForLifeForms SA_19;
    static CISWeaponsForLifeForms GRAD_1P_MANPORTABLE_TRIPOD_ROCKET_LAUNCHER_122_MM_FOR_SPESNATZ_AND_OTHER_SPECIALISTS_AKA_9P132;
    static CISWeaponsForLifeForms LIGHT_ANTI_ARMOR_WEAPON_RPG_18;
    static CISWeaponsForLifeForms LIGHT_ANTITANK_WEAPON_RPG_22;
    static CISWeaponsForLifeForms MG_RPG;
    static CISWeaponsForLifeForms PORTABLE_ROCKET_LAUNCHER_RPG_16;
    static CISWeaponsForLifeForms RECOILLESS_GUN_73_MM_SPG_9;
    static CISWeaponsForLifeForms VAT_ROCKET_LAUNCHER_RPG_7;
    static CISWeaponsForLifeForms MON_50_ANTIPERSONNEL_MINE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CISWeaponsForLifeForms getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CISWeaponsForLifeForms*> enumContainer;
    static enumContainer getEnumerations();

    CISWeaponsForLifeForms& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CISWeaponsForLifeForms(int value, std::string description);

	  static CISWeaponsForLifeForms* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CISWeaponsForLifeForms */


}  /* namespace DIS */

#endif /* CISWEAPONSFORLIFEFORMS__H */

