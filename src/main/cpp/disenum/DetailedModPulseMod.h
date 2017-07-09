#ifndef DETAILEDMODPULSEMOD__H
#define DETAILEDMODPULSEMOD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModPulseMod : public Enumeration {
  public:
    static DetailedModPulseMod OTHER;
    static DetailedModPulseMod PULSE;
    static DetailedModPulseMod X_BAND_TACAN_PULSE;
    static DetailedModPulseMod Y_BAND_TACAN_PULSE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModPulseMod getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModPulseMod*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModPulseMod& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModPulseMod(int value, std::string description);

	  static DetailedModPulseMod* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModPulseMod */


}  /* namespace DIS */

#endif /* DETAILEDMODPULSEMOD__H */

