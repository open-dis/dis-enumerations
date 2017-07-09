#ifndef DIGITCHEVRONCODE__H
#define DIGITCHEVRONCODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DigitChevronCode : public Enumeration {
  public:
    static DigitChevronCode X_0_9;
    static DigitChevronCode UNDERSCORE_0_9;
    static DigitChevronCode E;
    static DigitChevronCode UNDERSCORE_E;
    static DigitChevronCode S;
    static DigitChevronCode UNDERSCORE_S;
    static DigitChevronCode X;
    static DigitChevronCode UNDERSCORE_X;
    static DigitChevronCode BLANK;
    static DigitChevronCode _CARET_;
    static DigitChevronCode _GT_;
    static DigitChevronCode INVERTED_CARROT;
    static DigitChevronCode _LT_;
    static DigitChevronCode _CARET_AND_INVERTED_CARROT;
    static DigitChevronCode _LT_GT_;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DigitChevronCode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DigitChevronCode*> enumContainer;
    static enumContainer getEnumerations();

    DigitChevronCode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DigitChevronCode(int value, std::string description);

	  static DigitChevronCode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DigitChevronCode */


}  /* namespace DIS */

#endif /* DIGITCHEVRONCODE__H */

