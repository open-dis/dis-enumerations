#ifndef BEAMFUNCTION__H
#define BEAMFUNCTION__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class BeamFunction : public Enumeration {
  public:
    static BeamFunction OTHER;
    static BeamFunction SEARCH;
    static BeamFunction HEIGHT_FINDER;
    static BeamFunction ACQUISITION;
    static BeamFunction TRACKING;
    static BeamFunction ACQUISITION_AND_TRACKING;
    static BeamFunction COMMAND_GUIDANCE;
    static BeamFunction ILLUMINATION;
    static BeamFunction RANGE_ONLY_RADAR;
    static BeamFunction MISSILE_BEACON;
    static BeamFunction MISSILE_FUZE;
    static BeamFunction ACTIVE_RADAR_MISSILE_SEEKER;
    static BeamFunction JAMMER;
    static BeamFunction IFF;
    static BeamFunction NAVIGATIONAL_WEATHER;
    static BeamFunction METEOROLOGICAL;
    static BeamFunction DATA_TRANSMISSION;
    static BeamFunction NAVIGATIONAL_DIRECTIONAL_BEACON;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static BeamFunction getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,BeamFunction*> enumContainer;
    static enumContainer getEnumerations();

    BeamFunction& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  BeamFunction(int value, std::string description);

	  static BeamFunction* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* BeamFunction */


}  /* namespace DIS */

#endif /* BEAMFUNCTION__H */

