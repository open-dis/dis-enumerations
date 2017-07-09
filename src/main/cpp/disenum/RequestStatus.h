#ifndef REQUESTSTATUS__H
#define REQUESTSTATUS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RequestStatus : public Enumeration {
  public:
    static RequestStatus OTHER;
    static RequestStatus PENDING;
    static RequestStatus EXECUTING;
    static RequestStatus PARTIALLY_COMPLETE;
    static RequestStatus COMPLETE;
    static RequestStatus REQUEST_REJECTED;
    static RequestStatus RETRANSMIT_REQUEST_NOW;
    static RequestStatus RETRANSMIT_REQUEST_LATER;
    static RequestStatus INVALID_TIME_PARAMETERS;
    static RequestStatus SIMULATION_TIME_EXCEEDED;
    static RequestStatus REQUEST_DONE;
    static RequestStatus TACCSF_LOS_REPLY_TYPE_1;
    static RequestStatus TACCSF_LOS_REPLY_TYPE_2;
    static RequestStatus JOIN_EXERCISE_REQUEST_REJECTED;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RequestStatus getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RequestStatus*> enumContainer;
    static enumContainer getEnumerations();

    RequestStatus& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RequestStatus(int value, std::string description);

	  static RequestStatus* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RequestStatus */


}  /* namespace DIS */

#endif /* REQUESTSTATUS__H */

