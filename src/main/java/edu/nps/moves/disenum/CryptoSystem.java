package edu.nps.moves.disenum;

import java.util.HashMap;
import edu.nps.moves.siso.EnumNotFoundException;

/** Enumeration values for CryptoSystem
 * The enumeration values are generated from the SISO DIS XML EBV document (R35), which was
 * obtained from http://discussions.sisostds.org/default.asp?action=10&fd=31<p>
 *
 * Note that this has two ways to look up an enumerated instance from a value: a fast
 * but brittle array lookup, and a slower and more garbage-intensive, but safer, method.
 * if you want to minimize memory use, get rid of one or the other.<p>
 *
 * Copyright 2008-2009. This work is licensed under the BSD license, available at
 * http://www.movesinstitute.org/licenses<p>
 *
 * @author DMcG, Jason Nelson
 */

public enum CryptoSystem 
{

    NO_ENCRYPTION_DEVICE(0, "No Encryption Device"),
    KY_28(1, "KY-28"),
    VINSON_KY_57_KY_58_SINCGARS_ICOM(2, "VINSON (KY-57, KY-58, SINCGARS ICOM)"),
    NARROW_SPECTRUM_SECURE_VOICE_NSVE(3, "Narrow Spectrum Secure Voice (NSVE)"),
    WIDE_SPECTRUM_SECURE_VOICE_WSVE(4, "Wide Spectrum Secure Voice (WSVE)"),
    SINCGARS_ICOM(5, "SINCGARS ICOM"),
    KY_75(6, "KY-75"),
    KY_100(7, "KY-100"),
    KY_57(8, "KY-57"),
    KYV_5(9, "KYV-5"),
    LINK_11_KG_40A_P_NTDS(10, "Link 11 KG-40A-P (NTDS)"),  
    LINK_11B_KG_40A_S(11, "Link 11B KG-40A-S"),   
    LINK_11_KG_40AR(12, "Link 11 KG-40AR"),   
    KGV_135A(13, "KGV-135A");   

    /** The enumerated value */
    public final int value;

    /** Text/english description of the enumerated value */
    public final String description;

/** This is an array, with each slot corresponding to an enumerated value. This is a fast but brittle way to look up
 * enumerated values. If there is no enumeration corresponding to the value it will fail, and it will also fail if the
 * index it out of range of the array. But it is fast, and generates less garbage than the alternative of using 
 * getEnumerationForValue(). It should be used only in real-time environments, and be careful even then.<p>
 * Use as CryptoSystem.lookup[aVal] to get the enumeration that corresponds to a value.<p>
 * In non-realtime environments, the prefered method is getEnumerationForValue().
 */
static public CryptoSystem lookup[] = new CryptoSystem[14];

static private HashMap<Integer, CryptoSystem>enumerations = new HashMap<Integer, CryptoSystem>();

/* initialize the array and hash table at class load time */
static 
{
    for(CryptoSystem anEnum:CryptoSystem.values())
    {
        lookup[anEnum.value] = anEnum;
        enumerations.put(new Integer(anEnum.getValue()), anEnum);
    }
}

/** Constructor */
CryptoSystem(int value, String description)
{
    this.value = value;
    this.description = description;
}

/** Returns the string description associated with the enumerated instance with this value. 
 * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.
*/
static public String getDescriptionForValue(int aVal)
{
  String desc;

    CryptoSystem val = enumerations.get(new Integer(aVal));
      if(val == null)
        desc = "Invalid enumeration: " + (new Integer(aVal)).toString();
      else
         desc = val.getDescription();

      return desc;
}

/** Returns the enumerated instance with this value. 
 * If there is no enumerated instance for this value, the exception is thrown.
*/
static public CryptoSystem getEnumerationForValue(int aVal) throws EnumNotFoundException
{
    CryptoSystem val;
      val = enumerations.get(new Integer(aVal));
      if(val == null)
         throw new EnumNotFoundException("no enumeration found for value " + aVal + " of enumeration CryptoSystem");
      return val;
}

/** Returns true if there is an enumerated instance for this value, false otherwise. 
*/
static public boolean enumerationForValueExists(int aVal)
{
    CryptoSystem val;
      val = enumerations.get(new Integer(aVal));
      if(val == null)
         return false;
      return true;
}

/** Returns the enumerated value for this enumeration */
public int getValue()
{
  return value;
}


/** Returns a text descriptioni for this enumerated value. This is usually used as the basis for the enumeration name. */
public String getDescription()
{
  return description;
}

}
