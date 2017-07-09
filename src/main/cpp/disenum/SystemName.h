#ifndef SYSTEMNAME__H
#define SYSTEMNAME__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class SystemName : public Enumeration {
  public:
    static SystemName OTHER;
    static SystemName MARK_X;
    static SystemName MARK_XII;
    static SystemName ATCRBS;
    static SystemName SOVIET;
    static SystemName MODE_S;
    static SystemName MARK_X_XII_ATCRBS;
    static SystemName MARK_X_XII_ATCRBS_MODE_S;
    static SystemName ARI_5954;
    static SystemName ARI_5983;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static SystemName getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,SystemName*> enumContainer;
    static enumContainer getEnumerations();

    SystemName& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  SystemName(int value, std::string description);

	  static SystemName* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* SystemName */


}  /* namespace DIS */

#endif /* SYSTEMNAME__H */

