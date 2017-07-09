#ifndef HULLAIRFRAMEBODY__H
#define HULLAIRFRAMEBODY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class HullAirframeBody : public Enumeration {
  public:
    static HullAirframeBody HULL;
    static HullAirframeBody AIRFRAME;
    static HullAirframeBody TRUCK_BODY;
    static HullAirframeBody TANK_BODY;
    static HullAirframeBody TRAILER_BODY;
    static HullAirframeBody TURRET;
    static HullAirframeBody MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static HullAirframeBody getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,HullAirframeBody*> enumContainer;
    static enumContainer getEnumerations();

    HullAirframeBody& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  HullAirframeBody(int value, std::string description);

	  static HullAirframeBody* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* HullAirframeBody */


}  /* namespace DIS */

#endif /* HULLAIRFRAMEBODY__H */

