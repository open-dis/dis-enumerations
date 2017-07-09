#include <sstream>
#include <cstddef>
#include <disenum/radio_tx_encoding.h>

namespace DIS {

namespace radio_tx_encoding {

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
	 **  EncodingType implementation **
	 */

	hashMap<int,EncodingType*> EncodingType::enumerations;
	short EncodingType::startBit = 0;
	short EncodingType::endBit   = 13;

 EncodingType EncodingType::X_8_BIT_MU_LAW(1, "8-bit mu-law");
 EncodingType EncodingType::CVSD_PER_MIL_STD_188_113(2, "CVSD per MIL-STD-188-113");
 EncodingType EncodingType::ADPCM_PER_CCITT_G721(3, "ADPCM per CCITT G.721");
 EncodingType EncodingType::X_16_BIT_LINEAR_PCM(4, "16-bit linear PCM");
 EncodingType EncodingType::X_8_BIT_LINEAR_PCM(5, "8-bit linear PCM");
 EncodingType EncodingType::VQ_VECTOR_QUANTIZATION(6, "VQ (Vector Quantization)");


	EncodingType::EncodingType(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	EncodingType* EncodingType::findEnumeration(int aVal) {
	  EncodingType* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string EncodingType::getDescriptionForValue(int aVal) {
	  EncodingType* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	EncodingType EncodingType::getEnumerationForValue(int aVal) throw(EnumException) {
	  EncodingType* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration EncodingType";
		throw EnumException("EncodingType", aVal, ss.str());
	  }
	};

	bool EncodingType::enumerationForValueExists(int aVal) {
	  EncodingType* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	EncodingType::enumContainer EncodingType::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  EncodingClass implementation **
	 */

	hashMap<int,EncodingClass*> EncodingClass::enumerations;
	short EncodingClass::startBit = 14;
	short EncodingClass::endBit   = 15;

 EncodingClass EncodingClass::ENCODED_AUDIO(0, "Encoded audio");
 EncodingClass EncodingClass::RAW_BINARY_DATA(1, "Raw Binary Data");
 EncodingClass EncodingClass::APPLICATION_SPECIFIC_DATA(2, "Application-Specific Data");
 EncodingClass EncodingClass::DATABASE_INDEX(3, "Database index");


	EncodingClass::EncodingClass(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	EncodingClass* EncodingClass::findEnumeration(int aVal) {
	  EncodingClass* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string EncodingClass::getDescriptionForValue(int aVal) {
	  EncodingClass* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	EncodingClass EncodingClass::getEnumerationForValue(int aVal) throw(EnumException) {
	  EncodingClass* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration EncodingClass";
		throw EnumException("EncodingClass", aVal, ss.str());
	  }
	};

	bool EncodingClass::enumerationForValueExists(int aVal) {
	  EncodingClass* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	EncodingClass::enumContainer EncodingClass::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace radio_tx_encoding */

} /* namespace DIS */
