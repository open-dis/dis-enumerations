#ifndef STATERECORDTYPEFIELD__H
#define STATERECORDTYPEFIELD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class StateRecordTypeField : public Enumeration {
  public:
    static StateRecordTypeField COMBIC_STATE;
    static StateRecordTypeField FLARE_STATE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static StateRecordTypeField getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,StateRecordTypeField*> enumContainer;
    static enumContainer getEnumerations();

    StateRecordTypeField& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  StateRecordTypeField(int value, std::string description);

	  static StateRecordTypeField* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* StateRecordTypeField */


}  /* namespace DIS */

#endif /* STATERECORDTYPEFIELD__H */

