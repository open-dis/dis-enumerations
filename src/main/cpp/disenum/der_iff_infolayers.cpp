#include <sstream>
#include <cstddef>
#include <disenum/der_iff_infolayers.h>

namespace DIS {

namespace der_iff_infolayers {

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
	 **  Layer1 implementation **
	 */

	hashMap<int,Layer1*> Layer1::enumerations;
	short Layer1::startBit = 12;
	short Layer1::endBit   = 12;

 Layer1 Layer1::NOT_PRESENT(0, "Not Present");
 Layer1 Layer1::PRESENT(1, "Present");


	Layer1::Layer1(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Layer1* Layer1::findEnumeration(int aVal) {
	  Layer1* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Layer1::getDescriptionForValue(int aVal) {
	  Layer1* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Layer1 Layer1::getEnumerationForValue(int aVal) throw(EnumException) {
	  Layer1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Layer1";
		throw EnumException("Layer1", aVal, ss.str());
	  }
	};

	bool Layer1::enumerationForValueExists(int aVal) {
	  Layer1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Layer1::enumContainer Layer1::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Layer2 implementation **
	 */

	hashMap<int,Layer2*> Layer2::enumerations;
	short Layer2::startBit = 13;
	short Layer2::endBit   = 13;

 Layer2 Layer2::NOT_PRESENT(0, "Not Present");
 Layer2 Layer2::PRESENT(1, "Present");


	Layer2::Layer2(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Layer2* Layer2::findEnumeration(int aVal) {
	  Layer2* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Layer2::getDescriptionForValue(int aVal) {
	  Layer2* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Layer2 Layer2::getEnumerationForValue(int aVal) throw(EnumException) {
	  Layer2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Layer2";
		throw EnumException("Layer2", aVal, ss.str());
	  }
	};

	bool Layer2::enumerationForValueExists(int aVal) {
	  Layer2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Layer2::enumContainer Layer2::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_iff_infolayers */

} /* namespace DIS */
