#ifndef RADIONOMENCLATUREVERSION__H
#define RADIONOMENCLATUREVERSION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RadioNomenclatureVersion : public Enumeration {
  public:
    static RadioNomenclatureVersion OTHER;
    static RadioNomenclatureVersion JOINT_ELECTRONICS_TYPE_DESIGNATION_SYSTEM_JETDS_NOMENCLATURE_AN_PER_MIL_STD_196;
    static RadioNomenclatureVersion MANUFACTURER_DESIGNATION;
    static RadioNomenclatureVersion NATIONAL_DESIGNATION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RadioNomenclatureVersion getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RadioNomenclatureVersion*> enumContainer;
    static enumContainer getEnumerations();

    RadioNomenclatureVersion& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RadioNomenclatureVersion(int value, std::string description);

	  static RadioNomenclatureVersion* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RadioNomenclatureVersion */


}  /* namespace DIS */

#endif /* RADIONOMENCLATUREVERSION__H */

