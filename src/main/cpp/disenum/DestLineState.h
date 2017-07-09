#ifndef DESTLINESTATE__H
#define DESTLINESTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DestLineState : public Enumeration {
  public:
    static DestLineState NONE;
    static DestLineState SET_LINE_STATE_TRANSMITTING;
    static DestLineState SET_LINE_STATE_NOT_TRANSMITTING;
    static DestLineState RETURN_TO_LOCAL_LINE_STATE_CONTROL;
    static DestLineState MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DestLineState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DestLineState*> enumContainer;
    static enumContainer getEnumerations();

    DestLineState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DestLineState(int value, std::string description);

	  static DestLineState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DestLineState */


}  /* namespace DIS */

#endif /* DESTLINESTATE__H */

