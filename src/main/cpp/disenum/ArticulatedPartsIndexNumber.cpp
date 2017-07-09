#include <sstream>
#include <cstddef>
#include <disenum/ArticulatedPartsIndexNumber.h>

namespace DIS {


hashMap<int,ArticulatedPartsIndexNumber*> ArticulatedPartsIndexNumber::enumerations;

ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::RUDDER(1024, "rudder");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::LEFT_FLAP(1056, "left flap");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::RIGHT_FLAP(1088, "right flap");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::LEFT_AILERON(1120, "left aileron");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::RIGHT_AILERON(1152, "right aileron");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::HELICOPTER_MAIN_ROTOR(1184, "helicopter - main rotor");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::HELICOPTER_TAIL_ROTOR(1216, "helicopter - tail rotor");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::OTHER_AIRCRAFT_CONTROL_SURFACES_DEFINED_AS_NEEDED(1248, "other Aircraft Control Surfaces defined as needed");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PERISCOPE(2048, "periscope");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::GENERIC_ANTENNA(2080, "generic antenna");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SNORKEL(2112, "snorkel");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::OTHER_EXTENDIBLE_PARTS_DEFINED_AS_NEEDED(2144, "other extendible parts defined as needed");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::LANDING_GEAR(3072, "landing gear");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::TAIL_HOOK(3104, "tail hook");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SPEED_BRAKE(3136, "speed brake");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::LEFT_WEAPON_BAY_DOOR(3168, "left weapon bay door");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::RIGHT_WEAPON_BAY_DOORS(3200, "right weapon bay doors");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::TANK_OR_APC_HATCH(3232, "tank or APC hatch");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::WINGSWEEP(3264, "wingsweep");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::BRIDGE_LAUNCHER(3296, "Bridge launcher");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::BRIDGE_SECTION_1(3328, "Bridge section 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::BRIDGE_SECTION_2(3360, "Bridge section 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::BRIDGE_SECTION_3(3392, "Bridge section 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_BLADE_1(3424, "Primary blade 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_BLADE_2(3456, "Primary blade 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_BOOM(3488, "Primary boom");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_ARM(3520, "Primary launcher arm");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::OTHER_FIXED_POSITION_PARTS_DEFINED_AS_NEEDED(3552, "other fixed position parts defined as needed");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_1(4096, "Primary turret number 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_2(4128, "Primary turret number 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_3(4160, "Primary turret number 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_4(4192, "Primary turret number 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_5(4224, "Primary turret number 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_6(4256, "Primary turret number 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_7(4288, "Primary turret number 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_8(4320, "Primary turret number 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_9(4352, "Primary turret number 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_TURRET_NUMBER_10(4384, "Primary turret number 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_1(4416, "Primary gun number 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_2(4448, "Primary gun number 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_3(4480, "Primary gun number 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_4(4512, "Primary gun number 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_5(4544, "Primary gun number 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_6(4576, "Primary gun number 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_7(4608, "Primary gun number 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_8(4640, "Primary gun number 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_9(4672, "Primary gun number 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_GUN_NUMBER_10(4704, "Primary gun number 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_1(4736, "Primary launcher 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_2(4768, "Primary launcher 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_3(4800, "Primary launcher 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_4(4832, "Primary launcher 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_5(4864, "Primary launcher 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_6(4896, "Primary launcher 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_7(4928, "Primary launcher 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_8(4960, "Primary launcher 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_9(4992, "Primary launcher 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_LAUNCHER_10(5024, "Primary launcher 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_1(5056, "Primary defense systems 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_2(5088, "Primary defense systems 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_3(5120, "Primary defense systems 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_4(5152, "Primary defense systems 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_5(5184, "Primary defense systems 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_6(5216, "Primary defense systems 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_7(5248, "Primary defense systems 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_8(5280, "Primary defense systems 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_9(5312, "Primary defense systems 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_DEFENSE_SYSTEMS_10(5344, "Primary defense systems 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_1(5376, "Primary radar 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_2(5408, "Primary radar 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_3(5440, "Primary radar 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_4(5472, "Primary radar 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_5(5504, "Primary radar 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_6(5536, "Primary radar 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_7(5568, "Primary radar 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_8(5600, "Primary radar 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_9(5632, "Primary radar 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::PRIMARY_RADAR_10(5664, "Primary radar 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_1(5696, "Secondary turret number 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_2(5728, "Secondary turret number 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_3(5760, "Secondary turret number 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_4(5792, "Secondary turret number 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_5(5824, "Secondary turret number 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_6(5856, "Secondary turret number 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_7(5888, "Secondary turret number 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_8(5920, "Secondary turret number 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_9(5952, "Secondary turret number 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_TURRET_NUMBER_10(5984, "Secondary turret number 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_1(6016, "Secondary gun number 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_2(6048, "Secondary gun number 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_3(6080, "Secondary gun number 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_4(6112, "Secondary gun number 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_5(6144, "Secondary gun number 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_6(6176, "Secondary gun number 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_7(6208, "Secondary gun number 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_8(6240, "Secondary gun number 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_9(6272, "Secondary gun number 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_GUN_NUMBER_10(6304, "Secondary gun number 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_1(6336, "Secondary launcher 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_2(6368, "Secondary launcher 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_3(6400, "Secondary launcher 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_4(6432, "Secondary launcher 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_5(6464, "Secondary launcher 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_6(6496, "Secondary launcher 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_7(6528, "Secondary launcher 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_8(6560, "Secondary launcher 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_9(6592, "Secondary launcher 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_LAUNCHER_10(6624, "Secondary launcher 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_1(6656, "Secondary defense systems 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_2(6688, "Secondary defense systems 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_3(6720, "Secondary defense systems 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_4(6752, "Secondary defense systems 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_5(6784, "Secondary defense systems 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_6(6816, "Secondary defense systems 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_7(6848, "Secondary defense systems 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_8(6880, "Secondary defense systems 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_9(6912, "Secondary defense systems 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_DEFENSE_SYSTEMS_10(6944, "Secondary defense systems 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_1(6976, "Secondary radar 1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_2(7008, "Secondary radar 2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_3(7040, "Secondary radar 3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_4(7072, "Secondary radar 4");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_5(7104, "Secondary radar 5");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_6(7136, "Secondary radar 6");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_7(7168, "Secondary radar 7");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_8(7200, "Secondary radar 8");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_9(7232, "Secondary radar 9");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::SECONDARY_RADAR_10(7264, "Secondary radar 10");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::DECK_ELEVATOR_1(7296, "Deck Elevator #1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::DECK_ELEVATOR_2(7328, "Deck Elevator #2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::CATAPULT_1(7360, "Catapult #1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::CATAPULT_2(7392, "Catapult #2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::JET_BLAST_DEFLECTOR_1(7424, "Jet Blast Deflector #1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::JET_BLAST_DEFLECTOR_2(7456, "Jet Blast Deflector #2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::ARRESTOR_WIRES_1(7488, "Arrestor Wires #1");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::ARRESTOR_WIRES_2(7520, "Arrestor Wires #2");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::ARRESTOR_WIRES_3(7552, "Arrestor Wires #3");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::WING_OR_ROTOR_FOLD(7584, "Wing (or rotor) fold");
ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::FUSELAGE_FOLD(7616, "Fuselage fold");


ArticulatedPartsIndexNumber::ArticulatedPartsIndexNumber(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

ArticulatedPartsIndexNumber* ArticulatedPartsIndexNumber::findEnumeration(int aVal) {
  ArticulatedPartsIndexNumber* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string ArticulatedPartsIndexNumber::getDescriptionForValue(int aVal) {
  ArticulatedPartsIndexNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

ArticulatedPartsIndexNumber ArticulatedPartsIndexNumber::getEnumerationForValue(int aVal) throw(EnumException) {
  ArticulatedPartsIndexNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration ArticulatedPartsIndexNumber";
    throw EnumException("ArticulatedPartsIndexNumber", aVal, ss.str());
  }
};

bool ArticulatedPartsIndexNumber::enumerationForValueExists(int aVal) {
  ArticulatedPartsIndexNumber* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

ArticulatedPartsIndexNumber::enumContainer ArticulatedPartsIndexNumber::getEnumerations() {
  return (enumerations);
};

ArticulatedPartsIndexNumber& ArticulatedPartsIndexNumber::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

