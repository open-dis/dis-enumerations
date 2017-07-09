#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_1_fop_modifier.h>

namespace DIS {

namespace der_iff_type_1_fop_modifier {

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
	 **  Other implementation **
	 */

	hashMap<int,Other*> Other::enumerations;
	short Other::startBit = 0;
	short Other::endBit   = 0;



	Other::Other(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Other* Other::findEnumeration(int aVal) {
	  Other* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Other::getDescriptionForValue(int aVal) {
	  Other* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Other Other::getEnumerationForValue(int aVal) throw(EnumException) {
	  Other* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Other";
		throw EnumException("Other", aVal, ss.str());
	  }
	};

	bool Other::enumerationForValueExists(int aVal) {
	  Other* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Other::enumContainer Other::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Emergency implementation **
	 */

	hashMap<int,Emergency*> Emergency::enumerations;
	short Emergency::startBit = 1;
	short Emergency::endBit   = 1;

 Emergency Emergency::OFF(0, "Off");
 Emergency Emergency::ON(1, "On");


	Emergency::Emergency(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Emergency* Emergency::findEnumeration(int aVal) {
	  Emergency* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Emergency::getDescriptionForValue(int aVal) {
	  Emergency* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Emergency Emergency::getEnumerationForValue(int aVal) throw(EnumException) {
	  Emergency* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Emergency";
		throw EnumException("Emergency", aVal, ss.str());
	  }
	};

	bool Emergency::enumerationForValueExists(int aVal) {
	  Emergency* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Emergency::enumContainer Emergency::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Ident_SquawkFlash implementation **
	 */

	hashMap<int,Ident_SquawkFlash*> Ident_SquawkFlash::enumerations;
	short Ident_SquawkFlash::startBit = 2;
	short Ident_SquawkFlash::endBit   = 2;

 Ident_SquawkFlash Ident_SquawkFlash::OFF(0, "Off");
 Ident_SquawkFlash Ident_SquawkFlash::ON(1, "On");


	Ident_SquawkFlash::Ident_SquawkFlash(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Ident_SquawkFlash* Ident_SquawkFlash::findEnumeration(int aVal) {
	  Ident_SquawkFlash* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Ident_SquawkFlash::getDescriptionForValue(int aVal) {
	  Ident_SquawkFlash* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Ident_SquawkFlash Ident_SquawkFlash::getEnumerationForValue(int aVal) throw(EnumException) {
	  Ident_SquawkFlash* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Ident_SquawkFlash";
		throw EnumException("Ident_SquawkFlash", aVal, ss.str());
	  }
	};

	bool Ident_SquawkFlash::enumerationForValueExists(int aVal) {
	  Ident_SquawkFlash* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Ident_SquawkFlash::enumContainer Ident_SquawkFlash::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  STI implementation **
	 */

	hashMap<int,STI*> STI::enumerations;
	short STI::startBit = 3;
	short STI::endBit   = 3;

 STI STI::NO_DAMAGE(0, "No damage");
 STI STI::DAMAGE(1, "Damage");


	STI::STI(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	STI* STI::findEnumeration(int aVal) {
	  STI* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string STI::getDescriptionForValue(int aVal) {
	  STI* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	STI STI::getEnumerationForValue(int aVal) throw(EnumException) {
	  STI* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration STI";
		throw EnumException("STI", aVal, ss.str());
	  }
	};

	bool STI::enumerationForValueExists(int aVal) {
	  STI* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	STI::enumContainer STI::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_iff_type_1_fop_modifier */

} /* namespace DIS */
