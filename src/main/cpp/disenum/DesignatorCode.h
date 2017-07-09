#ifndef DESIGNATORCODE__H
#define DESIGNATORCODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DesignatorCode : public Enumeration {
  public:
    static DesignatorCode OTHER;
    static DesignatorCode MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DesignatorCode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DesignatorCode*> enumContainer;
    static enumContainer getEnumerations();

    DesignatorCode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DesignatorCode(int value, std::string description);

	  static DesignatorCode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DesignatorCode */


}  /* namespace DIS */

#endif /* DESIGNATORCODE__H */

