#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_5_fop_param4.h>

namespace DIS {

namespace der_iff_type_5_fop_param4 {

  bitmask& bitmask::operator=(const unsigned short& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned short*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned short& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned short) 0;
  }

  unsigned short bitmask::getValue(){
    unsigned short val = *( reinterpret_cast<unsigned short *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned short& i){
	  (*this) = i;
  }




}; /* namespace der_iff_type_5_fop_param4 */

} /* namespace DIS */
