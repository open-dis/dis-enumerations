#include <sstream>
#include <cstddef>
#include <disenum/entity_mine_fusing.h>

namespace DIS {

namespace entity_mine_fusing {

  bitmask& bitmask::operator=(const unsigned short& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned short*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned short& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned short) 0;
  }

  unsigned short bitmask::getValue(){
    unsigned short val = *( reinterpret_cast<unsigned short *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned short& i){
	  (*this) = i;
  }

	/*
	 **  Primary implementation **
	 */

	hashMap<int,Primary*> Primary::enumerations;
	short Primary::startBit = 0;
	short Primary::endBit   = 6;

 Primary Primary::NO_FUSE(0, "No Fuse");
 Primary Primary::OTHER(1, "Other");
 Primary Primary::PRESSURE(2, "Pressure");
 Primary Primary::MAGNETIC(3, "Magnetic");
 Primary Primary::TILT_ROD(4, "Tilt Rod");
 Primary Primary::COMMAND(5, "Command");
 Primary Primary::TRIP_WIRE(6, "Trip Wire");


	Primary::Primary(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Primary* Primary::findEnumeration(int aVal) {
	  Primary* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Primary::getDescriptionForValue(int aVal) {
	  Primary* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Primary Primary::getEnumerationForValue(int aVal) throw(EnumException) {
	  Primary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Primary";
		throw EnumException("Primary", aVal, ss.str());
	  }
	};

	bool Primary::enumerationForValueExists(int aVal) {
	  Primary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Primary::enumContainer Primary::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Secondary implementation **
	 */

	hashMap<int,Secondary*> Secondary::enumerations;
	short Secondary::startBit = 7;
	short Secondary::endBit   = 13;

 Secondary Secondary::NO_FUSE(0, "No Fuse");
 Secondary Secondary::OTHER(1, "Other");
 Secondary Secondary::PRESSURE(2, "Pressure");
 Secondary Secondary::MAGNETIC(3, "Magnetic");
 Secondary Secondary::TILT_ROD(4, "Tilt Rod");
 Secondary Secondary::COMMAND(5, "Command");
 Secondary Secondary::TRIP_WIRE(6, "Trip Wire");


	Secondary::Secondary(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Secondary* Secondary::findEnumeration(int aVal) {
	  Secondary* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Secondary::getDescriptionForValue(int aVal) {
	  Secondary* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Secondary Secondary::getEnumerationForValue(int aVal) throw(EnumException) {
	  Secondary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Secondary";
		throw EnumException("Secondary", aVal, ss.str());
	  }
	};

	bool Secondary::enumerationForValueExists(int aVal) {
	  Secondary* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Secondary::enumContainer Secondary::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  AHD implementation **
	 */

	hashMap<int,AHD*> AHD::enumerations;
	short AHD::startBit = 4;
	short AHD::endBit   = 4;

 AHD AHD::NO_ANTI_HANDLING_DEVICE(0, "No anti-handling device");
 AHD AHD::ANTI_HANDLING_DEVICE(1, "Anti-handling device");


	AHD::AHD(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	AHD* AHD::findEnumeration(int aVal) {
	  AHD* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string AHD::getDescriptionForValue(int aVal) {
	  AHD* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	AHD AHD::getEnumerationForValue(int aVal) throw(EnumException) {
	  AHD* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration AHD";
		throw EnumException("AHD", aVal, ss.str());
	  }
	};

	bool AHD::enumerationForValueExists(int aVal) {
	  AHD* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	AHD::enumContainer AHD::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace entity_mine_fusing */

} /* namespace DIS */
