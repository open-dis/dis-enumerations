#ifndef RADIO_TX_ENCODING__H
#define RADIO_TX_ENCODING__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace radio_tx_encoding {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int EncodingType:14;
    unsigned int EncodingClass:2;

    bitmask& operator=(const unsigned short& i);
	  bitmask(const unsigned short& i);
	  bitmask();
	  unsigned short getValue();
	  void  setValue(const unsigned short& i);
	};

	/** Enumerations declaration **/
	class EncodingType : public Enumeration {
  public:
    static EncodingType X_8_BIT_MU_LAW;
    static EncodingType CVSD_PER_MIL_STD_188_113;
    static EncodingType ADPCM_PER_CCITT_G721;
    static EncodingType X_16_BIT_LINEAR_PCM;
    static EncodingType X_8_BIT_LINEAR_PCM;
    static EncodingType VQ_VECTOR_QUANTIZATION;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static EncodingType getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,EncodingType*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		EncodingType(int value, std::string description);

		static EncodingType* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* EncodingType */

	class EncodingClass : public Enumeration {
  public:
    static EncodingClass ENCODED_AUDIO;
    static EncodingClass RAW_BINARY_DATA;
    static EncodingClass APPLICATION_SPECIFIC_DATA;
    static EncodingClass DATABASE_INDEX;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static EncodingClass getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,EncodingClass*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		EncodingClass(int value, std::string description);

		static EncodingClass* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* EncodingClass */




}; /* namespace radio_tx_encoding */

}  /* namespace DIS */

#endif /* RADIO_TX_ENCODING__H */
