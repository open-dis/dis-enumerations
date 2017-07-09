#ifndef COMMAND__H
#define COMMAND__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Command : public Enumeration {
  public:
    static Command NO_COMMAND;
    static Command STATUS;
    static Command CONNECT;
    static Command DISCONNECT;
    static Command RESET;
    static Command ON;
    static Command OFF;
    static Command MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Command getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Command*> enumContainer;
    static enumContainer getEnumerations();

    Command& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Command(int value, std::string description);

	  static Command* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Command */


}  /* namespace DIS */

#endif /* COMMAND__H */

