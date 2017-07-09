#ifndef DEADRECKONINGALGORITHM__H
#define DEADRECKONINGALGORITHM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DeadReckoningAlgorithm : public Enumeration {
  public:
    static DeadReckoningAlgorithm OTHER;
    static DeadReckoningAlgorithm STATIC_ENTITY_DOES_NOT_MOVE;
    static DeadReckoningAlgorithm DRMF_P_W;
    static DeadReckoningAlgorithm DRMR_P_W;
    static DeadReckoningAlgorithm DRMR_V_W;
    static DeadReckoningAlgorithm DRMF_V_W;
    static DeadReckoningAlgorithm DRMF_P_B;
    static DeadReckoningAlgorithm DRMR_P_B;
    static DeadReckoningAlgorithm DRMR_V_B;
    static DeadReckoningAlgorithm DRMF_V_B;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DeadReckoningAlgorithm getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DeadReckoningAlgorithm*> enumContainer;
    static enumContainer getEnumerations();

    DeadReckoningAlgorithm& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DeadReckoningAlgorithm(int value, std::string description);

	  static DeadReckoningAlgorithm* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DeadReckoningAlgorithm */


}  /* namespace DIS */

#endif /* DEADRECKONINGALGORITHM__H */

