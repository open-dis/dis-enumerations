#ifndef PROTOCOLFAMILY__H
#define PROTOCOLFAMILY__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ProtocolFamily : public Enumeration {
  public:
    static ProtocolFamily OTHER;
    static ProtocolFamily ENTITY_INFORMATION_INTERACTION;
    static ProtocolFamily WARFARE;
    static ProtocolFamily LOGISTICS;
    static ProtocolFamily RADIO_COMMUNICATION;
    static ProtocolFamily SIMULATION_MANAGEMENT;
    static ProtocolFamily DISTRIBUTED_EMISSION_REGENERATION;
    static ProtocolFamily ENTITY_MANAGEMENT;
    static ProtocolFamily MINEFIELD;
    static ProtocolFamily SYNTHETIC_ENVIRONMENT;
    static ProtocolFamily SIMULATION_MANAGEMENT_WITH_RELIABILITY;
    static ProtocolFamily LIVE_ENTITY;
    static ProtocolFamily NON_REAL_TIME;
    static ProtocolFamily EXPERIMENTAL_COMPUTER_GENERATED_FORCES;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ProtocolFamily getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ProtocolFamily*> enumContainer;
    static enumContainer getEnumerations();

    ProtocolFamily& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ProtocolFamily(int value, std::string description);

	  static ProtocolFamily* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ProtocolFamily */


}  /* namespace DIS */

#endif /* PROTOCOLFAMILY__H */

