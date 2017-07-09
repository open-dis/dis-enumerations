#include <sstream>
#include <cstddef>
#include <disenum/entity_mine_appear.h>

namespace DIS {

namespace entity_mine_appear {

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
	 **  Minefieldtype implementation **
	 */

	hashMap<int,Minefieldtype*> Minefieldtype::enumerations;
	short Minefieldtype::startBit = 0;
	short Minefieldtype::endBit   = 1;

 Minefieldtype Minefieldtype::MIXED_ANTI_PERSONNEL_AND_ANTI_TANK_MINEFIELD(0, "Mixed anti-personnel and anti-tank minefield");
 Minefieldtype Minefieldtype::PURE_ANTI_PERSONNEL_MINEFIELD(1, "Pure anti-personnel minefield");
 Minefieldtype Minefieldtype::PURE_ANTI_TANK_MINEFIELD(2, "Pure anti-tank minefield");


	Minefieldtype::Minefieldtype(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Minefieldtype* Minefieldtype::findEnumeration(int aVal) {
	  Minefieldtype* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Minefieldtype::getDescriptionForValue(int aVal) {
	  Minefieldtype* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Minefieldtype Minefieldtype::getEnumerationForValue(int aVal) throw(EnumException) {
	  Minefieldtype* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Minefieldtype";
		throw EnumException("Minefieldtype", aVal, ss.str());
	  }
	};

	bool Minefieldtype::enumerationForValueExists(int aVal) {
	  Minefieldtype* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Minefieldtype::enumContainer Minefieldtype::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ActiveStatus implementation **
	 */

	hashMap<int,ActiveStatus*> ActiveStatus::enumerations;
	short ActiveStatus::startBit = 2;
	short ActiveStatus::endBit   = 2;

 ActiveStatus ActiveStatus::ACTIVE(0, "Active");
 ActiveStatus ActiveStatus::INACTIVE(1, "Inactive");


	ActiveStatus::ActiveStatus(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ActiveStatus* ActiveStatus::findEnumeration(int aVal) {
	  ActiveStatus* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ActiveStatus::getDescriptionForValue(int aVal) {
	  ActiveStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ActiveStatus ActiveStatus::getEnumerationForValue(int aVal) throw(EnumException) {
	  ActiveStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ActiveStatus";
		throw EnumException("ActiveStatus", aVal, ss.str());
	  }
	};

	bool ActiveStatus::enumerationForValueExists(int aVal) {
	  ActiveStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ActiveStatus::enumContainer ActiveStatus::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Lane implementation **
	 */

	hashMap<int,Lane*> Lane::enumerations;
	short Lane::startBit = 3;
	short Lane::endBit   = 3;

 Lane Lane::MINEFIELD_HAS_ACTIVE_LANE(0, "Minefield has active lane");
 Lane Lane::MINEFIELD_HAS_AN_INACTIVE_LANE(1, "Minefield has an inactive lane");


	Lane::Lane(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Lane* Lane::findEnumeration(int aVal) {
	  Lane* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Lane::getDescriptionForValue(int aVal) {
	  Lane* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Lane Lane::getEnumerationForValue(int aVal) throw(EnumException) {
	  Lane* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Lane";
		throw EnumException("Lane", aVal, ss.str());
	  }
	};

	bool Lane::enumerationForValueExists(int aVal) {
	  Lane* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Lane::enumContainer Lane::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  State implementation **
	 */

	hashMap<int,State*> State::enumerations;
	short State::startBit = 13;
	short State::endBit   = 13;

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





}; /* namespace entity_mine_appear */

} /* namespace DIS */
