#include <sstream>
#include <cstddef>
#include <disenum/es_appear_platform_air.h>

namespace DIS {

namespace es_appear_platform_air {

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
	 **  Propulsion implementation **
	 */

	hashMap<int,Propulsion*> Propulsion::enumerations;
	short Propulsion::startBit = 1;
	short Propulsion::endBit   = 1;

 Propulsion Propulsion::NO_PROPULSION_KILL(0, "No Propulsion kill");
 Propulsion Propulsion::PROPULSION_KILL(1, "Propulsion kill");


	Propulsion::Propulsion(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Propulsion* Propulsion::findEnumeration(int aVal) {
	  Propulsion* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Propulsion::getDescriptionForValue(int aVal) {
	  Propulsion* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Propulsion Propulsion::getEnumerationForValue(int aVal) throw(EnumException) {
	  Propulsion* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Propulsion";
		throw EnumException("Propulsion", aVal, ss.str());
	  }
	};

	bool Propulsion::enumerationForValueExists(int aVal) {
	  Propulsion* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Propulsion::enumContainer Propulsion::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Damage implementation **
	 */

	hashMap<int,Damage*> Damage::enumerations;
	short Damage::startBit = 3;
	short Damage::endBit   = 4;

 Damage Damage::NO_DAMAGE(0, "No damage");
 Damage Damage::SLIGHT_DAMAGE(1, "Slight damage");
 Damage Damage::MODERATE_DAMAGE(2, "Moderate damage");
 Damage Damage::DESTROYED(3, "Destroyed");


	Damage::Damage(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Damage* Damage::findEnumeration(int aVal) {
	  Damage* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Damage::getDescriptionForValue(int aVal) {
	  Damage* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Damage Damage::getEnumerationForValue(int aVal) throw(EnumException) {
	  Damage* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Damage";
		throw EnumException("Damage", aVal, ss.str());
	  }
	};

	bool Damage::enumerationForValueExists(int aVal) {
	  Damage* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Damage::enumContainer Damage::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Smoke implementation **
	 */

	hashMap<int,Smoke*> Smoke::enumerations;
	short Smoke::startBit = 5;
	short Smoke::endBit   = 6;

 Smoke Smoke::NOT_SMOKING(0, "Not smoking");
 Smoke Smoke::SMOKE_PLUME_RISING_FROM_THE_ENTITY(1, "Smoke plume rising from the entity");
 Smoke Smoke::ENTITY_IS_EMITTING_ENGINE_SMOKE(2, "Entity is emitting engine smoke");
 Smoke Smoke::ENTITY_IS_EMITTING_ENGINE_SMOKE_AND_SMOKE_PLUME_IS_RISING_FROM_THE_ENTITY(3, "Entity is emitting engine smoke, and smoke plume is rising from the entity");


	Smoke::Smoke(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Smoke* Smoke::findEnumeration(int aVal) {
	  Smoke* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Smoke::getDescriptionForValue(int aVal) {
	  Smoke* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Smoke Smoke::getEnumerationForValue(int aVal) throw(EnumException) {
	  Smoke* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Smoke";
		throw EnumException("Smoke", aVal, ss.str());
	  }
	};

	bool Smoke::enumerationForValueExists(int aVal) {
	  Smoke* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Smoke::enumContainer Smoke::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  TrailingEffects implementation **
	 */

	hashMap<int,TrailingEffects*> TrailingEffects::enumerations;
	short TrailingEffects::startBit = 7;
	short TrailingEffects::endBit   = 8;

 TrailingEffects TrailingEffects::NONE(0, "None");
 TrailingEffects TrailingEffects::SMALL(1, "Small");
 TrailingEffects TrailingEffects::MEDIUM(2, "Medium");
 TrailingEffects TrailingEffects::LARGE(3, "Large");


	TrailingEffects::TrailingEffects(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	TrailingEffects* TrailingEffects::findEnumeration(int aVal) {
	  TrailingEffects* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string TrailingEffects::getDescriptionForValue(int aVal) {
	  TrailingEffects* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	TrailingEffects TrailingEffects::getEnumerationForValue(int aVal) throw(EnumException) {
	  TrailingEffects* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration TrailingEffects";
		throw EnumException("TrailingEffects", aVal, ss.str());
	  }
	};

	bool TrailingEffects::enumerationForValueExists(int aVal) {
	  TrailingEffects* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	TrailingEffects::enumContainer TrailingEffects::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Canopy implementation **
	 */

	hashMap<int,Canopy*> Canopy::enumerations;
	short Canopy::startBit = 9;
	short Canopy::endBit   = 11;

 Canopy Canopy::NOT_APPLICABLE(0, "Not applicable");
 Canopy Canopy::CANOPY_IS_CLOSED(1, "Canopy is closed");
 Canopy Canopy::CANOPY_IS_OPEN(4, "Canopy is open");


	Canopy::Canopy(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Canopy* Canopy::findEnumeration(int aVal) {
	  Canopy* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Canopy::getDescriptionForValue(int aVal) {
	  Canopy* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Canopy Canopy::getEnumerationForValue(int aVal) throw(EnumException) {
	  Canopy* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Canopy";
		throw EnumException("Canopy", aVal, ss.str());
	  }
	};

	bool Canopy::enumerationForValueExists(int aVal) {
	  Canopy* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Canopy::enumContainer Canopy::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  LandingLights implementation **
	 */

	hashMap<int,LandingLights*> LandingLights::enumerations;
	short LandingLights::startBit = 12;
	short LandingLights::endBit   = 12;

 LandingLights LandingLights::OFF(0, "Off");
 LandingLights LandingLights::ON(1, "On");


	LandingLights::LandingLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	LandingLights* LandingLights::findEnumeration(int aVal) {
	  LandingLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string LandingLights::getDescriptionForValue(int aVal) {
	  LandingLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	LandingLights LandingLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  LandingLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration LandingLights";
		throw EnumException("LandingLights", aVal, ss.str());
	  }
	};

	bool LandingLights::enumerationForValueExists(int aVal) {
	  LandingLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	LandingLights::enumContainer LandingLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  NavigationLights implementation **
	 */

	hashMap<int,NavigationLights*> NavigationLights::enumerations;
	short NavigationLights::startBit = 13;
	short NavigationLights::endBit   = 13;

 NavigationLights NavigationLights::OFF(0, "Off");
 NavigationLights NavigationLights::ON(1, "On");


	NavigationLights::NavigationLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	NavigationLights* NavigationLights::findEnumeration(int aVal) {
	  NavigationLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string NavigationLights::getDescriptionForValue(int aVal) {
	  NavigationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	NavigationLights NavigationLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  NavigationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration NavigationLights";
		throw EnumException("NavigationLights", aVal, ss.str());
	  }
	};

	bool NavigationLights::enumerationForValueExists(int aVal) {
	  NavigationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	NavigationLights::enumContainer NavigationLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Anti_CollisionLights implementation **
	 */

	hashMap<int,Anti_CollisionLights*> Anti_CollisionLights::enumerations;
	short Anti_CollisionLights::startBit = 14;
	short Anti_CollisionLights::endBit   = 14;

 Anti_CollisionLights Anti_CollisionLights::OFF(0, "Off");
 Anti_CollisionLights Anti_CollisionLights::ON(1, "On");


	Anti_CollisionLights::Anti_CollisionLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Anti_CollisionLights* Anti_CollisionLights::findEnumeration(int aVal) {
	  Anti_CollisionLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Anti_CollisionLights::getDescriptionForValue(int aVal) {
	  Anti_CollisionLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Anti_CollisionLights Anti_CollisionLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  Anti_CollisionLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Anti_CollisionLights";
		throw EnumException("Anti_CollisionLights", aVal, ss.str());
	  }
	};

	bool Anti_CollisionLights::enumerationForValueExists(int aVal) {
	  Anti_CollisionLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Anti_CollisionLights::enumContainer Anti_CollisionLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Flaming implementation **
	 */

	hashMap<int,Flaming*> Flaming::enumerations;
	short Flaming::startBit = 15;
	short Flaming::endBit   = 15;

 Flaming Flaming::NONE(0, "None");
 Flaming Flaming::FLAMES_PRESENT(1, "Flames present");


	Flaming::Flaming(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Flaming* Flaming::findEnumeration(int aVal) {
	  Flaming* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Flaming::getDescriptionForValue(int aVal) {
	  Flaming* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Flaming Flaming::getEnumerationForValue(int aVal) throw(EnumException) {
	  Flaming* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Flaming";
		throw EnumException("Flaming", aVal, ss.str());
	  }
	};

	bool Flaming::enumerationForValueExists(int aVal) {
	  Flaming* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Flaming::enumContainer Flaming::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Afterburner implementation **
	 */

	hashMap<int,Afterburner*> Afterburner::enumerations;
	short Afterburner::startBit = 16;
	short Afterburner::endBit   = 16;

 Afterburner Afterburner::AFTERBURNER_NOT_ON(0, "Afterburner not on");
 Afterburner Afterburner::AFTERBURNER_ON(1, "Afterburner on");


	Afterburner::Afterburner(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Afterburner* Afterburner::findEnumeration(int aVal) {
	  Afterburner* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Afterburner::getDescriptionForValue(int aVal) {
	  Afterburner* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Afterburner Afterburner::getEnumerationForValue(int aVal) throw(EnumException) {
	  Afterburner* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Afterburner";
		throw EnumException("Afterburner", aVal, ss.str());
	  }
	};

	bool Afterburner::enumerationForValueExists(int aVal) {
	  Afterburner* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Afterburner::enumContainer Afterburner::getEnumerations() {
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
	 **  Power_plantStatus implementation **
	 */

	hashMap<int,Power_plantStatus*> Power_plantStatus::enumerations;
	short Power_plantStatus::startBit = 22;
	short Power_plantStatus::endBit   = 22;

 Power_plantStatus Power_plantStatus::POWER_PLANT_OFF(0, "Power plant off");
 Power_plantStatus Power_plantStatus::POWER_PLANT_ON(1, "Power plant on");


	Power_plantStatus::Power_plantStatus(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Power_plantStatus* Power_plantStatus::findEnumeration(int aVal) {
	  Power_plantStatus* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Power_plantStatus::getDescriptionForValue(int aVal) {
	  Power_plantStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Power_plantStatus Power_plantStatus::getEnumerationForValue(int aVal) throw(EnumException) {
	  Power_plantStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Power_plantStatus";
		throw EnumException("Power_plantStatus", aVal, ss.str());
	  }
	};

	bool Power_plantStatus::enumerationForValueExists(int aVal) {
	  Power_plantStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Power_plantStatus::enumContainer Power_plantStatus::getEnumerations() {
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
	 **  FormationLights implementation **
	 */

	hashMap<int,FormationLights*> FormationLights::enumerations;
	short FormationLights::startBit = 24;
	short FormationLights::endBit   = 24;

 FormationLights FormationLights::OFF(0, "Off");
 FormationLights FormationLights::ON(1, "On");


	FormationLights::FormationLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	FormationLights* FormationLights::findEnumeration(int aVal) {
	  FormationLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string FormationLights::getDescriptionForValue(int aVal) {
	  FormationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	FormationLights FormationLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  FormationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration FormationLights";
		throw EnumException("FormationLights", aVal, ss.str());
	  }
	};

	bool FormationLights::enumerationForValueExists(int aVal) {
	  FormationLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	FormationLights::enumContainer FormationLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  SpotLights implementation **
	 */

	hashMap<int,SpotLights*> SpotLights::enumerations;
	short SpotLights::startBit = 28;
	short SpotLights::endBit   = 28;

 SpotLights SpotLights::OFF(0, "Off");
 SpotLights SpotLights::ON(1, "On");


	SpotLights::SpotLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	SpotLights* SpotLights::findEnumeration(int aVal) {
	  SpotLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string SpotLights::getDescriptionForValue(int aVal) {
	  SpotLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	SpotLights SpotLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  SpotLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration SpotLights";
		throw EnumException("SpotLights", aVal, ss.str());
	  }
	};

	bool SpotLights::enumerationForValueExists(int aVal) {
	  SpotLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	SpotLights::enumContainer SpotLights::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  InteriorLights implementation **
	 */

	hashMap<int,InteriorLights*> InteriorLights::enumerations;
	short InteriorLights::startBit = 29;
	short InteriorLights::endBit   = 29;

 InteriorLights InteriorLights::OFF(0, "Off");
 InteriorLights InteriorLights::ON(1, "On");


	InteriorLights::InteriorLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	InteriorLights* InteriorLights::findEnumeration(int aVal) {
	  InteriorLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string InteriorLights::getDescriptionForValue(int aVal) {
	  InteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	InteriorLights InteriorLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  InteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration InteriorLights";
		throw EnumException("InteriorLights", aVal, ss.str());
	  }
	};

	bool InteriorLights::enumerationForValueExists(int aVal) {
	  InteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	InteriorLights::enumContainer InteriorLights::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace es_appear_platform_air */

} /* namespace DIS */
