#ifndef EXPENDABLESURFACECATEGORY__H
#define EXPENDABLESURFACECATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ExpendableSurfaceCategory : public Enumeration {
  public:
    static ExpendableSurfaceCategory OTHER;
    static ExpendableSurfaceCategory FLARE;
    static ExpendableSurfaceCategory ACTIVE_EMITTER;
    static ExpendableSurfaceCategory PASSIVE_DECOY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ExpendableSurfaceCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ExpendableSurfaceCategory*> enumContainer;
    static enumContainer getEnumerations();

    ExpendableSurfaceCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ExpendableSurfaceCategory(int value, std::string description);

	  static ExpendableSurfaceCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ExpendableSurfaceCategory */


}  /* namespace DIS */

#endif /* EXPENDABLESURFACECATEGORY__H */

