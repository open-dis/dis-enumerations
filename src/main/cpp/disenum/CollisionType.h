#ifndef COLLISIONTYPE__H
#define COLLISIONTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CollisionType : public Enumeration {
  public:
    static CollisionType INELASTIC;
    static CollisionType ELASTIC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CollisionType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CollisionType*> enumContainer;
    static enumContainer getEnumerations();

    CollisionType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CollisionType(int value, std::string description);

	  static CollisionType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CollisionType */


}  /* namespace DIS */

#endif /* COLLISIONTYPE__H */

