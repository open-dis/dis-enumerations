#include <sstream>
#include <cstddef>
#include <disenum/TDLType.h>

namespace DIS {


hashMap<int,TDLType*> TDLType::enumerations;

TDLType TDLType::OTHER(0, "Other");
TDLType TDLType::PADIL(1, "PADIL");
TDLType TDLType::NATO_LINK_1(2, "NATO Link-1");
TDLType TDLType::ATDL_1(3, "ATDL-1");
TDLType TDLType::LINK_11B_TADIL_B(4, "Link 11B (TADIL B)");
TDLType TDLType::SITUATIONAL_AWARENESS_DATA_LINK_SADL(5, "Situational Awareness Data Link (SADL)");
TDLType TDLType::LINK_16_LEGACY_FORMAT_JTIDS_TADIL_J(6, "Link 16 Legacy Format (JTIDS/TADIL-J)");
TDLType TDLType::LINK_16_LEGACY_FORMAT_JTIDS_FDL_TADIL_J(7, "Link 16 Legacy Format (JTIDS/FDL/TADIL-J)");
TDLType TDLType::LINK_11A_TADIL_A(8, "Link 11A (TADIL A)");
TDLType TDLType::IJMS(9, "IJMS");
TDLType TDLType::LINK_4A_TADIL_C(10, "Link 4A (TADIL C)");
TDLType TDLType::LINK_4C(11, "Link 4C");
TDLType TDLType::TIBS(12, "TIBS");
TDLType TDLType::ATL(13, "ATL");
TDLType TDLType::CONSTANT_SOURCE(14, "Constant Source");
TDLType TDLType::ABBREVIATED_COMMAND_AND_CONTROL(15, "Abbreviated Command and Control");
TDLType TDLType::MILSTAR(16, "MILSTAR");
TDLType TDLType::ATHS(17, "ATHS");
TDLType TDLType::OTHGOLD(18, "OTHGOLD");
TDLType TDLType::TACELINT(19, "TACELINT");
TDLType TDLType::WEAPONS_DATA_LINK_AWW_13(20, "Weapons Data Link (AWW-13)");
TDLType TDLType::ABBREVIATED_COMMAND_AND_CONTROL_1(21, "Abbreviated Command and Control");
TDLType TDLType::ENHANCED_POSITION_LOCATION_REPORTING_SYSTEM_EPLRS(22, "Enhanced Position Location Reporting System (EPLRS)");
TDLType TDLType::POSITION_LOCATION_REPORTING_SYSTEM_PLRS(23, "Position Location Reporting System (PLRS)");
TDLType TDLType::SINCGARS(24, "SINCGARS");
TDLType TDLType::HAVE_QUICK_I(25, "Have Quick I");
TDLType TDLType::HAVE_QUICK_II(26, "Have Quick II");
TDLType TDLType::HAVE_QUICK_IIA_SATURN(27, "Have Quick IIA (Saturn)");
TDLType TDLType::INTRA_FLIGHT_DATA_LINK_1(28, "Intra-Flight Data Link 1");
TDLType TDLType::INTRA_FLIGHT_DATA_LINK_2(29, "Intra-Flight Data Link 2");
TDLType TDLType::IMPROVED_DATA_MODEM_IDM(30, "Improved Data Modem (IDM)");
TDLType TDLType::AIR_FORCE_APPLICATION_PROGRAM_DEVELOPMENT_AFAPD(31, "Air Force Application Program Development (AFAPD)");
TDLType TDLType::COOPERATIVE_ENGAGEMENT_CAPABILITY_CEC(32, "Cooperative Engagement Capability (CEC)");
TDLType TDLType::FORWARD_AREA_AIR_DEFENSE_FAAD_DATA_LINK_FDL(33, "Forward Area Air Defense (FAAD) Data Link (FDL)");
TDLType TDLType::GROUND_BASED_DATA_LINK_GBDL(34, "Ground Based Data Link (GBDL)");
TDLType TDLType::INTRA_VEHICULAR_INFO_SYSTEM_IVIS(35, "Intra Vehicular Info System (IVIS)");
TDLType TDLType::MARINE_TACTICAL_SYSTEM_MTS(36, "Marine Tactical System (MTS)");
TDLType TDLType::TACTICAL_FIRE_DIRECTION_SYSTEM_TACFIRE(37, "Tactical Fire Direction System (TACFIRE)");
TDLType TDLType::INTEGRATED_BROADCAST_SERVICE_IBS(38, "Integrated Broadcast Service (IBS)");
TDLType TDLType::AIRBORNE_INFORMATION_TRANSFER_ABIT(39, "Airborne Information Transfer (ABIT)");
TDLType TDLType::ADVANCED_TACTICAL_AIRBORNE_RECONNAISSANCE_SYSTEM_ATARS_DATA_LINK(40, "Advanced Tactical Airborne Reconnaissance System (ATARS) Data Link");
TDLType TDLType::BATTLE_GROUP_PASSIVE_HORIZON_EXTENSION_SYSTEM_BGPHES_DATA_LINK(41, "Battle Group Passive Horizon Extension System (BGPHES) Data Link");
TDLType TDLType::COMMON_HIGH_BANDWIDTH_DATA_LINK_CHBDL(42, "Common High Bandwidth Data Link (CHBDL)");
TDLType TDLType::GUARDRAIL_INTEROPERABLE_DATA_LINK_IDL(43, "Guardrail Interoperable Data Link (IDL)");
TDLType TDLType::GUARDRAIL_COMMON_SENSOR_SYSTEM_ONE_CSS1_DATA_LINK(44, "Guardrail Common Sensor System One (CSS1) Data Link");
TDLType TDLType::GUARDRAIL_COMMON_SENSOR_SYSTEM_TWO_CSS2_DATA_LINK(45, "Guardrail Common Sensor System Two (CSS2) Data Link");
TDLType TDLType::GUARDRAIL_CSS2_MULTI_ROLE_DATA_LINK_MRDL(46, "Guardrail CSS2 Multi-Role Data Link (MRDL)");
TDLType TDLType::GUARDRAIL_CSS2_DIRECT_AIR_TO_SATELLITE_RELAY_DASR_DATA_LINK(47, "Guardrail CSS2 Direct Air to Satellite Relay (DASR) Data Link");
TDLType TDLType::LINE_OF_SIGHT_LOS_DATA_LINK_IMPLEMENTATION_LOS_TETHER(48, "Line of Sight (LOS) Data Link Implementation (LOS tether)");
TDLType TDLType::LIGHTWEIGHT_CDL_LWCDL(49, "Lightweight CDL (LWCDL)");
TDLType TDLType::L_52M_SR_71(50, "L-52M (SR-71)");
TDLType TDLType::RIVET_REACH_RIVET_OWL_DATA_LINK(51, "Rivet Reach/Rivet Owl Data Link");
TDLType TDLType::SENIOR_SPAN(52, "Senior Span");
TDLType TDLType::SENIOR_SPUR(53, "Senior Spur");
TDLType TDLType::SENIOR_STRETCH(54, "Senior Stretch.");
TDLType TDLType::SENIOR_YEAR_INTEROPERABLE_DATA_LINK_IDL(55, "Senior Year Interoperable Data Link (IDL)");
TDLType TDLType::SPACE_CDL(56, "Space CDL");
TDLType TDLType::TR_1_MODE_MIST_AIRBORNE_DATA_LINK(57, "TR-1 mode MIST Airborne Data Link");
TDLType TDLType::KU_BAND_SATCOM_DATA_LINK_IMPLEMENTATION_UAV(58, "Ku-band SATCOM Data Link Implementation (UAV)");
TDLType TDLType::MISSION_EQUIPMENT_CONTROL_DATA_LINK_MECDL(59, "Mission Equipment Control Data link (MECDL)");
TDLType TDLType::RADAR_DATA_TRANSMITTING_SET_DATA_LINK(60, "Radar Data Transmitting Set Data Link");
TDLType TDLType::SURVEILLANCE_AND_CONTROL_DATA_LINK_SCDL(61, "Surveillance and Control Data Link (SCDL)");
TDLType TDLType::TACTICAL_UAV_VIDEO(62, "Tactical UAV Video");
TDLType TDLType::UHF_SATCOM_DATA_LINK_IMPLEMENTATION_UAV(63, "UHF SATCOM Data Link Implementation (UAV)");
TDLType TDLType::TACTICAL_COMMON_DATA_LINK_TCDL(64, "Tactical Common Data Link (TCDL)");
TDLType TDLType::LOW_LEVEL_AIR_PICTURE_INTERFACE_LLAPI(65, "Low Level Air Picture Interface (LLAPI)");
TDLType TDLType::WEAPONS_DATA_LINK_AGM_130(66, "Weapons Data Link (AGM-130)");
TDLType TDLType::GC3(99, "GC3");
TDLType TDLType::LINK_16_STANDARDIZED_FORMAT_JTIDS_MIDS_TADIL_J(100, "Link 16 Standardized Format (JTIDS/MIDS/TADIL J)");
TDLType TDLType::LINK_16_ENHANCED_DATA_RATE_EDR_JTIDS_MIDS_TADIL_J(101, "Link 16 Enhanced Data Rate (EDR JTIDS/MIDS/TADIL-J)");
TDLType TDLType::JTIDS_MIDS_NET_DATA_LOAD_TIMS_TOMS(102, "JTIDS/MIDS Net Data Load (TIMS/TOMS)");
TDLType TDLType::LINK_22(103, "Link 22");
TDLType TDLType::AFIWC_IADS_COMMUNICATIONS_LINKS(104, "AFIWC IADS Communications Links");


TDLType::TDLType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

TDLType* TDLType::findEnumeration(int aVal) {
  TDLType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string TDLType::getDescriptionForValue(int aVal) {
  TDLType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

TDLType TDLType::getEnumerationForValue(int aVal) throw(EnumException) {
  TDLType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration TDLType";
    throw EnumException("TDLType", aVal, ss.str());
  }
};

bool TDLType::enumerationForValueExists(int aVal) {
  TDLType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

TDLType::enumContainer TDLType::getEnumerations() {
  return (enumerations);
};

TDLType& TDLType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

