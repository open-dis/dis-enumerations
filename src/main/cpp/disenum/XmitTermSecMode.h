#ifndef XMITTERMSECMODE__H
#define XMITTERMSECMODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class XmitTermSecMode : public Enumeration {
  public:
    static XmitTermSecMode NONE;
    static XmitTermSecMode NET_POSITION_REFERENCE;
    static XmitTermSecMode PRIMARY_NAVIGATION_CONTROLLER;
    static XmitTermSecMode SECONDARY_NAVIGATION_CONTROLLER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static XmitTermSecMode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,XmitTermSecMode*> enumContainer;
    static enumContainer getEnumerations();

    XmitTermSecMode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  XmitTermSecMode(int value, std::string description);

	  static XmitTermSecMode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* XmitTermSecMode */


}  /* namespace DIS */

#endif /* XMITTERMSECMODE__H */

