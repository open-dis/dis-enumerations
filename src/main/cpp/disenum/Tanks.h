#ifndef TANKS__H
#define TANKS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Tanks : public Enumeration {
  public:
    static Tanks ENGINE_OFF;
    static Tanks IDLE_POWER;
    static Tanks MAX_POWER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Tanks getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Tanks*> enumContainer;
    static enumContainer getEnumerations();

    Tanks& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Tanks(int value, std::string description);

	  static Tanks* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Tanks */


}  /* namespace DIS */

#endif /* TANKS__H */

