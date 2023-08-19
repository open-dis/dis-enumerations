#ifndef @BITMASKUPPERCASE__H
#define @BITMASKUPPERCASE__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

namespace @BITMASK {

	/** Bitmask declaration **/
	struct bitmask {
@BITFIELDS
    bitmask& operator=(const @TYPE& i);
	  bitmask(const @TYPE& i);
	  bitmask();
	  @TYPE getValue();
	  void  setValue(const @TYPE& i);
	};

	/** Enumerations declaration **/
@ENUMSHEADER


}; /* namespace @BITMASK */

}  /* namespace DIS */

#endif /* @BITMASKUPPERCASE__H */
