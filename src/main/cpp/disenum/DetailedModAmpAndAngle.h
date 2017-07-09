#ifndef DETAILEDMODAMPANDANGLE__H
#define DETAILEDMODAMPANDANGLE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DetailedModAmpAndAngle : public Enumeration {
  public:
    static DetailedModAmpAndAngle OTHER;
    static DetailedModAmpAndAngle AMPLITUDE_AND_ANGLE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DetailedModAmpAndAngle getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DetailedModAmpAndAngle*> enumContainer;
    static enumContainer getEnumerations();

    DetailedModAmpAndAngle& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DetailedModAmpAndAngle(int value, std::string description);

	  static DetailedModAmpAndAngle* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DetailedModAmpAndAngle */


}  /* namespace DIS */

#endif /* DETAILEDMODAMPANDANGLE__H */

