#include <sstream>
#include <cstddef>
#include <disenum/InputSource.h>

namespace DIS {


hashMap<int,InputSource*> InputSource::enumerations;

InputSource InputSource::OTHER(0, "Other");
InputSource InputSource::PILOT(1, "Pilot");
InputSource InputSource::COPILOT(2, "Copilot");
InputSource InputSource::FIRST_OFFICER(3, "First Officer");
InputSource InputSource::DRIVER(4, "Driver");
InputSource InputSource::LOADER(5, "Loader");
InputSource InputSource::GUNNER(6, "Gunner");
InputSource InputSource::COMMANDER(7, "Commander");
InputSource InputSource::DIGITAL_DATA_DEVICE(8, "Digital Data Device");
InputSource InputSource::INTERCOM(9, "Intercom");


InputSource::InputSource(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

InputSource* InputSource::findEnumeration(int aVal) {
  InputSource* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string InputSource::getDescriptionForValue(int aVal) {
  InputSource* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

InputSource InputSource::getEnumerationForValue(int aVal) throw(EnumException) {
  InputSource* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration InputSource";
    throw EnumException("InputSource", aVal, ss.str());
  }
};

bool InputSource::enumerationForValueExists(int aVal) {
  InputSource* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

InputSource::enumContainer InputSource::getEnumerations() {
  return (enumerations);
};

InputSource& InputSource::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

