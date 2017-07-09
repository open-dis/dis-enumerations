#ifndef CODENAME__H
#define CODENAME__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CodeName : public Enumeration {
  public:
    static CodeName OTHER;
    static CodeName MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CodeName getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CodeName*> enumContainer;
    static enumContainer getEnumerations();

    CodeName& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CodeName(int value, std::string description);

	  static CodeName* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CodeName */


}  /* namespace DIS */

#endif /* CODENAME__H */

