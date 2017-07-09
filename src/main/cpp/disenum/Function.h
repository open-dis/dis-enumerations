#ifndef FUNCTION__H
#define FUNCTION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Function : public Enumeration {
  public:
    static Function OTHER;
    static Function PLATFORM_SEARCH_DETECT_TRACK;
    static Function NAVIGATION;
    static Function MINE_HUNTING;
    static Function WEAPON_SEARCH_DETECT_TRACK_DETECT;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Function getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Function*> enumContainer;
    static enumContainer getEnumerations();

    Function& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Function(int value, std::string description);

	  static Function* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Function */


}  /* namespace DIS */

#endif /* FUNCTION__H */

