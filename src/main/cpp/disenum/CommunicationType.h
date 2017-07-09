#ifndef COMMUNICATIONTYPE__H
#define COMMUNICATIONTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CommunicationType : public Enumeration {
  public:
    static CommunicationType RESERVED;
    static CommunicationType CONNECTION_FDX;
    static CommunicationType CONNECTION_HDX_DESTINATION_IS_RECEIVE_ONLY;
    static CommunicationType CONNECTION_HDX_DESTINATION_IS_TRANSMIT_ONLY;
    static CommunicationType CONNECTION_HDX;
    static CommunicationType MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CommunicationType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CommunicationType*> enumContainer;
    static enumContainer getEnumerations();

    CommunicationType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CommunicationType(int value, std::string description);

	  static CommunicationType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CommunicationType */


}  /* namespace DIS */

#endif /* COMMUNICATIONTYPE__H */

