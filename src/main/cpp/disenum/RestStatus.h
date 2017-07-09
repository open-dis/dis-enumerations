#ifndef RESTSTATUS__H
#define RESTSTATUS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class RestStatus : public Enumeration {
  public:
    static RestStatus NOT_RESTED_HAS_NOT_SLEPT_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_1_HOUR_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_2_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_3_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_4_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_5_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_6_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus HAS_SLEPT_AN_AVERAGE_OF_7_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    static RestStatus FULLY_RESTED_HAS_SLEPT_AN_AVERAGE_OF_8_HOURS_PER_DAY_IN_THE_LAST_THREE_DAYS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static RestStatus getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,RestStatus*> enumContainer;
    static enumContainer getEnumerations();

    RestStatus& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  RestStatus(int value, std::string description);

	  static RestStatus* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* RestStatus */


}  /* namespace DIS */

#endif /* RESTSTATUS__H */

