#ifndef GROUPEDENTITYCATEGORY__H
#define GROUPEDENTITYCATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class GroupedEntityCategory : public Enumeration {
  public:
    static GroupedEntityCategory UNDEFINED;
    static GroupedEntityCategory BASIC_GROUND_COMBAT_VEHICLE;
    static GroupedEntityCategory ENHANCED_GROUND_COMBAT_VEHICLE;
    static GroupedEntityCategory BASIC_GROUND_COMBAT_SOLDIER;
    static GroupedEntityCategory ENHANCED_GROUND_COMBAT_SOLDIER;
    static GroupedEntityCategory BASIC_ROTOR_WING_AIRCRAFT;
    static GroupedEntityCategory ENHANCED_ROTOR_WING_AIRCRAFT;
    static GroupedEntityCategory BASIC_FIXED_WING_AIRCRAFT;
    static GroupedEntityCategory ENHANCED_FIXED_WING_AIRCRAFT;
    static GroupedEntityCategory GROUND_LOGISTICS_VEHICLE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static GroupedEntityCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,GroupedEntityCategory*> enumContainer;
    static enumContainer getEnumerations();

    GroupedEntityCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  GroupedEntityCategory(int value, std::string description);

	  static GroupedEntityCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* GroupedEntityCategory */


}  /* namespace DIS */

#endif /* GROUPEDENTITYCATEGORY__H */

