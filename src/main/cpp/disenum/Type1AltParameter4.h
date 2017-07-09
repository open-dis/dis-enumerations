#ifndef TYPE1ALTPARAMETER4__H
#define TYPE1ALTPARAMETER4__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Type1AltParameter4 : public Enumeration {
  public:
    static Type1AltParameter4 OTHER;
    static Type1AltParameter4 VALID;
    static Type1AltParameter4 INVALID;
    static Type1AltParameter4 NO_RESPONSE;
    static Type1AltParameter4 MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Type1AltParameter4 getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Type1AltParameter4*> enumContainer;
    static enumContainer getEnumerations();

    Type1AltParameter4& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Type1AltParameter4(int value, std::string description);

	  static Type1AltParameter4* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Type1AltParameter4 */


}  /* namespace DIS */

#endif /* TYPE1ALTPARAMETER4__H */

