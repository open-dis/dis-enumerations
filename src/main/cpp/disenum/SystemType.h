#ifndef SYSTEMTYPE__H
#define SYSTEMTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SystemType : public Enumeration {
  public:
    static SystemType OTHER;
    static SystemType MARK_X_XII_ATCRBS_MODE_S_TRANSPONDER;
    static SystemType MARK_X_XII_ATCRBS_MODE_S_INTERROGATOR;
    static SystemType SOVIET_TRANSPONDER;
    static SystemType SOVIET_INTERROGATOR;
    static SystemType RRB_TRANSPONDER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SystemType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SystemType*> enumContainer;
    static enumContainer getEnumerations();

    SystemType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SystemType(int value, std::string description);

	  static SystemType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SystemType */


}  /* namespace DIS */

#endif /* SYSTEMTYPE__H */

