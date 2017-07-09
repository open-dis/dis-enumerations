#ifndef SERVICEREQUESTPDU__H
#define SERVICEREQUESTPDU__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ServiceRequestPDU : public Enumeration {
  public:
    static ServiceRequestPDU OTHER;
    static ServiceRequestPDU RESUPPLY;
    static ServiceRequestPDU REPAIR;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ServiceRequestPDU getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ServiceRequestPDU*> enumContainer;
    static enumContainer getEnumerations();

    ServiceRequestPDU& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ServiceRequestPDU(int value, std::string description);

	  static ServiceRequestPDU* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ServiceRequestPDU */


}  /* namespace DIS */

#endif /* SERVICEREQUESTPDU__H */

