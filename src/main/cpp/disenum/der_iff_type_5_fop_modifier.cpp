#include <sstream>
#include <cstddef>
#include <disenum/der_iff_type_5_fop_modifier.h>

namespace DIS {

namespace der_iff_type_5_fop_modifier {

  bitmask& bitmask::operator=(const unsigned char& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned char*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned char& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned char) 0;
  }

  unsigned char bitmask::getValue(){
    unsigned char val = *( reinterpret_cast<unsigned char *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned char& i){
	  (*this) = i;
  }




}; /* namespace der_iff_type_5_fop_modifier */

} /* namespace DIS */
