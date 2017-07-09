#ifndef OPTICAL__H
#define OPTICAL__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Optical : public Enumeration {
  public:
    static Optical UNAIDED_EYE_ACTIVELY_SEARCHING;
    static Optical UNAIDED_EYE_NOT_ACTIVELY_SEARCHING;
    static Optical BINOCULARS;
    static Optical IMAGE_INTENSIFIER;
    static Optical HMMWV_OCCUPANT_ACTIVELY_SEARCHING;
    static Optical HMMWV_OCCUPANT_NOT_ACTIVELY_SEARCHING;
    static Optical TRUCK_OCCUPANT_ACTIVELY_SEARCHING;
    static Optical TRUCK_OCCUPANT_NOT_ACTIVELY_SEARCHING;
    static Optical TRACKED_VEHICLE_OCCUPANT_CLOSED_HATCH_ACTIVELY_SEARCHING;
    static Optical TRACKED_VEHICLE_OCCUPANT_CLOSED_HATCH_NOT_ACTIVELY_SEARCHING;
    static Optical TRACKED_VEHICLE_OCCUPANT_OPEN_HATCH_ACTIVELY_SEARCHING;
    static Optical TRACKED_VEHICLE_OCCUPANT_OPEN_HATCH_NOT_ACTIVELY_SEARCHING;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Optical getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Optical*> enumContainer;
    static enumContainer getEnumerations();

    Optical& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Optical(int value, std::string description);

	  static Optical* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Optical */


}  /* namespace DIS */

#endif /* OPTICAL__H */

