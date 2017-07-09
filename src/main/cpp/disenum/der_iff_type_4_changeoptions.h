#ifndef DER_IFF_TYPE_4_CHANGEOPTIONS__H
#define DER_IFF_TYPE_4_CHANGEOPTIONS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_iff_type_4_changeoptions {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int ChangeIndicator:1;
    unsigned int unused:7;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class ChangeIndicator : public Enumeration {
  public:
    static ChangeIndicator NO_CHANGE_SINCE_LAST_REPORT;
    static ChangeIndicator INITIAL_REPORT_OR_CHANGE_SINCE_LAST_REPORT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ChangeIndicator getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ChangeIndicator*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ChangeIndicator(int value, std::string description);

		static ChangeIndicator* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ChangeIndicator */




}; /* namespace der_iff_type_4_changeoptions */

}  /* namespace DIS */

#endif /* DER_IFF_TYPE_4_CHANGEOPTIONS__H */
