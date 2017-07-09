#ifndef DER_IFF_TYPE_1_FOP_MODIFIER__H
#define DER_IFF_TYPE_1_FOP_MODIFIER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_iff_type_1_fop_modifier {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Other:1;
    unsigned int Emergency:1;
    unsigned int Ident_SquawkFlash:1;
    unsigned int STI:1;
    unsigned int unused:4;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Other : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Other getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Other*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Other(int value, std::string description);

		static Other* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Other */

	class Emergency : public Enumeration {
  public:
    static Emergency OFF;
    static Emergency ON;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Emergency getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Emergency*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Emergency(int value, std::string description);

		static Emergency* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Emergency */

	class Ident_SquawkFlash : public Enumeration {
  public:
    static Ident_SquawkFlash OFF;
    static Ident_SquawkFlash ON;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Ident_SquawkFlash getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Ident_SquawkFlash*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Ident_SquawkFlash(int value, std::string description);

		static Ident_SquawkFlash* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Ident_SquawkFlash */

	class STI : public Enumeration {
  public:
    static STI NO_DAMAGE;
    static STI DAMAGE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static STI getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,STI*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		STI(int value, std::string description);

		static STI* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* STI */




}; /* namespace der_iff_type_1_fop_modifier */

}  /* namespace DIS */

#endif /* DER_IFF_TYPE_1_FOP_MODIFIER__H */
