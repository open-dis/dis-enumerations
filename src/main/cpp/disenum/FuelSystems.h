#ifndef FUELSYSTEMS__H
#define FUELSYSTEMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class FuelSystems : public Enumeration {
  public:
    static FuelSystems FUEL_TRANSFER_PUMP;
    static FuelSystems FUEL_LINES;
    static FuelSystems GAUGES;
    static FuelSystems GENERAL_FUEL_SYSTEM;
    static FuelSystems MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static FuelSystems getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,FuelSystems*> enumContainer;
    static enumContainer getEnumerations();

    FuelSystems& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  FuelSystems(int value, std::string description);

	  static FuelSystems* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* FuelSystems */


}  /* namespace DIS */

#endif /* FUELSYSTEMS__H */

