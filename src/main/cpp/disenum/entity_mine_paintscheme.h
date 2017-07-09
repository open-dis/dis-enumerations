#ifndef ENTITY_MINE_PAINTSCHEME__H
#define ENTITY_MINE_PAINTSCHEME__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace entity_mine_paintscheme {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Algae:2;
    unsigned int PaintScheme:6;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Algae : public Enumeration {
  public:
    static Algae NONE;
    static Algae LIGHT;
    static Algae MODERATE;
    static Algae HEAVY;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Algae getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Algae*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Algae(int value, std::string description);

		static Algae* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Algae */

	class PaintScheme : public Enumeration {
  public:
    static PaintScheme OTHER;
    static PaintScheme STANDARD;
    static PaintScheme CAMOUFLAGE_DESERT;
    static PaintScheme CAMOUFLAGE_JUNGLE;
    static PaintScheme CAMOUFLAGE_SNOW;
    static PaintScheme CAMOUFLAGE_GRAVEL;
    static PaintScheme CAMOUFLAGE_PAVEMENT;
    static PaintScheme CAMOUFLAGE_SAND;
    static PaintScheme NATURAL_WOOD;
    static PaintScheme CLEAR;
    static PaintScheme RED;
    static PaintScheme BLUE;
    static PaintScheme GREEN;
    static PaintScheme OLIVE;
    static PaintScheme WHITE;
    static PaintScheme TAN;
    static PaintScheme BLACK;
    static PaintScheme YELLOW;
    static PaintScheme BROWN;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static PaintScheme getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,PaintScheme*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		PaintScheme(int value, std::string description);

		static PaintScheme* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* PaintScheme */




}; /* namespace entity_mine_paintscheme */

}  /* namespace DIS */

#endif /* ENTITY_MINE_PAINTSCHEME__H */
