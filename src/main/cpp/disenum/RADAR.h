#ifndef RADAR__H
#define RADAR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RADAR : public Enumeration {
  public:
    static RADAR GENERIC;
    static RADAR GENERIC_GPR;
    static RADAR GSTAMIDS_I;
    static RADAR GSTAMIDS_II;
    static RADAR HSTAMIDS_I;
    static RADAR HSTAMIDS_II;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RADAR getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RADAR*> enumContainer;
    static enumContainer getEnumerations();

    RADAR& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RADAR(int value, std::string description);

	  static RADAR* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RADAR */


}  /* namespace DIS */

#endif /* RADAR__H */

