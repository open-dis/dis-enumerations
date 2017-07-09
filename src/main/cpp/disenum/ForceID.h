#ifndef FORCEID__H
#define FORCEID__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ForceID : public Enumeration {
  public:
    static ForceID OTHER;
    static ForceID FRIENDLY;
    static ForceID OPPOSING;
    static ForceID NEUTRAL;
    static ForceID FRIENDLY_2;
    static ForceID OPPOSING_2;
    static ForceID NEUTRAL_2;
    static ForceID FRIENDLY_3;
    static ForceID OPPOSING_3;
    static ForceID NEUTRAL_3;
    static ForceID FRIENDLY_4;
    static ForceID OPPOSING_4;
    static ForceID NEUTRAL_4;
    static ForceID FRIENDLY_5;
    static ForceID OPPOSING_5;
    static ForceID NEUTRAL_5;
    static ForceID FRIENDLY_6;
    static ForceID OPPOSING_6;
    static ForceID NEUTRAL_6;
    static ForceID FRIENDLY_7;
    static ForceID OPPOSING_7;
    static ForceID NEUTRAL_7;
    static ForceID FRIENDLY_8;
    static ForceID OPPOSING_8;
    static ForceID NEUTRAL_8;
    static ForceID FRIENDLY_9;
    static ForceID OPPOSING_9;
    static ForceID NEUTRAL_9;
    static ForceID FRIENDLY_10;
    static ForceID OPPOSING_10;
    static ForceID NEUTRAL_10;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ForceID getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ForceID*> enumContainer;
    static enumContainer getEnumerations();

    ForceID& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ForceID(int value, std::string description);

	  static ForceID* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ForceID */


}  /* namespace DIS */

#endif /* FORCEID__H */

