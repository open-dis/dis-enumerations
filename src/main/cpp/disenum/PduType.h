#ifndef PDUTYPE__H
#define PDUTYPE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class PduType : public Enumeration {
  public:
    static PduType OTHER;
    static PduType ENTITY_STATE;
    static PduType FIRE;
    static PduType DETONATION;
    static PduType COLLISION;
    static PduType SERVICE_REQUEST;
    static PduType RESUPPLY_OFFER;
    static PduType RESUPPLY_RECEIVED;
    static PduType RESUPPLY_CANCEL;
    static PduType REPAIR_COMPLETE;
    static PduType REPAIR_RESPONSE;
    static PduType CREATE_ENTITY;
    static PduType REMOVE_ENTITY;
    static PduType START_RESUME;
    static PduType STOP_FREEZE;
    static PduType ACKNOWLEDGE;
    static PduType ACTION_REQUEST;
    static PduType ACTION_RESPONSE;
    static PduType DATA_QUERY;
    static PduType SET_DATA;
    static PduType DATA;
    static PduType EVENT_REPORT;
    static PduType COMMENT;
    static PduType ELECTROMAGNETIC_EMISSION;
    static PduType DESIGNATOR;
    static PduType TRANSMITTER;
    static PduType SIGNAL;
    static PduType RECEIVER;
    static PduType IFF_ATC_NAVAIDS;
    static PduType UNDERWATER_ACOUSTIC;
    static PduType SUPPLEMENTAL_EMISSION_ENTITY_STATE;
    static PduType INTERCOM_SIGNAL;
    static PduType INTERCOM_CONTROL;
    static PduType AGGREGATE_STATE;
    static PduType ISGROUPOF;
    static PduType TRANSFER_CONTROL;
    static PduType ISPARTOF;
    static PduType MINEFIELD_STATE;
    static PduType MINEFIELD_QUERY;
    static PduType MINEFIELD_DATA;
    static PduType MINEFIELD_RESPONSE_NAK;
    static PduType ENVIRONMENTAL_PROCESS;
    static PduType GRIDDED_DATA;
    static PduType POINT_OBJECT_STATE;
    static PduType LINEAR_OBJECT_STATE;
    static PduType AREAL_OBJECT_STATE;
    static PduType TSPI;
    static PduType APPEARANCE;
    static PduType ARTICULATED_PARTS;
    static PduType LE_FIRE;
    static PduType LE_DETONATION;
    static PduType CREATE_ENTITY_R;
    static PduType REMOVE_ENTITY_R;
    static PduType START_RESUME_R;
    static PduType STOP_FREEZE_R;
    static PduType ACKNOWLEDGE_R;
    static PduType ACTION_REQUEST_R;
    static PduType ACTION_RESPONSE_R;
    static PduType DATA_QUERY_R;
    static PduType SET_DATA_R;
    static PduType DATA_R;
    static PduType EVENT_REPORT_R;
    static PduType COMMENT_R;
    static PduType RECORD_R;
    static PduType SET_RECORD_R;
    static PduType RECORD_QUERY_R;
    static PduType COLLISION_ELASTIC;
    static PduType ENTITY_STATE_UPDATE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static PduType getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,PduType*> enumContainer;
    static enumContainer getEnumerations();

    PduType& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  PduType(int value, std::string description);

	  static PduType* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* PduType */


}  /* namespace DIS */

#endif /* PDUTYPE__H */

