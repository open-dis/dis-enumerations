#ifndef MUNITIONDOMAIN__H
#define MUNITIONDOMAIN__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class MunitionDomain : public Enumeration {
  public:
    static MunitionDomain OTHER;
    static MunitionDomain ANTI_AIR;
    static MunitionDomain ANTI_ARMOR;
    static MunitionDomain ANTI_GUIDED_WEAPON;
    static MunitionDomain ANTIRADAR;
    static MunitionDomain ANTISATELLITE;
    static MunitionDomain ANTISHIP;
    static MunitionDomain ANTISUBMARINE;
    static MunitionDomain ANTIPERSONNEL;
    static MunitionDomain BATTLEFIELD_SUPPORT;
    static MunitionDomain STRATEGIC;
    static MunitionDomain TACTICAL;
    static MunitionDomain DIRECTED_ENERGY_DE_WEAPON;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static MunitionDomain getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,MunitionDomain*> enumContainer;
    static enumContainer getEnumerations();

    MunitionDomain& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  MunitionDomain(int value, std::string description);

	  static MunitionDomain* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* MunitionDomain */


}  /* namespace DIS */

#endif /* MUNITIONDOMAIN__H */

