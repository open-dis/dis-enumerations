#ifndef REFERENCESYSTEM__H
#define REFERENCESYSTEM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ReferenceSystem : public Enumeration {
  public:
    static ReferenceSystem WORLD_COORDINATES;
    static ReferenceSystem ENTITY_COORDINATES;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ReferenceSystem getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ReferenceSystem*> enumContainer;
    static enumContainer getEnumerations();

    ReferenceSystem& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ReferenceSystem(int value, std::string description);

	  static ReferenceSystem* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ReferenceSystem */


}  /* namespace DIS */

#endif /* REFERENCESYSTEM__H */

