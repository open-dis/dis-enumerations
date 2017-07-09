#ifndef CONTROLTYPE__H
#define CONTROLTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ControlType : public Enumeration {
  public:
    static ControlType RESERVED;
    static ControlType STATUS;
    static ControlType REQUEST_ACKNOWLEDGE_REQUIRED;
    static ControlType REQUEST_NO_ACKNOWLEDGE;
    static ControlType ACK_REQUEST_GRANTED;
    static ControlType NACK_REQUEST_DENIED;
    static ControlType MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ControlType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ControlType*> enumContainer;
    static enumContainer getEnumerations();

    ControlType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ControlType(int value, std::string description);

	  static ControlType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ControlType */


}  /* namespace DIS */

#endif /* CONTROLTYPE__H */

