#include <sstream>
#include <cstddef>
#include <disenum/GeometryRecordTypeField.h>

namespace DIS {


hashMap<int,GeometryRecordTypeField*> GeometryRecordTypeField::enumerations;

GeometryRecordTypeField GeometryRecordTypeField::POINT_RECORD_1(655360, "Point Record 1");
GeometryRecordTypeField GeometryRecordTypeField::POINT_RECORD_2(167772160, "Point Record 2");
GeometryRecordTypeField GeometryRecordTypeField::LINE_RECORD_1(786432, "Line Record 1");
GeometryRecordTypeField GeometryRecordTypeField::LINE_RECORD_2(201326592, "Line Record 2");
GeometryRecordTypeField GeometryRecordTypeField::BOUNDING_SPHERE_RECORD(65536, "Bounding Sphere Record");
GeometryRecordTypeField GeometryRecordTypeField::SPHERE_RECORD_1(851968, "Sphere Record 1");
GeometryRecordTypeField GeometryRecordTypeField::SPHERE_RECORD_2(218103808, "Sphere Record 2");
GeometryRecordTypeField GeometryRecordTypeField::ELLIPSOID_RECORD_1(1048576, "Ellipsoid Record 1");
GeometryRecordTypeField GeometryRecordTypeField::ELLIPSOID_RECORD_2(268435456, "Ellipsoid Record 2");
GeometryRecordTypeField GeometryRecordTypeField::CONE_RECORD_1(3145728, "Cone Record 1");
GeometryRecordTypeField GeometryRecordTypeField::CONE_RECORD_2(805306368, "Cone Record 2");
GeometryRecordTypeField GeometryRecordTypeField::UNIFORM_GEOMETRY_RECORD(327680, "Uniform Geometry Record");
GeometryRecordTypeField GeometryRecordTypeField::RECTANGULAR_VOLUME_RECORD_1(5242880, "Rectangular Volume Record 1");
GeometryRecordTypeField GeometryRecordTypeField::RECTANGULAR_VOLUME_RECORD_2(1342177280, "Rectangular Volume Record 2");
GeometryRecordTypeField GeometryRecordTypeField::GAUSSIAN_PLUME_RECORD(1610612736, "Gaussian Plume Record");
GeometryRecordTypeField GeometryRecordTypeField::GAUSSIAN_PUFF_RECORD(1879048192, "Gaussian Puff Record");
GeometryRecordTypeField GeometryRecordTypeField::RECTANGULAR_VOLUME_RECORD_3(83886080, "Rectangular Volume Record 3");


GeometryRecordTypeField::GeometryRecordTypeField(int value, std::string description) :
  Enumeration(value, description)
{
  enumerations[value] = this;
};

GeometryRecordTypeField* GeometryRecordTypeField::findEnumeration(int aVal) {
  GeometryRecordTypeField* pEnum;

  enumContainer::iterator enumIter = enumerations.find(aVal);
  if (enumIter == enumerations.end()) pEnum = NULL;
  else pEnum = (*enumIter).second;
  return pEnum;
};

std::string GeometryRecordTypeField::getDescriptionForValue(int aVal) {
  GeometryRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return pEnum->description;
  else {
    std::stringstream ss;
    ss <<  "Invalid enumeration: " << aVal;
    return (ss.str());
  }
};

GeometryRecordTypeField GeometryRecordTypeField::getEnumerationForValue(int aVal) throw(EnumException) {
  GeometryRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return (*pEnum);
  else  {
    std::stringstream ss;
    ss << "No enumeration found for value " << aVal << " of enumeration GeometryRecordTypeField";
    throw EnumException("GeometryRecordTypeField", aVal, ss.str());
  }
};

bool GeometryRecordTypeField::enumerationForValueExists(int aVal) {
  GeometryRecordTypeField* pEnum = findEnumeration(aVal);
  if (pEnum) return (true);
  else       return (false);
};

GeometryRecordTypeField::enumContainer GeometryRecordTypeField::getEnumerations() {
  return (enumerations);
};

GeometryRecordTypeField& GeometryRecordTypeField::operator=(const int& aVal) throw(EnumException)
{
	(*this) = getEnumerationForValue(aVal);
	return (*this);
};


}  /* namespace DIS */

