#ifndef COORDINATESYSTEM__H
#define COORDINATESYSTEM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class CoordinateSystem : public Enumeration {
  public:
    static CoordinateSystem RIGHT_HANDED_CARTESIAN_LOCAL_TOPOGRAPHIC_PROJECTION_EAST_NORTH_UP;
    static CoordinateSystem LEFT_HANDED_CARTESIAN_LOCAL_TOPOGRAPHIC_PROJECTION_EAST_NORTH_DOWN;
    static CoordinateSystem LATITUDE_LONGITUDE_HEIGHT;
    static CoordinateSystem LATITUDE_LONGITUDE_DEPTH;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static CoordinateSystem getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,CoordinateSystem*> enumContainer;
    static enumContainer getEnumerations();

    CoordinateSystem& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  CoordinateSystem(int value, std::string description);

	  static CoordinateSystem* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* CoordinateSystem */


}  /* namespace DIS */

#endif /* COORDINATESYSTEM__H */

