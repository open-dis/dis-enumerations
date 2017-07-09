#ifndef FORMATION__H
#define FORMATION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Formation : public Enumeration {
  public:
    static Formation OTHER;
    static Formation ASSEMBLY;
    static Formation VEE;
    static Formation WEDGE;
    static Formation LINE;
    static Formation COLUMN;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Formation getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Formation*> enumContainer;
    static enumContainer getEnumerations();

    Formation& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Formation(int value, std::string description);

	  static Formation* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Formation */


}  /* namespace DIS */

#endif /* FORMATION__H */

