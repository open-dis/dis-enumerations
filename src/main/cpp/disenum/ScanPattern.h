#ifndef SCANPATTERN__H
#define SCANPATTERN__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class ScanPattern : public Enumeration {
  public:
    static ScanPattern SCAN_PATTERN_NOT_USED;
    static ScanPattern CONICAL;
    static ScanPattern HELICAL;
    static ScanPattern RASTER;
    static ScanPattern SECTOR_SEARCH;
    static ScanPattern CONTINUOUS_SEARCH;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static ScanPattern getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,ScanPattern*> enumContainer;
    static enumContainer getEnumerations();

    ScanPattern& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  ScanPattern(int value, std::string description);

	  static ScanPattern* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* ScanPattern */


}  /* namespace DIS */

#endif /* SCANPATTERN__H */

