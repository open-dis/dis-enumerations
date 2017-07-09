#ifndef ENV_OBJ_APPEAR_LINEAR_TANKDITCH__H
#define ENV_OBJ_APPEAR_LINEAR_TANKDITCH__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace env_obj_appear_linear_tankditch {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Breach:2;
    unsigned int unused:14;
    unsigned int BreachLength:8;
    unsigned int BreachLocation:8;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class Breach : public Enumeration {
  public:
    static Breach NO_BREACHING;
    static Breach SLIGHT_BREACHING;
    static Breach MODERATE_BREACHED;
    static Breach CLEARED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Breach getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Breach*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Breach(int value, std::string description);

		static Breach* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Breach */

	class BreachLength : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static BreachLength getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,BreachLength*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		BreachLength(int value, std::string description);

		static BreachLength* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* BreachLength */

	class BreachLocation : public Enumeration {
  public:
    static BreachLocation ASSOCIATED_PORTION_OF_SEGMENT_IS_NOT_BREACHED;
    static BreachLocation ASSOCIATED_PORTION_OF_SEGMENT_IS_BREACHED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static BreachLocation getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,BreachLocation*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		BreachLocation(int value, std::string description);

		static BreachLocation* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* BreachLocation */




}; /* namespace env_obj_appear_linear_tankditch */

}  /* namespace DIS */

#endif /* ENV_OBJ_APPEAR_LINEAR_TANKDITCH__H */
