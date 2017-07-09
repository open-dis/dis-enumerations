#ifndef PARAMETERTYPEDESIGNATOR__H
#define PARAMETERTYPEDESIGNATOR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ParameterTypeDesignator : public Enumeration {
  public:
    static ParameterTypeDesignator ARTICULATED_PART;
    static ParameterTypeDesignator ATTACHED_PART;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ParameterTypeDesignator getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ParameterTypeDesignator*> enumContainer;
    static enumContainer getEnumerations();

    ParameterTypeDesignator& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ParameterTypeDesignator(int value, std::string description);

	  static ParameterTypeDesignator* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ParameterTypeDesignator */


}  /* namespace DIS */

#endif /* PARAMETERTYPEDESIGNATOR__H */

