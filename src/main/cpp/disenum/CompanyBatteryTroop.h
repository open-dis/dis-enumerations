#ifndef COMPANYBATTERYTROOP__H
#define COMPANYBATTERYTROOP__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CompanyBatteryTroop : public Enumeration {
  public:
    static CompanyBatteryTroop A_M;
    static CompanyBatteryTroop HQ;
    static CompanyBatteryTroop HHB;
    static CompanyBatteryTroop HHC;
    static CompanyBatteryTroop HHD;
    static CompanyBatteryTroop HHT;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CompanyBatteryTroop getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CompanyBatteryTroop*> enumContainer;
    static enumContainer getEnumerations();

    CompanyBatteryTroop& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CompanyBatteryTroop(int value, std::string description);

	  static CompanyBatteryTroop* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CompanyBatteryTroop */


}  /* namespace DIS */

#endif /* COMPANYBATTERYTROOP__H */

