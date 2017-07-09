#ifndef ACOUSTICEMITTERS__H
#define ACOUSTICEMITTERS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AcousticEmitters : public Enumeration {
  public:
    static AcousticEmitters MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AcousticEmitters getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AcousticEmitters*> enumContainer;
    static enumContainer getEnumerations();

    AcousticEmitters& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AcousticEmitters(int value, std::string description);

	  static AcousticEmitters* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AcousticEmitters */


}  /* namespace DIS */

#endif /* ACOUSTICEMITTERS__H */

