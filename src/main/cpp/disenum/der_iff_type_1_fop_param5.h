#ifndef DER_IFF_TYPE_1_FOP_PARAM5__H
#define DER_IFF_TYPE_1_FOP_PARAM5__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_iff_type_1_fop_param5 {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int NegativeAltitude:1;
    unsigned int ModeCaltitude:11;
    unsigned int unused:1;
    unsigned int Status:1;
    unsigned int Damage:1;
    unsigned int Malfunction:1;

    bitmask& operator=(const unsigned short& i);
	  bitmask(const unsigned short& i);
	  bitmask();
	  unsigned short getValue();
	  void  setValue(const unsigned short& i);
	};

	/** Enumerations declaration **/
	class NegativeAltitude : public Enumeration {
  public:
    static NegativeAltitude POSITIVE_ALTITUDE_ABOVE_MEAN_SEA_LEVEL_INDICATOR_IF_MODE_C_ALTITUDE_IS_CONTAINED_IN_BITS_1_11;
    static NegativeAltitude NEGATIVE_ALTITUDE_BELOW_MEAN_SEA_LEVEL_INDICATOR_IF_MODE_C_ALTITUDE_IS_CONTAINED_IN_BITS_1_11_OR_ALTERNATE_MODE_5_IF_ALTITUDE_BITS_1_11_EQ_2047;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static NegativeAltitude getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,NegativeAltitude*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		NegativeAltitude(int value, std::string description);

		static NegativeAltitude* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* NegativeAltitude */

	class ModeCaltitude : public Enumeration {
  public:
    static ModeCaltitude ACTUAL_MODE_C_ALTITUDE_IN_THE_RANGE_0_126000_FEET_IN_100_FOOT_INCREMENTS_BIT_0_NEGATIVE_POSITIVE_INDICATOR_MUST_BE_SET_APPROPRIATELY;
    static ModeCaltitude NOT_ACTUAL_MODE_C_ALTITUDE_VALUE_USE_ALTERNATE_MODE_5_BITS_0_11_EQ_4095_IE_ALL_1_S;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ModeCaltitude getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ModeCaltitude*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ModeCaltitude(int value, std::string description);

		static ModeCaltitude* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ModeCaltitude */

	class Status : public Enumeration {
  public:
    static Status OFF;
    static Status ON;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Status getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Status*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Status(int value, std::string description);

		static Status* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Status */

	class Damage : public Enumeration {
  public:
    static Damage NO_DAMAGE;
    static Damage DAMAGE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Damage getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Damage*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Damage(int value, std::string description);

		static Damage* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Damage */

	class Malfunction : public Enumeration {
  public:
    static Malfunction NO_MALFUNCTION;
    static Malfunction MALFUNCTION;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Malfunction getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Malfunction*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Malfunction(int value, std::string description);

		static Malfunction* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Malfunction */




}; /* namespace der_iff_type_1_fop_param5 */

}  /* namespace DIS */

#endif /* DER_IFF_TYPE_1_FOP_PARAM5__H */
