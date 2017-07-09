#ifndef ENTITYDOMAIN__H
#define ENTITYDOMAIN__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class EntityDomain : public Enumeration {
  public:
    static EntityDomain OTHER;
    static EntityDomain LAND;
    static EntityDomain AIR;
    static EntityDomain SURFACE;
    static EntityDomain SUBSURFACE;
    static EntityDomain SPACE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static EntityDomain getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,EntityDomain*> enumContainer;
    static enumContainer getEnumerations();

    EntityDomain& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  EntityDomain(int value, std::string description);

	  static EntityDomain* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* EntityDomain */


}  /* namespace DIS */

#endif /* ENTITYDOMAIN__H */

