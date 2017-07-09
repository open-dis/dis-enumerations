#ifndef INPUTSOURCE__H
#define INPUTSOURCE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class InputSource : public Enumeration {
  public:
    static InputSource OTHER;
    static InputSource PILOT;
    static InputSource COPILOT;
    static InputSource FIRST_OFFICER;
    static InputSource DRIVER;
    static InputSource LOADER;
    static InputSource GUNNER;
    static InputSource COMMANDER;
    static InputSource DIGITAL_DATA_DEVICE;
    static InputSource INTERCOM;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static InputSource getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,InputSource*> enumContainer;
    static enumContainer getEnumerations();

    InputSource& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  InputSource(int value, std::string description);

	  static InputSource* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* InputSource */


}  /* namespace DIS */

#endif /* INPUTSOURCE__H */

