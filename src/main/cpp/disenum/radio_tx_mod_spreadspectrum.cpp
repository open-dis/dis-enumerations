#include <sstream>
#include <cstddef>
#include <disenum/radio_tx_mod_spreadspectrum.h>

namespace DIS {

namespace radio_tx_mod_spreadspectrum {

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
	 **  FrequencyHopping implementation **
	 */

	hashMap<int,FrequencyHopping*> FrequencyHopping::enumerations;
	short FrequencyHopping::startBit = 0;
	short FrequencyHopping::endBit   = 0;



	FrequencyHopping::FrequencyHopping(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	FrequencyHopping* FrequencyHopping::findEnumeration(int aVal) {
	  FrequencyHopping* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string FrequencyHopping::getDescriptionForValue(int aVal) {
	  FrequencyHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	FrequencyHopping FrequencyHopping::getEnumerationForValue(int aVal) throw(EnumException) {
	  FrequencyHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration FrequencyHopping";
		throw EnumException("FrequencyHopping", aVal, ss.str());
	  }
	};

	bool FrequencyHopping::enumerationForValueExists(int aVal) {
	  FrequencyHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	FrequencyHopping::enumContainer FrequencyHopping::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Pseudo_noise implementation **
	 */

	hashMap<int,Pseudo_noise*> Pseudo_noise::enumerations;
	short Pseudo_noise::startBit = 1;
	short Pseudo_noise::endBit   = 1;



	Pseudo_noise::Pseudo_noise(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Pseudo_noise* Pseudo_noise::findEnumeration(int aVal) {
	  Pseudo_noise* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Pseudo_noise::getDescriptionForValue(int aVal) {
	  Pseudo_noise* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Pseudo_noise Pseudo_noise::getEnumerationForValue(int aVal) throw(EnumException) {
	  Pseudo_noise* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Pseudo_noise";
		throw EnumException("Pseudo_noise", aVal, ss.str());
	  }
	};

	bool Pseudo_noise::enumerationForValueExists(int aVal) {
	  Pseudo_noise* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Pseudo_noise::enumContainer Pseudo_noise::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  TimeHopping implementation **
	 */

	hashMap<int,TimeHopping*> TimeHopping::enumerations;
	short TimeHopping::startBit = 2;
	short TimeHopping::endBit   = 2;



	TimeHopping::TimeHopping(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	TimeHopping* TimeHopping::findEnumeration(int aVal) {
	  TimeHopping* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string TimeHopping::getDescriptionForValue(int aVal) {
	  TimeHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	TimeHopping TimeHopping::getEnumerationForValue(int aVal) throw(EnumException) {
	  TimeHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration TimeHopping";
		throw EnumException("TimeHopping", aVal, ss.str());
	  }
	};

	bool TimeHopping::enumerationForValueExists(int aVal) {
	  TimeHopping* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	TimeHopping::enumContainer TimeHopping::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace radio_tx_mod_spreadspectrum */

} /* namespace DIS */
