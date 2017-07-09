#ifndef FLIR__H
#define FLIR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class FLIR : public Enumeration {
  public:
    static FLIR GENERIC_3_5;
    static FLIR GENERIC_8_12;
    static FLIR ASTAMIDS_I;
    static FLIR ASTAMIDS_II;
    static FLIR GSTAMIDS_3_5;
    static FLIR GSTAMIDS_8_12;
    static FLIR HSTAMIDS_3_5;
    static FLIR HSTAMIDS_8_12;
    static FLIR COBRA_3_5;
    static FLIR COBRA_8_12;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static FLIR getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,FLIR*> enumContainer;
    static enumContainer getEnumerations();

    FLIR& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  FLIR(int value, std::string description);

	  static FLIR* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* FLIR */


}  /* namespace DIS */

#endif /* FLIR__H */

