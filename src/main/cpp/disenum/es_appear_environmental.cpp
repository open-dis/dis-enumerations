#include <sstream>
#include <cstddef>
#include <disenum/es_appear_environmental.h>

namespace DIS {

namespace es_appear_environmental {

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
	 **  Density implementation **
	 */

	hashMap<int,Density*> Density::enumerations;
	short Density::startBit = 16;
	short Density::endBit   = 19;

 Density Density::CLEAR(0, "Clear");
 Density Density::HAZY(1, "Hazy");
 Density Density::DENSE(2, "Dense");
 Density Density::VERY_DENSE(3, "Very dense");
 Density Density::OPAQUE(4, "Opaque");


	Density::Density(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Density* Density::findEnumeration(int aVal) {
	  Density* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Density::getDescriptionForValue(int aVal) {
	  Density* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Density Density::getEnumerationForValue(int aVal) throw(EnumException) {
	  Density* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Density";
		throw EnumException("Density", aVal, ss.str());
	  }
	};

	bool Density::enumerationForValueExists(int aVal) {
	  Density* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Density::enumContainer Density::getEnumerations() {
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





}; /* namespace es_appear_environmental */

} /* namespace DIS */
