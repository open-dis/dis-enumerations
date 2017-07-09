#ifndef ENVIRONMENTALKIND__H
#define ENVIRONMENTALKIND__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class EnvironmentalKind : public Enumeration {
  public:
    static EnvironmentalKind OTHER;
    static EnvironmentalKind VERY_SMALL;
    static EnvironmentalKind SMALL;
    static EnvironmentalKind MEDIUM;
    static EnvironmentalKind LARGE;
    static EnvironmentalKind VERY_LARGE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static EnvironmentalKind getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,EnvironmentalKind*> enumContainer;
    static enumContainer getEnumerations();

    EnvironmentalKind& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  EnvironmentalKind(int value, std::string description);

	  static EnvironmentalKind* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* EnvironmentalKind */


}  /* namespace DIS */

#endif /* ENVIRONMENTALKIND__H */

