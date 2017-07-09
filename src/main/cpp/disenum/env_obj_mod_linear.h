#ifndef ENV_OBJ_MOD_LINEAR__H
#define ENV_OBJ_MOD_LINEAR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace env_obj_mod_linear {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Location:1;
    unsigned int Orientation:1;
    unsigned int unused:6;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Location : public Enumeration {
  public:
    static Location LOCATION_HAS_NOT_BEEN_MODIFIED;
    static Location LOCATION_HAS_BEEN_MODIFIED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Location getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Location*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Location(int value, std::string description);

		static Location* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Location */

	class Orientation : public Enumeration {
  public:
    static Orientation ORIENTATION_HAS_NOT_BEEN_MODIFIED;
    static Orientation ORIENTATION_HAS_BEEN_MODIFIED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Orientation getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Orientation*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Orientation(int value, std::string description);

		static Orientation* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Orientation */




}; /* namespace env_obj_mod_linear */

}  /* namespace DIS */

#endif /* ENV_OBJ_MOD_LINEAR__H */
