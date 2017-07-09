#ifndef PLATFORMSURFACE__H
#define PLATFORMSURFACE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PlatformSurface : public Enumeration {
  public:
    static PlatformSurface OTHER;
    static PlatformSurface CARRIER;
    static PlatformSurface COMMAND_SHIP_CRUISER;
    static PlatformSurface GUIDED_MISSILE_CRUISER;
    static PlatformSurface GUIDED_MISSILE_DESTROYER_DDG;
    static PlatformSurface DESTROYER_DD;
    static PlatformSurface GUIDED_MISSILE_FRIGATE_FFG;
    static PlatformSurface LIGHT_PATROL_CRAFT;
    static PlatformSurface MINE_COUNTERMEASURE_SHIP_CRAFT;
    static PlatformSurface DOCK_LANDING_SHIP;
    static PlatformSurface TANK_LANDING_SHIP;
    static PlatformSurface LANDING_CRAFT;
    static PlatformSurface LIGHT_CARRIER;
    static PlatformSurface CRUISER_HELICOPTER_CARRIER;
    static PlatformSurface HYDROFOIL;
    static PlatformSurface AIR_CUSHION_SURFACE_EFFECT;
    static PlatformSurface AUXILIARY;
    static PlatformSurface AUXILIARY_MERCHANT_MARINE;
    static PlatformSurface UTILITY;
    static PlatformSurface FRIGATE_INCLUDING_CORVETTE;
    static PlatformSurface BATTLESHIP;
    static PlatformSurface HEAVY_CRUISER;
    static PlatformSurface DESTROYER_TENDER;
    static PlatformSurface AMPHIBIOUS_ASSAULT_SHIP;
    static PlatformSurface AMPHIBIOUS_CARGO_SHIP;
    static PlatformSurface AMPHIBIOUS_TRANSPORT_DOCK;
    static PlatformSurface AMMUNITION_SHIP;
    static PlatformSurface COMBAT_STORES_SHIP;
    static PlatformSurface SURVEILLANCE_TOWED_ARRAY_SONAR_SYSTEM_SURTASS;
    static PlatformSurface FAST_COMBAT_SUPPORT_SHIP;
    static PlatformSurface NON_COMBATANT_SHIP;
    static PlatformSurface COAST_GUARD_CUTTERS;
    static PlatformSurface COAST_GUARD_BOATS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PlatformSurface getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PlatformSurface*> enumContainer;
    static enumContainer getEnumerations();

    PlatformSurface& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PlatformSurface(int value, std::string description);

	  static PlatformSurface* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PlatformSurface */


}  /* namespace DIS */

#endif /* PLATFORMSURFACE__H */

