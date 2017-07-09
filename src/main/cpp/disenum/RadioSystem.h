#ifndef RADIOSYSTEM__H
#define RADIOSYSTEM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RadioSystem : public Enumeration {
  public:
    static RadioSystem OTHER;
    static RadioSystem GENERIC;
    static RadioSystem HQ;
    static RadioSystem HQII;
    static RadioSystem HQIIA;
    static RadioSystem SINCGARS;
    static RadioSystem CCTT_SINCGARS;
    static RadioSystem EPLRS_ENHANCED_POSITION_LOCATION_REPORTING_SYSTEM;
    static RadioSystem JTIDS_MIDS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RadioSystem getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RadioSystem*> enumContainer;
    static enumContainer getEnumerations();

    RadioSystem& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RadioSystem(int value, std::string description);

	  static RadioSystem* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RadioSystem */


}  /* namespace DIS */

#endif /* RADIOSYSTEM__H */

