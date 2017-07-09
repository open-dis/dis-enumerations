#ifndef REPAIRRESPONSEPDU__H
#define REPAIRRESPONSEPDU__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RepairResponsePDU : public Enumeration {
  public:
    static RepairResponsePDU OTHER;
    static RepairResponsePDU REPAIR_ENDED;
    static RepairResponsePDU INVALID_REPAIR;
    static RepairResponsePDU REPAIR_INTERRUPTED;
    static RepairResponsePDU SERVICE_CANCELED_BY_THE_SUPPLIER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RepairResponsePDU getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RepairResponsePDU*> enumContainer;
    static enumContainer getEnumerations();

    RepairResponsePDU& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RepairResponsePDU(int value, std::string description);

	  static RepairResponsePDU* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RepairResponsePDU */


}  /* namespace DIS */

#endif /* REPAIRRESPONSEPDU__H */

