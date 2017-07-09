#ifndef INTERFACESWITHENVIRONMENT__H
#define INTERFACESWITHENVIRONMENT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class InterfacesWithEnvironment : public Enumeration {
  public:
    static InterfacesWithEnvironment PROPELLER;
    static InterfacesWithEnvironment FILTERS;
    static InterfacesWithEnvironment WHEELS;
    static InterfacesWithEnvironment TIRE;
    static InterfacesWithEnvironment TRACK;
    static InterfacesWithEnvironment MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static InterfacesWithEnvironment getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,InterfacesWithEnvironment*> enumContainer;
    static enumContainer getEnumerations();

    InterfacesWithEnvironment& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  InterfacesWithEnvironment(int value, std::string description);

	  static InterfacesWithEnvironment* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* InterfacesWithEnvironment */


}  /* namespace DIS */

#endif /* INTERFACESWITHENVIRONMENT__H */

