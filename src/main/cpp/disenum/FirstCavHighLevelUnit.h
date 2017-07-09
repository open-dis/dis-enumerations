#ifndef FIRSTCAVHIGHLEVELUNIT__H
#define FIRSTCAVHIGHLEVELUNIT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class FirstCavHighLevelUnit : public Enumeration {
  public:
    static FirstCavHighLevelUnit X_1_7CAV;
    static FirstCavHighLevelUnit X_2_5CAV;
    static FirstCavHighLevelUnit X_2_8CAV;
    static FirstCavHighLevelUnit X_3_32AR;
    static FirstCavHighLevelUnit X_1_5CAV;
    static FirstCavHighLevelUnit X_1_8CAV;
    static FirstCavHighLevelUnit X_1_32AR;
    static FirstCavHighLevelUnit X_1_67AR;
    static FirstCavHighLevelUnit X_3_67AR;
    static FirstCavHighLevelUnit X_3_41INF;
    static FirstCavHighLevelUnit X_1_82F;
    static FirstCavHighLevelUnit X_3_82F;
    static FirstCavHighLevelUnit X_1_3F;
    static FirstCavHighLevelUnit X_21F;
    static FirstCavHighLevelUnit X_92F;
    static FirstCavHighLevelUnit X_8E;
    static FirstCavHighLevelUnit X_20E;
    static FirstCavHighLevelUnit X_91E;
    static FirstCavHighLevelUnit X_1_227AVN;
    static FirstCavHighLevelUnit X_4_227AVN;
    static FirstCavHighLevelUnit F_227AVN;
    static FirstCavHighLevelUnit X_4_5ADA;
    static FirstCavHighLevelUnit X_15MSB;
    static FirstCavHighLevelUnit X_27FSB;
    static FirstCavHighLevelUnit X_115FSB;
    static FirstCavHighLevelUnit X_215FSB;
    static FirstCavHighLevelUnit X_312MI;
    static FirstCavHighLevelUnit X_13S;
    static FirstCavHighLevelUnit X_545MP;
    static FirstCavHighLevelUnit X_68CML;
    static FirstCavHighLevelUnit X_1CAV;
    static FirstCavHighLevelUnit XBDE;
    static FirstCavHighLevelUnit AVNBDE;
    static FirstCavHighLevelUnit E;
    static FirstCavHighLevelUnit F;
    static FirstCavHighLevelUnit DSC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static FirstCavHighLevelUnit getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,FirstCavHighLevelUnit*> enumContainer;
    static enumContainer getEnumerations();

    FirstCavHighLevelUnit& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  FirstCavHighLevelUnit(int value, std::string description);

	  static FirstCavHighLevelUnit* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* FirstCavHighLevelUnit */


}  /* namespace DIS */

#endif /* FIRSTCAVHIGHLEVELUNIT__H */

