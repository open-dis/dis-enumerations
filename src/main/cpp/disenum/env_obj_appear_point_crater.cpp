#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_point_crater.h>

namespace DIS {

namespace env_obj_appear_point_crater {

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
	 **  Size implementation **
	 */

	hashMap<int,Size*> Size::enumerations;
	short Size::startBit = 16;
	short Size::endBit   = 23;



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





}; /* namespace env_obj_appear_point_crater */

} /* namespace DIS */
