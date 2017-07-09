#include <sstream>
#include <cstddef>
#include <disenum/env_process_environmentstatus.h>

namespace DIS {

namespace env_process_environmentstatus {

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
	 **  Last implementation **
	 */

	hashMap<int,Last*> Last::enumerations;
	short Last::startBit = 0;
	short Last::endBit   = 0;



	Last::Last(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Last* Last::findEnumeration(int aVal) {
	  Last* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Last::getDescriptionForValue(int aVal) {
	  Last* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Last Last::getEnumerationForValue(int aVal) throw(EnumException) {
	  Last* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Last";
		throw EnumException("Last", aVal, ss.str());
	  }
	};

	bool Last::enumerationForValueExists(int aVal) {
	  Last* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Last::enumContainer Last::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  On implementation **
	 */

	hashMap<int,On*> On::enumerations;
	short On::startBit = 1;
	short On::endBit   = 1;



	On::On(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	On* On::findEnumeration(int aVal) {
	  On* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string On::getDescriptionForValue(int aVal) {
	  On* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	On On::getEnumerationForValue(int aVal) throw(EnumException) {
	  On* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration On";
		throw EnumException("On", aVal, ss.str());
	  }
	};

	bool On::enumerationForValueExists(int aVal) {
	  On* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	On::enumContainer On::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_process_environmentstatus */

} /* namespace DIS */
