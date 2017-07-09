#ifndef PASSIVEPARAMETERINDEX__H
#define PASSIVEPARAMETERINDEX__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PassiveParameterIndex : public Enumeration {
  public:
    static PassiveParameterIndex OTHER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PassiveParameterIndex getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PassiveParameterIndex*> enumContainer;
    static enumContainer getEnumerations();

    PassiveParameterIndex& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PassiveParameterIndex(int value, std::string description);

	  static PassiveParameterIndex* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PassiveParameterIndex */


}  /* namespace DIS */

#endif /* PASSIVEPARAMETERINDEX__H */

