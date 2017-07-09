#include <sstream>
#include <cstddef>
#include <disenum/es_appear_munition.h>

namespace DIS {

namespace es_appear_munition {

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
 Smoke Smoke::SMOKE_OR_VAPOR_IS_EMANATING_FROM_THE_ENTITY(1, "Smoke or vapor is emanating from the entity");
 Smoke Smoke::ENTITY_IS_EMITTING_MOTOR_SMOKE(2, "Entity is emitting motor smoke");
 Smoke Smoke::ENTITY_IS_EMITTING_MOTOR_SMOKE_AND_SMOKE_OR_VAPOR_IS_EMANATING_FROM_THE_ENTITY(3, "Entity is emitting motor smoke, and smoke or vapor is emanating from the entity");


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
	 **  Launchflash implementation **
	 */

	hashMap<int,Launchflash*> Launchflash::enumerations;
	short Launchflash::startBit = 16;
	short Launchflash::endBit   = 16;

 Launchflash Launchflash::NO_LAUNCH_FLASH_PRESENT(0, "No launch flash present");
 Launchflash Launchflash::LAUNCH_FLASH_PRESENT(1, "Launch flash present");


	Launchflash::Launchflash(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Launchflash* Launchflash::findEnumeration(int aVal) {
	  Launchflash* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Launchflash::getDescriptionForValue(int aVal) {
	  Launchflash* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Launchflash Launchflash::getEnumerationForValue(int aVal) throw(EnumException) {
	  Launchflash* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Launchflash";
		throw EnumException("Launchflash", aVal, ss.str());
	  }
	};

	bool Launchflash::enumerationForValueExists(int aVal) {
	  Launchflash* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Launchflash::enumContainer Launchflash::getEnumerations() {
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
	 **  Masked_Cloaked implementation **
	 */

	hashMap<int,Masked_Cloaked*> Masked_Cloaked::enumerations;
	short Masked_Cloaked::startBit = 31;
	short Masked_Cloaked::endBit   = 31;

 Masked_Cloaked Masked_Cloaked::NOT_MASKED_NOT_CLOAKED(0, "Not Masked / Not Cloaked");
 Masked_Cloaked Masked_Cloaked::MASKED_CLOAKED(1, "Masked / Cloaked");


	Masked_Cloaked::Masked_Cloaked(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Masked_Cloaked* Masked_Cloaked::findEnumeration(int aVal) {
	  Masked_Cloaked* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Masked_Cloaked::getDescriptionForValue(int aVal) {
	  Masked_Cloaked* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Masked_Cloaked Masked_Cloaked::getEnumerationForValue(int aVal) throw(EnumException) {
	  Masked_Cloaked* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Masked_Cloaked";
		throw EnumException("Masked_Cloaked", aVal, ss.str());
	  }
	};

	bool Masked_Cloaked::enumerationForValueExists(int aVal) {
	  Masked_Cloaked* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Masked_Cloaked::enumContainer Masked_Cloaked::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace es_appear_munition */

} /* namespace DIS */
