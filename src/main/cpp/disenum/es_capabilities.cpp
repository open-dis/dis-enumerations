#include <sstream>
#include <cstddef>
#include <disenum/es_capabilities.h>

namespace DIS {

namespace es_capabilities {

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
	 **  AmmunitionSupply implementation **
	 */

	hashMap<int,AmmunitionSupply*> AmmunitionSupply::enumerations;
	short AmmunitionSupply::startBit = 0;
	short AmmunitionSupply::endBit   = 0;



	AmmunitionSupply::AmmunitionSupply(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	AmmunitionSupply* AmmunitionSupply::findEnumeration(int aVal) {
	  AmmunitionSupply* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string AmmunitionSupply::getDescriptionForValue(int aVal) {
	  AmmunitionSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	AmmunitionSupply AmmunitionSupply::getEnumerationForValue(int aVal) throw(EnumException) {
	  AmmunitionSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration AmmunitionSupply";
		throw EnumException("AmmunitionSupply", aVal, ss.str());
	  }
	};

	bool AmmunitionSupply::enumerationForValueExists(int aVal) {
	  AmmunitionSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	AmmunitionSupply::enumContainer AmmunitionSupply::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  FuelSupply implementation **
	 */

	hashMap<int,FuelSupply*> FuelSupply::enumerations;
	short FuelSupply::startBit = 1;
	short FuelSupply::endBit   = 1;



	FuelSupply::FuelSupply(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	FuelSupply* FuelSupply::findEnumeration(int aVal) {
	  FuelSupply* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string FuelSupply::getDescriptionForValue(int aVal) {
	  FuelSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	FuelSupply FuelSupply::getEnumerationForValue(int aVal) throw(EnumException) {
	  FuelSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration FuelSupply";
		throw EnumException("FuelSupply", aVal, ss.str());
	  }
	};

	bool FuelSupply::enumerationForValueExists(int aVal) {
	  FuelSupply* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	FuelSupply::enumContainer FuelSupply::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Recovery implementation **
	 */

	hashMap<int,Recovery*> Recovery::enumerations;
	short Recovery::startBit = 2;
	short Recovery::endBit   = 2;



	Recovery::Recovery(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Recovery* Recovery::findEnumeration(int aVal) {
	  Recovery* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Recovery::getDescriptionForValue(int aVal) {
	  Recovery* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Recovery Recovery::getEnumerationForValue(int aVal) throw(EnumException) {
	  Recovery* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Recovery";
		throw EnumException("Recovery", aVal, ss.str());
	  }
	};

	bool Recovery::enumerationForValueExists(int aVal) {
	  Recovery* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Recovery::enumContainer Recovery::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Repair implementation **
	 */

	hashMap<int,Repair*> Repair::enumerations;
	short Repair::startBit = 3;
	short Repair::endBit   = 3;



	Repair::Repair(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Repair* Repair::findEnumeration(int aVal) {
	  Repair* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Repair::getDescriptionForValue(int aVal) {
	  Repair* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Repair Repair::getEnumerationForValue(int aVal) throw(EnumException) {
	  Repair* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Repair";
		throw EnumException("Repair", aVal, ss.str());
	  }
	};

	bool Repair::enumerationForValueExists(int aVal) {
	  Repair* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Repair::enumContainer Repair::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ADS_B implementation **
	 */

	hashMap<int,ADS_B*> ADS_B::enumerations;
	short ADS_B::startBit = 4;
	short ADS_B::endBit   = 4;



	ADS_B::ADS_B(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ADS_B* ADS_B::findEnumeration(int aVal) {
	  ADS_B* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ADS_B::getDescriptionForValue(int aVal) {
	  ADS_B* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ADS_B ADS_B::getEnumerationForValue(int aVal) throw(EnumException) {
	  ADS_B* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ADS_B";
		throw EnumException("ADS_B", aVal, ss.str());
	  }
	};

	bool ADS_B::enumerationForValueExists(int aVal) {
	  ADS_B* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ADS_B::enumContainer ADS_B::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace es_capabilities */

} /* namespace DIS */
