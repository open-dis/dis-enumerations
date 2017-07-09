#ifndef ENTITY_MINE_DATAFILTER__H
#define ENTITY_MINE_DATAFILTER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace entity_mine_datafilter {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int GroundBurialDepthOffset:1;
    unsigned int WaterBurialDepthOffset:1;
    unsigned int SnowBurialDepthOffset:1;
    unsigned int MineOrientation:1;
    unsigned int ThermalContrast:1;
    unsigned int Reflectance:1;
    unsigned int MineEmplacementAge:1;
    unsigned int Trip_DetonationWire:1;
    unsigned int Fusing:1;
    unsigned int ScalarDetectionCoefficient:1;
    unsigned int PaintScheme:1;
    unsigned int unused:21;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class GroundBurialDepthOffset : public Enumeration {
  public:
    static GroundBurialDepthOffset DATA_NOT_REQUESTED_PRESENT;
    static GroundBurialDepthOffset DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static GroundBurialDepthOffset getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,GroundBurialDepthOffset*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		GroundBurialDepthOffset(int value, std::string description);

		static GroundBurialDepthOffset* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* GroundBurialDepthOffset */

	class WaterBurialDepthOffset : public Enumeration {
  public:
    static WaterBurialDepthOffset DATA_NOT_REQUESTED_PRESENT;
    static WaterBurialDepthOffset DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static WaterBurialDepthOffset getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,WaterBurialDepthOffset*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		WaterBurialDepthOffset(int value, std::string description);

		static WaterBurialDepthOffset* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* WaterBurialDepthOffset */

	class SnowBurialDepthOffset : public Enumeration {
  public:
    static SnowBurialDepthOffset DATA_NOT_REQUESTED_PRESENT;
    static SnowBurialDepthOffset DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static SnowBurialDepthOffset getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,SnowBurialDepthOffset*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		SnowBurialDepthOffset(int value, std::string description);

		static SnowBurialDepthOffset* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* SnowBurialDepthOffset */

	class MineOrientation : public Enumeration {
  public:
    static MineOrientation DATA_NOT_REQUESTED_PRESENT;
    static MineOrientation DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static MineOrientation getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,MineOrientation*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		MineOrientation(int value, std::string description);

		static MineOrientation* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* MineOrientation */

	class ThermalContrast : public Enumeration {
  public:
    static ThermalContrast DATA_NOT_REQUESTED_PRESENT;
    static ThermalContrast DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ThermalContrast getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ThermalContrast*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ThermalContrast(int value, std::string description);

		static ThermalContrast* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ThermalContrast */

	class Reflectance : public Enumeration {
  public:
    static Reflectance DATA_NOT_REQUESTED_PRESENT;
    static Reflectance DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Reflectance getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Reflectance*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Reflectance(int value, std::string description);

		static Reflectance* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Reflectance */

	class MineEmplacementAge : public Enumeration {
  public:
    static MineEmplacementAge DATA_NOT_REQUESTED_PRESENT;
    static MineEmplacementAge DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static MineEmplacementAge getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,MineEmplacementAge*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		MineEmplacementAge(int value, std::string description);

		static MineEmplacementAge* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* MineEmplacementAge */

	class Trip_DetonationWire : public Enumeration {
  public:
    static Trip_DetonationWire DATA_NOT_REQUESTED_PRESENT;
    static Trip_DetonationWire DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Trip_DetonationWire getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Trip_DetonationWire*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Trip_DetonationWire(int value, std::string description);

		static Trip_DetonationWire* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Trip_DetonationWire */

	class Fusing : public Enumeration {
  public:
    static Fusing DATA_NOT_REQUESTED_PRESENT;
    static Fusing DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Fusing getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Fusing*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Fusing(int value, std::string description);

		static Fusing* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Fusing */

	class ScalarDetectionCoefficient : public Enumeration {
  public:
    static ScalarDetectionCoefficient DATA_NOT_REQUESTED_PRESENT;
    static ScalarDetectionCoefficient DATA_IS_REQUESTED_PRESENT;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ScalarDetectionCoefficient getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ScalarDetectionCoefficient*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ScalarDetectionCoefficient(int value, std::string description);

		static ScalarDetectionCoefficient* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ScalarDetectionCoefficient */

	class PaintScheme : public Enumeration {
  public:
    static PaintScheme DATA_NOT_REQUESTED_PRESENT;
    static PaintScheme DATA_IS_REQUESTED_PRESENT;

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




}; /* namespace entity_mine_datafilter */

}  /* namespace DIS */

#endif /* ENTITY_MINE_DATAFILTER__H */
