#ifndef DIVISIONCORPSDESIGNATION__H
#define DIVISIONCORPSDESIGNATION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DivisionCorpsDesignation : public Enumeration {
  public:
    static DivisionCorpsDesignation NA_CASE;
    static DivisionCorpsDesignation X_1ST_CAVALRY;
    static DivisionCorpsDesignation X_1ST_INFANTRY;
    static DivisionCorpsDesignation CORPS_ASSETS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DivisionCorpsDesignation getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DivisionCorpsDesignation*> enumContainer;
    static enumContainer getEnumerations();

    DivisionCorpsDesignation& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DivisionCorpsDesignation(int value, std::string description);

	  static DivisionCorpsDesignation* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DivisionCorpsDesignation */


}  /* namespace DIS */

#endif /* DIVISIONCORPSDESIGNATION__H */

