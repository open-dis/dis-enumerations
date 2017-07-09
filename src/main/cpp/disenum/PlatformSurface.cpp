#include <sstream>
#include <cstddef>
#include <disenum/PlatformSurface.h>

namespace DIS {


hashMap<int,PlatformSurface*> PlatformSurface::enumerations;

PlatformSurface PlatformSurface::OTHER(0, "Other");
PlatformSurface PlatformSurface::CARRIER(1, "Carrier");
PlatformSurface PlatformSurface::COMMAND_SHIP_CRUISER(2, "Command Ship/Cruiser");
PlatformSurface PlatformSurface::GUIDED_MISSILE_CRUISER(3, "Guided Missile Cruiser");
PlatformSurface PlatformSurface::GUIDED_MISSILE_DESTROYER_DDG(4, "Guided Missile Destroyer (DDG)");
PlatformSurface PlatformSurface::DESTROYER_DD(5, "Destroyer (DD)");
PlatformSurface PlatformSurface::GUIDED_MISSILE_FRIGATE_FFG(6, "Guided Missile Frigate (FFG)");
PlatformSurface PlatformSurface::LIGHT_PATROL_CRAFT(7, "Light/Patrol Craft");
PlatformSurface PlatformSurface::MINE_COUNTERMEASURE_SHIP_CRAFT(8, "Mine Countermeasure Ship/Craft");
PlatformSurface PlatformSurface::DOCK_LANDING_SHIP(9, "Dock Landing Ship");
PlatformSurface PlatformSurface::TANK_LANDING_SHIP(10, "Tank Landing Ship");
PlatformSurface PlatformSurface::LANDING_CRAFT(11, "Landing Craft");
PlatformSurface PlatformSurface::LIGHT_CARRIER(12, "Light Carrier");
PlatformSurface PlatformSurface::CRUISER_HELICOPTER_CARRIER(13, "Cruiser/Helicopter Carrier");
PlatformSurface PlatformSurface::HYDROFOIL(14, "Hydrofoil");
PlatformSurface PlatformSurface::AIR_CUSHION_SURFACE_EFFECT(15, "Air Cushion/Surface Effect");
PlatformSurface PlatformSurface::AUXILIARY(16, "Auxiliary");
PlatformSurface PlatformSurface::AUXILIARY_MERCHANT_MARINE(17, "Auxiliary, Merchant Marine");
PlatformSurface PlatformSurface::UTILITY(18, "Utility");
PlatformSurface PlatformSurface::FRIGATE_INCLUDING_CORVETTE(50, "Frigate (including Corvette)");
PlatformSurface PlatformSurface::BATTLESHIP(51, "Battleship");
PlatformSurface PlatformSurface::HEAVY_CRUISER(52, "Heavy Cruiser");
PlatformSurface PlatformSurface::DESTROYER_TENDER(53, "Destroyer Tender");
PlatformSurface PlatformSurface::AMPHIBIOUS_ASSAULT_SHIP(54, "Amphibious Assault Ship");
PlatformSurface PlatformSurface::AMPHIBIOUS_CARGO_SHIP(55, "Amphibious Cargo Ship");
PlatformSurface PlatformSurface::AMPHIBIOUS_TRANSPORT_DOCK(56, "Amphibious Transport Dock");
PlatformSurface PlatformSurface::AMMUNITION_SHIP(57, "Ammunition Ship");
PlatformSurface PlatformSurface::COMBAT_STORES_SHIP(58, "Combat Stores Ship");
PlatformSurface PlatformSurface::SURVEILLANCE_TOWED_ARRAY_SONAR_SYSTEM_SURTASS(59, "Surveillance Towed Array Sonar System (SURTASS)");
PlatformSurface PlatformSurface::FAST_COMBAT_SUPPORT_SHIP(60, "Fast Combat Support Ship");
PlatformSurface PlatformSurface::NON_COMBATANT_SHIP(61, "Non-Combatant Ship");
PlatformSurface PlatformSurface::COAST_GUARD_CUTTERS(62, "Coast Guard Cutters");
PlatformSurface PlatformSurface::COAST_GUARD_BOATS(63, "Coast Guard Boats");


PlatformSurface::PlatformSurface(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatformSurface* PlatformSurface::findEnumeration(int aVal) {
  PlatformSurface* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatformSurface::getDescriptionForValue(int aVal) {
  PlatformSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatformSurface PlatformSurface::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatformSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatformSurface";
    throw EnumException("PlatformSurface", aVal, ss.str());
  }
};

bool PlatformSurface::enumerationForValueExists(int aVal) {
  PlatformSurface* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatformSurface::enumContainer PlatformSurface::getEnumerations() {
  return (enumerations);
};

PlatformSurface& PlatformSurface::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

