#ifndef AIRCRAFT__H
#define AIRCRAFT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Aircraft : public Enumeration {
  public:
    static Aircraft ENGINE_OFF;
    static Aircraft IDLE_POWER;
    static Aircraft MIL_POWER;
    static Aircraft MIN_A_B;
    static Aircraft MAX_A_B;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Aircraft getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Aircraft*> enumContainer;
    static enumContainer getEnumerations();

    Aircraft& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Aircraft(int value, std::string description);

	  static Aircraft* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Aircraft */


}  /* namespace DIS */

#endif /* AIRCRAFT__H */

