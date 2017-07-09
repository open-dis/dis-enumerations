#ifndef REASON__H
#define REASON__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Reason : public Enumeration {
  public:
    static Reason OTHER;
    static Reason RECESS;
    static Reason TERMINATION;
    static Reason SYSTEM_FAILURE;
    static Reason SECURITY_VIOLATION;
    static Reason ENTITY_RECONSTITUTION;
    static Reason STOP_FOR_RESET;
    static Reason STOP_FOR_RESTART;
    static Reason ABORT_TRAINING_RETURN_TO_TACTICAL_OPERATIONS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Reason getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Reason*> enumContainer;
    static enumContainer getEnumerations();

    Reason& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Reason(int value, std::string description);

	  static Reason* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Reason */


}  /* namespace DIS */

#endif /* REASON__H */

