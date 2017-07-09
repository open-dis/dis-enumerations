#ifndef PHYSICAL__H
#define PHYSICAL__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Physical : public Enumeration {
  public:
    static Physical GENERIC_PROBE;
    static Physical PROBE_METAL_CONTENT;
    static Physical PROBE_NO_METAL_CONTENT;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Physical getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Physical*> enumContainer;
    static enumContainer getEnumerations();

    Physical& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Physical(int value, std::string description);

	  static Physical* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Physical */


}  /* namespace DIS */

#endif /* PHYSICAL__H */

