#ifndef LAYERSPECIFICINFORMATION__H
#define LAYERSPECIFICINFORMATION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class LayerSpecificInformation : public Enumeration {
  public:
    static LayerSpecificInformation OTHER;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static LayerSpecificInformation getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,LayerSpecificInformation*> enumContainer;
    static enumContainer getEnumerations();

    LayerSpecificInformation& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  LayerSpecificInformation(int value, std::string description);

	  static LayerSpecificInformation* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* LayerSpecificInformation */


}  /* namespace DIS */

#endif /* LAYERSPECIFICINFORMATION__H */

