#ifndef DER_UA_PPCFG__H
#define DER_UA_PPCFG__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_ua_ppcfg {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Configuration:7;
    unsigned int HullMountedMasker:1;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Configuration : public Enumeration {
  public:
    static Configuration OTHER;
    static Configuration DIESEL_ELECTRIC;
    static Configuration DIESEL;
    static Configuration BATTERY;
    static Configuration TURBINE_REDUCTION;
    static Configuration STEAM;
    static Configuration GAS_TURBINE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Configuration getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Configuration*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Configuration(int value, std::string description);

		static Configuration* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Configuration */

	class HullMountedMasker : public Enumeration {
  public:
    static HullMountedMasker OFF;
    static HullMountedMasker ON;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static HullMountedMasker getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,HullMountedMasker*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		HullMountedMasker(int value, std::string description);

		static HullMountedMasker* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* HullMountedMasker */




}; /* namespace der_ua_ppcfg */

}  /* namespace DIS */

#endif /* DER_UA_PPCFG__H */
