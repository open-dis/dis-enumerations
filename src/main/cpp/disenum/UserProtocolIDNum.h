#ifndef USERPROTOCOLIDNUM__H
#define USERPROTOCOLIDNUM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class UserProtocolIDNum : public Enumeration {
  public:
    static UserProtocolIDNum CCSIL;
    static UserProtocolIDNum A2ATD_SINCGARS_ERF;
    static UserProtocolIDNum A2ATD_CAC2;
    static UserProtocolIDNum BATTLE_COMMAND;
    static UserProtocolIDNum AFIWC_IADS_TRACK_REPORT;
    static UserProtocolIDNum AFIWC_IADS_COMM_C2_MESSAGE;
    static UserProtocolIDNum AFIWC_IADS_GROUND_CONTROL_INTERCEPTOR_GCI_COMMAND;
    static UserProtocolIDNum AFIWC_VOICE_TEXT_MESSAGE;
    static UserProtocolIDNum MODSAF_TEXT_RADIO;
    static UserProtocolIDNum CCTT_SINCGARS_ERF_LOCKOUT;
    static UserProtocolIDNum CCTT_SINCGARS_ERF_HOPSET;
    static UserProtocolIDNum CCTT_SINCGARS_OTAR;
    static UserProtocolIDNum CCTT_SINCGARS_DATA;
    static UserProtocolIDNum MODSAF_FWA_FORWARD_AIR_CONTROLLER;
    static UserProtocolIDNum MODSAF_THREAT_ADA_C3;
    static UserProtocolIDNum F_16_MTC_AFAPD_PROTOCOL;
    static UserProtocolIDNum F_16_MTC_IDL_PROTOCOL;
    static UserProtocolIDNum MODSAF_ARTILLERY_FIRE_CONTROL;
    static UserProtocolIDNum AGTS;
    static UserProtocolIDNum GC3;
    static UserProtocolIDNum WNCP_DATA;
    static UserProtocolIDNum SPOKEN_TEXT_MESSAGE;
    static UserProtocolIDNum LONGBOW_IDM_MESSAGE;
    static UserProtocolIDNum COMANCHE_IDM_MESSAGE;
    static UserProtocolIDNum LONGBOW_AIRBORNE_TACFIRE_MESSAGE;
    static UserProtocolIDNum LONGBOW_GROUND_TACFIRE_MESSAGE;
    static UserProtocolIDNum LONGBOW_AFAPD_MESSAGE;
    static UserProtocolIDNum LONGBOW_ERF_MESSAGE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static UserProtocolIDNum getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,UserProtocolIDNum*> enumContainer;
    static enumContainer getEnumerations();

    UserProtocolIDNum& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  UserProtocolIDNum(int value, std::string description);

	  static UserProtocolIDNum* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* UserProtocolIDNum */


}  /* namespace DIS */

#endif /* USERPROTOCOLIDNUM__H */

