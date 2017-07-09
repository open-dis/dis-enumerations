#ifndef ENV_OBJ_APPEAR_LINEAR_MARKER__H
#define ENV_OBJ_APPEAR_LINEAR_MARKER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace env_obj_appear_linear_marker {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int VisibleSide:2;
    unsigned int unused:30;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class VisibleSide : public Enumeration {
  public:
    static VisibleSide LEFT_SIDE_IS_VISIBLE;
    static VisibleSide RIGHT_SIDE_IS_VISIBLE;
    static VisibleSide BOTH_SIDES_ARE_VISIBLE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static VisibleSide getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,VisibleSide*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		VisibleSide(int value, std::string description);

		static VisibleSide* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* VisibleSide */




}; /* namespace env_obj_appear_linear_marker */

}  /* namespace DIS */

#endif /* ENV_OBJ_APPEAR_LINEAR_MARKER__H */
