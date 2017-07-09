#include <sstream>
#include <cstddef>
#include <disenum/PlatformLand.h>

namespace DIS {


hashMap<int,PlatformLand*> PlatformLand::enumerations;

PlatformLand PlatformLand::OTHER(0, "Other");
PlatformLand PlatformLand::TANK(1, "Tank");
PlatformLand PlatformLand::ARMORED_FIGHTING_VEHICLE_IFV_APC_SP_MORTARS_ARMORED_CARS_CHEMICAL_RECONNAISSANCE_ANTI_TANK_GUIDED_MISSILE_LAUNCHERS_ETC(2, "Armored Fighting Vehicle - (IFV, APC, SP mortars, armored cars, chemical reconnaissance, anti-tank guided missile launchers, etc.)");
PlatformLand PlatformLand::ARMORED_UTILITY_VEHICLE_ENGINEERING_VEHICLE_TRACKED_LOAD_CARRIERS_TOWING_VEHICLES_RECOVERY_VEHICLES_AVLB_ETC(3, "Armored Utility Vehicle - (Engineering vehicle, tracked load carriers, towing vehicles, recovery vehicles, AVLB, etc.)");
PlatformLand PlatformLand::SELF_PROPELLED_ARTILLERY_GUNS_AND_HOWITZERS(4, "Self-propelled Artillery - (guns and howitzers)");
PlatformLand PlatformLand::TOWED_ARTILLERY_ANTI_TANK_GUNS_GUNS_AND_HOWITZERS(5, "Towed Artillery - (anti-tank guns, guns and howitzers)");
PlatformLand PlatformLand::SMALL_WHEELED_UTILITY_VEHICLE_0_125_TONS(6, "Small Wheeled Utility Vehicle - (0-1.25 tons)");
PlatformLand PlatformLand::LARGE_WHEELED_UTILITY_VEHICLE_GREATER_THAN_125_TONS(7, "Large Wheeled Utility Vehicle - (greater than 1.25 tons)");
PlatformLand PlatformLand::SMALL_TRACKED_UTILITY_VEHICLE_0_4999_KG_WEIGHT_LOAD(8, "Small Tracked Utility Vehicle - (0-4999 kg weight load)");
PlatformLand PlatformLand::LARGE_TRACKED_UTILITY_VEHICLE_GREATER_THAN_4999_KG_WEIGHT_LOAD(9, "Large Tracked Utility Vehicle - (greater than 4999 kg weight load)");
PlatformLand PlatformLand::MORTAR(10, "Mortar");
PlatformLand PlatformLand::MINE_PLOW(11, "Mine plow");
PlatformLand PlatformLand::MINE_RAKE(12, "Mine rake");
PlatformLand PlatformLand::MINE_ROLLER(13, "Mine roller");
PlatformLand PlatformLand::CARGO_TRAILER(14, "Cargo trailer");
PlatformLand PlatformLand::FUEL_TRAILER(15, "Fuel trailer");
PlatformLand PlatformLand::GENERATOR_TRAILER(16, "Generator trailer");
PlatformLand PlatformLand::WATER_TRAILER(17, "Water trailer");
PlatformLand PlatformLand::ENGINEER_EQUIPMENT(18, "Engineer equipment");
PlatformLand PlatformLand::HEAVY_EQUIPMENT_TRANSPORT_TRAILER(19, "Heavy equipment transport trailer");
PlatformLand PlatformLand::MAINTENANCE_EQUIPMENT_TRAILER(20, "Maintenance equipment trailer");
PlatformLand PlatformLand::LIMBER(21, "Limber");
PlatformLand PlatformLand::CHEMICAL_DECONTAMINATION_TRAILER(22, "Chemical decontamination trailer");
PlatformLand PlatformLand::WARNING_SYSTEM(23, "Warning System");
PlatformLand PlatformLand::TRAIN_ENGINE(24, "Train - Engine");
PlatformLand PlatformLand::TRAIN_CAR(25, "Train - Car");
PlatformLand PlatformLand::TRAIN_CABOOSE(26, "Train - Caboose");
PlatformLand PlatformLand::CIVILIAN_VEHICLE(27, "Civilian Vehicle");
PlatformLand PlatformLand::AIR_DEFENSE_MISSILE_DEFENSE_UNIT_EQUIPMENT(28, "Air Defense / Missile Defense Unit Equipment");
PlatformLand PlatformLand::COMMAND_CONTROL_COMMUNICATIONS_AND_INTELLIGENCE_C3I_SYSTEM(29, "Command, Control, Communications, and Intelligence (C3I) System");
PlatformLand PlatformLand::OPERATIONS_FACILITY(30, "Operations Facility");
PlatformLand PlatformLand::INTELLIGENCE_FACILITY(31, "Intelligence Facility");
PlatformLand PlatformLand::SURVEILLANCE_FACILITY(32, "Surveillance Facility");
PlatformLand PlatformLand::COMMUNICATIONS_FACILITY(33, "Communications Facility");
PlatformLand PlatformLand::COMMAND_FACILITY(34, "Command Facility");
PlatformLand PlatformLand::C4I_FACILITY(35, "C4I Facility");
PlatformLand PlatformLand::CONTROL_FACILITY(36, "Control Facility");
PlatformLand PlatformLand::FIRE_CONTROL_FACILITY(37, "Fire Control Facility");
PlatformLand PlatformLand::MISSILE_DEFENSE_FACILITY(38, "Missile Defense Facility");
PlatformLand PlatformLand::FIELD_COMMAND_POST(39, "Field Command Post");
PlatformLand PlatformLand::OBSERVATION_POST(40, "Observation Post");


PlatformLand::PlatformLand(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

PlatformLand* PlatformLand::findEnumeration(int aVal) {
  PlatformLand* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string PlatformLand::getDescriptionForValue(int aVal) {
  PlatformLand* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

PlatformLand PlatformLand::getEnumerationForValue(int aVal) throw(EnumException) {
  PlatformLand* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration PlatformLand";
    throw EnumException("PlatformLand", aVal, ss.str());
  }
};

bool PlatformLand::enumerationForValueExists(int aVal) {
  PlatformLand* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

PlatformLand::enumContainer PlatformLand::getEnumerations() {
  return (enumerations);
};

PlatformLand& PlatformLand::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

