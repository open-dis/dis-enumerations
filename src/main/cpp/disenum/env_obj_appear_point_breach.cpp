#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_point_breach.h>

namespace DIS {

namespace env_obj_appear_point_breach {

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
 Breach Breach::BREACHED(1, "Breached");
 Breach Breach::CLEARED(2, "Cleared");


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





}; /* namespace env_obj_appear_point_breach */

} /* namespace DIS */
