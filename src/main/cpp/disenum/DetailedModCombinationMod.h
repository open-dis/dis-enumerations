#ifndef DETAILEDMODCOMBINATIONMOD__H
#define DETAILEDMODCOMBINATIONMOD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModCombinationMod : public Enumeration {
  public:
    static DetailedModCombinationMod OTHER;
    static DetailedModCombinationMod AMPLITUDE_ANGLE_PULSE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModCombinationMod getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModCombinationMod*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModCombinationMod& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModCombinationMod(int value, std::string description);

	  static DetailedModCombinationMod* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModCombinationMod */


}  /* namespace DIS */

#endif /* DETAILEDMODCOMBINATIONMOD__H */

