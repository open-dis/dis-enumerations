#ifndef OTHERACOUSTICEMITTERS__H
#define OTHERACOUSTICEMITTERS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class OtherAcousticEmitters : public Enumeration {
  public:
    static OtherAcousticEmitters MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static OtherAcousticEmitters getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,OtherAcousticEmitters*> enumContainer;
    static enumContainer getEnumerations();

    OtherAcousticEmitters& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  OtherAcousticEmitters(int value, std::string description);

	  static OtherAcousticEmitters* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* OtherAcousticEmitters */


}  /* namespace DIS */

#endif /* OTHERACOUSTICEMITTERS__H */

