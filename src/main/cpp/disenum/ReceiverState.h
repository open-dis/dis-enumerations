#ifndef RECEIVERSTATE__H
#define RECEIVERSTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ReceiverState : public Enumeration {
  public:
    static ReceiverState OFF;
    static ReceiverState ON_BUT_NOT_RECEIVING;
    static ReceiverState ON_AND_RECEIVING;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ReceiverState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ReceiverState*> enumContainer;
    static enumContainer getEnumerations();

    ReceiverState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ReceiverState(int value, std::string description);

	  static ReceiverState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ReceiverState */


}  /* namespace DIS */

#endif /* RECEIVERSTATE__H */

