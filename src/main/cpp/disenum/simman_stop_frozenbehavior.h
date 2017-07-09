#ifndef SIMMAN_STOP_FROZENBEHAVIOR__H
#define SIMMAN_STOP_FROZENBEHAVIOR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace simman_stop_frozenbehavior {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int Simulationclock:1;
    unsigned int TransmitPDUs:1;
    unsigned int ReceivePDUs:1;
    unsigned int unused:5;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class Simulationclock : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static Simulationclock getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,Simulationclock*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		Simulationclock(int value, std::string description);

		static Simulationclock* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* Simulationclock */

	class TransmitPDUs : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static TransmitPDUs getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,TransmitPDUs*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		TransmitPDUs(int value, std::string description);

		static TransmitPDUs* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* TransmitPDUs */

	class ReceivePDUs : public Enumeration {
  public:

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ReceivePDUs getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ReceivePDUs*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ReceivePDUs(int value, std::string description);

		static ReceivePDUs* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ReceivePDUs */




}; /* namespace simman_stop_frozenbehavior */

}  /* namespace DIS */

#endif /* SIMMAN_STOP_FROZENBEHAVIOR__H */
