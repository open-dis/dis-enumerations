#ifndef ANTENNAPATTERNTYPE__H
#define ANTENNAPATTERNTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AntennaPatternType : public Enumeration {
  public:
    static AntennaPatternType OMNI_DIRECTIONAL;
    static AntennaPatternType BEAM;
    static AntennaPatternType SPHERICAL_HARMONIC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AntennaPatternType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AntennaPatternType*> enumContainer;
    static enumContainer getEnumerations();

    AntennaPatternType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AntennaPatternType(int value, std::string description);

	  static AntennaPatternType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AntennaPatternType */


}  /* namespace DIS */

#endif /* ANTENNAPATTERNTYPE__H */

