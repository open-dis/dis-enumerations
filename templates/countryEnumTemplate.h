#ifndef @ENUMUPPERCASE__H
#define @ENUMUPPERCASE__H

#include <string>
#include <disenum/Enumeration.h>


namespace DIS {

class @ENUMERATIONNAME : public Enumeration {
  public:
	@ENUMS

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static @ENUMERATIONNAME getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    /** As an alternative, returns the internet domain code for this country, if it exists. */
    std::string getInternetDomainCode() { return internetDomainCode; }

    typedef hashMap<int,@ENUMERATIONNAME*> enumContainer;
    static enumContainer getEnumerations();

  private:
    /** Constructor */
	  @ENUMERATIONNAME(int value, std::string description, std::string internetDomainCode);

    /** Internet domain code (US, FR, UK, CA, etc). This is a guess for many countries */
    std::string internetDomainCode;

    static @ENUMERATIONNAME* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* @ENUMERATIONNAME */


}  /* namespace DIS */

#endif /* @ENUMUPPERCASE__H */

