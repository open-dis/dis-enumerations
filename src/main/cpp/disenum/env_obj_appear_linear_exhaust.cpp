#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_linear_exhaust.h>

namespace DIS {

namespace env_obj_appear_linear_exhaust {

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
	 **  Opacity implementation **
	 */

	hashMap<int,Opacity*> Opacity::enumerations;
	short Opacity::startBit = 16;
	short Opacity::endBit   = 23;



	Opacity::Opacity(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Opacity* Opacity::findEnumeration(int aVal) {
	  Opacity* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Opacity::getDescriptionForValue(int aVal) {
	  Opacity* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Opacity Opacity::getEnumerationForValue(int aVal) throw(EnumException) {
	  Opacity* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Opacity";
		throw EnumException("Opacity", aVal, ss.str());
	  }
	};

	bool Opacity::enumerationForValueExists(int aVal) {
	  Opacity* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Opacity::enumContainer Opacity::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Attached implementation **
	 */

	hashMap<int,Attached*> Attached::enumerations;
	short Attached::startBit = 24;
	short Attached::endBit   = 24;

 Attached Attached::NOT_ATTACHED(0, "Not attached");
 Attached Attached::ATTACHED(1, "Attached");


	Attached::Attached(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Attached* Attached::findEnumeration(int aVal) {
	  Attached* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Attached::getDescriptionForValue(int aVal) {
	  Attached* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Attached Attached::getEnumerationForValue(int aVal) throw(EnumException) {
	  Attached* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Attached";
		throw EnumException("Attached", aVal, ss.str());
	  }
	};

	bool Attached::enumerationForValueExists(int aVal) {
	  Attached* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Attached::enumContainer Attached::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Chemical implementation **
	 */

	hashMap<int,Chemical*> Chemical::enumerations;
	short Chemical::startBit = 25;
	short Chemical::endBit   = 26;

 Chemical Chemical::OTHER(0, "Other");
 Chemical Chemical::HYDROCHLORIC(1, "Hydrochloric");
 Chemical Chemical::WHITE_PHOSPHOROUS(2, "White phosphorous");
 Chemical Chemical::RED_PHOSPHOROUS(3, "Red phosphorous");


	Chemical::Chemical(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Chemical* Chemical::findEnumeration(int aVal) {
	  Chemical* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Chemical::getDescriptionForValue(int aVal) {
	  Chemical* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Chemical Chemical::getEnumerationForValue(int aVal) throw(EnumException) {
	  Chemical* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Chemical";
		throw EnumException("Chemical", aVal, ss.str());
	  }
	};

	bool Chemical::enumerationForValueExists(int aVal) {
	  Chemical* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Chemical::enumContainer Chemical::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_obj_appear_linear_exhaust */

} /* namespace DIS */
