#ifndef SYNCHRONIZATIONSTATE__H
#define SYNCHRONIZATIONSTATE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SynchronizationState : public Enumeration {
  public:
    static SynchronizationState COARSE_SYNCHRONIZATION;
    static SynchronizationState FINE_SYNCHRONIZATION;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SynchronizationState getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SynchronizationState*> enumContainer;
    static enumContainer getEnumerations();

    SynchronizationState& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SynchronizationState(int value, std::string description);

	  static SynchronizationState* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SynchronizationState */


}  /* namespace DIS */

#endif /* SYNCHRONIZATIONSTATE__H */

