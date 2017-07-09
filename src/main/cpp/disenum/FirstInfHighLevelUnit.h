#ifndef FIRSTINFHIGHLEVELUNIT__H
#define FIRSTINFHIGHLEVELUNIT__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class FirstInfHighLevelUnit : public Enumeration {
  public:
    static FirstInfHighLevelUnit X_1_16INF;
    static FirstInfHighLevelUnit X_2_16INF;
    static FirstInfHighLevelUnit X_1_34AR;
    static FirstInfHighLevelUnit X_2_34AR;
    static FirstInfHighLevelUnit X_3_37AR;
    static FirstInfHighLevelUnit X_4_37AR;
    static FirstInfHighLevelUnit X_1_118INF;
    static FirstInfHighLevelUnit X_4_118INF;
    static FirstInfHighLevelUnit X_2_265AR;
    static FirstInfHighLevelUnit X_2_136IF;
    static FirstInfHighLevelUnit X_1_5F;
    static FirstInfHighLevelUnit X_4_5F;
    static FirstInfHighLevelUnit X_1_178F;
    static FirstInfHighLevelUnit X_6F;
    static FirstInfHighLevelUnit X_25F;
    static FirstInfHighLevelUnit X_1E;
    static FirstInfHighLevelUnit X_70E;
    static FirstInfHighLevelUnit X_4_1AVN;
    static FirstInfHighLevelUnit X_1_1AVN;
    static FirstInfHighLevelUnit X_2_3ADA;
    static FirstInfHighLevelUnit X_1_4CAV;
    static FirstInfHighLevelUnit X_701MSB;
    static FirstInfHighLevelUnit X_101FSB;
    static FirstInfHighLevelUnit X_201FSB;
    static FirstInfHighLevelUnit X_163FSB;
    static FirstInfHighLevelUnit X_101MI;
    static FirstInfHighLevelUnit X_121S;
    static FirstInfHighLevelUnit X_1MP;
    static FirstInfHighLevelUnit X_12CML;
    static FirstInfHighLevelUnit X_1INF;
    static FirstInfHighLevelUnit XBDE;
    static FirstInfHighLevelUnit AVNBDE;
    static FirstInfHighLevelUnit E;
    static FirstInfHighLevelUnit F;
    static FirstInfHighLevelUnit DSC;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static FirstInfHighLevelUnit getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,FirstInfHighLevelUnit*> enumContainer;
    static enumContainer getEnumerations();

    FirstInfHighLevelUnit& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  FirstInfHighLevelUnit(int value, std::string description);

	  static FirstInfHighLevelUnit* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* FirstInfHighLevelUnit */


}  /* namespace DIS */

#endif /* FIRSTINFHIGHLEVELUNIT__H */

