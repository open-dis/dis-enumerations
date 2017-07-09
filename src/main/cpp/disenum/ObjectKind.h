#ifndef OBJECTKIND__H
#define OBJECTKIND__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ObjectKind : public Enumeration {
  public:
    static ObjectKind OTHER;
    static ObjectKind OBSTACLE;
    static ObjectKind PREPARED_POSITION;
    static ObjectKind CULTURAL_FEATURE;
    static ObjectKind PASSAGEWAY;
    static ObjectKind TACTICAL_SMOKE;
    static ObjectKind OBSTACLE_MARKER;
    static ObjectKind OBSTACLE_BREACH;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ObjectKind getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ObjectKind*> enumContainer;
    static enumContainer getEnumerations();

    ObjectKind& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ObjectKind(int value, std::string description);

	  static ObjectKind* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ObjectKind */


}  /* namespace DIS */

#endif /* OBJECTKIND__H */

