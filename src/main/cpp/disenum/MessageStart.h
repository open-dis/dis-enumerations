#ifndef MESSAGESTART__H
#define MESSAGESTART__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class MessageStart : public Enumeration {
  public:
    static MessageStart NOT_START_OF_MESSAGE;
    static MessageStart START_OF_MESSAGE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static MessageStart getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,MessageStart*> enumContainer;
    static enumContainer getEnumerations();

    MessageStart& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  MessageStart(int value, std::string description);

	  static MessageStart* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* MessageStart */


}  /* namespace DIS */

#endif /* MESSAGESTART__H */

