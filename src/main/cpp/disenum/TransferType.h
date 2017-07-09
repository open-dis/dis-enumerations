#ifndef TRANSFERTYPE__H
#define TRANSFERTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class TransferType : public Enumeration {
  public:
    static TransferType OTHER;
    static TransferType CONTROLLING_APPLICATION_REQUESTS_TRANSFER_OF_AN_ENTITY;
    static TransferType APPLICATION_DESIRING_CONTROL_REQUESTS_TRANSFER_OF_AN_ENTITY;
    static TransferType MUTUAL_EXCHANGE_SWAP_OF_AN_ENTITY;
    static TransferType CONTROLLING_APPLICATION_REQUESTS_TRANSFER_OF_AN_ENVIRONMENTAL_PROCESS;
    static TransferType APPLICATION_DESIRING_CONTROLS_REQUESTS_TRANSFER_OF_AN_ENVIRONMENTAL_PROCESS;
    static TransferType MUTUAL_EXCHANGE_SWAP_OF_AN_ENVIRONMENTAL;
    static TransferType CANCEL_TRANSFER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static TransferType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,TransferType*> enumContainer;
    static enumContainer getEnumerations();

    TransferType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  TransferType(int value, std::string description);

	  static TransferType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* TransferType */


}  /* namespace DIS */

#endif /* TRANSFERTYPE__H */

