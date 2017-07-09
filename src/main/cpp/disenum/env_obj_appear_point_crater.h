#ifndef ENV_OBJ_APPEAR_POINT_CRATER__H
#define ENV_OBJ_APPEAR_POINT_CRATER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace env_obj_appear_point_crater {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Size:8;
    unsigned int unused:24;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class Size : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Size getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Size*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Size(int value, std::string description);

		static Size* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Size */




}; /* namespace env_obj_appear_point_crater */

}  /* namespace DIS */

#endif /* ENV_OBJ_APPEAR_POINT_CRATER__H */
