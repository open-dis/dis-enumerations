#ifndef AGGREGATEKIND__H
#define AGGREGATEKIND__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AggregateKind : public Enumeration {
  public:
    static AggregateKind OTHER;
    static AggregateKind MILITARY_HIERARCHY;
    static AggregateKind COMMON_TYPE;
    static AggregateKind COMMON_MISSION;
    static AggregateKind SIMILAR_CAPABILITIES;
    static AggregateKind COMMON_LOCATION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AggregateKind getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AggregateKind*> enumContainer;
    static enumContainer getEnumerations();

    AggregateKind& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AggregateKind(int value, std::string description);

	  static AggregateKind* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AggregateKind */


}  /* namespace DIS */

#endif /* AGGREGATEKIND__H */

