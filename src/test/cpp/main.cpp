#include <iostream>
#include <cassert>

#include <disenum/PduType.h>
#include <disenum/CountryType.h>
#include <disenum/es_appear_platform_land.h>


int main()
{
  std::cout << "***** Standard enumerations test *****\n";
  DIS::PduType espdu = DIS::PduType::ENTITY_STATE;
  assert(espdu.getDescription() == "Entity State");
  assert(espdu.getValue() == 1);

  DIS::CountryType us = DIS::CountryType::UNITED_STATES;
  assert(us.getDescription() == "United States");
  assert(us.getValue() ==  225);
  assert(us.getInternetDomainCode() == "US");

  espdu = 2;
  std::cout << "espdu: " << espdu << ", value: " << espdu.getValue() << std::endl;
  std::cout << "us: " << us << ", value: " << us.getValue() << ", internet code: " << us.getInternetDomainCode() << std::endl;

  DIS::PduType::enumContainer hMap(DIS::PduType::getEnumerations());
  DIS::PduType::enumContainer::const_iterator hMapIter;
  for (hMapIter = hMap.begin(); hMapIter != hMap.end(); hMapIter++){
    int enumValue = hMapIter->first;
    espdu = *(hMapIter->second);
    std::cout << enumValue << ": " << espdu << std::endl;
  }

  std::cout << "The next line should generate an exception... " << std::endl;
  try {
    espdu = 2048;
    std::cout << ":-( Exception not thrown.... " << std::endl;
  }
  catch (DIS::EnumException e) {
    std::cout << "YES! Caught exception: " << e.what() << std::endl;
  }

  std::cout << "***** Bitmask enumerations test *****\n";
  namespace land = DIS::es_appear_platform_land;
  land::Smoke smokeStatus = land::Smoke::NOT_SMOKING;

  assert(smokeStatus.getDescription() == "Not smoking");
  assert(smokeStatus.getValue() == 0);
  assert(smokeStatus.getStartBit() == 5);
  assert(smokeStatus.getEndBit() == 6);

  std::cout << "smokeStatus: " << smokeStatus << ", value: " << smokeStatus.getValue()
    << ", [startBit,endBit]: [" << land::Smoke::getStartBit() << ", "
    << land::Smoke::getEndBit() << "]" <<std::endl;


  land::Smoke::enumContainer bmHMap(land::Smoke::getEnumerations());
  land::Smoke::enumContainer::const_iterator bmHMapIter;
  for (bmHMapIter = bmHMap.begin(); bmHMapIter != bmHMap.end(); bmHMapIter++){
    int enumValue = bmHMapIter->first;
    smokeStatus = *(bmHMapIter->second);
    std::cout << enumValue << ": " << smokeStatus << std::endl;
  }

  int appearance = 1;
  land::bitmask bitfield = appearance;
  bitfield.Smoke = 5555; //this will produce warning: "large integer implicitly truncated to unsigned type"
  bitfield.Hatch = land::Hatch::PRIMARY_HATCH_IS_CLOSED.getValue();

  std::cout << "size: " << sizeof(bitfield) << std::endl;

  std::cout << "smoke: " << bitfield.Smoke << " paintScheme: " << bitfield.PaintScheme
    << " masked/cloaked: " << bitfield.Masked_Cloaked
    << std::endl;

  appearance = bitfield.getValue();
  std::cout << "appearance: " << appearance << std::endl;

  return 0;
}
