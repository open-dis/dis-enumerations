#ifndef ARTICULATEDPARTSOFFSETNUMBER__H
#define ARTICULATEDPARTSOFFSETNUMBER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ArticulatedPartsOffsetNumber : public Enumeration {
  public:
    static ArticulatedPartsOffsetNumber POSITION;
    static ArticulatedPartsOffsetNumber POSITION_RATE;
    static ArticulatedPartsOffsetNumber EXTENSION;
    static ArticulatedPartsOffsetNumber EXTENSION_RATE;
    static ArticulatedPartsOffsetNumber X;
    static ArticulatedPartsOffsetNumber X_RATE;
    static ArticulatedPartsOffsetNumber Y;
    static ArticulatedPartsOffsetNumber Y_RATE;
    static ArticulatedPartsOffsetNumber Z;
    static ArticulatedPartsOffsetNumber Z_RATE;
    static ArticulatedPartsOffsetNumber AZIMUTH;
    static ArticulatedPartsOffsetNumber AZIMUTH_RATE;
    static ArticulatedPartsOffsetNumber ELEVATION;
    static ArticulatedPartsOffsetNumber ELEVATION_RATE;
    static ArticulatedPartsOffsetNumber ROTATION;
    static ArticulatedPartsOffsetNumber ROTATION_RATE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ArticulatedPartsOffsetNumber getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ArticulatedPartsOffsetNumber*> enumContainer;
    static enumContainer getEnumerations();

    ArticulatedPartsOffsetNumber& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ArticulatedPartsOffsetNumber(int value, std::string description);

	  static ArticulatedPartsOffsetNumber* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ArticulatedPartsOffsetNumber */


}  /* namespace DIS */

#endif /* ARTICULATEDPARTSOFFSETNUMBER__H */

