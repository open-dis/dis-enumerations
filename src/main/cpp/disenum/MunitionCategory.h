#ifndef MUNITIONCATEGORY__H
#define MUNITIONCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class MunitionCategory : public Enumeration {
  public:
    static MunitionCategory OTHER;
    static MunitionCategory GUIDED;
    static MunitionCategory BALLISTIC;
    static MunitionCategory FIXED;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static MunitionCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,MunitionCategory*> enumContainer;
    static enumContainer getEnumerations();

    MunitionCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  MunitionCategory(int value, std::string description);

	  static MunitionCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* MunitionCategory */


}  /* namespace DIS */

#endif /* MUNITIONCATEGORY__H */

