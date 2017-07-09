#ifndef ENTITY_MINE_FUSING__H
#define ENTITY_MINE_FUSING__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace entity_mine_fusing {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Primary:7;
    unsigned int Secondary:7;
    unsigned int AHD:1;
    unsigned int unused:1;

    bitmask& operator=(const unsigned short& i);
	  bitmask(const unsigned short& i);
	  bitmask();
	  unsigned short getValue();
	  void  setValue(const unsigned short& i);
	};

	/** Enumerations declaration **/
	class Primary : public Enumeration {
  public:
    static Primary NO_FUSE;
    static Primary OTHER;
    static Primary PRESSURE;
    static Primary MAGNETIC;
    static Primary TILT_ROD;
    static Primary COMMAND;
    static Primary TRIP_WIRE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Primary getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Primary*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Primary(int value, std::string description);

		static Primary* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Primary */

	class Secondary : public Enumeration {
  public:
    static Secondary NO_FUSE;
    static Secondary OTHER;
    static Secondary PRESSURE;
    static Secondary MAGNETIC;
    static Secondary TILT_ROD;
    static Secondary COMMAND;
    static Secondary TRIP_WIRE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Secondary getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Secondary*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Secondary(int value, std::string description);

		static Secondary* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Secondary */

	class AHD : public Enumeration {
  public:
    static AHD NO_ANTI_HANDLING_DEVICE;
    static AHD ANTI_HANDLING_DEVICE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static AHD getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,AHD*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		AHD(int value, std::string description);

		static AHD* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* AHD */




}; /* namespace entity_mine_fusing */

}  /* namespace DIS */

#endif /* ENTITY_MINE_FUSING__H */
