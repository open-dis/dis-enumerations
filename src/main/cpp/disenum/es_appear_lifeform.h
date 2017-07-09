#ifndef ES_APPEAR_LIFEFORM__H
#define ES_APPEAR_LIFEFORM__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace es_appear_lifeform {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int PaintScheme:1;
    unsigned int unused:2;
    unsigned int Health:2;
    unsigned int Compliance:4;
    unsigned int unused_2:3;
    unsigned int FlashLights:1;
    unsigned int unused_3:3;
    unsigned int Life_formstate:4;
    unsigned int unused_4:1;
    unsigned int FrozenStatus:1;
    unsigned int unused_5:1;
    unsigned int State:1;
    unsigned int Weapon1:2;
    unsigned int Weapon2:2;
    unsigned int CamouflageType:2;
    unsigned int ConcealedStationary:1;
    unsigned int ConcealedMovement:1;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/
	class PaintScheme : public Enumeration {
  public:
    static PaintScheme UNIFORM_COLOR;
    static PaintScheme CAMOUFLAGE;

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

	class Health : public Enumeration {
  public:
    static Health NO_INJURY;
    static Health SLIGHT_INJURY;
    static Health MODERATE_INJURY;
    static Health FATAL_INJURY;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Health getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Health*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Health(int value, std::string description);

		static Health* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Health */

	class Compliance : public Enumeration {
  public:
    static Compliance DETAINED;
    static Compliance SURRENDER;
    static Compliance USING_FISTS;
    static Compliance VERBAL_ABUSE_LEVEL_1;
    static Compliance VERBAL_ABUSE_LEVEL_2;
    static Compliance VERBAL_ABUSE_LEVEL_3;
    static Compliance PASSIVE_RESISTANCE_LEVEL_1;
    static Compliance PASSIVE_RESISTANCE_LEVEL_2;
    static Compliance PASSIVE_RESISTANCE_LEVEL_3;
    static Compliance USING_NON_LETHAL_WEAPON_1;
    static Compliance USING_NON_LETHAL_WEAPON_2;
    static Compliance USING_NON_LETHAL_WEAPON_3;
    static Compliance USING_NON_LETHAL_WEAPON_4;
    static Compliance USING_NON_LETHAL_WEAPON_5;
    static Compliance USING_NON_LETHAL_WEAPON_6;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Compliance getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Compliance*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Compliance(int value, std::string description);

		static Compliance* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Compliance */

	class FlashLights : public Enumeration {
  public:
    static FlashLights OFF;
    static FlashLights ON;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static FlashLights getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,FlashLights*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		FlashLights(int value, std::string description);

		static FlashLights* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* FlashLights */

	class Life_formstate : public Enumeration {
  public:
    static Life_formstate UPRIGHT_STANDING_STILL;
    static Life_formstate UPRIGHT_WALKING;
    static Life_formstate UPRIGHT_RUNNING;
    static Life_formstate KNEELING;
    static Life_formstate PRONE;
    static Life_formstate CRAWLING;
    static Life_formstate SWIMMING;
    static Life_formstate PARACHUTING;
    static Life_formstate JUMPING;
    static Life_formstate SITTING;
    static Life_formstate SQUATTING;
    static Life_formstate CROUCHING;
    static Life_formstate WADING;
    static Life_formstate SURRENDER;
    static Life_formstate DETAINED;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Life_formstate getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Life_formstate*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Life_formstate(int value, std::string description);

		static Life_formstate* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Life_formstate */

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

	class Weapon1 : public Enumeration {
  public:
    static Weapon1 NO_PRIMARY_WEAPON_PRESENT;
    static Weapon1 PRIMARY_WEAPON_IS_STOWED;
    static Weapon1 PRIMARY_WEAPON_IS_DEPLOYED;
    static Weapon1 PRIMARY_WEAPON_IS_IN_FIRING_POSITION;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Weapon1 getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Weapon1*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Weapon1(int value, std::string description);

		static Weapon1* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Weapon1 */

	class Weapon2 : public Enumeration {
  public:
    static Weapon2 NO_SECONDARY_WEAPON_PRESENT;
    static Weapon2 SECONDARY_WEAPON_IS_STOWED;
    static Weapon2 SECONDARY_WEAPON_IS_DEPLOYED;
    static Weapon2 SECONDARY_WEAPON_IS_IN_FIRING_POSITION;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Weapon2 getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Weapon2*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Weapon2(int value, std::string description);

		static Weapon2* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Weapon2 */

	class CamouflageType : public Enumeration {
  public:
    static CamouflageType DESERT_CAMOUFLAGE;
    static CamouflageType WINTER_CAMOUFLAGE;
    static CamouflageType FOREST_CAMOUFLAGE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static CamouflageType getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,CamouflageType*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		CamouflageType(int value, std::string description);

		static CamouflageType* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* CamouflageType */

	class ConcealedStationary : public Enumeration {
  public:
    static ConcealedStationary NOT_CONCEALED;
    static ConcealedStationary ENTITY_IN_A_PREPARED_CONCEALED_POSITION;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ConcealedStationary getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ConcealedStationary*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ConcealedStationary(int value, std::string description);

		static ConcealedStationary* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ConcealedStationary */

	class ConcealedMovement : public Enumeration {
  public:
    static ConcealedMovement OPEN_MOVEMENT;
    static ConcealedMovement RUSHES_BETWEEN_COVERED_POSITIONS;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ConcealedMovement getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ConcealedMovement*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ConcealedMovement(int value, std::string description);

		static ConcealedMovement* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ConcealedMovement */




}; /* namespace es_appear_lifeform */

}  /* namespace DIS */

#endif /* ES_APPEAR_LIFEFORM__H */
