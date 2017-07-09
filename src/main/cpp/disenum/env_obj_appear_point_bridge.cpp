#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_point_bridge.h>

namespace DIS {

namespace env_obj_appear_point_bridge {

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
	 **  NumofSegments implementation **
	 */

	hashMap<int,NumofSegments*> NumofSegments::enumerations;
	short NumofSegments::startBit = 16;
	short NumofSegments::endBit   = 23;



	NumofSegments::NumofSegments(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	NumofSegments* NumofSegments::findEnumeration(int aVal) {
	  NumofSegments* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string NumofSegments::getDescriptionForValue(int aVal) {
	  NumofSegments* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	NumofSegments NumofSegments::getEnumerationForValue(int aVal) throw(EnumException) {
	  NumofSegments* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration NumofSegments";
		throw EnumException("NumofSegments", aVal, ss.str());
	  }
	};

	bool NumofSegments::enumerationForValueExists(int aVal) {
	  NumofSegments* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	NumofSegments::enumContainer NumofSegments::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_obj_appear_point_bridge */

} /* namespace DIS */
