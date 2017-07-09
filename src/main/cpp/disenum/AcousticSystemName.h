#ifndef ACOUSTICSYSTEMNAME__H
#define ACOUSTICSYSTEMNAME__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AcousticSystemName : public Enumeration {
  public:
    static AcousticSystemName OTHER;
    static AcousticSystemName AN_BQQ_5;
    static AcousticSystemName AN_SSQ_62;
    static AcousticSystemName AN_SQS_23;
    static AcousticSystemName AN_SQS_26;
    static AcousticSystemName AN_SQS_53;
    static AcousticSystemName ALFS;
    static AcousticSystemName LFA;
    static AcousticSystemName AN_AQS_901;
    static AcousticSystemName AN_AQS_902;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AcousticSystemName getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AcousticSystemName*> enumContainer;
    static enumContainer getEnumerations();

    AcousticSystemName& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AcousticSystemName(int value, std::string description);

	  static AcousticSystemName* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AcousticSystemName */


}  /* namespace DIS */

#endif /* ACOUSTICSYSTEMNAME__H */

