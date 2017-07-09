#ifndef PLATFORMSPACE__H
#define PLATFORMSPACE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PlatformSpace : public Enumeration {
  public:
    static PlatformSpace OTHER;
    static PlatformSpace MANNED;
    static PlatformSpace UNMANNED;
    static PlatformSpace BOOSTER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PlatformSpace getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PlatformSpace*> enumContainer;
    static enumContainer getEnumerations();

    PlatformSpace& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PlatformSpace(int value, std::string description);

	  static PlatformSpace* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PlatformSpace */


}  /* namespace DIS */

#endif /* PLATFORMSPACE__H */

