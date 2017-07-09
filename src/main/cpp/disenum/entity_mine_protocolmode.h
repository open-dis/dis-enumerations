#ifndef ENTITY_MINE_PROTOCOLMODE__H
#define ENTITY_MINE_PROTOCOLMODE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace entity_mine_protocolmode {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int ProtocolMode:2;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/
	class ProtocolMode : public Enumeration {
  public:
    static ProtocolMode HEARTBEAT_MODE;
    static ProtocolMode QRP_MODE;

		/** Returns the string description associated with the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
		static std::string getDescriptionForValue(int aVal);

		/** Returns the enumerated instance with this value.
		 * If there is no enumerated instance for this value, the exception is thrown.     */
		static ProtocolMode getEnumerationForValue(int aVal) throw(EnumException);

		/** Returns true if there is an enumerated instance for this value, false otherwise. */
		static bool enumerationForValueExists(int aVal);

		typedef hashMap<int,ProtocolMode*> enumContainer;
		static enumContainer getEnumerations();

		/** Returns the start bit number for this subfield */
		static short  getStartBit() { return startBit; };

		/** Returns the end bit number for this subfield */
		static short  getEndBit()   { return endBit;   };


	private:
		/** Constructor */
		ProtocolMode(int value, std::string description);

		static ProtocolMode* findEnumeration(int aVal);
		static enumContainer enumerations;

		static short startBit;
		static short endBit;

	};  /* ProtocolMode */




}; /* namespace entity_mine_protocolmode */

}  /* namespace DIS */

#endif /* ENTITY_MINE_PROTOCOLMODE__H */
