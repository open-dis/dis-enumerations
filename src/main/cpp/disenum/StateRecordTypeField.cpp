#include <sstream>
#include <cstddef>
#include <disenum/StateRecordTypeField.h>

namespace DIS {


hashMap<int,StateRecordTypeField*> StateRecordTypeField::enumerations;

StateRecordTypeField StateRecordTypeField::COMBIC_STATE(256, "COMBIC State");
StateRecordTypeField StateRecordTypeField::FLARE_STATE(259, "Flare State");


StateRecordTypeField::StateRecordTypeField(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

StateRecordTypeField* StateRecordTypeField::findEnumeration(int aVal) {
  StateRecordTypeField* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string StateRecordTypeField::getDescriptionForValue(int aVal) {
  StateRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

StateRecordTypeField StateRecordTypeField::getEnumerationForValue(int aVal) throw(EnumException) {
  StateRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration StateRecordTypeField";
    throw EnumException("StateRecordTypeField", aVal, ss.str());
  }
};

bool StateRecordTypeField::enumerationForValueExists(int aVal) {
  StateRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

StateRecordTypeField::enumContainer StateRecordTypeField::getEnumerations() {
  return (enumerations);
};

StateRecordTypeField& StateRecordTypeField::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

