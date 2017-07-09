#ifndef EXPENDABLEAIRCATEGORY__H
#define EXPENDABLEAIRCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ExpendableAirCategory : public Enumeration {
  public:
    static ExpendableAirCategory OTHER;
    static ExpendableAirCategory CHAFF;
    static ExpendableAirCategory FLARE;
    static ExpendableAirCategory COMBINED_CHAFF_AND_FLARE;
    static ExpendableAirCategory ACTIVE_EMITTER;
    static ExpendableAirCategory PASSIVE_DECOY;
    static ExpendableAirCategory WINGED_DECOY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ExpendableAirCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ExpendableAirCategory*> enumContainer;
    static enumContainer getEnumerations();

    ExpendableAirCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ExpendableAirCategory(int value, std::string description);

	  static ExpendableAirCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ExpendableAirCategory */


}  /* namespace DIS */

#endif /* EXPENDABLEAIRCATEGORY__H */

