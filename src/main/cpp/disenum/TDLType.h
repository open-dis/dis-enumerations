#ifndef TDLTYPE__H
#define TDLTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class TDLType : public Enumeration {
  public:
    static TDLType OTHER;
    static TDLType PADIL;
    static TDLType NATO_LINK_1;
    static TDLType ATDL_1;
    static TDLType LINK_11B_TADIL_B;
    static TDLType SITUATIONAL_AWARENESS_DATA_LINK_SADL;
    static TDLType LINK_16_LEGACY_FORMAT_JTIDS_TADIL_J;
    static TDLType LINK_16_LEGACY_FORMAT_JTIDS_FDL_TADIL_J;
    static TDLType LINK_11A_TADIL_A;
    static TDLType IJMS;
    static TDLType LINK_4A_TADIL_C;
    static TDLType LINK_4C;
    static TDLType TIBS;
    static TDLType ATL;
    static TDLType CONSTANT_SOURCE;
    static TDLType ABBREVIATED_COMMAND_AND_CONTROL;
    static TDLType MILSTAR;
    static TDLType ATHS;
    static TDLType OTHGOLD;
    static TDLType TACELINT;
    static TDLType WEAPONS_DATA_LINK_AWW_13;
    static TDLType ABBREVIATED_COMMAND_AND_CONTROL_1;
    static TDLType ENHANCED_POSITION_LOCATION_REPORTING_SYSTEM_EPLRS;
    static TDLType POSITION_LOCATION_REPORTING_SYSTEM_PLRS;
    static TDLType SINCGARS;
    static TDLType HAVE_QUICK_I;
    static TDLType HAVE_QUICK_II;
    static TDLType HAVE_QUICK_IIA_SATURN;
    static TDLType INTRA_FLIGHT_DATA_LINK_1;
    static TDLType INTRA_FLIGHT_DATA_LINK_2;
    static TDLType IMPROVED_DATA_MODEM_IDM;
    static TDLType AIR_FORCE_APPLICATION_PROGRAM_DEVELOPMENT_AFAPD;
    static TDLType COOPERATIVE_ENGAGEMENT_CAPABILITY_CEC;
    static TDLType FORWARD_AREA_AIR_DEFENSE_FAAD_DATA_LINK_FDL;
    static TDLType GROUND_BASED_DATA_LINK_GBDL;
    static TDLType INTRA_VEHICULAR_INFO_SYSTEM_IVIS;
    static TDLType MARINE_TACTICAL_SYSTEM_MTS;
    static TDLType TACTICAL_FIRE_DIRECTION_SYSTEM_TACFIRE;
    static TDLType INTEGRATED_BROADCAST_SERVICE_IBS;
    static TDLType AIRBORNE_INFORMATION_TRANSFER_ABIT;
    static TDLType ADVANCED_TACTICAL_AIRBORNE_RECONNAISSANCE_SYSTEM_ATARS_DATA_LINK;
    static TDLType BATTLE_GROUP_PASSIVE_HORIZON_EXTENSION_SYSTEM_BGPHES_DATA_LINK;
    static TDLType COMMON_HIGH_BANDWIDTH_DATA_LINK_CHBDL;
    static TDLType GUARDRAIL_INTEROPERABLE_DATA_LINK_IDL;
    static TDLType GUARDRAIL_COMMON_SENSOR_SYSTEM_ONE_CSS1_DATA_LINK;
    static TDLType GUARDRAIL_COMMON_SENSOR_SYSTEM_TWO_CSS2_DATA_LINK;
    static TDLType GUARDRAIL_CSS2_MULTI_ROLE_DATA_LINK_MRDL;
    static TDLType GUARDRAIL_CSS2_DIRECT_AIR_TO_SATELLITE_RELAY_DASR_DATA_LINK;
    static TDLType LINE_OF_SIGHT_LOS_DATA_LINK_IMPLEMENTATION_LOS_TETHER;
    static TDLType LIGHTWEIGHT_CDL_LWCDL;
    static TDLType L_52M_SR_71;
    static TDLType RIVET_REACH_RIVET_OWL_DATA_LINK;
    static TDLType SENIOR_SPAN;
    static TDLType SENIOR_SPUR;
    static TDLType SENIOR_STRETCH;
    static TDLType SENIOR_YEAR_INTEROPERABLE_DATA_LINK_IDL;
    static TDLType SPACE_CDL;
    static TDLType TR_1_MODE_MIST_AIRBORNE_DATA_LINK;
    static TDLType KU_BAND_SATCOM_DATA_LINK_IMPLEMENTATION_UAV;
    static TDLType MISSION_EQUIPMENT_CONTROL_DATA_LINK_MECDL;
    static TDLType RADAR_DATA_TRANSMITTING_SET_DATA_LINK;
    static TDLType SURVEILLANCE_AND_CONTROL_DATA_LINK_SCDL;
    static TDLType TACTICAL_UAV_VIDEO;
    static TDLType UHF_SATCOM_DATA_LINK_IMPLEMENTATION_UAV;
    static TDLType TACTICAL_COMMON_DATA_LINK_TCDL;
    static TDLType LOW_LEVEL_AIR_PICTURE_INTERFACE_LLAPI;
    static TDLType WEAPONS_DATA_LINK_AGM_130;
    static TDLType GC3;
    static TDLType LINK_16_STANDARDIZED_FORMAT_JTIDS_MIDS_TADIL_J;
    static TDLType LINK_16_ENHANCED_DATA_RATE_EDR_JTIDS_MIDS_TADIL_J;
    static TDLType JTIDS_MIDS_NET_DATA_LOAD_TIMS_TOMS;
    static TDLType LINK_22;
    static TDLType AFIWC_IADS_COMMUNICATIONS_LINKS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static TDLType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,TDLType*> enumContainer;
    static enumContainer getEnumerations();

    TDLType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  TDLType(int value, std::string description);

	  static TDLType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* TDLType */


}  /* namespace DIS */

#endif /* TDLTYPE__H */

