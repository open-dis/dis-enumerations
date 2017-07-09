#ifndef RADIONOMENCLATURE__H
#define RADIONOMENCLATURE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RadioNomenclature : public Enumeration {
  public:
    static RadioNomenclature OTHER;
    static RadioNomenclature AN_ARN_118;
    static RadioNomenclature AN_ARN_139;
    static RadioNomenclature GENERIC_GROUND_FIXED_TRANSMITTER;
    static RadioNomenclature GENERIC_GROUND_MOBILE_TRANSMITTER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RadioNomenclature getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RadioNomenclature*> enumContainer;
    static enumContainer getEnumerations();

    RadioNomenclature& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RadioNomenclature(int value, std::string description);

	  static RadioNomenclature* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RadioNomenclature */


}  /* namespace DIS */

#endif /* RADIONOMENCLATURE__H */

