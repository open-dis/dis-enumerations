#ifndef MAGNETIC__H
#define MAGNETIC__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Magnetic : public Enumeration {
  public:
    static Magnetic GENERIC;
    static Magnetic AN_PSS_11;
    static Magnetic AN_PSS_12;
    static Magnetic GSTAMIDS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Magnetic getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Magnetic*> enumContainer;
    static enumContainer getEnumerations();

    Magnetic& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Magnetic(int value, std::string description);

	  static Magnetic* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Magnetic */


}  /* namespace DIS */

#endif /* MAGNETIC__H */

