#ifndef ENTITYKIND__H
#define ENTITYKIND__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class EntityKind : public Enumeration {
  public:
    static EntityKind OTHER;
    static EntityKind PLATFORM;
    static EntityKind MUNITION;
    static EntityKind LIFE_FORM;
    static EntityKind ENVIRONMENTAL;
    static EntityKind CULTURAL_FEATURE;
    static EntityKind SUPPLY;
    static EntityKind RADIO;
    static EntityKind EXPENDABLE;
    static EntityKind SENSOR_EMITTER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static EntityKind getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,EntityKind*> enumContainer;
    static enumContainer getEnumerations();

    EntityKind& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  EntityKind(int value, std::string description);

	  static EntityKind* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* EntityKind */


}  /* namespace DIS */

#endif /* ENTITYKIND__H */

