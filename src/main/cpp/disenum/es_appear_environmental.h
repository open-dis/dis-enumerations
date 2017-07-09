#ifndef ES_APPEAR_ENVIRONMENTAL__H
#define ES_APPEAR_ENVIRONMENTAL__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace es_appear_environmental {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int unused:16;
    unsigned int Density:4;
    unsigned int unused_2:1;
    unsigned int FrozenStatus:1;
    unsigned int unused_3:1;
    unsigned int State:1;
    unsigned int unused_4:7;
    unsigned int Masked_Cloaked:1;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class Density : public Enumeration {
  public:
    static Density CLEAR;
    static Density HAZY;
    static Density DENSE;
    static Density VERY_DENSE;
    static Density OPAQUE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Density getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Density*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Density(int value, std::string description);

		static Density* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Density */

	class FrozenStatus : public Enumeration {
  public:
    static FrozenStatus NOT_FROZEN;
    static FrozenStatus FROZEN_FROZEN_ENTITIES_SHOULD_NOT_BE_DEAD_RECKONED_IE_THEY_SHOULD_BE_DISPLAYED_AS_FIXED_AT_THE_CURRENT_LOCATION_EVEN_IF_NONZERO_VELOCITY_ACCELERATION_OR_ROTATION_DATA_IS_RECEIVED_FROM_THE_FROZEN_ENTITY;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static FrozenStatus getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,FrozenStatus*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		FrozenStatus(int value, std::string description);

		static FrozenStatus* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* FrozenStatus */

	class State : public Enumeration {
  public:
    static State ACTIVE;
    static State DEACTIVATED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static State getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,State*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		State(int value, std::string description);

		static State* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* State */

	class Masked_Cloaked : public Enumeration {
  public:
    static Masked_Cloaked NOT_MASKED_NOT_CLOAKED;
    static Masked_Cloaked MASKED_CLOAKED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Masked_Cloaked getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Masked_Cloaked*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Masked_Cloaked(int value, std::string description);

		static Masked_Cloaked* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Masked_Cloaked */




}; /* namespace es_appear_environmental */

}  /* namespace DIS */

#endif /* ES_APPEAR_ENVIRONMENTAL__H */
