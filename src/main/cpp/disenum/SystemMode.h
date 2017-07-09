#ifndef SYSTEMMODE__H
#define SYSTEMMODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SystemMode : public Enumeration {
  public:
    static SystemMode OTHER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SystemMode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SystemMode*> enumContainer;
    static enumContainer getEnumerations();

    SystemMode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SystemMode(int value, std::string description);

	  static SystemMode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SystemMode */


}  /* namespace DIS */

#endif /* SYSTEMMODE__H */

