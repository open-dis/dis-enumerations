#ifndef CLEARCHANNEL__H
#define CLEARCHANNEL__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ClearChannel : public Enumeration {
  public:
    static ClearChannel NOT_CLEAR_CHANNEL;
    static ClearChannel CLEAR_CHANNEL;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ClearChannel getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ClearChannel*> enumContainer;
    static enumContainer getEnumerations();

    ClearChannel& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ClearChannel(int value, std::string description);

	  static ClearChannel* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ClearChannel */


}  /* namespace DIS */

#endif /* CLEARCHANNEL__H */

