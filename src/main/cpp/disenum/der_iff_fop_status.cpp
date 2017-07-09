#include <sstream>
#include <cstddef>
#include <disenum/der_iff_fop_status.h>

namespace DIS {

namespace der_iff_fop_status {

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
	 **  SystemOn_Off implementation **
	 */

	hashMap<int,SystemOn_Off*> SystemOn_Off::enumerations;
	short SystemOn_Off::startBit = 0;
	short SystemOn_Off::endBit   = 0;

 SystemOn_Off SystemOn_Off::OFF(0, "Off");
 SystemOn_Off SystemOn_Off::ON(1, "On");


	SystemOn_Off::SystemOn_Off(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	SystemOn_Off* SystemOn_Off::findEnumeration(int aVal) {
	  SystemOn_Off* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string SystemOn_Off::getDescriptionForValue(int aVal) {
	  SystemOn_Off* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	SystemOn_Off SystemOn_Off::getEnumerationForValue(int aVal) throw(EnumException) {
	  SystemOn_Off* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration SystemOn_Off";
		throw EnumException("SystemOn_Off", aVal, ss.str());
	  }
	};

	bool SystemOn_Off::enumerationForValueExists(int aVal) {
	  SystemOn_Off* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	SystemOn_Off::enumContainer SystemOn_Off::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter1 implementation **
	 */

	hashMap<int,Parameter1*> Parameter1::enumerations;
	short Parameter1::startBit = 1;
	short Parameter1::endBit   = 1;

 Parameter1 Parameter1::CAPABLE(0, "Capable");
 Parameter1 Parameter1::NOT_CAPABLE(1, "Not capable");


	Parameter1::Parameter1(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter1* Parameter1::findEnumeration(int aVal) {
	  Parameter1* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter1::getDescriptionForValue(int aVal) {
	  Parameter1* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter1 Parameter1::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter1";
		throw EnumException("Parameter1", aVal, ss.str());
	  }
	};

	bool Parameter1::enumerationForValueExists(int aVal) {
	  Parameter1* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter1::enumContainer Parameter1::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter2 implementation **
	 */

	hashMap<int,Parameter2*> Parameter2::enumerations;
	short Parameter2::startBit = 2;
	short Parameter2::endBit   = 2;

 Parameter2 Parameter2::CAPABLE(0, "Capable");
 Parameter2 Parameter2::NOT_CAPABLE(1, "Not capable");


	Parameter2::Parameter2(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter2* Parameter2::findEnumeration(int aVal) {
	  Parameter2* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter2::getDescriptionForValue(int aVal) {
	  Parameter2* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter2 Parameter2::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter2";
		throw EnumException("Parameter2", aVal, ss.str());
	  }
	};

	bool Parameter2::enumerationForValueExists(int aVal) {
	  Parameter2* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter2::enumContainer Parameter2::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter3 implementation **
	 */

	hashMap<int,Parameter3*> Parameter3::enumerations;
	short Parameter3::startBit = 3;
	short Parameter3::endBit   = 3;

 Parameter3 Parameter3::CAPABLE(0, "Capable");
 Parameter3 Parameter3::NOT_CAPABLE(1, "Not capable");


	Parameter3::Parameter3(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter3* Parameter3::findEnumeration(int aVal) {
	  Parameter3* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter3::getDescriptionForValue(int aVal) {
	  Parameter3* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter3 Parameter3::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter3* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter3";
		throw EnumException("Parameter3", aVal, ss.str());
	  }
	};

	bool Parameter3::enumerationForValueExists(int aVal) {
	  Parameter3* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter3::enumContainer Parameter3::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter4 implementation **
	 */

	hashMap<int,Parameter4*> Parameter4::enumerations;
	short Parameter4::startBit = 4;
	short Parameter4::endBit   = 4;

 Parameter4 Parameter4::CAPABLE(0, "Capable");
 Parameter4 Parameter4::NOT_CAPABLE(1, "Not capable");


	Parameter4::Parameter4(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter4* Parameter4::findEnumeration(int aVal) {
	  Parameter4* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter4::getDescriptionForValue(int aVal) {
	  Parameter4* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter4 Parameter4::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter4* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter4";
		throw EnumException("Parameter4", aVal, ss.str());
	  }
	};

	bool Parameter4::enumerationForValueExists(int aVal) {
	  Parameter4* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter4::enumContainer Parameter4::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter5 implementation **
	 */

	hashMap<int,Parameter5*> Parameter5::enumerations;
	short Parameter5::startBit = 5;
	short Parameter5::endBit   = 5;

 Parameter5 Parameter5::CAPABLE(0, "Capable");
 Parameter5 Parameter5::NOT_CAPABLE(1, "Not capable");


	Parameter5::Parameter5(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter5* Parameter5::findEnumeration(int aVal) {
	  Parameter5* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter5::getDescriptionForValue(int aVal) {
	  Parameter5* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter5 Parameter5::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter5* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter5";
		throw EnumException("Parameter5", aVal, ss.str());
	  }
	};

	bool Parameter5::enumerationForValueExists(int aVal) {
	  Parameter5* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter5::enumContainer Parameter5::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Parameter6 implementation **
	 */

	hashMap<int,Parameter6*> Parameter6::enumerations;
	short Parameter6::startBit = 6;
	short Parameter6::endBit   = 6;

 Parameter6 Parameter6::CAPABLE(0, "Capable");
 Parameter6 Parameter6::NOT_CAPABLE(1, "Not capable");


	Parameter6::Parameter6(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Parameter6* Parameter6::findEnumeration(int aVal) {
	  Parameter6* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Parameter6::getDescriptionForValue(int aVal) {
	  Parameter6* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Parameter6 Parameter6::getEnumerationForValue(int aVal) throw(EnumException) {
	  Parameter6* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Parameter6";
		throw EnumException("Parameter6", aVal, ss.str());
	  }
	};

	bool Parameter6::enumerationForValueExists(int aVal) {
	  Parameter6* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Parameter6::enumContainer Parameter6::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  OperationalStatus implementation **
	 */

	hashMap<int,OperationalStatus*> OperationalStatus::enumerations;
	short OperationalStatus::startBit = 7;
	short OperationalStatus::endBit   = 7;

 OperationalStatus OperationalStatus::OPERATIONAL(0, "Operational");
 OperationalStatus OperationalStatus::SYSTEM_FAILED(1, "System failed");


	OperationalStatus::OperationalStatus(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	OperationalStatus* OperationalStatus::findEnumeration(int aVal) {
	  OperationalStatus* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string OperationalStatus::getDescriptionForValue(int aVal) {
	  OperationalStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	OperationalStatus OperationalStatus::getEnumerationForValue(int aVal) throw(EnumException) {
	  OperationalStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration OperationalStatus";
		throw EnumException("OperationalStatus", aVal, ss.str());
	  }
	};

	bool OperationalStatus::enumerationForValueExists(int aVal) {
	  OperationalStatus* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	OperationalStatus::enumContainer OperationalStatus::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_iff_fop_status */

} /* namespace DIS */
