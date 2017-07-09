#ifndef XMITTERMPRIMODE__H
#define XMITTERMPRIMODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class XmitTermPriMode : public Enumeration {
  public:
    static XmitTermPriMode NTR;
    static XmitTermPriMode JTIDS_UNIT_PARTICIPANT;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static XmitTermPriMode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,XmitTermPriMode*> enumContainer;
    static enumContainer getEnumerations();

    XmitTermPriMode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  XmitTermPriMode(int value, std::string description);

	  static XmitTermPriMode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* XmitTermPriMode */


}  /* namespace DIS */

#endif /* XMITTERMPRIMODE__H */

