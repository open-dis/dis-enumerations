#ifndef DETAILEDMODANGLEMOD__H
#define DETAILEDMODANGLEMOD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModAngleMod : public Enumeration {
  public:
    static DetailedModAngleMod OTHER;
    static DetailedModAngleMod FM_FREQUENCY_MODULATION;
    static DetailedModAngleMod FSK_FREQUENCY_SHIFT_KEYING;
    static DetailedModAngleMod PM_PHASE_MODULATION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModAngleMod getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModAngleMod*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModAngleMod& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModAngleMod(int value, std::string description);

	  static DetailedModAngleMod* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModAngleMod */


}  /* namespace DIS */

#endif /* DETAILEDMODANGLEMOD__H */

