#include <sstream>
#include <cstddef>
#include <disenum/es_appear_platform_subsurface.h>

namespace DIS {

namespace es_appear_platform_subsurface {

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
	 **  Mobility implementation **
	 */

	hashMap<int,Mobility*> Mobility::enumerations;
	short Mobility::startBit = 1;
	short Mobility::endBit   = 1;

 Mobility Mobility::NO_MOBILITY_KILL(0, "No mobility kill");
 Mobility Mobility::MOBILITY_KILL(1, "Mobility kill");


	Mobility::Mobility(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Mobility* Mobility::findEnumeration(int aVal) {
	  Mobility* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Mobility::getDescriptionForValue(int aVal) {
	  Mobility* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Mobility Mobility::getEnumerationForValue(int aVal) throw(EnumException) {
	  Mobility* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Mobility";
		throw EnumException("Mobility", aVal, ss.str());
	  }
	};

	bool Mobility::enumerationForValueExists(int aVal) {
	  Mobility* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Mobility::enumContainer Mobility::getEnumerations() {
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
	 **  Hatch implementation **
	 */

	hashMap<int,Hatch*> Hatch::enumerations;
	short Hatch::startBit = 9;
	short Hatch::endBit   = 11;

 Hatch Hatch::NOT_APPLICABLE(0, "Not applicable");
 Hatch Hatch::HATCH_IS_CLOSED(1, "Hatch is closed");
 Hatch Hatch::HATCH_IS_OPEN(4, "Hatch is open");


	Hatch::Hatch(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Hatch* Hatch::findEnumeration(int aVal) {
	  Hatch* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Hatch::getDescriptionForValue(int aVal) {
	  Hatch* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Hatch Hatch::getEnumerationForValue(int aVal) throw(EnumException) {
	  Hatch* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Hatch";
		throw EnumException("Hatch", aVal, ss.str());
	  }
	};

	bool Hatch::enumerationForValueExists(int aVal) {
	  Hatch* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Hatch::enumContainer Hatch::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  RunningLights implementation **
	 */

	hashMap<int,RunningLights*> RunningLights::enumerations;
	short RunningLights::startBit = 12;
	short RunningLights::endBit   = 12;

 RunningLights RunningLights::OFF(0, "Off");
 RunningLights RunningLights::ON(1, "On");


	RunningLights::RunningLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	RunningLights* RunningLights::findEnumeration(int aVal) {
	  RunningLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string RunningLights::getDescriptionForValue(int aVal) {
	  RunningLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	RunningLights RunningLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  RunningLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration RunningLights";
		throw EnumException("RunningLights", aVal, ss.str());
	  }
	};

	bool RunningLights::enumerationForValueExists(int aVal) {
	  RunningLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	RunningLights::enumContainer RunningLights::getEnumerations() {
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





}; /* namespace es_appear_platform_subsurface */

} /* namespace DIS */
