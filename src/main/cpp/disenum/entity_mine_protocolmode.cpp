#include <sstream>
#include <cstddef>
#include <disenum/entity_mine_protocolmode.h>

namespace DIS {

namespace entity_mine_protocolmode {

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
	 **  ProtocolMode implementation **
	 */

	hashMap<int,ProtocolMode*> ProtocolMode::enumerations;
	short ProtocolMode::startBit = 0;
	short ProtocolMode::endBit   = 1;

 ProtocolMode ProtocolMode::HEARTBEAT_MODE(0, "Heartbeat mode");
 ProtocolMode ProtocolMode::QRP_MODE(1, "QRP mode");


	ProtocolMode::ProtocolMode(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ProtocolMode* ProtocolMode::findEnumeration(int aVal) {
	  ProtocolMode* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ProtocolMode::getDescriptionForValue(int aVal) {
	  ProtocolMode* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ProtocolMode ProtocolMode::getEnumerationForValue(int aVal) throw(EnumException) {
	  ProtocolMode* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ProtocolMode";
		throw EnumException("ProtocolMode", aVal, ss.str());
	  }
	};

	bool ProtocolMode::enumerationForValueExists(int aVal) {
	  ProtocolMode* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ProtocolMode::enumContainer ProtocolMode::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace entity_mine_protocolmode */

} /* namespace DIS */
