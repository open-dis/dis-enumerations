#ifndef AUXILIARYCRAFT__H
#define AUXILIARYCRAFT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AuxiliaryCraft : public Enumeration {
  public:
    static AuxiliaryCraft LIFE_BOATS;
    static AuxiliaryCraft LANDING_CRAFT;
    static AuxiliaryCraft EJECTION_SEATS;
    static AuxiliaryCraft MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AuxiliaryCraft getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AuxiliaryCraft*> enumContainer;
    static enumContainer getEnumerations();

    AuxiliaryCraft& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AuxiliaryCraft(int value, std::string description);

	  static AuxiliaryCraft* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AuxiliaryCraft */


}  /* namespace DIS */

#endif /* AUXILIARYCRAFT__H */

