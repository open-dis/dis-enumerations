#ifndef AGGREGATESTATE__H
#define AGGREGATESTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AggregateState : public Enumeration {
  public:
    static AggregateState OTHER;
    static AggregateState AGGREGATED;
    static AggregateState DISAGGREGATED;
    static AggregateState FULLY_DISAGGREGATED;
    static AggregateState PSEUDO_DISAGGREGATED;
    static AggregateState PARTIALLY_DISAGGREGATED;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AggregateState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AggregateState*> enumContainer;
    static enumContainer getEnumerations();

    AggregateState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AggregateState(int value, std::string description);

	  static AggregateState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AggregateState */


}  /* namespace DIS */

#endif /* AGGREGATESTATE__H */

