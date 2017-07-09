
package edu.nps.moves.siso;

/**
 * An exception thrown when a number does not correspond to any known
 * value of enumeration.<p>
 * 
 * @author DMcG
 */
public class EnumNotFoundException extends Exception {

    /**
     * Creates a new instance of <code>EnumNotFoundException</code> without detail message.
     */
    public EnumNotFoundException() {
    }


    /**
     * Constructs an instance of <code>EnumNotFoundException</code> with the specified detail message.
     * @param msg the detail message.
     */
    public EnumNotFoundException(String msg) {
        super(msg);
    }
}
