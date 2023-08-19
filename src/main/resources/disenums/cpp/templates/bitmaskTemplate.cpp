#include <sstream>
#include <cstddef>
#include <disenum/@BITMASK.h>

namespace DIS {

namespace @BITMASK {

  bitmask& bitmask::operator=(const @TYPE& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<@TYPE*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const @TYPE& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (@TYPE) 0;
  }

  @TYPE bitmask::getValue(){
    @TYPE val = *( reinterpret_cast<@TYPE *> (this));
    return val;
  }

  void bitmask::setValue(const @TYPE& i){
	  (*this) = i;
  }

@ENUMSIMPL


}; /* namespace @BITMASK */

} /* namespace DIS */
