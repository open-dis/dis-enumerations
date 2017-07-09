#ifndef RECORDTYPE__H
#define RECORDTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RecordType : public Enumeration {
  public:
    static RecordType ENTITY_DESTINATION_RECORD;
    static RecordType GROUP_DESTINATION_RECORD;
    static RecordType GROUP_ASSIGNMENT_RECORD;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RecordType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RecordType*> enumContainer;
    static enumContainer getEnumerations();

    RecordType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RecordType(int value, std::string description);

	  static RecordType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RecordType */


}  /* namespace DIS */

#endif /* RECORDTYPE__H */

