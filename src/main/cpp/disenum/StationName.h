#ifndef STATIONNAME__H
#define STATIONNAME__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class StationName : public Enumeration {
  public:
    static StationName OTHER;
    static StationName AIRCRAFT_WINGSTATION;
    static StationName SHIPS_FORWARD_GUNMOUNT_STARBOARD;
    static StationName SHIPS_FORWARD_GUNMOUNT_PORT;
    static StationName SHIPS_FORWARD_GUNMOUNT_CENTERLINE;
    static StationName SHIPS_AFT_GUNMOUNT_STARBOARD;
    static StationName SHIPS_AFT_GUNMOUNT_PORT;
    static StationName SHIPS_AFT_GUNMOUNT_CENTERLINE;
    static StationName FORWARD_TORPEDO_TUBE;
    static StationName AFT_TORPEDO_TUBE;
    static StationName BOMB_BAY;
    static StationName CARGO_BAY;
    static StationName TRUCK_BED;
    static StationName TRAILER_BED;
    static StationName WELL_DECK;
    static StationName ON_STATION_RNG_BRG;
    static StationName ON_STATION_XYZ;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static StationName getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,StationName*> enumContainer;
    static enumContainer getEnumerations();

    StationName& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  StationName(int value, std::string description);

	  static StationName* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* StationName */


}  /* namespace DIS */

#endif /* STATIONNAME__H */

