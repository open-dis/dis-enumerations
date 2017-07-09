#include <sstream>
#include <cstddef>
#include <disenum/der_ua_ppcfg.h>

namespace DIS {

namespace der_ua_ppcfg {

  bitmask& bitmask::operator=(const unsigned char& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned char*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned char& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned char) 0;
  }

  unsigned char bitmask::getValue(){
    unsigned char val = *( reinterpret_cast<unsigned char *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned char& i){
	  (*this) = i;
  }

	/*
	 **  Configuration implementation **
	 */

	hashMap<int,Configuration*> Configuration::enumerations;
	short Configuration::startBit = 0;
	short Configuration::endBit   = 6;

 Configuration Configuration::OTHER(0, "Other");
 Configuration Configuration::DIESEL_ELECTRIC(1, "Diesel/electric");
 Configuration Configuration::DIESEL(2, "Diesel");
 Configuration Configuration::BATTERY(3, "Battery");
 Configuration Configuration::TURBINE_REDUCTION(4, "Turbine reduction");
 Configuration Configuration::STEAM(6, "Steam");
 Configuration Configuration::GAS_TURBINE(7, "Gas turbine");


	Configuration::Configuration(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Configuration* Configuration::findEnumeration(int aVal) {
	  Configuration* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Configuration::getDescriptionForValue(int aVal) {
	  Configuration* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Configuration Configuration::getEnumerationForValue(int aVal) throw(EnumException) {
	  Configuration* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Configuration";
		throw EnumException("Configuration", aVal, ss.str());
	  }
	};

	bool Configuration::enumerationForValueExists(int aVal) {
	  Configuration* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Configuration::enumContainer Configuration::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  HullMountedMasker implementation **
	 */

	hashMap<int,HullMountedMasker*> HullMountedMasker::enumerations;
	short HullMountedMasker::startBit = 7;
	short HullMountedMasker::endBit   = 7;

 HullMountedMasker HullMountedMasker::OFF(0, "Off");
 HullMountedMasker HullMountedMasker::ON(1, "On");


	HullMountedMasker::HullMountedMasker(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	HullMountedMasker* HullMountedMasker::findEnumeration(int aVal) {
	  HullMountedMasker* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string HullMountedMasker::getDescriptionForValue(int aVal) {
	  HullMountedMasker* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	HullMountedMasker HullMountedMasker::getEnumerationForValue(int aVal) throw(EnumException) {
	  HullMountedMasker* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration HullMountedMasker";
		throw EnumException("HullMountedMasker", aVal, ss.str());
	  }
	};

	bool HullMountedMasker::enumerationForValueExists(int aVal) {
	  HullMountedMasker* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	HullMountedMasker::enumContainer HullMountedMasker::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_ua_ppcfg */

} /* namespace DIS */
