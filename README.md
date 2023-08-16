# DIS Enumerations

This is older, essentially obsolete software, but the code generated is still somewhat useful.

SISO did an initial description of DIS entities in `siso-std-10.xml`, which contains names and descriptions to accompany arbitrary numbers. 
The problem is that the format of the code here should be rewritten to match the new XML format used by SISO. 
But, in the end, the output here is still kind of useful as is.

This is what the XML looked like for PDU types, for example:

~~~
 <enum length="8" id="2" cname="pduheader.pdutype" name="PDU Type" source="3.2">
    <enumrow id="0" description="Other"/>
    <enumrow id="1" description="Entity State"/>
    <enumrow id="2" description="Fire"/>
    <enumrow id="3" description="Detonation"/>
    <enumrow id="4" description="Collision"/>
    <enumrow id="5" description="Service Request"/>
~~~

This shows "Entity State" associated with the number 1, meaning that all entity state PDUs should have an ID number of 1. 
It's the number that's actually included in the packet transmitted over the network or DIS code.

We want language constants that let us use English-like, but also code-friendly variable names that help us read code.
This, for example, is not very readable:

~~~
if (aPdu.type == 1) {
   doSomething();
}
~~~

What does 1 mean? The following is easier to read and is the purpose of this dis-enumerations library:

~~~
if (aPdu.type == PduType.ENTITY_STATE.value) {
  doSomething();
}
~~~

Here is an example Java enumeration provided by the dis-enumerations library.

~~~
public enum PduType {
    OTHER(0, "Other"),
    ENTITY_STATE(1, "Entity State"),
    FIRE(2, "Fire"),
    DETONATION(3, "Detonation"),
    COLLISION(4, "Collision"),
    SERVICE_REQUEST(5, "Service Request"),
    RESUPPLY_OFFER(6, "Resupply Offer"),
...  
    /** The enumerated value */
    public final int value;

    /** Text/english description of the enumerated value */
    public final String description;
~~~

And so on.
In this case the XML includes the text "Entity State", including the space.
That's translated into a Java-friendly variable name, entirely capitalized, with no spaces in the ENTITY_STATE name.
Other examples of the text from the XML can include commas and such.
The generating code translates it into language-firendly text. 
The constant name used, such as "ENTITY_STATE", is somewhat arbitrary.

Again, the XML format from SISO has changed some since this code has been written, so the code needs to be modified a bit.

Also, I've added a non-generated `PduTypeDIS7` file manually, rather than auto-generating it. 
DIS7 has some slightly different names for some PDUs, kind of, since the PDU names aren't exactly official.
There's no XML to generate it, but it's still useful to have the PDU types enumeration for DIS7. 

Also, there are some generated enumerations for C# and c++. 
Pretty primitive, though.
