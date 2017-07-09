#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_1_fop_param5.h>

namespace DIS {

namespace der_iff_type_1_fop_param5 {

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
	 **  NegativeAltitude implementation **
	 */

	hashMap<int,NegativeAltitude*> NegativeAltitude::enumerations;
	short NegativeAltitude::startBit = 0;
	short NegativeAltitude::endBit   = 0;

 NegativeAltitude NegativeAltitude::POSITIVE_ALTITUDE_ABOVE_MEAN_SEA_LEVEL_INDICATOR_IF_MODE_C_ALTITUDE_IS_CONTAINED_IN_BITS_1_11(0, "Positive altitude above mean sea level Indicator if Mode C altitude is contained in Bits 1-11");
 NegativeAltitude NegativeAltitude::NEGATIVE_ALTITUDE_BELOW_MEAN_SEA_LEVEL_INDICATOR_IF_MODE_C_ALTITUDE_IS_CONTAINED_IN_BITS_1_11_OR_ALTERNATE_MODE_5_IF_ALTITUDE_BITS_1_11_EQ_2047(1, "Negative altitude below mean sea level Indicator if Mode C altitude is contained in Bits 1-11, or, Alternate Mode 5 if altitude Bits 1-11 = 2047.");


	NegativeAltitude::NegativeAltitude(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	NegativeAltitude* NegativeAltitude::findEnumeration(int aVal) {
	  NegativeAltitude* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string NegativeAltitude::getDescriptionForValue(int aVal) {
	  NegativeAltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	NegativeAltitude NegativeAltitude::getEnumerationForValue(int aVal) throw(EnumException) {
	  NegativeAltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration NegativeAltitude";
		throw EnumException("NegativeAltitude", aVal, ss.str());
	  }
	};

	bool NegativeAltitude::enumerationForValueExists(int aVal) {
	  NegativeAltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	NegativeAltitude::enumContainer NegativeAltitude::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ModeCaltitude implementation **
	 */

	hashMap<int,ModeCaltitude*> ModeCaltitude::enumerations;
	short ModeCaltitude::startBit = 1;
	short ModeCaltitude::endBit   = 11;

 ModeCaltitude ModeCaltitude::ACTUAL_MODE_C_ALTITUDE_IN_THE_RANGE_0_126000_FEET_IN_100_FOOT_INCREMENTS_BIT_0_NEGATIVE_POSITIVE_INDICATOR_MUST_BE_SET_APPROPRIATELY(0, "Actual Mode C altitude in the range 0-126,000 feet in 100-foot increments (Bit 0 - Negative / Positive Indicator must be set appropriately)");
 ModeCaltitude ModeCaltitude::NOT_ACTUAL_MODE_C_ALTITUDE_VALUE_USE_ALTERNATE_MODE_5_BITS_0_11_EQ_4095_IE_ALL_1_S(2047, "Not actual Mode C altitude value. Use alternate Mode 5 (Bits 0-11 = 4095 i.e. all 1-s)");


	ModeCaltitude::ModeCaltitude(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ModeCaltitude* ModeCaltitude::findEnumeration(int aVal) {
	  ModeCaltitude* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ModeCaltitude::getDescriptionForValue(int aVal) {
	  ModeCaltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ModeCaltitude ModeCaltitude::getEnumerationForValue(int aVal) throw(EnumException) {
	  ModeCaltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ModeCaltitude";
		throw EnumException("ModeCaltitude", aVal, ss.str());
	  }
	};

	bool ModeCaltitude::enumerationForValueExists(int aVal) {
	  ModeCaltitude* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ModeCaltitude::enumContainer ModeCaltitude::getEnumerations() {
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





}; /* namespace der_iff_type_1_fop_param5 */

} /* namespace DIS */
