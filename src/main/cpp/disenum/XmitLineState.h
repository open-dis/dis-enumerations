#ifndef XMITLINESTATE__H
#define XMITLINESTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class XmitLineState : public Enumeration {
  public:
    static XmitLineState TRANSMIT_LINE_STATE_NOT_APPLICABLE;
    static XmitLineState NOT_TRANSMITTING;
    static XmitLineState TRANSMITTING;
    static XmitLineState MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static XmitLineState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,XmitLineState*> enumContainer;
    static enumContainer getEnumerations();

    XmitLineState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  XmitLineState(int value, std::string description);

	  static XmitLineState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* XmitLineState */


}  /* namespace DIS */

#endif /* XMITLINESTATE__H */

