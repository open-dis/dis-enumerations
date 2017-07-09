#ifndef EXPENDABLESUBSURFACECATEGORY__H
#define EXPENDABLESUBSURFACECATEGORY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ExpendableSubsurfaceCategory : public Enumeration {
  public:
    static ExpendableSubsurfaceCategory OTHER;
    static ExpendableSubsurfaceCategory ACTIVE_EMITTER;
    static ExpendableSubsurfaceCategory PASSIVE_DECOY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ExpendableSubsurfaceCategory getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ExpendableSubsurfaceCategory*> enumContainer;
    static enumContainer getEnumerations();

    ExpendableSubsurfaceCategory& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ExpendableSubsurfaceCategory(int value, std::string description);

	  static ExpendableSubsurfaceCategory* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ExpendableSubsurfaceCategory */


}  /* namespace DIS */

#endif /* EXPENDABLESUBSURFACECATEGORY__H */

