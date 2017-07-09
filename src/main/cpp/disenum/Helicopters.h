#ifndef HELICOPTERS__H
#define HELICOPTERS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Helicopters : public Enumeration {
  public:
    static Helicopters ENGINE_OFF;
    static Helicopters IDLE_POWER;
    static Helicopters MAX_POWER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Helicopters getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Helicopters*> enumContainer;
    static enumContainer getEnumerations();

    Helicopters& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Helicopters(int value, std::string description);

	  static Helicopters* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Helicopters */


}  /* namespace DIS */

#endif /* HELICOPTERS__H */

