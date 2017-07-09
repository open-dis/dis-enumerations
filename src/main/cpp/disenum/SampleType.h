#ifndef SAMPLETYPE__H
#define SAMPLETYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SampleType : public Enumeration {
  public:
    static SampleType MISSING_DESCRIPTION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SampleType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SampleType*> enumContainer;
    static enumContainer getEnumerations();

    SampleType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SampleType(int value, std::string description);

	  static SampleType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SampleType */


}  /* namespace DIS */

#endif /* SAMPLETYPE__H */

