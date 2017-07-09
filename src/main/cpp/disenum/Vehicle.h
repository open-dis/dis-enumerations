#ifndef VEHICLE__H
#define VEHICLE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Vehicle : public Enumeration {
  public:
    static Vehicle X_0_9;
    static Vehicle BLANK;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Vehicle getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Vehicle*> enumContainer;
    static enumContainer getEnumerations();

    Vehicle& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Vehicle(int value, std::string description);

	  static Vehicle* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Vehicle */


}  /* namespace DIS */

#endif /* VEHICLE__H */

