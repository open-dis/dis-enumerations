#ifndef REQUIREDRELIABILITYSERVICE__H
#define REQUIREDRELIABILITYSERVICE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RequiredReliabilityService : public Enumeration {
  public:
    static RequiredReliabilityService ACKNOWLEDGED;
    static RequiredReliabilityService UNACKNOWLEDGED;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RequiredReliabilityService getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RequiredReliabilityService*> enumContainer;
    static enumContainer getEnumerations();

    RequiredReliabilityService& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RequiredReliabilityService(int value, std::string description);

	  static RequiredReliabilityService* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RequiredReliabilityService */


}  /* namespace DIS */

#endif /* REQUIREDRELIABILITYSERVICE__H */

