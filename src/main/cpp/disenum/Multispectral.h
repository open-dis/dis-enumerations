#ifndef MULTISPECTRAL__H
#define MULTISPECTRAL__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Multispectral : public Enumeration {
  public:
    static Multispectral GENERIC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Multispectral getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Multispectral*> enumContainer;
    static enumContainer getEnumerations();

    Multispectral& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Multispectral(int value, std::string description);

	  static Multispectral* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Multispectral */


}  /* namespace DIS */

#endif /* MULTISPECTRAL__H */

