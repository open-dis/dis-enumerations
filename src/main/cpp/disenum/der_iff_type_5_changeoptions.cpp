#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_5_changeoptions.h>

namespace DIS {

namespace der_iff_type_5_changeoptions {

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
	 **  ChangeIndicator implementation **
	 */

	hashMap<int,ChangeIndicator*> ChangeIndicator::enumerations;
	short ChangeIndicator::startBit = 0;
	short ChangeIndicator::endBit   = 0;

 ChangeIndicator ChangeIndicator::NO_CHANGE_SINCE_LAST_REPORT(0, "No change since last report");
 ChangeIndicator ChangeIndicator::INITIAL_REPORT_OR_CHANGE_SINCE_LAST_REPORT(1, "Initial report or change since last report");


	ChangeIndicator::ChangeIndicator(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ChangeIndicator* ChangeIndicator::findEnumeration(int aVal) {
	  ChangeIndicator* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ChangeIndicator::getDescriptionForValue(int aVal) {
	  ChangeIndicator* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ChangeIndicator ChangeIndicator::getEnumerationForValue(int aVal) throw(EnumException) {
	  ChangeIndicator* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ChangeIndicator";
		throw EnumException("ChangeIndicator", aVal, ss.str());
	  }
	};

	bool ChangeIndicator::enumerationForValueExists(int aVal) {
	  ChangeIndicator* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ChangeIndicator::enumContainer ChangeIndicator::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace der_iff_type_5_changeoptions */

} /* namespace DIS */
