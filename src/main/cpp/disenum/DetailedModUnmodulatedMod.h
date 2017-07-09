#ifndef DETAILEDMODUNMODULATEDMOD__H
#define DETAILEDMODUNMODULATEDMOD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModUnmodulatedMod : public Enumeration {
  public:
    static DetailedModUnmodulatedMod OTHER;
    static DetailedModUnmodulatedMod CONTINUOUS_WAVE_EMISSION_OF_AN_UNMODULATED_CARRIER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModUnmodulatedMod getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModUnmodulatedMod*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModUnmodulatedMod& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModUnmodulatedMod(int value, std::string description);

	  static DetailedModUnmodulatedMod* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModUnmodulatedMod */


}  /* namespace DIS */

#endif /* DETAILEDMODUNMODULATEDMOD__H */

