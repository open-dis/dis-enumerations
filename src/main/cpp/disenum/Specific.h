#ifndef SPECIFIC__H
#define SPECIFIC__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Specific : public Enumeration {
  public:
    static Specific NO_HEADQUARTERS;
    static Specific YES_AGGREGATE_UNIT_CONTAINS_A_HEADQUARTERS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Specific getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Specific*> enumContainer;
    static enumContainer getEnumerations();

    Specific& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Specific(int value, std::string description);

	  static Specific* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Specific */


}  /* namespace DIS */

#endif /* SPECIFIC__H */

