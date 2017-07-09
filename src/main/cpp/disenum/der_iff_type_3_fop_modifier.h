#ifndef DER_IFF_TYPE_3_FOP_MODIFIER__H
#define DER_IFF_TYPE_3_FOP_MODIFIER__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_iff_type_3_fop_modifier {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int unused:8;

    bitmask& operator=(const unsigned char& i);
	  bitmask(const unsigned char& i);
	  bitmask();
	  unsigned char getValue();
	  void  setValue(const unsigned char& i);
	};

	/** Enumerations declaration **/



}; /* namespace der_iff_type_3_fop_modifier */

}  /* namespace DIS */

#endif /* DER_IFF_TYPE_3_FOP_MODIFIER__H */
