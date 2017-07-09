#ifndef LIFESUPPORTSYSTEMS__H
#define LIFESUPPORTSYSTEMS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class LifeSupportSystems : public Enumeration {
  public:
    static LifeSupportSystems AIR_SUPPLY;
    static LifeSupportSystems FILTERS;
    static LifeSupportSystems WATER_SUPPLY;
    static LifeSupportSystems REFRIGERATION_SYSTEM;
    static LifeSupportSystems CHEMICAL_BIOLOGICAL_AND_RADIOLOGICAL_PROTECTION;
    static LifeSupportSystems WATER_WASH_DOWN_SYSTEMS;
    static LifeSupportSystems DECONTAMINATION_SYSTEMS;
    static LifeSupportSystems MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static LifeSupportSystems getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,LifeSupportSystems*> enumContainer;
    static enumContainer getEnumerations();

    LifeSupportSystems& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  LifeSupportSystems(int value, std::string description);

	  static LifeSupportSystems* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* LifeSupportSystems */


}  /* namespace DIS */

#endif /* LIFESUPPORTSYSTEMS__H */

