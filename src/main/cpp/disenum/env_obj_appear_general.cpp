#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_general.h>

namespace DIS {

namespace env_obj_appear_general {

  bitmask& bitmask::operator=(const unsigned short& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned short*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned short& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned short) 0;
  }

  unsigned short bitmask::getValue(){
    unsigned short val = *( reinterpret_cast<unsigned short *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned short& i){
	  (*this) = i;
  }

	/*
	 **  _pct_complete implementation **
	 */

	hashMap<int,_pct_complete*> _pct_complete::enumerations;
	short _pct_complete::startBit = 0;
	short _pct_complete::endBit   = 7;



	_pct_complete::_pct_complete(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	_pct_complete* _pct_complete::findEnumeration(int aVal) {
	  _pct_complete* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string _pct_complete::getDescriptionForValue(int aVal) {
	  _pct_complete* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	_pct_complete _pct_complete::getEnumerationForValue(int aVal) throw(EnumException) {
	  _pct_complete* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration _pct_complete";
		throw EnumException("_pct_complete", aVal, ss.str());
	  }
	};

	bool _pct_complete::enumerationForValueExists(int aVal) {
	  _pct_complete* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	_pct_complete::enumContainer _pct_complete::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Damage implementation **
	 */

	hashMap<int,Damage*> Damage::enumerations;
	short Damage::startBit = 8;
	short Damage::endBit   = 9;

 Damage Damage::NO_DAMAGE(0, "No damage");
 Damage Damage::DAMAGED(1, "Damaged");
 Damage Damage::DESTROYED(2, "Destroyed");


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
	 **  Predistributed implementation **
	 */

	hashMap<int,Predistributed*> Predistributed::enumerations;
	short Predistributed::startBit = 10;
	short Predistributed::endBit   = 10;

 Predistributed Predistributed::OBJECT_CREATED_DURING_THE_EXERCISE(0, "Object created during the exercise");
 Predistributed Predistributed::OBJECT_PREDISTRIBUTED_PRIOR_TO_EXERCISE_START(1, "Object predistributed prior to exercise start");


	Predistributed::Predistributed(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Predistributed* Predistributed::findEnumeration(int aVal) {
	  Predistributed* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Predistributed::getDescriptionForValue(int aVal) {
	  Predistributed* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Predistributed Predistributed::getEnumerationForValue(int aVal) throw(EnumException) {
	  Predistributed* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Predistributed";
		throw EnumException("Predistributed", aVal, ss.str());
	  }
	};

	bool Predistributed::enumerationForValueExists(int aVal) {
	  Predistributed* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Predistributed::enumContainer Predistributed::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  State implementation **
	 */

	hashMap<int,State*> State::enumerations;
	short State::startBit = 11;
	short State::endBit   = 11;

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
	 **  Smoking implementation **
	 */

	hashMap<int,Smoking*> Smoking::enumerations;
	short Smoking::startBit = 12;
	short Smoking::endBit   = 12;

 Smoking Smoking::NONE(0, "None");
 Smoking Smoking::SMOKE_PRESENT(1, "Smoke present");


	Smoking::Smoking(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Smoking* Smoking::findEnumeration(int aVal) {
	  Smoking* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Smoking::getDescriptionForValue(int aVal) {
	  Smoking* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Smoking Smoking::getEnumerationForValue(int aVal) throw(EnumException) {
	  Smoking* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Smoking";
		throw EnumException("Smoking", aVal, ss.str());
	  }
	};

	bool Smoking::enumerationForValueExists(int aVal) {
	  Smoking* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Smoking::enumContainer Smoking::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Flaming implementation **
	 */

	hashMap<int,Flaming*> Flaming::enumerations;
	short Flaming::startBit = 13;
	short Flaming::endBit   = 13;

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





}; /* namespace env_obj_appear_general */

} /* namespace DIS */
