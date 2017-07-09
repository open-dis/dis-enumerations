#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_linear_tankditch.h>

namespace DIS {

namespace env_obj_appear_linear_tankditch {

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
	 **  Breach implementation **
	 */

	hashMap<int,Breach*> Breach::enumerations;
	short Breach::startBit = 16;
	short Breach::endBit   = 17;

 Breach Breach::NO_BREACHING(0, "No breaching");
 Breach Breach::SLIGHT_BREACHING(1, "Slight breaching");
 Breach Breach::MODERATE_BREACHED(2, "Moderate breached");
 Breach Breach::CLEARED(3, "Cleared");


	Breach::Breach(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Breach* Breach::findEnumeration(int aVal) {
	  Breach* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Breach::getDescriptionForValue(int aVal) {
	  Breach* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Breach Breach::getEnumerationForValue(int aVal) throw(EnumException) {
	  Breach* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Breach";
		throw EnumException("Breach", aVal, ss.str());
	  }
	};

	bool Breach::enumerationForValueExists(int aVal) {
	  Breach* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Breach::enumContainer Breach::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  BreachLength implementation **
	 */

	hashMap<int,BreachLength*> BreachLength::enumerations;
	short BreachLength::startBit = 32;
	short BreachLength::endBit   = 39;



	BreachLength::BreachLength(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	BreachLength* BreachLength::findEnumeration(int aVal) {
	  BreachLength* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string BreachLength::getDescriptionForValue(int aVal) {
	  BreachLength* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	BreachLength BreachLength::getEnumerationForValue(int aVal) throw(EnumException) {
	  BreachLength* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration BreachLength";
		throw EnumException("BreachLength", aVal, ss.str());
	  }
	};

	bool BreachLength::enumerationForValueExists(int aVal) {
	  BreachLength* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	BreachLength::enumContainer BreachLength::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  BreachLocation implementation **
	 */

	hashMap<int,BreachLocation*> BreachLocation::enumerations;
	short BreachLocation::startBit = 40;
	short BreachLocation::endBit   = 47;

 BreachLocation BreachLocation::ASSOCIATED_PORTION_OF_SEGMENT_IS_NOT_BREACHED(0, "Associated portion of segment is not breached");
 BreachLocation BreachLocation::ASSOCIATED_PORTION_OF_SEGMENT_IS_BREACHED(1, "Associated portion of segment is breached");


	BreachLocation::BreachLocation(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	BreachLocation* BreachLocation::findEnumeration(int aVal) {
	  BreachLocation* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string BreachLocation::getDescriptionForValue(int aVal) {
	  BreachLocation* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	BreachLocation BreachLocation::getEnumerationForValue(int aVal) throw(EnumException) {
	  BreachLocation* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration BreachLocation";
		throw EnumException("BreachLocation", aVal, ss.str());
	  }
	};

	bool BreachLocation::enumerationForValueExists(int aVal) {
	  BreachLocation* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	BreachLocation::enumContainer BreachLocation::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_obj_appear_linear_tankditch */

} /* namespace DIS */
