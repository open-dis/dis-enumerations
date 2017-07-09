#include <sstream>
#include <cstddef>
#include <disenum/UserProtocolIDNum.h>

namespace DIS {


hashMap<int,UserProtocolIDNum*> UserProtocolIDNum::enumerations;

UserProtocolIDNum UserProtocolIDNum::CCSIL(1, "CCSIL");
UserProtocolIDNum UserProtocolIDNum::A2ATD_SINCGARS_ERF(5, "A2ATD SINCGARS ERF");
UserProtocolIDNum UserProtocolIDNum::A2ATD_CAC2(6, "A2ATD CAC2");
UserProtocolIDNum UserProtocolIDNum::BATTLE_COMMAND(20, "Battle Command");
UserProtocolIDNum UserProtocolIDNum::AFIWC_IADS_TRACK_REPORT(30, "AFIWC IADS Track Report");
UserProtocolIDNum UserProtocolIDNum::AFIWC_IADS_COMM_C2_MESSAGE(31, "AFIWC IADS Comm C2 Message");
UserProtocolIDNum UserProtocolIDNum::AFIWC_IADS_GROUND_CONTROL_INTERCEPTOR_GCI_COMMAND(32, "AFIWC IADS Ground Control Interceptor (GCI) Command");
UserProtocolIDNum UserProtocolIDNum::AFIWC_VOICE_TEXT_MESSAGE(35, "AFIWC Voice Text Message");
UserProtocolIDNum UserProtocolIDNum::MODSAF_TEXT_RADIO(177, "ModSAF Text Radio");
UserProtocolIDNum UserProtocolIDNum::CCTT_SINCGARS_ERF_LOCKOUT(200, "CCTT SINCGARS ERF-LOCKOUT");
UserProtocolIDNum UserProtocolIDNum::CCTT_SINCGARS_ERF_HOPSET(201, "CCTT SINCGARS ERF-HOPSET");
UserProtocolIDNum UserProtocolIDNum::CCTT_SINCGARS_OTAR(202, "CCTT SINCGARS OTAR");
UserProtocolIDNum UserProtocolIDNum::CCTT_SINCGARS_DATA(203, "CCTT SINCGARS DATA");
UserProtocolIDNum UserProtocolIDNum::MODSAF_FWA_FORWARD_AIR_CONTROLLER(546, "ModSAF FWA Forward Air Controller");
UserProtocolIDNum UserProtocolIDNum::MODSAF_THREAT_ADA_C3(832, "ModSAF Threat ADA C3");
UserProtocolIDNum UserProtocolIDNum::F_16_MTC_AFAPD_PROTOCOL(1000, "F-16 MTC AFAPD Protocol");
UserProtocolIDNum UserProtocolIDNum::F_16_MTC_IDL_PROTOCOL(1100, "F-16 MTC IDL Protocol");
UserProtocolIDNum UserProtocolIDNum::MODSAF_ARTILLERY_FIRE_CONTROL(4570, "ModSAF Artillery Fire Control");
UserProtocolIDNum UserProtocolIDNum::AGTS(5361, "AGTS");
UserProtocolIDNum UserProtocolIDNum::GC3(6000, "GC3");
UserProtocolIDNum UserProtocolIDNum::WNCP_DATA(6010, "WNCP data");
UserProtocolIDNum UserProtocolIDNum::SPOKEN_TEXT_MESSAGE(6020, "Spoken text message");
UserProtocolIDNum UserProtocolIDNum::LONGBOW_IDM_MESSAGE(6661, "Longbow IDM message");
UserProtocolIDNum UserProtocolIDNum::COMANCHE_IDM_MESSAGE(6662, "Comanche IDM message");
UserProtocolIDNum UserProtocolIDNum::LONGBOW_AIRBORNE_TACFIRE_MESSAGE(6663, "Longbow Airborne TACFIRE Message");
UserProtocolIDNum UserProtocolIDNum::LONGBOW_GROUND_TACFIRE_MESSAGE(6664, "Longbow Ground TACFIRE Message");
UserProtocolIDNum UserProtocolIDNum::LONGBOW_AFAPD_MESSAGE(6665, "Longbow AFAPD Message");
UserProtocolIDNum UserProtocolIDNum::LONGBOW_ERF_MESSAGE(6666, "Longbow ERF message");


UserProtocolIDNum::UserProtocolIDNum(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

UserProtocolIDNum* UserProtocolIDNum::findEnumeration(int aVal) {
  UserProtocolIDNum* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string UserProtocolIDNum::getDescriptionForValue(int aVal) {
  UserProtocolIDNum* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

UserProtocolIDNum UserProtocolIDNum::getEnumerationForValue(int aVal) throw(EnumException) {
  UserProtocolIDNum* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration UserProtocolIDNum";
    throw EnumException("UserProtocolIDNum", aVal, ss.str());
  }
};

bool UserProtocolIDNum::enumerationForValueExists(int aVal) {
  UserProtocolIDNum* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

UserProtocolIDNum::enumContainer UserProtocolIDNum::getEnumerations() {
  return (enumerations);
};

UserProtocolIDNum& UserProtocolIDNum::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

