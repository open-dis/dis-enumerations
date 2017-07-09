#ifndef ENV_PROCESS_ENVIRONMENTSTATUS__H
#define ENV_PROCESS_ENVIRONMENTSTATUS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace env_process_environmentstatus {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Last:1;
    unsigned int On:1;
    unsigned int unused:6;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Last : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Last getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Last*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Last(int value, std::string description);

		static Last* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Last */

	class On : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static On getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,On*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		On(int value, std::string description);

		static On* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* On */




}; /* namespace env_process_environmentstatus */

}  /* namespace DIS */

#endif /* ENV_PROCESS_ENVIRONMENTSTATUS__H */
