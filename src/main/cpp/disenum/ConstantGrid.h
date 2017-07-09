#ifndef CONSTANTGRID__H
#define CONSTANTGRID__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ConstantGrid : public Enumeration {
  public:
    static ConstantGrid CONSTANT_GRID;
    static ConstantGrid UPDATED_GRID;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ConstantGrid getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ConstantGrid*> enumContainer;
    static enumContainer getEnumerations();

    ConstantGrid& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ConstantGrid(int value, std::string description);

	  static ConstantGrid* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ConstantGrid */


}  /* namespace DIS */

#endif /* CONSTANTGRID__H */

