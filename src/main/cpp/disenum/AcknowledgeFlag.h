#ifndef ACKNOWLEDGEFLAG__H
#define ACKNOWLEDGEFLAG__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AcknowledgeFlag : public Enumeration {
  public:
    static AcknowledgeFlag CREATE_ENTITY;
    static AcknowledgeFlag REMOVE_ENTITY;
    static AcknowledgeFlag START_RESUME;
    static AcknowledgeFlag STOP_FREEZE;
    static AcknowledgeFlag TRANSFER_CONTROL_REQUEST;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AcknowledgeFlag getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AcknowledgeFlag*> enumContainer;
    static enumContainer getEnumerations();

    AcknowledgeFlag& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AcknowledgeFlag(int value, std::string description);

	  static AcknowledgeFlag* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AcknowledgeFlag */


}  /* namespace DIS */

#endif /* ACKNOWLEDGEFLAG__H */

