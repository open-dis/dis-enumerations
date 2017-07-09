#ifndef GENERALREPAIRCODE__H
#define GENERALREPAIRCODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class GeneralRepairCode : public Enumeration {
  public:
    static GeneralRepairCode NO_REPAIRS_PERFORMED;
    static GeneralRepairCode ALL_REQUESTED_REPAIRS_PERFORMED;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static GeneralRepairCode getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,GeneralRepairCode*> enumContainer;
    static enumContainer getEnumerations();

    GeneralRepairCode& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  GeneralRepairCode(int value, std::string description);

	  static GeneralRepairCode* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* GeneralRepairCode */


}  /* namespace DIS */

#endif /* GENERALREPAIRCODE__H */

