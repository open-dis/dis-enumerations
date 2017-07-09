#ifndef ADDITIONALPASSIVEACTIVITY__H
#define ADDITIONALPASSIVEACTIVITY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AdditionalPassiveActivity : public Enumeration {
  public:
    static AdditionalPassiveActivity OTHER;
    static AdditionalPassiveActivity GRAHAMS_MKV_COFFEE_MAKER;
    static AdditionalPassiveActivity RESERVED_FOR_CLASSIFIED_ENUMERATIONS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AdditionalPassiveActivity getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AdditionalPassiveActivity*> enumContainer;
    static enumContainer getEnumerations();

    AdditionalPassiveActivity& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AdditionalPassiveActivity(int value, std::string description);

	  static AdditionalPassiveActivity* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AdditionalPassiveActivity */


}  /* namespace DIS */

#endif /* ADDITIONALPASSIVEACTIVITY__H */

