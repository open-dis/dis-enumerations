#ifndef PLATOONSECTION__H
#define PLATOONSECTION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PlatoonSection : public Enumeration {
  public:
    static PlatoonSection X_0_9;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PlatoonSection getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PlatoonSection*> enumContainer;
    static enumContainer getEnumerations();

    PlatoonSection& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PlatoonSection(int value, std::string description);

	  static PlatoonSection* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PlatoonSection */


}  /* namespace DIS */

#endif /* PLATOONSECTION__H */

