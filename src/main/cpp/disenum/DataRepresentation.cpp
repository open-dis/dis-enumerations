#include <sstream>
#include <cstddef>
#include <disenum/DataRepresentation.h>

namespace DIS {


hashMap<int,DataRepresentation*> DataRepresentation::enumerations;

DataRepresentation DataRepresentation::TYPE_0(0, "Type 0");
DataRepresentation DataRepresentation::TYPE_1(1, "Type 1");
DataRepresentation DataRepresentation::TYPE_2(2, "Type 2");


DataRepresentation::DataRepresentation(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

DataRepresentation* DataRepresentation::findEnumeration(int aVal) {
  DataRepresentation* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string DataRepresentation::getDescriptionForValue(int aVal) {
  DataRepresentation* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

DataRepresentation DataRepresentation::getEnumerationForValue(int aVal) throw(EnumException) {
  DataRepresentation* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration DataRepresentation";
    throw EnumException("DataRepresentation", aVal, ss.str());
  }
};

bool DataRepresentation::enumerationForValueExists(int aVal) {
  DataRepresentation* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

DataRepresentation::enumContainer DataRepresentation::getEnumerations() {
  return (enumerations);
};

DataRepresentation& DataRepresentation::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

