#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_point_burst.h>

namespace DIS {

namespace env_obj_appear_point_burst {

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
	 **  Size implementation **
	 */

	hashMap<int,Size*> Size::enumerations;
	short Size::startBit = 24;
	short Size::endBit   = 31;



	Size::Size(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Size* Size::findEnumeration(int aVal) {
	  Size* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Size::getDescriptionForValue(int aVal) {
	  Size* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Size Size::getEnumerationForValue(int aVal) throw(EnumException) {
	  Size* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Size";
		throw EnumException("Size", aVal, ss.str());
	  }
	};

	bool Size::enumerationForValueExists(int aVal) {
	  Size* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Size::enumContainer Size::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Height implementation **
	 */

	hashMap<int,Height*> Height::enumerations;
	short Height::startBit = 32;
	short Height::endBit   = 39;



	Height::Height(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Height* Height::findEnumeration(int aVal) {
	  Height* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Height::getDescriptionForValue(int aVal) {
	  Height* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Height Height::getEnumerationForValue(int aVal) throw(EnumException) {
	  Height* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Height";
		throw EnumException("Height", aVal, ss.str());
	  }
	};

	bool Height::enumerationForValueExists(int aVal) {
	  Height* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Height::enumContainer Height::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  NumofBursts implementation **
	 */

	hashMap<int,NumofBursts*> NumofBursts::enumerations;
	short NumofBursts::startBit = 40;
	short NumofBursts::endBit   = 45;



	NumofBursts::NumofBursts(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	NumofBursts* NumofBursts::findEnumeration(int aVal) {
	  NumofBursts* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string NumofBursts::getDescriptionForValue(int aVal) {
	  NumofBursts* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	NumofBursts NumofBursts::getEnumerationForValue(int aVal) throw(EnumException) {
	  NumofBursts* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration NumofBursts";
		throw EnumException("NumofBursts", aVal, ss.str());
	  }
	};

	bool NumofBursts::enumerationForValueExists(int aVal) {
	  NumofBursts* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	NumofBursts::enumContainer NumofBursts::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Chemical implementation **
	 */

	hashMap<int,Chemical*> Chemical::enumerations;
	short Chemical::startBit = 46;
	short Chemical::endBit   = 47;

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





}; /* namespace env_obj_appear_point_burst */

} /* namespace DIS */
