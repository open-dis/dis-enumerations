#ifndef ES_APPEAR_SUPPLIES__H
#define ES_APPEAR_SUPPLIES__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace es_appear_supplies {

	/** Bitmask declaration **/
	struct bitmask {
    unsigned int unused:32;

    bitmask& operator=(const unsigned int& i);
	  bitmask(const unsigned int& i);
	  bitmask();
	  unsigned int getValue();
	  void  setValue(const unsigned int& i);
	};

	/** Enumerations declaration **/



}; /* namespace es_appear_supplies */

}  /* namespace DIS */

#endif /* ES_APPEAR_SUPPLIES__H */
