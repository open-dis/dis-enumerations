#ifndef TYPE4ALTPARAMETER4__H
#define TYPE4ALTPARAMETER4__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Type4AltParameter4 : public Enumeration {
  public:
    static Type4AltParameter4 MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Type4AltParameter4 getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Type4AltParameter4*> enumContainer;
    static enumContainer getEnumerations();

    Type4AltParameter4& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Type4AltParameter4(int value, std::string description);

	  static Type4AltParameter4* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Type4AltParameter4 */


}  /* namespace DIS */

#endif /* TYPE4ALTPARAMETER4__H */

