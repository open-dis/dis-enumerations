#ifndef BYTE11__H
#define BYTE11__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Byte11 : public Enumeration {
  public:
    static Byte11 _CARET_;
    static Byte11 _GT_;
    static Byte11 INVERTED_CARROT;
    static Byte11 _LT_;
    static Byte11 _CARET_AND_INVERTED_CARROT;
    static Byte11 _LT_GT_;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Byte11 getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Byte11*> enumContainer;
    static enumContainer getEnumerations();

    Byte11& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Byte11(int value, std::string description);

	  static Byte11* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Byte11 */


}  /* namespace DIS */

#endif /* BYTE11__H */

