#include <sstream>
#include <cstddef>
#include <disenum/TransferType.h>

namespace DIS {


hashMap<int,TransferType*> TransferType::enumerations;

TransferType TransferType::OTHER(0, "Other");
TransferType TransferType::CONTROLLING_APPLICATION_REQUESTS_TRANSFER_OF_AN_ENTITY(1, "Controlling application requests transfer of an entity");
TransferType TransferType::APPLICATION_DESIRING_CONTROL_REQUESTS_TRANSFER_OF_AN_ENTITY(2, "Application desiring control requests transfer of an entity");
TransferType TransferType::MUTUAL_EXCHANGE_SWAP_OF_AN_ENTITY(3, "Mutual exchange / swap of an entity");
TransferType TransferType::CONTROLLING_APPLICATION_REQUESTS_TRANSFER_OF_AN_ENVIRONMENTAL_PROCESS(4, "Controlling application requests transfer of an environmental process");
TransferType TransferType::APPLICATION_DESIRING_CONTROLS_REQUESTS_TRANSFER_OF_AN_ENVIRONMENTAL_PROCESS(5, "Application desiring controls requests transfer of an environmental process");
TransferType TransferType::MUTUAL_EXCHANGE_SWAP_OF_AN_ENVIRONMENTAL(6, "Mutual exchange / swap of an environmental");
TransferType TransferType::CANCEL_TRANSFER(7, "Cancel transfer");


TransferType::TransferType(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

TransferType* TransferType::findEnumeration(int aVal) {
  TransferType* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string TransferType::getDescriptionForValue(int aVal) {
  TransferType* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

TransferType TransferType::getEnumerationForValue(int aVal) throw(EnumException) {
  TransferType* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration TransferType";
    throw EnumException("TransferType", aVal, ss.str());
  }
};

bool TransferType::enumerationForValueExists(int aVal) {
  TransferType* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

TransferType::enumContainer TransferType::getEnumerations() {
  return (enumerations);
};

TransferType& TransferType::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

