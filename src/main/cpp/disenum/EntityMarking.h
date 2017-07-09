#ifndef ENTITYMARKING__H
#define ENTITYMARKING__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class EntityMarking : public Enumeration {
  public:
    static EntityMarking MISSING_DESCRIPTION;
    static EntityMarking ASCII;
    static EntityMarking ARMY_MARKING_CCTT;
    static EntityMarking DIGIT_CHEVRON;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static EntityMarking getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,EntityMarking*> enumContainer;
    static enumContainer getEnumerations();

    EntityMarking& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  EntityMarking(int value, std::string description);

	  static EntityMarking* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* EntityMarking */


}  /* namespace DIS */

#endif /* ENTITYMARKING__H */

