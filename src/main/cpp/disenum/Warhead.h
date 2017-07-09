#ifndef WARHEAD__H
#define WARHEAD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class Warhead : public Enumeration {
  public:
    static Warhead OTHER;
    static Warhead CARGO_VARIABLE_SUBMUNITIONS;
    static Warhead FUEL_AIR_EXPLOSIVE;
    static Warhead GLASS_BEADS;
    static Warhead X_1_UM;
    static Warhead X_5_UM;
    static Warhead X_10_UM;
    static Warhead HIGH_EXPLOSIVE_HE;
    static Warhead HE_PLASTIC;
    static Warhead HE_INCENDIARY;
    static Warhead HE_FRAGMENTATION;
    static Warhead HE_ANTITANK;
    static Warhead HE_BOMBLETS;
    static Warhead HE_SHAPED_CHARGE;
    static Warhead HE_CONTINUOUS_ROD;
    static Warhead HE_TUNGSTEN_BALL;
    static Warhead HE_BLAST_FRAGMENTATION;
    static Warhead HE_STEERABLE_DARTS_WITH_HE;
    static Warhead HE_DARTS;
    static Warhead HE_FLECHETTES;
    static Warhead HE_DIRECTED_FRAGMENTATION;
    static Warhead HE_SEMI_ARMOR_PIERCING_SAP;
    static Warhead HE_SHAPED_CHARGE_FRAGMENTATION;
    static Warhead HE_SEMI_ARMOR_PIERCING_FRAGMENTATION;
    static Warhead HE_HOLLOW_CHARGE;
    static Warhead HE_DOUBLE_HOLLOW_CHARGE;
    static Warhead HE_GENERAL_PURPOSE;
    static Warhead HE_BLAST_PENETRATOR;
    static Warhead HE_ROD_PENETRATOR;
    static Warhead HE_ANTIPERSONNEL;
    static Warhead SMOKE;
    static Warhead ILLUMINATION;
    static Warhead PRACTICE;
    static Warhead KINETIC;
    static Warhead MINES;
    static Warhead NUCLEAR;
    static Warhead NUCLEAR_IMT;
    static Warhead CHEMICAL_GENERAL;
    static Warhead CHEMICAL_BLISTER_AGENT;
    static Warhead HD_MUSTARD;
    static Warhead THICKENED_HD_MUSTARD;
    static Warhead DUSTY_HD_MUSTARD;
    static Warhead CHEMICAL_BLOOD_AGENT;
    static Warhead AC_HCN;
    static Warhead CK_CNCI;
    static Warhead CG_PHOSGENE;
    static Warhead CHEMICAL_NERVE_AGENT;
    static Warhead VX;
    static Warhead THICKENED_VX;
    static Warhead DUSTY_VX;
    static Warhead GA_TABUN;
    static Warhead THICKENED_GA_TABUN;
    static Warhead DUSTY_GA_TABUN;
    static Warhead GB_SARIN;
    static Warhead THICKENED_GB_SARIN;
    static Warhead DUSTY_GB_SARIN;
    static Warhead GD_SOMAN;
    static Warhead THICKENED_GD_SOMAN;
    static Warhead DUSTY_GD_SOMAN;
    static Warhead GF;
    static Warhead THICKENED_GF;
    static Warhead DUSTY_GF;
    static Warhead BIOLOGICAL;
    static Warhead BIOLOGICAL_VIRUS;
    static Warhead BIOLOGICAL_BACTERIA;
    static Warhead BIOLOGICAL_RICKETTSIA;
    static Warhead BIOLOGICAL_GENETICALLY_MODIFIED_MICRO_ORGANISMS;
    static Warhead BIOLOGICAL_TOXIN;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static Warhead getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,Warhead*> enumContainer;
    static enumContainer getEnumerations();

    Warhead& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  Warhead(int value, std::string description);

	  static Warhead* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* Warhead */


}  /* namespace DIS */

#endif /* WARHEAD__H */

