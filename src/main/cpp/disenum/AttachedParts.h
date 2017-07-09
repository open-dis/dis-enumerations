#ifndef ATTACHEDPARTS__H
#define ATTACHEDPARTS__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class AttachedParts : public Enumeration {
  public:
    static AttachedParts NOTHING_EMPTY;
    static AttachedParts SEQUENTIAL_IDS_FOR_MODEL_SPECIFIC_STATIONS;
    static AttachedParts FUSELAGE_STATIONS;
    static AttachedParts LEFT_WING_STATIONS;
    static AttachedParts RIGHT_WING_STATIONS;
    static AttachedParts M16A42_RIFLE;
    static AttachedParts M249_SAW;
    static AttachedParts M60_MACHINE_GUN;
    static AttachedParts M203_GRENADE_LAUNCHER;
    static AttachedParts M136_AT4;
    static AttachedParts M47_DRAGON;
    static AttachedParts AAWS_M_JAVELIN;
    static AttachedParts M18A1_CLAYMORE_MINE;
    static AttachedParts MK19_GRENADE_LAUNCHER;
    static AttachedParts M2_MACHINE_GUN;
    static AttachedParts OTHER_ATTACHED_PARTS;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static AttachedParts getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,AttachedParts*> enumContainer;
    static enumContainer getEnumerations();

    AttachedParts& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  AttachedParts(int value, std::string description);

	  static AttachedParts* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* AttachedParts */


}  /* namespace DIS */

#endif /* ATTACHEDPARTS__H */

