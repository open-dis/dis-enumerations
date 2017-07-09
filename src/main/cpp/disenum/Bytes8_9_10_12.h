#ifndef BYTES8_9_10_12__H
#define BYTES8_9_10_12__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Bytes8_9_10_12 : public Enumeration {
  public:
    static Bytes8_9_10_12 X_0_9;
    static Bytes8_9_10_12 X_0_9_1;
    static Bytes8_9_10_12 E;
    static Bytes8_9_10_12 UNDERSCORE_E;
    static Bytes8_9_10_12 S;
    static Bytes8_9_10_12 UNDERSCORE_S;
    static Bytes8_9_10_12 X;
    static Bytes8_9_10_12 UNDERSCORE_X;
    static Bytes8_9_10_12 BLANK;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Bytes8_9_10_12 getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Bytes8_9_10_12*> enumContainer;
    static enumContainer getEnumerations();

    Bytes8_9_10_12& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Bytes8_9_10_12(int value, std::string description);

	  static Bytes8_9_10_12* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Bytes8_9_10_12 */


}  /* namespace DIS */

#endif /* BYTES8_9_10_12__H */

