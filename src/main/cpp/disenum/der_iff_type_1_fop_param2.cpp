#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_1_fop_param2.h>

namespace DIS {

namespace der_iff_type_1_fop_param2 {

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
	 **  Codeelement1 implementation **
	 */

	hashMap<int,Codeelement1*> Codeelement1::enumerations;
	short Codeelement1::startBit = 0;
	short Codeelement1::endBit   = 2;



	Codeelement1::Codeelement1(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Codeelement1* Codeelement1::findEnumeration(int aVal) {
	  Codeelement1* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Codeelement1::getDescriptionForValue(int aVal) {
	  Codeelement1* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Codeelement1 Codeelement1::getEnumerationForValue(int aVal) throw(EnumException) {
	  Codeelement1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Codeelement1";
		throw EnumException("Codeelement1", aVal, ss.str());
	  }
	};

	bool Codeelement1::enumerationForValueExists(int aVal) {
	  Codeelement1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Codeelement1::enumContainer Codeelement1::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Codeelement2 implementation **
	 */

	hashMap<int,Codeelement2*> Codeelement2::enumerations;
	short Codeelement2::startBit = 3;
	short Codeelement2::endBit   = 5;



	Codeelement2::Codeelement2(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Codeelement2* Codeelement2::findEnumeration(int aVal) {
	  Codeelement2* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Codeelement2::getDescriptionForValue(int aVal) {
	  Codeelement2* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Codeelement2 Codeelement2::getEnumerationForValue(int aVal) throw(EnumException) {
	  Codeelement2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Codeelement2";
		throw EnumException("Codeelement2", aVal, ss.str());
	  }
	};

	bool Codeelement2::enumerationForValueExists(int aVal) {
	  Codeelement2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Codeelement2::enumContainer Codeelement2::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Codeelement3 implementation **
	 */

	hashMap<int,Codeelement3*> Codeelement3::enumerations;
	short Codeelement3::startBit = 6;
	short Codeelement3::endBit   = 8;



	Codeelement3::Codeelement3(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Codeelement3* Codeelement3::findEnumeration(int aVal) {
	  Codeelement3* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Codeelement3::getDescriptionForValue(int aVal) {
	  Codeelement3* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Codeelement3 Codeelement3::getEnumerationForValue(int aVal) throw(EnumException) {
	  Codeelement3* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Codeelement3";
		throw EnumException("Codeelement3", aVal, ss.str());
	  }
	};

	bool Codeelement3::enumerationForValueExists(int aVal) {
	  Codeelement3* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Codeelement3::enumContainer Codeelement3::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Codeelement4 implementation **
	 */

	hashMap<int,Codeelement4*> Codeelement4::enumerations;
	short Codeelement4::startBit = 9;
	short Codeelement4::endBit   = 11;



	Codeelement4::Codeelement4(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Codeelement4* Codeelement4::findEnumeration(int aVal) {
	  Codeelement4* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Codeelement4::getDescriptionForValue(int aVal) {
	  Codeelement4* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Codeelement4 Codeelement4::getEnumerationForValue(int aVal) throw(EnumException) {
	  Codeelement4* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Codeelement4";
		throw EnumException("Codeelement4", aVal, ss.str());
	  }
	};

	bool Codeelement4::enumerationForValueExists(int aVal) {
	  Codeelement4* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Codeelement4::enumContainer Codeelement4::getEnumerations() {
	  return (enumerations);
	};


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





}; /* namespace der_iff_type_1_fop_param2 */

} /* namespace DIS */
