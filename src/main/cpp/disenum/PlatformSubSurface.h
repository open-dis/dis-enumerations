#ifndef PLATFORMSUBSURFACE__H
#define PLATFORMSUBSURFACE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PlatformSubSurface : public Enumeration {
  public:
    static PlatformSubSurface OTHER;
    static PlatformSubSurface SSBN_NUCLEAR_BALLISTIC_MISSILE;
    static PlatformSubSurface SSGN_NUCLEAR_GUIDED_MISSILE;
    static PlatformSubSurface SSN_NUCLEAR_ATTACK_TORPEDO;
    static PlatformSubSurface SSG_CONVENTIONAL_GUIDED_MISSILE;
    static PlatformSubSurface SS_CONVENTIONAL_ATTACK_TORPEDO_PATROL;
    static PlatformSubSurface SSAN_NUCLEAR_AUXILIARY;
    static PlatformSubSurface SSA_CONVENTIONAL_AUXILIARY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PlatformSubSurface getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PlatformSubSurface*> enumContainer;
    static enumContainer getEnumerations();

    PlatformSubSurface& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PlatformSubSurface(int value, std::string description);

	  static PlatformSubSurface* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PlatformSubSurface */


}  /* namespace DIS */

#endif /* PLATFORMSUBSURFACE__H */

