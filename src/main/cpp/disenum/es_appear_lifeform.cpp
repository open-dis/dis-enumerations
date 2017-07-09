#include <sstream>
#include <cstddef>
#include <disenum/es_appear_lifeform.h>

namespace DIS {

namespace es_appear_lifeform {

  bitmask& bitmask::operator=(const unsigned int& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned int*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned int& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned int) 0;
  }

  unsigned int bitmask::getValue(){
    unsigned int val = *( reinterpret_cast<unsigned int *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned int& i){
	  (*this) = i;
  }

	/*
	 **  PaintScheme implementation **
	 */

	hashMap<int,PaintScheme*> PaintScheme::enumerations;
	short PaintScheme::startBit = 0;
	short PaintScheme::endBit   = 0;

 PaintScheme PaintScheme::UNIFORM_COLOR(0, "Uniform color");
 PaintScheme PaintScheme::CAMOUFLAGE(1, "Camouflage");


	PaintScheme::PaintScheme(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	PaintScheme* PaintScheme::findEnumeration(int aVal) {
	  PaintScheme* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string PaintScheme::getDescriptionForValue(int aVal) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	PaintScheme PaintScheme::getEnumerationForValue(int aVal) throw(EnumException) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration PaintScheme";
		throw EnumException("PaintScheme", aVal, ss.str());
	  }
	};

	bool PaintScheme::enumerationForValueExists(int aVal) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	PaintScheme::enumContainer PaintScheme::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Health implementation **
	 */

	hashMap<int,Health*> Health::enumerations;
	short Health::startBit = 3;
	short Health::endBit   = 4;

 Health Health::NO_INJURY(0, "No injury");
 Health Health::SLIGHT_INJURY(1, "Slight injury");
 Health Health::MODERATE_INJURY(2, "Moderate injury");
 Health Health::FATAL_INJURY(3, "Fatal injury");


	Health::Health(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Health* Health::findEnumeration(int aVal) {
	  Health* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Health::getDescriptionForValue(int aVal) {
	  Health* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Health Health::getEnumerationForValue(int aVal) throw(EnumException) {
	  Health* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Health";
		throw EnumException("Health", aVal, ss.str());
	  }
	};

	bool Health::enumerationForValueExists(int aVal) {
	  Health* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Health::enumContainer Health::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Compliance implementation **
	 */

	hashMap<int,Compliance*> Compliance::enumerations;
	short Compliance::startBit = 5;
	short Compliance::endBit   = 8;

 Compliance Compliance::DETAINED(1, "Detained");
 Compliance Compliance::SURRENDER(2, "Surrender");
 Compliance Compliance::USING_FISTS(3, "Using fists");
 Compliance Compliance::VERBAL_ABUSE_LEVEL_1(4, "Verbal abuse level 1");
 Compliance Compliance::VERBAL_ABUSE_LEVEL_2(5, "Verbal abuse level 2");
 Compliance Compliance::VERBAL_ABUSE_LEVEL_3(6, "Verbal abuse level 3");
 Compliance Compliance::PASSIVE_RESISTANCE_LEVEL_1(7, "Passive resistance level 1");
 Compliance Compliance::PASSIVE_RESISTANCE_LEVEL_2(8, "Passive resistance level 2");
 Compliance Compliance::PASSIVE_RESISTANCE_LEVEL_3(9, "Passive resistance level 3");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_1(10, "Using non-lethal weapon 1");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_2(11, "Using non-lethal weapon 2");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_3(12, "Using non-lethal weapon 3");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_4(13, "Using non-lethal weapon 4");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_5(14, "Using non-lethal weapon 5");
 Compliance Compliance::USING_NON_LETHAL_WEAPON_6(15, "Using non-lethal weapon 6");


	Compliance::Compliance(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Compliance* Compliance::findEnumeration(int aVal) {
	  Compliance* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Compliance::getDescriptionForValue(int aVal) {
	  Compliance* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Compliance Compliance::getEnumerationForValue(int aVal) throw(EnumException) {
	  Compliance* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Compliance";
		throw EnumException("Compliance", aVal, ss.str());
	  }
	};

	bool Compliance::enumerationForValueExists(int aVal) {
	  Compliance* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Compliance::enumContainer Compliance::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  FlashLights implementation **
	 */

	hashMap<int,FlashLights*> FlashLights::enumerations;
	short FlashLights::startBit = 12;
	short FlashLights::endBit   = 12;

 FlashLights FlashLights::OFF(0, "Off");
 FlashLights FlashLights::ON(1, "On");


	FlashLights::FlashLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	FlashLights* FlashLights::findEnumeration(int aVal) {
	  FlashLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string FlashLights::getDescriptionForValue(int aVal) {
	  FlashLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	FlashLights FlashLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  FlashLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration FlashLights";
		throw EnumException("FlashLights", aVal, ss.str());
	  }
	};

	bool FlashLights::enumerationForValueExists(int aVal) {
	  FlashLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	FlashLights::enumContainer FlashLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Life_formstate implementation **
	 */

	hashMap<int,Life_formstate*> Life_formstate::enumerations;
	short Life_formstate::startBit = 16;
	short Life_formstate::endBit   = 19;

 Life_formstate Life_formstate::UPRIGHT_STANDING_STILL(1, "Upright, standing still");
 Life_formstate Life_formstate::UPRIGHT_WALKING(2, "Upright, walking");
 Life_formstate Life_formstate::UPRIGHT_RUNNING(3, "Upright, running");
 Life_formstate Life_formstate::KNEELING(4, "Kneeling");
 Life_formstate Life_formstate::PRONE(5, "Prone");
 Life_formstate Life_formstate::CRAWLING(6, "Crawling");
 Life_formstate Life_formstate::SWIMMING(7, "Swimming");
 Life_formstate Life_formstate::PARACHUTING(8, "Parachuting");
 Life_formstate Life_formstate::JUMPING(9, "Jumping");
 Life_formstate Life_formstate::SITTING(10, "Sitting");
 Life_formstate Life_formstate::SQUATTING(11, "Squatting");
 Life_formstate Life_formstate::CROUCHING(12, "Crouching");
 Life_formstate Life_formstate::WADING(13, "Wading");
 Life_formstate Life_formstate::SURRENDER(14, "Surrender");
 Life_formstate Life_formstate::DETAINED(15, "Detained");


	Life_formstate::Life_formstate(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Life_formstate* Life_formstate::findEnumeration(int aVal) {
	  Life_formstate* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Life_formstate::getDescriptionForValue(int aVal) {
	  Life_formstate* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Life_formstate Life_formstate::getEnumerationForValue(int aVal) throw(EnumException) {
	  Life_formstate* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Life_formstate";
		throw EnumException("Life_formstate", aVal, ss.str());
	  }
	};

	bool Life_formstate::enumerationForValueExists(int aVal) {
	  Life_formstate* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Life_formstate::enumContainer Life_formstate::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  FrozenStatus implementation **
	 */

	hashMap<int,FrozenStatus*> FrozenStatus::enumerations;
	short FrozenStatus::startBit = 21;
	short FrozenStatus::endBit   = 21;

 FrozenStatus FrozenStatus::NOT_FROZEN(0, "Not frozen");
 FrozenStatus FrozenStatus::FROZEN_FROZEN_ENTITIES_SHOULD_NOT_BE_DEAD_RECKONED_IE_THEY_SHOULD_BE_DISPLAYED_AS_FIXED_AT_THE_CURRENT_LOCATION_EVEN_IF_NONZERO_VELOCITY_ACCELERATION_OR_ROTATION_DATA_IS_RECEIVED_FROM_THE_FROZEN_ENTITY(1, "Frozen (Frozen entities should not be dead-reckoned, i.e. they should be displayed as fixed at the current location even if nonzero velocity, acceleration or rotation data is received from the frozen entity)");


	FrozenStatus::FrozenStatus(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	FrozenStatus* FrozenStatus::findEnumeration(int aVal) {
	  FrozenStatus* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string FrozenStatus::getDescriptionForValue(int aVal) {
	  FrozenStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	FrozenStatus FrozenStatus::getEnumerationForValue(int aVal) throw(EnumException) {
	  FrozenStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration FrozenStatus";
		throw EnumException("FrozenStatus", aVal, ss.str());
	  }
	};

	bool FrozenStatus::enumerationForValueExists(int aVal) {
	  FrozenStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	FrozenStatus::enumContainer FrozenStatus::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  State implementation **
	 */

	hashMap<int,State*> State::enumerations;
	short State::startBit = 23;
	short State::endBit   = 23;

 State State::ACTIVE(0, "Active");
 State State::DEACTIVATED(1, "Deactivated");


	State::State(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	State* State::findEnumeration(int aVal) {
	  State* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string State::getDescriptionForValue(int aVal) {
	  State* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	State State::getEnumerationForValue(int aVal) throw(EnumException) {
	  State* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration State";
		throw EnumException("State", aVal, ss.str());
	  }
	};

	bool State::enumerationForValueExists(int aVal) {
	  State* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	State::enumContainer State::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Weapon1 implementation **
	 */

	hashMap<int,Weapon1*> Weapon1::enumerations;
	short Weapon1::startBit = 24;
	short Weapon1::endBit   = 25;

 Weapon1 Weapon1::NO_PRIMARY_WEAPON_PRESENT(0, "No primary weapon present");
 Weapon1 Weapon1::PRIMARY_WEAPON_IS_STOWED(1, "Primary weapon is stowed");
 Weapon1 Weapon1::PRIMARY_WEAPON_IS_DEPLOYED(2, "Primary weapon is deployed");
 Weapon1 Weapon1::PRIMARY_WEAPON_IS_IN_FIRING_POSITION(3, "Primary weapon is in firing position");


	Weapon1::Weapon1(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Weapon1* Weapon1::findEnumeration(int aVal) {
	  Weapon1* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Weapon1::getDescriptionForValue(int aVal) {
	  Weapon1* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Weapon1 Weapon1::getEnumerationForValue(int aVal) throw(EnumException) {
	  Weapon1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Weapon1";
		throw EnumException("Weapon1", aVal, ss.str());
	  }
	};

	bool Weapon1::enumerationForValueExists(int aVal) {
	  Weapon1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Weapon1::enumContainer Weapon1::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Weapon2 implementation **
	 */

	hashMap<int,Weapon2*> Weapon2::enumerations;
	short Weapon2::startBit = 26;
	short Weapon2::endBit   = 27;

 Weapon2 Weapon2::NO_SECONDARY_WEAPON_PRESENT(0, "No secondary weapon present");
 Weapon2 Weapon2::SECONDARY_WEAPON_IS_STOWED(1, "Secondary weapon is stowed");
 Weapon2 Weapon2::SECONDARY_WEAPON_IS_DEPLOYED(2, "Secondary weapon is deployed");
 Weapon2 Weapon2::SECONDARY_WEAPON_IS_IN_FIRING_POSITION(3, "Secondary weapon is in firing position");


	Weapon2::Weapon2(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Weapon2* Weapon2::findEnumeration(int aVal) {
	  Weapon2* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Weapon2::getDescriptionForValue(int aVal) {
	  Weapon2* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Weapon2 Weapon2::getEnumerationForValue(int aVal) throw(EnumException) {
	  Weapon2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Weapon2";
		throw EnumException("Weapon2", aVal, ss.str());
	  }
	};

	bool Weapon2::enumerationForValueExists(int aVal) {
	  Weapon2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Weapon2::enumContainer Weapon2::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  CamouflageType implementation **
	 */

	hashMap<int,CamouflageType*> CamouflageType::enumerations;
	short CamouflageType::startBit = 28;
	short CamouflageType::endBit   = 29;

 CamouflageType CamouflageType::DESERT_CAMOUFLAGE(0, "Desert camouflage");
 CamouflageType CamouflageType::WINTER_CAMOUFLAGE(1, "Winter camouflage");
 CamouflageType CamouflageType::FOREST_CAMOUFLAGE(2, "Forest camouflage");


	CamouflageType::CamouflageType(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	CamouflageType* CamouflageType::findEnumeration(int aVal) {
	  CamouflageType* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string CamouflageType::getDescriptionForValue(int aVal) {
	  CamouflageType* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	CamouflageType CamouflageType::getEnumerationForValue(int aVal) throw(EnumException) {
	  CamouflageType* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration CamouflageType";
		throw EnumException("CamouflageType", aVal, ss.str());
	  }
	};

	bool CamouflageType::enumerationForValueExists(int aVal) {
	  CamouflageType* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	CamouflageType::enumContainer CamouflageType::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ConcealedStationary implementation **
	 */

	hashMap<int,ConcealedStationary*> ConcealedStationary::enumerations;
	short ConcealedStationary::startBit = 30;
	short ConcealedStationary::endBit   = 30;

 ConcealedStationary ConcealedStationary::NOT_CONCEALED(0, "Not concealed");
 ConcealedStationary ConcealedStationary::ENTITY_IN_A_PREPARED_CONCEALED_POSITION(1, "Entity in a prepared concealed position");


	ConcealedStationary::ConcealedStationary(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ConcealedStationary* ConcealedStationary::findEnumeration(int aVal) {
	  ConcealedStationary* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ConcealedStationary::getDescriptionForValue(int aVal) {
	  ConcealedStationary* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ConcealedStationary ConcealedStationary::getEnumerationForValue(int aVal) throw(EnumException) {
	  ConcealedStationary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ConcealedStationary";
		throw EnumException("ConcealedStationary", aVal, ss.str());
	  }
	};

	bool ConcealedStationary::enumerationForValueExists(int aVal) {
	  ConcealedStationary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ConcealedStationary::enumContainer ConcealedStationary::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ConcealedMovement implementation **
	 */

	hashMap<int,ConcealedMovement*> ConcealedMovement::enumerations;
	short ConcealedMovement::startBit = 31;
	short ConcealedMovement::endBit   = 31;

 ConcealedMovement ConcealedMovement::OPEN_MOVEMENT(0, "Open movement");
 ConcealedMovement ConcealedMovement::RUSHES_BETWEEN_COVERED_POSITIONS(1, "Rushes between covered positions");


	ConcealedMovement::ConcealedMovement(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ConcealedMovement* ConcealedMovement::findEnumeration(int aVal) {
	  ConcealedMovement* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ConcealedMovement::getDescriptionForValue(int aVal) {
	  ConcealedMovement* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ConcealedMovement ConcealedMovement::getEnumerationForValue(int aVal) throw(EnumException) {
	  ConcealedMovement* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ConcealedMovement";
		throw EnumException("ConcealedMovement", aVal, ss.str());
	  }
	};

	bool ConcealedMovement::enumerationForValueExists(int aVal) {
	  ConcealedMovement* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ConcealedMovement::enumContainer ConcealedMovement::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace es_appear_lifeform */

} /* namespace DIS */
