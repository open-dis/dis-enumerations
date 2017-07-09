#ifndef RADIO_TX_MOD_SPREADSPECTRUM__H
#define RADIO_TX_MOD_SPREADSPECTRUM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace radio_tx_mod_spreadspectrum {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int FrequencyHopping:1;
    unsigned int Pseudo_noise:1;
    unsigned int TimeHopping:1;
    unsigned int unused:13;

    bitmask& operator=(const unsigned short& i);
	  bitmask(const unsigned short& i);
	  bitmask();
	  unsigned short getValue();
	  void  setValue(const unsigned short& i);
	};

	/** Enumerations declaration **/
	class FrequencyHopping : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static FrequencyHopping getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,FrequencyHopping*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		FrequencyHopping(int value, std::string description);

		static FrequencyHopping* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* FrequencyHopping */

	class Pseudo_noise : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Pseudo_noise getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Pseudo_noise*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Pseudo_noise(int value, std::string description);

		static Pseudo_noise* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Pseudo_noise */

	class TimeHopping : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static TimeHopping getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,TimeHopping*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		TimeHopping(int value, std::string description);

		static TimeHopping* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* TimeHopping */




}; /* namespace radio_tx_mod_spreadspectrum */

}  /* namespace DIS */

#endif /* RADIO_TX_MOD_SPREADSPECTRUM__H */
