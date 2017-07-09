#ifndef SONAR__H
#define SONAR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SONAR : public Enumeration {
  public:
    static SONAR GENERIC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SONAR getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SONAR*> enumContainer;
    static enumContainer getEnumerations();

    SONAR& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SONAR(int value, std::string description);

	  static SONAR* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SONAR */


}  /* namespace DIS */

#endif /* SONAR__H */

