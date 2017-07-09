#ifndef RESPONSEFLAG__H
#define RESPONSEFLAG__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ResponseFlag : public Enumeration {
  public:
    static ResponseFlag OTHER;
    static ResponseFlag ABLE_TO_COMPLY;
    static ResponseFlag UNABLE_TO_COMPLY;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ResponseFlag getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ResponseFlag*> enumContainer;
    static enumContainer getEnumerations();

    ResponseFlag& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ResponseFlag(int value, std::string description);

	  static ResponseFlag* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ResponseFlag */


}  /* namespace DIS */

#endif /* RESPONSEFLAG__H */

