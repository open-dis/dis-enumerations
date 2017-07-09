#include <sstream>
#include <cstddef>
#include <disenum/entity_mine_paintscheme.h>

namespace DIS {

namespace entity_mine_paintscheme {

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
	 **  Algae implementation **
	 */

	hashMap<int,Algae*> Algae::enumerations;
	short Algae::startBit = 0;
	short Algae::endBit   = 1;

 Algae Algae::NONE(0, "None");
 Algae Algae::LIGHT(1, "Light");
 Algae Algae::MODERATE(2, "Moderate");
 Algae Algae::HEAVY(3, "Heavy");


	Algae::Algae(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Algae* Algae::findEnumeration(int aVal) {
	  Algae* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Algae::getDescriptionForValue(int aVal) {
	  Algae* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Algae Algae::getEnumerationForValue(int aVal) throw(EnumException) {
	  Algae* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Algae";
		throw EnumException("Algae", aVal, ss.str());
	  }
	};

	bool Algae::enumerationForValueExists(int aVal) {
	  Algae* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Algae::enumContainer Algae::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  PaintScheme implementation **
	 */

	hashMap<int,PaintScheme*> PaintScheme::enumerations;
	short PaintScheme::startBit = 2;
	short PaintScheme::endBit   = 7;

 PaintScheme PaintScheme::OTHER(0, "Other");
 PaintScheme PaintScheme::STANDARD(1, "Standard");
 PaintScheme PaintScheme::CAMOUFLAGE_DESERT(2, "Camouflage Desert");
 PaintScheme PaintScheme::CAMOUFLAGE_JUNGLE(3, "Camouflage Jungle");
 PaintScheme PaintScheme::CAMOUFLAGE_SNOW(4, "Camouflage Snow");
 PaintScheme PaintScheme::CAMOUFLAGE_GRAVEL(5, "Camouflage Gravel");
 PaintScheme PaintScheme::CAMOUFLAGE_PAVEMENT(6, "Camouflage Pavement");
 PaintScheme PaintScheme::CAMOUFLAGE_SAND(7, "Camouflage Sand");
 PaintScheme PaintScheme::NATURAL_WOOD(8, "Natural Wood");
 PaintScheme PaintScheme::CLEAR(9, "Clear");
 PaintScheme PaintScheme::RED(10, "Red");
 PaintScheme PaintScheme::BLUE(11, "Blue");
 PaintScheme PaintScheme::GREEN(12, "Green");
 PaintScheme PaintScheme::OLIVE(13, "Olive");
 PaintScheme PaintScheme::WHITE(14, "White");
 PaintScheme PaintScheme::TAN(15, "Tan");
 PaintScheme PaintScheme::BLACK(16, "Black");
 PaintScheme PaintScheme::YELLOW(17, "Yellow");
 PaintScheme PaintScheme::BROWN(18, "Brown");


	PaintScheme::PaintScheme(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	PaintScheme* PaintScheme::findEnumeration(int aVal) {
	  PaintScheme* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string PaintScheme::getDescriptionForValue(int aVal) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	PaintScheme PaintScheme::getEnumerationForValue(int aVal) throw(EnumException) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration PaintScheme";
		throw EnumException("PaintScheme", aVal, ss.str());
	  }
	};

	bool PaintScheme::enumerationForValueExists(int aVal) {
	  PaintScheme* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	PaintScheme::enumContainer PaintScheme::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace entity_mine_paintscheme */

} /* namespace DIS */
