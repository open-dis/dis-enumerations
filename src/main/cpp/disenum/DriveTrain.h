#ifndef DRIVETRAIN__H
#define DRIVETRAIN__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class DriveTrain : public Enumeration {
  public:
    static DriveTrain MOTOR_ENGINE;
    static DriveTrain STARTER;
    static DriveTrain ALTERNATOR;
    static DriveTrain GENERATOR;
    static DriveTrain BATTERY;
    static DriveTrain ENGINE_COOLANT_LEAK;
    static DriveTrain FUEL_FILTER;
    static DriveTrain TRANSMISSION_OIL_LEAK;
    static DriveTrain ENGINE_OIL_LEAK;
    static DriveTrain PUMPS;
    static DriveTrain FILTERS;
    static DriveTrain TRANSMISSION;
    static DriveTrain BRAKES;
    static DriveTrain SUSPENSION_SYSTEM;
    static DriveTrain OIL_FILTER;
    static DriveTrain MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static DriveTrain getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,DriveTrain*> enumContainer;
    static enumContainer getEnumerations();

    DriveTrain& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  DriveTrain(int value, std::string description);

	  static DriveTrain* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* DriveTrain */


}  /* namespace DIS */

#endif /* DRIVETRAIN__H */

