#ifndef CRYPTOSYSTEM__H
#define CRYPTOSYSTEM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CryptoSystem : public Enumeration {
  public:
    static CryptoSystem OTHER;
    static CryptoSystem KY_28;
    static CryptoSystem VINSON_KY_57_KY_58_SINCGARS_ICOM;
    static CryptoSystem NARROW_SPECTRUM_SECURE_VOICE_NSVE;
    static CryptoSystem WIDE_SPECTRUM_SECURE_VOICE_WSVE;
    static CryptoSystem MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CryptoSystem getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CryptoSystem*> enumContainer;
    static enumContainer getEnumerations();

    CryptoSystem& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CryptoSystem(int value, std::string description);

	  static CryptoSystem* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CryptoSystem */


}  /* namespace DIS */

#endif /* CRYPTOSYSTEM__H */

