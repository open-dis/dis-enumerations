#ifndef DISENUMERATION__H
#define DISENUMERATION__H

#include <stdexcept>
#include <ostream>

#include <disenum/enumcfg.h>

namespace DIS {

class EnumException : public std::runtime_error {
  public:
    EnumException(std::string enumName, int aVal, std::string msg = ""):
      std::runtime_error(msg), _aVal(aVal), _enumName(enumName) { };
    std::string getEnumName() const   {return _enumName;};
    int getValNotFound() const {return _aVal;};
    ~EnumException () throw () {};
  private:
    int _aVal;
    std::string _enumName;

}; /* EnumException */


class Enumeration {
  public:
    /** Returns the enumerated value for this enumeration */
    int getValue() const {return value;};

    /** Returns a text description for this enumerated value. This is usually used as the basis for the enumeration name. */
    std::string getDescription() const {return description;};

  protected:
    /** The enumerated value */
    int value;
    /** Text/english description of the enumerated value */
    std::string description;
    /** Constructor */
    Enumeration(int _value, std::string _description) : value(_value), description(_description) {};
}; /* Enumeration */



inline
std::ostream& operator<<( std::ostream& os, const Enumeration& e ) {
  return os << e.getDescription();
};




}  /* namespace DIS */

#endif /* DISENUMERATION__H */
