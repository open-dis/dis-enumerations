#ifndef DER_IFF_TYPE_5_FOP_PARAM2__H
#define DER_IFF_TYPE_5_FOP_PARAM2__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace der_iff_type_5_fop_param2 {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int unused:16;

    bitmask& operator=(const unsigned short& i);
	  bitmask(const unsigned short& i);
	  bitmask();
	  unsigned short getValue();
	  void  setValue(const unsigned short& i);
	};

	/** Enumerations declaration **/



}; /* namespace der_iff_type_5_fop_param2 */

}  /* namespace DIS */

#endif /* DER_IFF_TYPE_5_FOP_PARAM2__H */
