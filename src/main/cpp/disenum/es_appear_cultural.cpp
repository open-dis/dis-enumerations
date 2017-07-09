#include <sstream>
#include <cstddef>
#include <disenum/es_appear_cultural.h>

namespace DIS {

namespace es_appear_cultural {

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
 FrozenStatus FrozenStatus::FROZEN_FROZEN_ENTITIES_SHOULD_NOT_BE_DEAD_RECKONED_IE_SHOULD_BE_DISPLAYED_AS_FIXED_AT_THE_CURRENT_LOCATION_EVEN_IF_NON_ZERO_VELOCITY_ACCELERATION_OR_ROTATION_DATA_RECEIVED_FROM_THE_FROZEN_ENTITY(1, "Frozen (Frozen entities should not be dead-reckoned, i.e. should be displayed as fixed at the current location even if non-zero velocity, acceleration or rotation data received from the frozen entity)");


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
	 **  Internal_HeatStatus implementation **
	 */

	hashMap<int,Internal_HeatStatus*> Internal_HeatStatus::enumerations;
	short Internal_HeatStatus::startBit = 22;
	short Internal_HeatStatus::endBit   = 22;

 Internal_HeatStatus Internal_HeatStatus::INTERNAL_HEAT_OFF(0, "Internal-Heat off");
 Internal_HeatStatus Internal_HeatStatus::INTERNAL_HEAT_ON(1, "Internal-Heat on");


	Internal_HeatStatus::Internal_HeatStatus(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Internal_HeatStatus* Internal_HeatStatus::findEnumeration(int aVal) {
	  Internal_HeatStatus* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Internal_HeatStatus::getDescriptionForValue(int aVal) {
	  Internal_HeatStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Internal_HeatStatus Internal_HeatStatus::getEnumerationForValue(int aVal) throw(EnumException) {
	  Internal_HeatStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Internal_HeatStatus";
		throw EnumException("Internal_HeatStatus", aVal, ss.str());
	  }
	};

	bool Internal_HeatStatus::enumerationForValueExists(int aVal) {
	  Internal_HeatStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Internal_HeatStatus::enumContainer Internal_HeatStatus::getEnumerations() {
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
	 **  ExteriorLights implementation **
	 */

	hashMap<int,ExteriorLights*> ExteriorLights::enumerations;
	short ExteriorLights::startBit = 28;
	short ExteriorLights::endBit   = 28;

 ExteriorLights ExteriorLights::OFF(0, "Off");
 ExteriorLights ExteriorLights::ON(1, "On");


	ExteriorLights::ExteriorLights(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ExteriorLights* ExteriorLights::findEnumeration(int aVal) {
	  ExteriorLights* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ExteriorLights::getDescriptionForValue(int aVal) {
	  ExteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ExteriorLights ExteriorLights::getEnumerationForValue(int aVal) throw(EnumException) {
	  ExteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ExteriorLights";
		throw EnumException("ExteriorLights", aVal, ss.str());
	  }
	};

	bool ExteriorLights::enumerationForValueExists(int aVal) {
	  ExteriorLights* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ExteriorLights::enumContainer ExteriorLights::getEnumerations() {
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





}; /* namespace es_appear_cultural */

} /* namespace DIS */
