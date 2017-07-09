#ifndef GEOMETRYRECORDTYPEFIELD__H
#define GEOMETRYRECORDTYPEFIELD__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class GeometryRecordTypeField : public Enumeration {
  public:
    static GeometryRecordTypeField POINT_RECORD_1;
    static GeometryRecordTypeField POINT_RECORD_2;
    static GeometryRecordTypeField LINE_RECORD_1;
    static GeometryRecordTypeField LINE_RECORD_2;
    static GeometryRecordTypeField BOUNDING_SPHERE_RECORD;
    static GeometryRecordTypeField SPHERE_RECORD_1;
    static GeometryRecordTypeField SPHERE_RECORD_2;
    static GeometryRecordTypeField ELLIPSOID_RECORD_1;
    static GeometryRecordTypeField ELLIPSOID_RECORD_2;
    static GeometryRecordTypeField CONE_RECORD_1;
    static GeometryRecordTypeField CONE_RECORD_2;
    static GeometryRecordTypeField UNIFORM_GEOMETRY_RECORD;
    static GeometryRecordTypeField RECTANGULAR_VOLUME_RECORD_1;
    static GeometryRecordTypeField RECTANGULAR_VOLUME_RECORD_2;
    static GeometryRecordTypeField GAUSSIAN_PLUME_RECORD;
    static GeometryRecordTypeField GAUSSIAN_PUFF_RECORD;
    static GeometryRecordTypeField RECTANGULAR_VOLUME_RECORD_3;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static GeometryRecordTypeField getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,GeometryRecordTypeField*> enumContainer;
    static enumContainer getEnumerations();

    GeometryRecordTypeField& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  GeometryRecordTypeField(int value, std::string description);

	  static GeometryRecordTypeField* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* GeometryRecordTypeField */


}  /* namespace DIS */

#endif /* GEOMETRYRECORDTYPEFIELD__H */

