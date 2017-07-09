#ifndef TRANSMITSTATE__H
#define TRANSMITSTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class TransmitState : public Enumeration {
  public:
    static TransmitState OFF;
    static TransmitState ON_BUT_NOT_TRANSMITTING;
    static TransmitState ON_AND_TRANSMITTING;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static TransmitState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,TransmitState*> enumContainer;
    static enumContainer getEnumerations();

    TransmitState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  TransmitState(int value, std::string description);

	  static TransmitState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* TransmitState */


}  /* namespace DIS */

#endif /* TRANSMITSTATE__H */

