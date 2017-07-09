#include <sstream>
#include <cstddef>
#include <disenum/env_obj_mod_areal.h>

namespace DIS {

namespace env_obj_mod_areal {

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
	 **  Location implementation **
	 */

	hashMap<int,Location*> Location::enumerations;
	short Location::startBit = 0;
	short Location::endBit   = 0;

 Location Location::NO_LOCATIONS_HAVE_BEEN_MODIFIED(0, "No locations have been modified");
 Location Location::LOCATIONS_HAVE_BEEN_MODIFIED(1, "Locations have been modified");


	Location::Location(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Location* Location::findEnumeration(int aVal) {
	  Location* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Location::getDescriptionForValue(int aVal) {
	  Location* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Location Location::getEnumerationForValue(int aVal) throw(EnumException) {
	  Location* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Location";
		throw EnumException("Location", aVal, ss.str());
	  }
	};

	bool Location::enumerationForValueExists(int aVal) {
	  Location* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Location::enumContainer Location::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_obj_mod_areal */

} /* namespace DIS */
