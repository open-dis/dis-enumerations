#include <sstream>
#include <cstddef>
#include <disenum/entity_mine_datafilter.h>

namespace DIS {

namespace entity_mine_datafilter {

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
	 **  GroundBurialDepthOffset implementation **
	 */

	hashMap<int,GroundBurialDepthOffset*> GroundBurialDepthOffset::enumerations;
	short GroundBurialDepthOffset::startBit = 0;
	short GroundBurialDepthOffset::endBit   = 0;

 GroundBurialDepthOffset GroundBurialDepthOffset::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 GroundBurialDepthOffset GroundBurialDepthOffset::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	GroundBurialDepthOffset::GroundBurialDepthOffset(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	GroundBurialDepthOffset* GroundBurialDepthOffset::findEnumeration(int aVal) {
	  GroundBurialDepthOffset* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string GroundBurialDepthOffset::getDescriptionForValue(int aVal) {
	  GroundBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	GroundBurialDepthOffset GroundBurialDepthOffset::getEnumerationForValue(int aVal) throw(EnumException) {
	  GroundBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration GroundBurialDepthOffset";
		throw EnumException("GroundBurialDepthOffset", aVal, ss.str());
	  }
	};

	bool GroundBurialDepthOffset::enumerationForValueExists(int aVal) {
	  GroundBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	GroundBurialDepthOffset::enumContainer GroundBurialDepthOffset::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  WaterBurialDepthOffset implementation **
	 */

	hashMap<int,WaterBurialDepthOffset*> WaterBurialDepthOffset::enumerations;
	short WaterBurialDepthOffset::startBit = 1;
	short WaterBurialDepthOffset::endBit   = 1;

 WaterBurialDepthOffset WaterBurialDepthOffset::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 WaterBurialDepthOffset WaterBurialDepthOffset::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	WaterBurialDepthOffset::WaterBurialDepthOffset(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	WaterBurialDepthOffset* WaterBurialDepthOffset::findEnumeration(int aVal) {
	  WaterBurialDepthOffset* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string WaterBurialDepthOffset::getDescriptionForValue(int aVal) {
	  WaterBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	WaterBurialDepthOffset WaterBurialDepthOffset::getEnumerationForValue(int aVal) throw(EnumException) {
	  WaterBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration WaterBurialDepthOffset";
		throw EnumException("WaterBurialDepthOffset", aVal, ss.str());
	  }
	};

	bool WaterBurialDepthOffset::enumerationForValueExists(int aVal) {
	  WaterBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	WaterBurialDepthOffset::enumContainer WaterBurialDepthOffset::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  SnowBurialDepthOffset implementation **
	 */

	hashMap<int,SnowBurialDepthOffset*> SnowBurialDepthOffset::enumerations;
	short SnowBurialDepthOffset::startBit = 2;
	short SnowBurialDepthOffset::endBit   = 2;

 SnowBurialDepthOffset SnowBurialDepthOffset::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 SnowBurialDepthOffset SnowBurialDepthOffset::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	SnowBurialDepthOffset::SnowBurialDepthOffset(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	SnowBurialDepthOffset* SnowBurialDepthOffset::findEnumeration(int aVal) {
	  SnowBurialDepthOffset* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string SnowBurialDepthOffset::getDescriptionForValue(int aVal) {
	  SnowBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	SnowBurialDepthOffset SnowBurialDepthOffset::getEnumerationForValue(int aVal) throw(EnumException) {
	  SnowBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration SnowBurialDepthOffset";
		throw EnumException("SnowBurialDepthOffset", aVal, ss.str());
	  }
	};

	bool SnowBurialDepthOffset::enumerationForValueExists(int aVal) {
	  SnowBurialDepthOffset* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	SnowBurialDepthOffset::enumContainer SnowBurialDepthOffset::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  MineOrientation implementation **
	 */

	hashMap<int,MineOrientation*> MineOrientation::enumerations;
	short MineOrientation::startBit = 3;
	short MineOrientation::endBit   = 3;

 MineOrientation MineOrientation::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 MineOrientation MineOrientation::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	MineOrientation::MineOrientation(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	MineOrientation* MineOrientation::findEnumeration(int aVal) {
	  MineOrientation* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string MineOrientation::getDescriptionForValue(int aVal) {
	  MineOrientation* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	MineOrientation MineOrientation::getEnumerationForValue(int aVal) throw(EnumException) {
	  MineOrientation* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration MineOrientation";
		throw EnumException("MineOrientation", aVal, ss.str());
	  }
	};

	bool MineOrientation::enumerationForValueExists(int aVal) {
	  MineOrientation* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	MineOrientation::enumContainer MineOrientation::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ThermalContrast implementation **
	 */

	hashMap<int,ThermalContrast*> ThermalContrast::enumerations;
	short ThermalContrast::startBit = 4;
	short ThermalContrast::endBit   = 4;

 ThermalContrast ThermalContrast::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 ThermalContrast ThermalContrast::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	ThermalContrast::ThermalContrast(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ThermalContrast* ThermalContrast::findEnumeration(int aVal) {
	  ThermalContrast* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ThermalContrast::getDescriptionForValue(int aVal) {
	  ThermalContrast* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ThermalContrast ThermalContrast::getEnumerationForValue(int aVal) throw(EnumException) {
	  ThermalContrast* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ThermalContrast";
		throw EnumException("ThermalContrast", aVal, ss.str());
	  }
	};

	bool ThermalContrast::enumerationForValueExists(int aVal) {
	  ThermalContrast* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ThermalContrast::enumContainer ThermalContrast::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Reflectance implementation **
	 */

	hashMap<int,Reflectance*> Reflectance::enumerations;
	short Reflectance::startBit = 5;
	short Reflectance::endBit   = 5;

 Reflectance Reflectance::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 Reflectance Reflectance::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	Reflectance::Reflectance(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Reflectance* Reflectance::findEnumeration(int aVal) {
	  Reflectance* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Reflectance::getDescriptionForValue(int aVal) {
	  Reflectance* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Reflectance Reflectance::getEnumerationForValue(int aVal) throw(EnumException) {
	  Reflectance* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Reflectance";
		throw EnumException("Reflectance", aVal, ss.str());
	  }
	};

	bool Reflectance::enumerationForValueExists(int aVal) {
	  Reflectance* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Reflectance::enumContainer Reflectance::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  MineEmplacementAge implementation **
	 */

	hashMap<int,MineEmplacementAge*> MineEmplacementAge::enumerations;
	short MineEmplacementAge::startBit = 6;
	short MineEmplacementAge::endBit   = 6;

 MineEmplacementAge MineEmplacementAge::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 MineEmplacementAge MineEmplacementAge::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	MineEmplacementAge::MineEmplacementAge(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	MineEmplacementAge* MineEmplacementAge::findEnumeration(int aVal) {
	  MineEmplacementAge* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string MineEmplacementAge::getDescriptionForValue(int aVal) {
	  MineEmplacementAge* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	MineEmplacementAge MineEmplacementAge::getEnumerationForValue(int aVal) throw(EnumException) {
	  MineEmplacementAge* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration MineEmplacementAge";
		throw EnumException("MineEmplacementAge", aVal, ss.str());
	  }
	};

	bool MineEmplacementAge::enumerationForValueExists(int aVal) {
	  MineEmplacementAge* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	MineEmplacementAge::enumContainer MineEmplacementAge::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Trip_DetonationWire implementation **
	 */

	hashMap<int,Trip_DetonationWire*> Trip_DetonationWire::enumerations;
	short Trip_DetonationWire::startBit = 7;
	short Trip_DetonationWire::endBit   = 7;

 Trip_DetonationWire Trip_DetonationWire::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 Trip_DetonationWire Trip_DetonationWire::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	Trip_DetonationWire::Trip_DetonationWire(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Trip_DetonationWire* Trip_DetonationWire::findEnumeration(int aVal) {
	  Trip_DetonationWire* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Trip_DetonationWire::getDescriptionForValue(int aVal) {
	  Trip_DetonationWire* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Trip_DetonationWire Trip_DetonationWire::getEnumerationForValue(int aVal) throw(EnumException) {
	  Trip_DetonationWire* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Trip_DetonationWire";
		throw EnumException("Trip_DetonationWire", aVal, ss.str());
	  }
	};

	bool Trip_DetonationWire::enumerationForValueExists(int aVal) {
	  Trip_DetonationWire* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Trip_DetonationWire::enumContainer Trip_DetonationWire::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  Fusing implementation **
	 */

	hashMap<int,Fusing*> Fusing::enumerations;
	short Fusing::startBit = 8;
	short Fusing::endBit   = 8;

 Fusing Fusing::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 Fusing Fusing::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	Fusing::Fusing(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	Fusing* Fusing::findEnumeration(int aVal) {
	  Fusing* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string Fusing::getDescriptionForValue(int aVal) {
	  Fusing* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	Fusing Fusing::getEnumerationForValue(int aVal) throw(EnumException) {
	  Fusing* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration Fusing";
		throw EnumException("Fusing", aVal, ss.str());
	  }
	};

	bool Fusing::enumerationForValueExists(int aVal) {
	  Fusing* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	Fusing::enumContainer Fusing::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  ScalarDetectionCoefficient implementation **
	 */

	hashMap<int,ScalarDetectionCoefficient*> ScalarDetectionCoefficient::enumerations;
	short ScalarDetectionCoefficient::startBit = 9;
	short ScalarDetectionCoefficient::endBit   = 9;

 ScalarDetectionCoefficient ScalarDetectionCoefficient::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 ScalarDetectionCoefficient ScalarDetectionCoefficient::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


	ScalarDetectionCoefficient::ScalarDetectionCoefficient(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	ScalarDetectionCoefficient* ScalarDetectionCoefficient::findEnumeration(int aVal) {
	  ScalarDetectionCoefficient* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string ScalarDetectionCoefficient::getDescriptionForValue(int aVal) {
	  ScalarDetectionCoefficient* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	ScalarDetectionCoefficient ScalarDetectionCoefficient::getEnumerationForValue(int aVal) throw(EnumException) {
	  ScalarDetectionCoefficient* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration ScalarDetectionCoefficient";
		throw EnumException("ScalarDetectionCoefficient", aVal, ss.str());
	  }
	};

	bool ScalarDetectionCoefficient::enumerationForValueExists(int aVal) {
	  ScalarDetectionCoefficient* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	ScalarDetectionCoefficient::enumContainer ScalarDetectionCoefficient::getEnumerations() {
	  return (enumerations);
	};


	/*
	 **  PaintScheme implementation **
	 */

	hashMap<int,PaintScheme*> PaintScheme::enumerations;
	short PaintScheme::startBit = 10;
	short PaintScheme::endBit   = 10;

 PaintScheme PaintScheme::DATA_NOT_REQUESTED_PRESENT(0, "Data not requested / present");
 PaintScheme PaintScheme::DATA_IS_REQUESTED_PRESENT(1, "Data is requested / present");


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





}; /* namespace entity_mine_datafilter */

} /* namespace DIS */
