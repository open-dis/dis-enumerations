#ifndef STATECHANGEUPDATEINDICATOR__H
#define STATECHANGEUPDATEINDICATOR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class StateChangeUpdateIndicator : public Enumeration {
  public:
    static StateChangeUpdateIndicator STATE_UPDATE;
    static StateChangeUpdateIndicator CHANGED_DATA_UPDATE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static StateChangeUpdateIndicator getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,StateChangeUpdateIndicator*> enumContainer;
    static enumContainer getEnumerations();

    StateChangeUpdateIndicator& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  StateChangeUpdateIndicator(int value, std::string description);

	  static StateChangeUpdateIndicator* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* StateChangeUpdateIndicator */


}  /* namespace DIS */

#endif /* STATECHANGEUPDATEINDICATOR__H */

