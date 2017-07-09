#ifndef POSITION__H
#define POSITION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Position : public Enumeration {
  public:
    static Position OTHER;
    static Position ON_TOP_OF;
    static Position INSIDE_OF;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Position getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Position*> enumContainer;
    static enumContainer getEnumerations();

    Position& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Position(int value, std::string description);

	  static Position* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Position */


}  /* namespace DIS */

#endif /* POSITION__H */

