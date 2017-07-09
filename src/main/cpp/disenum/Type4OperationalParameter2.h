#ifndef TYPE4OPERATIONALPARAMETER2__H
#define TYPE4OPERATIONALPARAMETER2__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Type4OperationalParameter2 : public Enumeration {
  public:
    static Type4OperationalParameter2 OTHER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Type4OperationalParameter2 getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Type4OperationalParameter2*> enumContainer;
    static enumContainer getEnumerations();

    Type4OperationalParameter2& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Type4OperationalParameter2(int value, std::string description);

	  static Type4OperationalParameter2* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Type4OperationalParameter2 */


}  /* namespace DIS */

#endif /* TYPE4OPERATIONALPARAMETER2__H */

