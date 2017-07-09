#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_4_fop_param5.h>

namespace DIS {

namespace der_iff_type_4_fop_param5 {

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
	 **  Status implementation **
	 */

	hashMap<int,Status*> Status::enumerations;
	short Status::startBit = 13;
	short Status::endBit   = 13;

 Status Status::OFF(0, "Off");
 Status Status::ON(1, "On");


	Status::Status(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Status* Status::findEnumeration(int aVal) {
	  Status* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Status::getDescriptionForValue(int aVal) {
	  Status* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Status Status::getEnumerationForValue(int aVal) throw(EnumException) {
	  Status* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Status";
		throw EnumException("Status", aVal, ss.str());
	  }
	};

	bool Status::enumerationForValueExists(int aVal) {
	  Status* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Status::enumContainer Status::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Damage implementation **
	 */

	hashMap<int,Damage*> Damage::enumerations;
	short Damage::startBit = 14;
	short Damage::endBit   = 14;

 Damage Damage::NO_DAMAGE(0, "No damage");
 Damage Damage::DAMAGE(1, "Damage");


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
	 **  Malfunction implementation **
	 */

	hashMap<int,Malfunction*> Malfunction::enumerations;
	short Malfunction::startBit = 15;
	short Malfunction::endBit   = 15;

 Malfunction Malfunction::NO_MALFUNCTION(0, "No malfunction");
 Malfunction Malfunction::MALFUNCTION(1, "Malfunction");


	Malfunction::Malfunction(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Malfunction* Malfunction::findEnumeration(int aVal) {
	  Malfunction* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Malfunction::getDescriptionForValue(int aVal) {
	  Malfunction* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Malfunction Malfunction::getEnumerationForValue(int aVal) throw(EnumException) {
	  Malfunction* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Malfunction";
		throw EnumException("Malfunction", aVal, ss.str());
	  }
	};

	bool Malfunction::enumerationForValueExists(int aVal) {
	  Malfunction* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Malfunction::enumContainer Malfunction::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_iff_type_4_fop_param5 */

} /* namespace DIS */
