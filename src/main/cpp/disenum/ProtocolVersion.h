#ifndef PROTOCOLVERSION__H
#define PROTOCOLVERSION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ProtocolVersion : public Enumeration {
  public:
    static ProtocolVersion OTHER;
    static ProtocolVersion DIS_PDU_VERSION_10_MAY_92;
    static ProtocolVersion IEEE_1278_1993;
    static ProtocolVersion DIS_PDU_VERSION_20_THIRD_DRAFT_MAY_93;
    static ProtocolVersion DIS_PDU_VERSION_20_FOURTH_DRAFT_REVISED_MARCH_16_1994;
    static ProtocolVersion IEEE_12781_1995;
    static ProtocolVersion IEEE_12781A_1998;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ProtocolVersion getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ProtocolVersion*> enumContainer;
    static enumContainer getEnumerations();

    ProtocolVersion& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ProtocolVersion(int value, std::string description);

	  static ProtocolVersion* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ProtocolVersion */


}  /* namespace DIS */

#endif /* PROTOCOLVERSION__H */

