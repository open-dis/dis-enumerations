#ifndef LASER__H
#define LASER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Laser : public Enumeration {
  public:
    static Laser GENERIC;
    static Laser ASTAMIDS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Laser getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Laser*> enumContainer;
    static enumContainer getEnumerations();

    Laser& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Laser(int value, std::string description);

	  static Laser* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Laser */


}  /* namespace DIS */

#endif /* LASER__H */

