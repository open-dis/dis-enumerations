
package edu.nps.moves.siso;

import java.io.*;
import java.util.*;
import javax.xml.bind.*;

import edu.nps.moves.siso.jaxb.*;

/**
 * Reads the SISO EBV XML document and turns it into java enumeration objects.
 * The SISO EBV document is available (as of this writing) at the SISO enum
 * mailing list, http://discussions.sisostds.org/default.asp?action=10&fid=31
 * 
 * 
 * @author DMcG, Jason Nelson
 * Modified by Peter Smith to output C#
 * Modified by Zvonko Bostjancic (zvonko.bostjancic@blubit.si) to output better C#
 */
public class EBVReaderCsharp 
{
    /** Location of EBV document. This should match up with the schema available
     * in the data directory. JAXB was used to generate the classes in 
     * edu.nps.moves.siso.jaxb, which is used to parse and databind the 
     * xml document--if the schema changes, you'll have to regenerate those
     * classes.
     */
    public static final String EBV_XML_DOCUMENT = "data/siso-std-010.xml";
    public static final Hashtable<String, String> sisoToObjectName = new Hashtable<String, String>();
    public static final Hashtable<String, Hashtable<Integer, String>> sisoObjectValueNames = new Hashtable<String, Hashtable<Integer, String>>();
    public static final Hashtable<String, String> sisoToNamespaces = new Hashtable<String, String>();

    private static void loadSisoObjectNames()
    {
        sisoToObjectName.put("pduheader.protocolversion", "Protocol Version");
        sisoToObjectName.put("pduheader.pdutype", "Pdu Type");
        sisoToObjectName.put("pduheader.protocolfamily", "Protocol Family");
        sisoToObjectName.put("es.forceid", "Entity Force Id");
        sisoToObjectName.put("es.type.kind", "Entity Kind");
        sisoToObjectName.put("es.type.kind.1.domain", "Platform");
        sisoToObjectName.put("es.type.kind.1.domain.1.cat", "Land Platform");
        sisoToObjectName.put("es.type.kind.1.domain.2.cat", "Air Platform");
        sisoToObjectName.put("es.type.kind.1.domain.3.cat", "Surface Platform");
        sisoToObjectName.put("es.type.kind.1.domain.4.cat", "Subsufrace Platform");
        sisoToObjectName.put("es.type.kind.1.domain.5.cat", "Space Platform");
        sisoToObjectName.put("es.type.kind.2.domain", "Munition");
        sisoToObjectName.put("es.type.kind.2.cat", "Munition Category");
        sisoToObjectName.put("es.type.225.kind.3.subcat", "US Weapons for Life Forms");
        sisoToObjectName.put("es.type.222.kind.3.suCommunicationTypebcat", "CIS Weapons for Life Forms");
        sisoToObjectName.put("es.type.224.kind.3.subcat", "U.K. Weapons for Life Forms");
        sisoToObjectName.put("es.type.71.kind.3.subcat", "French Weapons for Life Forms");
        sisoToObjectName.put("es.type.78.kind.3.subcat", "German Weapons for Life Forms");
        sisoToObjectName.put("es.type.kind.4.subcat", "Environmental Subcategory");
        sisoToObjectName.put("es.type.kind.7.cat", "Radio Category");
        sisoToObjectName.put("es.type.kind.7.version", "Radio Nomenclature Version");
        sisoToObjectName.put("es.type.kind.7.nomenclature", "Radio Nomenclature");
        sisoToObjectName.put("es.type.kind.8.domain.2.cat", "Expendable Air Category");
        sisoToObjectName.put("es.type.kind.8.domain.3.cat", "Expendable Surface Category");
        sisoToObjectName.put("es.type.kind.8.domain.4.cat", "Expendable Subsurface Category");
        sisoToObjectName.put("es.type.kind.9.cat", "Sensor Emitter Category");
        sisoToObjectName.put("es.appear.platform.land", "Land Platform Appearance");
        sisoToObjectName.put("es.appear.platform.air", "Air Platform Appearance");
        sisoToObjectName.put("es.appear.platform.surface", "Surface Platform Appearance");
        sisoToObjectName.put("es.appear.platform.subsurface", "Subsurface Platform Appearance");
        sisoToObjectName.put("es.appear.platform.space", "Space Platform Appearance");
        sisoToObjectName.put("es.appear.munition", "Munition Appearance");
        sisoToObjectName.put("es.appear.lifeform", "Life Form Appearance");
        sisoToObjectName.put("es.appear.environmental", "Environmental Appearance");
        sisoToObjectName.put("es.appear.cultural", "Cultural Appearance");
        sisoToObjectName.put("es.appear.supplies", "Supplies Appearance");
        sisoToObjectName.put("es.appear.radios", "Radios Appearance");
        sisoToObjectName.put("es.appear.expendables", "Expandables Appearance");
        sisoToObjectName.put("es.appear.sensoremitter", "Sensor Emitter Appearance");
        sisoToObjectName.put("es.dra", "Dead Reckoning Algorithm");
        sisoToObjectName.put("es.markingtext", "Entity Marking Text");
        sisoToObjectName.put("es.markingtext.cctt.div", "Army Marking Division Corps Designation");
        sisoToObjectName.put("es.markingtext.cctt.1cavunit", "Army Marking High Level Unit For 1st Cavalry");
        sisoToObjectName.put("es.markingtext.cctt.1infunit", "Army Marking High Level Unit For 1st Infantry");
        sisoToObjectName.put("es.markingtext.cctt.company", "Army Marking Company");
        sisoToObjectName.put("es.markingtext.cctt.platoon", "Army Marking Platoon");
        sisoToObjectName.put("es.markingtext.cctt.vehicle", "Army Marking Vehicle");
        sisoToObjectName.put("es.markingtext.cctt.symbol1", "Army Marking Marking Codes");
        sisoToObjectName.put("es.markingtext.cctt.symbol2", "Army Marking Platoon Codes");
        sisoToObjectName.put("es.markingtext.chevron.symbol", "Digit Chevron Marking Codes");
        sisoToObjectName.put("es.capabilities", "Entity Capabilities");
        sisoToObjectName.put("es.vp.type", "Parameter Type Designator");
        sisoToObjectName.put("es.vp.type.1.attached", "Attached Parts");
        sisoToObjectName.put("es.vp.type.0.articulated.offset", "Articulated Part Offset");
        sisoToObjectName.put("es.vp.type.0.articulated.index", "Articulated Part Index");
        sisoToObjectName.put("warfare.burstdescriptor.warhead", "Warhead");
        sisoToObjectName.put("warfare.burstdescriptor.fuse", "Fuse");
        sisoToObjectName.put("warfare.detonationresult", "Detonation Result");
        sisoToObjectName.put("log.servicerequest", "Service Request Type");
        sisoToObjectName.put("log.repaircomplete.general", "General Repair Code");
        sisoToObjectName.put("log.repaircomplete.drivetrain", "Drive Train Repair Code");
        sisoToObjectName.put("log.repaircomplete.hull", "Hull Airframe Body Repair Code");
        sisoToObjectName.put("log.repaircomplete.environment", "Interfaces With Environment Repair Code");
        sisoToObjectName.put("log.repaircomplete.weapons", "Weapon Repair Code");
        sisoToObjectName.put("log.repaircomplete.fuelsystem", "Fuel System Repair Code");
        sisoToObjectName.put("log.repaircomplete.electronics", "Electronics Repair Code");
        sisoToObjectName.put("log.repaircomplete.lifesupport", "Life Support Repair Code");
        sisoToObjectName.put("log.repaircomplete.hydraulics", "Hydraulic Repair Code");
        sisoToObjectName.put("log.repaircomplete.auxilary", "Auxilary Craft Repair Code");
        sisoToObjectName.put("log.repairresponse", "Response Result Code");
        sisoToObjectName.put("simman.datumid", "Datum Specification Record");
        sisoToObjectName.put("simman.stop.reason", "Stop Freeze Reason");
        sisoToObjectName.put("simman.stop.frozenbehavior", "Frozen Behavior");
        sisoToObjectName.put("simman.ack.ackflag", "Acknowledge Flag");
        sisoToObjectName.put("simman.ack.responseflag", "Response Flag");
        sisoToObjectName.put("simman.actionrequest.actionid", "Action Id");
        sisoToObjectName.put("simman.actionresponse.status", "Action Response Request Status");
        sisoToObjectName.put("simman.eventreport.eventtype", "Event Type");
        sisoToObjectName.put("simman.reliability.service", "Required Reliability Service");
        sisoToObjectName.put("der.emission.name.electro", "Electromagnetic Emitters");
        sisoToObjectName.put("der.emission.name.acoustic", "Acoustic Emitters");
        sisoToObjectName.put("der.emission.name.other", "Other Emitters");
        sisoToObjectName.put("der.emission.function", "Emission Function");
        sisoToObjectName.put("der.emission.beamfunction", "Emission Beam Function");
        sisoToObjectName.put("der.emission.stateupdate", "State Update Indicator");
        sisoToObjectName.put("der.emission.hdtj", "High Density Track Or Jam");
        sisoToObjectName.put("der.designator.codename", "Designator Code Name");
        sisoToObjectName.put("der.designator.code", "Designator Code");
        sisoToObjectName.put("der.iff.type", "System Type");
        sisoToObjectName.put("der.iff.name", "System Name");
        sisoToObjectName.put("der.iff.mode", "System Mode");
        sisoToObjectName.put("der.iff.fop.status", "System Status");
        sisoToObjectName.put("der.iff.infolayers", "Information Layers");
        sisoToObjectName.put("der.iff.layerspecific", "Layer Specific Information");
        sisoToObjectName.put("der.iff.type.1.changeoptions", "Type 1 Change Options");
        sisoToObjectName.put("der.iff.type.1.fop.param1", "Type 1 Parameter 1 Mode 1 Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.param2", "Type 1 Parameter 2 Mode 2 Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.param3", "Type 1 Parameter 3 Mode 3 Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.param4", "Type 1 Parameter 4 Mode 4 Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.param5", "Type 1 Parameter 5 Mode C Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.param6", "Type 1 Parameter 6 Mode S Code Status");
        sisoToObjectName.put("der.iff.type.1.fop.modifier", "Type 1 Modifier");
        sisoToObjectName.put("der.iff.type.1.fop.altp4", "Type 1 Alternate Parameter 4");
        sisoToObjectName.put("der.iff.type.1.sop.param1", "Type 1 Operational Parameter 1");
        sisoToObjectName.put("der.iff.type.1.sop.param2", "Type 1 Operational Parameter 2");
        sisoToObjectName.put("der.iff.type.2.changeoptions", "Type 2 Change Options");
        sisoToObjectName.put("der.iff.type.2.fop.param1", "Type 2 Parameter 1 Mode 1 Interrogator Status");
        sisoToObjectName.put("der.iff.type.2.fop.param2", "Type 2 Parameter 2 Mode 2 Interrogator Status");
        sisoToObjectName.put("der.iff.type.2.fop.param3", "Type 2 Parameter 3 Mode 3 Interrogator Status");
        sisoToObjectName.put("der.iff.type.2.fop.param4", "Type 2 Parameter 4 Mode 4 Interrogator Status");
        sisoToObjectName.put("der.iff.type.2.fop.param5", "Type 2 Parameter 5 Mode C Interrogator Status");
        sisoToObjectName.put("der.iff.type.2.fop.param6", "Type 2 Parameter 6 Mode S Code Status");
        sisoToObjectName.put("der.iff.type.2.fop.modifier", "Type 2 Modifier");
        sisoToObjectName.put("der.iff.type.2.fop.altp4", "Type 2 Alternate Parameter 4");
        sisoToObjectName.put("der.iff.type.2.sop.param1", "Type 2 Operational Parameter 1");
        sisoToObjectName.put("der.iff.type.2.sop.param2", "Type 2 Operational Parameter 2");
        sisoToObjectName.put("der.iff.type.3.changeoptions", "Type 3 Change Options");
        sisoToObjectName.put("der.iff.type.3.fop.param1", "Type 3 Parameter 1 Mode 1 Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.param2", "Type 3 Parameter 2 Mode 2 Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.param3", "Type 3 Parameter 3 Mode 3 Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.param4", "Type 3 Parameter 4 Mode 4 Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.param5", "Type 3 Parameter 5 Mode C Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.param6", "Type 3 Parameter 6 Mode 1 Code Status");
        sisoToObjectName.put("der.iff.type.3.fop.modifier", "Type 3 Modifier");
        sisoToObjectName.put("der.iff.type.3.fop.altp4", "Type 3 Alternate Parameter 4");
        sisoToObjectName.put("der.iff.type.3.sop.param1", "Type 3 Operational Parameter 1");
        sisoToObjectName.put("der.iff.type.3.sop.param2", "Type 3 Operational Parameter 2");
        sisoToObjectName.put("der.iff.type.4.changeoptions", "Type 4 Change Options");
        sisoToObjectName.put("der.iff.type.4.fop.param1", "Type 4 Parameter 1");
        sisoToObjectName.put("der.iff.type.4.fop.param2", "Type 4 Parameter 2");
        sisoToObjectName.put("der.iff.type.4.fop.param3", "Type 4 Parameter 3");
        sisoToObjectName.put("der.iff.type.4.fop.param4", "Type 4 Parameter 4");
        sisoToObjectName.put("der.iff.type.4.fop.param5", "Type 4 Parameter 5");
        sisoToObjectName.put("der.iff.type.4.fop.param6", "Type 4 Parameter 6");
        sisoToObjectName.put("der.iff.type.4.fop.modifier", "Type 4 Modifier");
        sisoToObjectName.put("der.iff.type.4.fop.altp4", "Type 4 Alternate Parameter 4");
        sisoToObjectName.put("der.iff.type.4.sop.param1", "Type 4 Operational Parameter 1");
        sisoToObjectName.put("der.iff.type.4.sop.param2", "Type 4 Operational Parameter 2");
        sisoToObjectName.put("der.iff.type.5.changeoptions", "Type 5 Change/Options");
        sisoToObjectName.put("der.iff.type.5.fop.param1", "Type 5 Parameter 1 - RRB Response");
        sisoToObjectName.put("der.iff.type.5.fop.param2", "Type 5 Parameter 2");
        sisoToObjectName.put("der.iff.type.5.fop.param3", "Type 5 Parameter 3");
        sisoToObjectName.put("der.iff.type.5.fop.param4", "Type 5 Parameter 4");
        sisoToObjectName.put("der.iff.type.5.fop.param5", "Type 5 Parameter 5");
        sisoToObjectName.put("der.iff.type.5.fop.param6", "Type 5 Parameter 6");
        sisoToObjectName.put("der.iff.type.5.fop.modifier", "Type 5 Modifier");
        sisoToObjectName.put("der.iff.type.5.fop.altp4", "Type 5 Alternate Parameter 4");
        sisoToObjectName.put("der.iff.type.5.sop.param1", "Type 5 Operational Parameter 1");
        sisoToObjectName.put("der.iff.type.5.sop.param2", "Type 5 Operational Parameter 2");
        sisoToObjectName.put("der.ua.statechangeupdate", "State Change Update Indicator");
        sisoToObjectName.put("der.ua.systemname", "System Name");
        sisoToObjectName.put("der.ua.function", "Emitter Function");
        sisoToObjectName.put("der.ua.activeparameterindex", "Active Emission Parameter Index");
        sisoToObjectName.put("der.ua.scanpattern", "Scan Pattern");
        sisoToObjectName.put("der.ua.passiveparameterindex", "Passive Parameter Index");
        sisoToObjectName.put("der.ua.ppcfg", "Propulsion Plant Configuration");
        sisoToObjectName.put("der.ua.apaparameterindex", "Additional Passive Activity Parameter Index");
        sisoToObjectName.put("der.sees.power.helicopters", "Helicopter Engine Power");
        sisoToObjectName.put("der.sees.power.tanks", "Tank Engine Power");
        sisoToObjectName.put("der.sees.power.aircraft", "Aircraft Engine Power");
        sisoToObjectName.put("radio.tx.mod.spreadspectrum", "Spread Spectrum");
        sisoToObjectName.put("radio.tx.mod.major", "Major Modulation");
        sisoToObjectName.put("radio.tx.mod.major.1.detail", "Detailed modulation for amplitude modulation");
        sisoToObjectName.put("radio.tx.mod.major.2.detail", "Detailed modulation for amplitude and angle modulation");
        sisoToObjectName.put("radio.tx.mod.major.3.detail", "Detailed modulation for angle modulation");
        sisoToObjectName.put("radio.tx.mod.major.4.detail", "Detailed modulation for combination modulation");
        sisoToObjectName.put("radio.tx.mod.major.5.detail", "Detailed modulation for pulse modulation");
        sisoToObjectName.put("radio.tx.mod.major.6.detail", "Detailed modulation for unmodulated modulation");
        sisoToObjectName.put("radio.tx.mod.major.7.detail", "Detailed Modulation for Carrier Phase Shift");
        sisoToObjectName.put("radio.tx.mod.system", "Transmitter Modulation System Type");
        sisoToObjectName.put("radio.tx.state", "Transmit State");
        sisoToObjectName.put("radio.tx.inputsource", "Input Source");
        sisoToObjectName.put("radio.tx.cryptosystem", "Crypto System");
        sisoToObjectName.put("radio.tx.antennapatterntype", "Antenna Pattern Type");
        sisoToObjectName.put("radio.tx.referencesystem", "Reference System");
        sisoToObjectName.put("radio.tx.modparam.cctt", "CCTT SINCGARS Modulation Parameters");
        sisoToObjectName.put("radio.tx.param.cctt.start", "Start of Message");
        sisoToObjectName.put("radio.tx.param.cctt.clear", "Clear Channel");
        sisoToObjectName.put("radio.tx.modparam.jtids", "JTIDS/MIDS Modulation Parameters");
        sisoToObjectName.put("radio.tx.param.jtids.mode1", "Jtids Transmitting Terminal Primary Mode");
        sisoToObjectName.put("radio.tx.param.jtids.mode2", "Jtids Transmitting Terminal Secondary Mode");
        sisoToObjectName.put("radio.tx.param.jtids.sync", "Jtids Synchronization State");
        sisoToObjectName.put("radio.tx.encoding", "Radio signal encoding");
        sisoToObjectName.put("radio.tx.protocolid", "User Protocol Identification Number");
        sisoToObjectName.put("radio.tx.tdltype", "TDL Type");
        sisoToObjectName.put("radio.rx.state", "Receiver State");
        sisoToObjectName.put("radio.ic.controltype", "Control Type");
        sisoToObjectName.put("radio.ic.commtype", "Communications Type");
        sisoToObjectName.put("radio.ic.command", "Command");
        sisoToObjectName.put("radio.ic.transmitstate", "Transmit Line State");
        sisoToObjectName.put("radio.ic.deststate", "Destination Line State Command");
        sisoToObjectName.put("radio.ic.param.type", "Record type");
        sisoToObjectName.put("radio.ic.paramrecords.dest", "Entity Destination record");
        sisoToObjectName.put("radio.ic.paramrecords.groupdest", "Group Destination record");
        sisoToObjectName.put("radio.ic.paramrecords.gassign", "Group Assignment record");
        sisoToObjectName.put("entity.collision.type", "Entity Collision Type");
        sisoToObjectName.put("entity.mine.appear", "Appearance");
        sisoToObjectName.put("entity.mine.datafilter", "Data Filter");
        sisoToObjectName.put("entity.mine.fusing", "Fusing");
        sisoToObjectName.put("entity.mine.sensortype", "Sensor Types");
        sisoToObjectName.put("entity.mine.sensortype.1.subcat", "Optical Sensor");
        sisoToObjectName.put("entity.mine.sensortype.2.subcat", "Flir Sensor");
        sisoToObjectName.put("entity.mine.sensortype.3.subcat", "Radar Sensor");
        sisoToObjectName.put("entity.mine.sensortype.4.subcat", "Magnetic Sensor");
        sisoToObjectName.put("entity.mine.sensortype.5.subcat", "Laser Sensor");
        sisoToObjectName.put("entity.mine.sensortype.6.subcat", "Sonar Sensor");
        sisoToObjectName.put("entity.mine.sensortype.7.subcat", "Physical Sensor");
        sisoToObjectName.put("entity.mine.sensortype.8.subcat", "Multispectral Sensor");
        sisoToObjectName.put("entity.mine.paintscheme", "Paint Scheme");
        sisoToObjectName.put("entity.mine.protocolmode", "Protocol Mode");
        sisoToObjectName.put("eman.aggregate.state", "Aggregate State");
        sisoToObjectName.put("eman.aggregate.formation", "Aggregate Formation");
        sisoToObjectName.put("eman.aggregate.type.kind", "Aggregate Kind");
        sisoToObjectName.put("eman.aggregate.type.subcategory", "Aggregate Subcategory");
        sisoToObjectName.put("eman.aggregate.type.specific", "Aggregate Specific");
        sisoToObjectName.put("eman.ispartof.nature", "Part Of Nature");
        sisoToObjectName.put("eman.ispartof.position", "Part Of Position");
        sisoToObjectName.put("eman.ispartof.stationname", "Part Of Station Name");
        sisoToObjectName.put("eman.isgroupof.category", "Group Of Grouped Entity Category");
        sisoToObjectName.put("eman.isgroupof.reststatus", "Group Of Rest Status");
        sisoToObjectName.put("eman.isgroupof.record1", "Grouped Entity Description Record 1");
        sisoToObjectName.put("eman.isgroupof.record2", "Grouped Entity Description Record 2");
        sisoToObjectName.put("eman.isgroupof.record3", "Grouped Entity Description Record 3");
        sisoToObjectName.put("eman.isgroupof.record4", "Grouped Entity Description Record 4");
        sisoToObjectName.put("eman.isgroupof.record5", "Grouped Entity Description Record 5");
        sisoToObjectName.put("eman.isgroupof.record6", "Grouped Entity Description Record 6");
        sisoToObjectName.put("eman.isgroupof.record7", "Grouped Entity Description Record 7");
        sisoToObjectName.put("eman.isgroupof.record8", "Grouped Entity Description Record 8");
        sisoToObjectName.put("eman.isgroupof.record9", "Grouped Entity Description Record 9");
        sisoToObjectName.put("eman.tc.transfertype", "Transfer Type");
        sisoToObjectName.put("env.obj.objecttype.kind", "Object Kind");
        sisoToObjectName.put("env.obj.appear.general", "General Appearance");
        sisoToObjectName.put("env.obj.appear.point.building", "Building Rubble Stationary Bridge and AVLB Appearance");
        sisoToObjectName.put("env.obj.appear.point.breach", "Log crib, Abatis, Vehicle defilade, and Infantry fighting position");
        sisoToObjectName.put("env.obj.appear.point.burst", "Air burst And Ground burst");
        sisoToObjectName.put("env.obj.appear.point.crater", "Crater");
        sisoToObjectName.put("env.obj.appear.point.bridge", "Ribbon Bridge");
        sisoToObjectName.put("env.obj.appear.linear.tankditch", "Tank ditch, and Concertina Wire");
        sisoToObjectName.put("env.obj.appear.linear.exhaust", "Exhaust smoke");
        sisoToObjectName.put("env.obj.appear.linear.marker", "Minefield Lane Marker");
        sisoToObjectName.put("env.obj.appear.linear.breach", "Breach");
        sisoToObjectName.put("env.obj.appear.areal.minefield", "Minefield");
        sisoToObjectName.put("env.obj.mod.point", "Point Object State PDU Modification Field");
        sisoToObjectName.put("env.obj.mod.linear", "Linear Object State PDU Modification Field");
        sisoToObjectName.put("env.obj.mod.areal", "Areal Object State PDU Modification Field");
        sisoToObjectName.put("env.gridded.fieldnumber", "Field Number");
        sisoToObjectName.put("env.gridded.coordinatesystem", "Coordinate System");
        sisoToObjectName.put("env.gridded.constantgrid", "Constant Grid");
        sisoToObjectName.put("env.gridded.sampletype", "Sample Type");
        sisoToObjectName.put("env.gridded.datarepresentation", "Data Representation Type");
        sisoToObjectName.put("env.process.modeltype", "Model Type");
        sisoToObjectName.put("env.process.environmentstatus", "Environment Status");
        sisoToObjectName.put("env.process.type.geometryrecord", "Environmental Process Types For Geometry Record");
        sisoToObjectName.put("env.process.geom.point1", "Point Record 1");
        sisoToObjectName.put("env.process.geom.point2", "Point Record 2");
        sisoToObjectName.put("env.process.geom.line1", "Line Record 1");
        sisoToObjectName.put("env.process.geom.line2", "Line Record 2");
        sisoToObjectName.put("env.process.geom.boundingsphere", "Bounding Sphere Record");
        sisoToObjectName.put("env.process.geom.sphere1", "Sphere Record 1");
        sisoToObjectName.put("env.process.geom.sphere2", "Sphere Record 2");
        sisoToObjectName.put("env.process.geom.ellipsoid1", "Ellipsoid Record 1");
        sisoToObjectName.put("env.process.geom.ellipsoid2", "Ellipsoid Record 2");
        sisoToObjectName.put("env.process.geom.cone1", "Cone Record 1");
        sisoToObjectName.put("env.process.geom.cone2", "Cone Record 2");
        sisoToObjectName.put("env.process.geom.rect1", "Rectangular Record 1");
        sisoToObjectName.put("env.process.geom.rect2", "Rectangular Record 2");
        sisoToObjectName.put("env.process.geom.gplume", "Gaussian Plume Record");
        sisoToObjectName.put("env.process.geom.gpuff", "Gaussian Puff Record");
        sisoToObjectName.put("env.process.geom.uniform", "Uniform Geometry Record");
        sisoToObjectName.put("env.process.geom.rect3", "Rectangular Record 3");
        sisoToObjectName.put("env.process.type.staterecord", "Environmental Process Types For State Record");
        sisoToObjectName.put("env.process.state.combic", "COMBIC State");
        sisoToObjectName.put("env.process.state.flare", "Flare State");
    }

    private static void loadSisoNamespaces()
    {
        sisoToNamespaces.put("es", "EntityState");
        sisoToNamespaces.put("es.type", "EntityState.Type");
        sisoToNamespaces.put("es.appear", "EntityState.Appearance");
        sisoToNamespaces.put("es.markingtext", "EntityState.Marking");
        sisoToNamespaces.put("warfare", "Warfare");
        sisoToNamespaces.put("log", "Logistics");
        sisoToNamespaces.put("simman", "SimulationManagement");
        sisoToNamespaces.put("der", "DistributedEmission");
        sisoToNamespaces.put("der.iff", "DistributedEmission.Iff");
        sisoToNamespaces.put("der.ua", "DistributedEmission.UnderwaterAcoustic");
        sisoToNamespaces.put("radio", "Radio");
        sisoToNamespaces.put("radio.tx", "Radio.Transmitter");
        sisoToNamespaces.put("radio.ic", "Radio.Intercom");
        sisoToNamespaces.put("entity", "Entity.Information");
        sisoToNamespaces.put("entity.mine", "Entity.Information.Minefield");
        sisoToNamespaces.put("eman", "Entity.Management");
        sisoToNamespaces.put("env.obj", "Environment.ObjectState");
        sisoToNamespaces.put("env.gridded", "Environment.Gridded");
        sisoToNamespaces.put("env.process", "Environment.Process");
    }

    private static void loadSisoObjectValueNames()
    {
        Hashtable<Integer, String> protocolVersion = new Hashtable<Integer, String>();
        protocolVersion.put(1, "Version1");
        protocolVersion.put(2, "Ieee1278_1993");
        protocolVersion.put(3, "Version2ThirdDraft");
        protocolVersion.put(4, "Version2FourthDraftRevised");
        protocolVersion.put(5, "Ieee1278_1_1995");
        protocolVersion.put(6, "Ieee1278_1A_1998");

        Hashtable<Integer, String> pduType = new Hashtable<Integer, String>();
        pduType.put(28, "IFF_ATC_NAVAIDS");

        Hashtable<Integer, String> platformLand = new Hashtable<Integer, String>();
        platformLand.put(2, "ArmoredFightingVehicle");
        platformLand.put(3, "ArmoredUtilityVehicle");
        platformLand.put(4, "SelfPropelledArtillery");
        platformLand.put(5, "TowedArtillery");
        platformLand.put(6, "SmallWheeledUtilityVehicle");
        platformLand.put(7, "LargeWheeledUtilityVehicle");
        platformLand.put(8, "SmallTrackedUtilityVehicle");
        platformLand.put(9, "LargeTrackedUtilityVehicle");

        Hashtable<Integer, String> platformAir = new Hashtable<Integer, String>();
        platformAir.put(6, "ElectronicWarfare");

        Hashtable<Integer, String> platformSubsurface = new Hashtable<Integer, String>();
        platformSubsurface.put(1, "NuclearBallisticMissile");
        platformSubsurface.put(2, "NuclearGuidedMissile");
        platformSubsurface.put(3, "NuclearAttackTorpedo");
        platformSubsurface.put(4, "ConventionalGuidedMissile");
        platformSubsurface.put(5, "ConventionalAttackTorpedoPatrol");
        platformSubsurface.put(6, "NuclearAuxiliary");
        platformSubsurface.put(7, "ConventionalAuxiliary");

        Hashtable<Integer, String> munitionDomain = new Hashtable<Integer, String>();
        platformAir.put(12, "DirectedEnergyWeapon");

        Hashtable<Integer, String> dra = new Hashtable<Integer, String>();
        dra.put(1, "Static");
        dra.put(2, "DRA_F_P_W");
        dra.put(3, "DRA_R_P_W");
        dra.put(4, "DRA_R_V_W");
        dra.put(5, "DRA_F_W_V");
        dra.put(6, "DRA_F_P_B");
        dra.put(7, "DRA_R_P_B");
        dra.put(8, "DRA_R_V_B");
        dra.put(9, "DRA_F_V_B");

        Hashtable<Integer, String> am = new Hashtable<Integer, String>();
        am.put(1, "AFSK");
        am.put(2, "AM");
        am.put(3, "CW");
        am.put(4, "DSB");
        am.put(5, "ISB");
        am.put(6, "LSB");
        am.put(7, "SSBFull");
        am.put(8, "SSBReduced");
        am.put(9, "USB");
        am.put(10, "VSB");

        Hashtable<Integer, String> am2 = new Hashtable<Integer, String>();
        am2.put(1, "FM");
        am2.put(2, "FSK");
        am2.put(3, "PM");
 
        Hashtable<Integer, String> tmts = new Hashtable<Integer, String>();
        tmts.put(7, "EPLRS");
        tmts.put(8, "JTIDS_MIDS");

        Hashtable<Integer, String> tmcs = new Hashtable<Integer, String>();
        tmcs.put(2, "VINSON");
        tmcs.put(3, "NarrowSpectrumSecureVoice");
        tmcs.put(4, "WideSpectrumSecureVoice");

        sisoObjectValueNames.put("pduheader.protocolversion", protocolVersion);
        sisoObjectValueNames.put("pduheader.pdutype", pduType);
        sisoObjectValueNames.put("es.type.kind.1.domain.1.cat", platformLand);
        sisoObjectValueNames.put("es.type.kind.1.domain.2.cat", platformAir);
        sisoObjectValueNames.put("es.type.kind.1.domain.4.cat", platformSubsurface);
        sisoObjectValueNames.put("es.type.kind.2.domain", munitionDomain);
        sisoObjectValueNames.put("es.dra", dra);
        sisoObjectValueNames.put("radio.tx.mod.major.1.detail", am);
        sisoObjectValueNames.put("radio.tx.mod.major.3.detail", am);
        sisoObjectValueNames.put("radio.tx.mod.system", tmts);
        sisoObjectValueNames.put("radio.tx.cryptosystem", tmcs);
    }

    public static void main(String args[])
    {
        loadSisoObjectNames();
        loadSisoObjectValueNames();
        loadSisoNamespaces();
        
        try
        {
            // Parse the EBV XML document
             JAXBContext context = JAXBContext.newInstance("edu.nps.moves.siso.jaxb");
             Unmarshaller unmarshaller = context.createUnmarshaller();
             Ebv data = (Ebv)unmarshaller.unmarshal(new FileInputStream("data/siso-std-010.xml"));

             // Retrieve the enumerations
             List<GenerictableT> genericList = data.getEnumOrBitmaskOrCet();
             for (int idx = 0; idx < genericList.size(); idx++)
             {
                 GenerictableT gen = genericList.get(idx);
                 EBVReaderCsharp reader = new EBVReaderCsharp();

                 String genName = gen.getName();
                 String cname = gen.getCname();

                 if (sisoToObjectName.containsKey(gen.getCname()))
                 {
                     genName = sisoToObjectName.get(gen.getCname());
                 }

                 String enumifiedName = enumifyString(genName);

                 // For each enumeration in the XML that we are interested in,
                 // generate a enumeration or struct
                 if(gen instanceof EnumT)
                 {
                     if(cname.equalsIgnoreCase("es.type.country"))
                     {
                         System.out.println("Writing country enumeration ...");
                         reader.writeCountryEnumeration("Country", (EnumT)gen);
                     }
                     else
                     {
                         System.out.println("Writing standard enumeration " + enumifiedName + " (" + gen.getName() + ") ...");
                         reader.writeEnumeration(enumifiedName, gen);
                     }
                 }
                 else if (gen instanceof BitmaskT)
                 {
                     BitmaskT bm = (BitmaskT)gen;

                     if (isStruct(bm))
                     {
                         //System.out.println("Writing struct " + enumifiedName + " (" + genName + ") ...");
                         //reader.writeStruct(enumifiedName, bm);
                     }
                     else
                     {
                         System.out.println("Writing flagged enumeration " + enumifiedName + " (" + genName + ") ...");
                         reader.writeEnumeration(enumifiedName, gen);
                     }
                 }
             }

        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    private static Boolean isStruct(BitmaskT bm)
    {
        List<BitmaskrowT> l = bm.getBitmaskrow();
        
        for (int idx = 0; idx < l.size(); idx++)
        {
            BitmaskrowT row = l.get(idx);

            if (row.getId2() != null &&
                row.getId2().intValue() > 0 &&
                row.getId2().intValue() > row.getId().intValue() &&
                (row.isUnused() == null || !row.isUnused()))
            {
                return true;
            }
        }

        return false;
    }

    private static String findNamespace(String cname)
    {
        if (cname != null)
        {
            // let's check if cname has its own namespace
            if (sisoToNamespaces.containsKey(cname))
            {
                return sisoToNamespaces.get(cname);
            }
            else
            {
                // split cname
                String[] splits = cname.split("\\.");

                // check N, N-1, N-2, ... 3, 2, 1 element of cname
                for (int i = splits.length - 1; i > 0; i--)
                {
                    String shorterCname = "";

                    // join N, N-1, N-2, ... 3, 2, 1 element of cname
                    for (int j = 0; j < i; j++)
                    {
                        shorterCname += splits[j];
                        if (j < i - 1)
                        {
                            shorterCname += ".";
                        }
                    }

                    if (sisoToNamespaces.containsKey(shorterCname))
                    {
                        return sisoToNamespaces.get(shorterCname);
                    }
                }
            }
        }

        return "";
    }

    private <T extends GenerictableT> void writeEnumeration(String enumerationName, T anEnumeration)
            throws java.io.IOException
    {
        int usedCount = 1;
        Set enumNamesUsed = new HashSet();
        List<GenericentryT> l = new ArrayList<GenericentryT>();
        String namespace = "OpenDis.Enumerations";
        String additionalNamespace = findNamespace(anEnumeration.getCname());
        String enumerationDirectory = "src/main/Csharp/disenum2/";   // default output directory
        String baseType = "int";   // default base type is integer
        Boolean lastEnumRowWritten = false;
        Boolean firstUsed = false;
        Boolean isEnum = anEnumeration instanceof EnumT;
        Boolean isFlaggedEnum = anEnumeration instanceof BitmaskT;

        // if additional namespace is specified, add it to the namespace
        // declaration and folder name for the current enum
        if (additionalNamespace != null &&
            !additionalNamespace.trim().equals(""))
        {
            namespace += "." + additionalNamespace;
            enumerationDirectory += additionalNamespace + "/";
        }

        // create directory for file (if it does not exist)
        File outputDirectory = new File(enumerationDirectory);
        if (!outputDirectory.exists())
        {
            outputDirectory.mkdirs();
        }

        // initialize file
        File outputFile = new File(enumerationDirectory + enumerationName + ".cs");
        outputFile.createNewFile();
        PrintWriter pw = new PrintWriter(outputFile);

        // determine the base data type for the enumeration
        if (anEnumeration.getLength() != null)
        {
            int size = anEnumeration.getLength().intValue();

            if (size == 8)
            {
                baseType = "byte";
            }
            else if (size == 16)
            {
                baseType = "ushort";
            }
        }

        // write file headers
        writeFileHeaders(pw, false);

        // write namespace and enum declaration
        writeEnumDeclaration(pw, namespace, enumerationName, anEnumeration, isFlaggedEnum, baseType);

        // fill the list of entries 
        if (isEnum)
        {
            List<EnumrowT> rows = ((EnumT)anEnumeration).getEnumrow();
            for (int r = 0; r < rows.size(); r++)
            {
                l.add(rows.get(r));
            }
        }
        else if (isFlaggedEnum)
        {
            List<BitmaskrowT> rows = ((BitmaskT)anEnumeration).getBitmaskrow();
            for (int r = 0; r < rows.size(); r++)
            {
                l.add(rows.get(r));
            }
        }

        // now output the entries as enumeration items
        for(int idx = 0; idx < l.size(); idx++)
        {
            GenericentryT er = l.get(idx);
            int enumId, enumValue;
            String enumValueName;

            // if the entry is unused or deleted, skip
            if ((er.isUnused() != null && er.isUnused()) ||
                (er.isDeleted() != null && er.isDeleted()))
            {
                continue;
            }

            // mark first entry (for output formatting)
            Boolean isFirst = firstUsed == false;
            firstUsed = true;

            // try getting the description
            String description = (er.getDescription() == null ? "" : er.getDescription()).trim();

            // Some entries in the EBV have missing descriptions. If that's the case, we just
            // make up a description; we may get something on the wire with that enumerated
            // value, and we want a valid enumeration object to match that, even if we don't
            // have a good name or description for it.
            if((description == null) || description.equals(""))
            {
                description = "Missing Description";
            }

            // add the period 
            if (!description.endsWith("."))
            {
                description += ". ";
            }

            if (isEnum)
            {
                // generate the name of the enumeration value
                enumValueName = enumifyString(description);

                // if the value is simple enumeration (not bit mask),
                // its value is same as the id so get the ID
                enumId = ((EnumrowT)er).getId();
                enumValue = enumId;
            }
            else
            {
                // bit mask values have description for bit values,
                // so get those strings, join them and set them as
                // the description for the value.
                List<EnumrowT> er2 = ((BitmaskrowT)er).getEnumrow();
                
                if (!er2.isEmpty())
                {
                    String whenZero = "";
                    String whenOne = "";

                    for (int erIdx = 0; erIdx < er2.size(); erIdx++)
                    {
                        if (er2.get(erIdx).getId() == 0)
                        {
                            whenZero = er2.get(erIdx).getDescription();
                        }
                        else if (er2.get(erIdx).getId() == 1)
                        {
                            whenOne = er2.get(erIdx).getDescription();
                        }
                    }

                    if (!whenZero.equals("") && !whenOne.equals(""))
                    {
                        description = "Set bit means '" + whenOne + "', reset bit means '" + whenZero + "'.";
                    }
                }

                // generate the name of the enumeration value
                if (((BitmaskrowT)er).getName() != null)
                {
                    enumValueName = enumifyString(((BitmaskrowT)er).getName());
                }
                else
                {
                    enumValueName = enumifyString(description);
                }

                // get the enum ID and calculate the value
                // value is 1 shifted to the left for N places,
                // where N equals the enum ID
                enumId = ((BitmaskrowT)er).getId().intValue();

                // WARNING: hacks!!
                if (anEnumeration.getCname().equals("der.iff.infolayers"))
                {
                    // der.iff.infolayers has wrong IDS!!!!!
                    if (enumId == 12) enumId = 1;
                    if (enumId == 13) enumId = 2;
                }

                enumValue = 1 << enumId;
            }

            // check for name overrides
            if (anEnumeration.getCname() != null &&
                sisoObjectValueNames.containsKey(anEnumeration.getCname()) &&
                sisoObjectValueNames.get(anEnumeration.getCname()).containsKey(enumId))
            {
                enumValueName = sisoObjectValueNames.get(anEnumeration.getCname()).get(enumId);
            }

            if (isEnum)
            {
                // if this is enum, read meta description from values
                // (if any) and add them to description
                List<MetaT> meta = ((EnumrowT)er).getMeta();
                if (meta != null && !meta.isEmpty())
                {
                    for (int mi = 0; mi < meta.size(); mi++)
                    {
                        if (meta.get(mi).getId() != null &&
                            (meta.get(mi).getId().equalsIgnoreCase("natoid") || meta.get(mi).getId().equalsIgnoreCase("commid")))
                        {
                            // fix for enumerations where description is provided as nato reporting name
                            description = meta.get(mi).getValue();
                        }
                        else
                        {
                            description += meta.get(mi).getId() + ": " + meta.get(mi).getValue() + ". ";
                        }
                    }
                }
            }

            if (isEnum &&
                ((EnumrowT)er).getId2() != null)
            {
                int enumValueMax = ((EnumrowT)er).getId2().intValue();

                // if there are some reserved enumeration values, don't
                // process them
                if (description.toLowerCase().contains("reserved"))
                {
                    description += " (values from " + enumValue + " to " + enumValueMax + ").";
                }
                else
                {
                    if (enumValueMax > enumValue)
                    {
                        // FIRST WE HANDLE SPECIAL CASES!

                        // first and second case: XBDE (HHC X BDE, where X = 1/2/3/4)
                        // third case: AttachedParts
                        if (anEnumeration.getCname().equals("es.markingtext.cctt.1cavunit") &&
                            enumValue == 51)
                        {
                            writeEnumValue(pw, "HHC_1_BDE", 51, "HHC 1 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_2_BDE", 52, "HHC 2 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_3_BDE", 53, "HHC 3 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_4_BDE", 54, "HHC 4 BDE", false, false, "");
                        }
                        else if (anEnumeration.getCname().equals("es.markingtext.cctt.1infunit") &&
                            enumValue == 51)
                        {
                            writeEnumValue(pw, "HHC_1_BDE", 51, "HHC 1 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_2_BDE", 52, "HHC 2 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_3_BDE", 53, "HHC 3 BDE", false, false, "");
                            writeEnumValue(pw, "HHC_4_BDE", 54, "HHC 4 BDE", false, false, "");
                        }
                        else if (anEnumeration.getCname().equals("es.vp.type.1.attached") &&
                            (enumValue == 1 || enumValue == 512 || enumValue == 640 || enumValue == 768 || enumValue == 906))
                        {
                            for (int apidx = enumValue; apidx <= enumValueMax; apidx++)
                            {
                                String d = er.getDescription() + " (with id " + apidx + ").";
                                String n = enumifyString(er.getDescription()) + "_" + apidx;
                                Boolean last = apidx == enumValueMax && idx == l.size() - 1;

                                writeEnumValue(pw, n, apidx, d, last, false, "");

                                lastEnumRowWritten = last;
                            }

                            continue;
                        }
                        else
                        {
                            // default generation
                            String desc = er.getDescription();
                            String descriptionBeginning = "Value";  // default
                            char descFirst = 0;

                            // ranges are usually defined as "0-9" or "A-F"
                            // or even "Underlined 0-9"
                            // take the last three characters (the "range part")
                            descFirst = desc.charAt(desc.length() - 3);

                            // if something is before "range part", get it,
                            // enumify and add to the beginning of the description
                            if (desc.length() - 3 > 0)
                            {
                                descriptionBeginning = enumifyString(desc.substring(0, desc.length() - 3).trim());
                            }

                            // foreach value calculate its value
                            // and determine if it is the last value
                            for (int ei = enumValue; ei <= enumValueMax; ei++)
                            {
                                int val = descFirst + ei - enumValue;
                                Boolean isLast = enumValue == enumValueMax && idx == l.size() - 1;

                                try
                                {
                                    // first we try to parse the integer value
                                    Integer v = Integer.parseInt(String.valueOf((char)val));
                                    description = descriptionBeginning + " " + v;
                                    enumValueName = descriptionBeginning + "_" + v;
                                }
                                catch (Exception e)
                                {
                                    // if integer parsing fails, we have the character range
                                    description = descriptionBeginning + " " + (char)val;
                                    enumValueName = String.valueOf((char)val);
                                }

                                // check if already used
                                if(enumNamesUsed.contains(enumValueName))
                                {
                                    enumValueName = enumValueName + "_"; // eg M1_RIFLE to M1_RIFLE_22875
                                }

                                enumNamesUsed.add(enumValueName);

                                // write value
                                writeEnumValue(pw, enumValueName, ei, description, isLast, isFirst && ei == enumValue, "");

                                lastEnumRowWritten = isLast;
                            }
                        }
                    }
                }
            }
            else
            {
                // If we've seen this enumeration name before, add some exra text
                // onto the end to make it unique
                if(enumNamesUsed.contains(enumValueName))
                {
                    enumValueName = enumValueName + "_" + enumValue; // eg M1_RIFLE to M1_RIFLE_22875
                    usedCount++;
                }

                enumNamesUsed.add(enumValueName);

                Boolean isLast = idx == l.size() - 1;

                // write value
                writeEnumValue(pw, enumValueName, enumValue, description, isLast, isFirst, "");

                lastEnumRowWritten = isLast;
            }
        }

        if (!lastEnumRowWritten)
        {
            pw.println();
            pw.println("    }");
        }
        
        pw.println("}");
        pw.flush();
        pw.close();


        // if there is no value added to enum, simply delete file
        if (enumNamesUsed.isEmpty())
        {
            System.out.println(" -> Deleting empty enumeration for '" + enumerationName + "'");
            outputFile.delete();
        }
    }

    private static <T extends GenerictableT> void writeEnumDeclaration(PrintWriter pw, String namespace, String enumerationName, T anEnumeration, Boolean isFlaggedEnum, String baseType) {
        pw.println("namespace " + namespace);
        pw.println("{");
        pw.println("    /// <summary>");
        pw.println("    /// Enumeration values for " + enumerationName + " (" + anEnumeration.getCname() + ", " + anEnumeration.getName() + ", ");
        pw.println("    /// section " + anEnumeration.getSource() + ")");
        pw.println("    /// The enumeration values are generated from the SISO DIS XML EBV document (R35), which was");
        pw.println("    /// obtained from http://discussions.sisostds.org/default.asp?action=10&amp;fd=31");
        pw.println("    /// </summary>");
        pw.println("    /// <remarks>");
        pw.println("    /// Note that this has two ways to look up an enumerated instance from a value: a fast");
        pw.println("    /// but brittle array lookup, and a slower and more garbage-intensive, but safer, method.");
        pw.println("    /// if you want to minimize memory use, get rid of one or the other.");
        pw.println("    /// </remarks>");
        pw.println("    [SuppressMessage(\"Microsoft.Naming\", \"CA1702:CompoundWordsShouldBeCasedCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("    [SuppressMessage(\"Microsoft.Naming\", \"CA1704:IdentifiersShouldBeSpelledCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("    [SuppressMessage(\"Microsoft.Naming\", \"CA1707:IdentifiersShouldNotContainUnderscores\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("    [SuppressMessage(\"Microsoft.Naming\", \"CA1709:IdentifiersShouldBeCasedCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("    [Serializable]");
        
        if (isFlaggedEnum)
        {
            pw.println("    [Flags]");
        }

        pw.println("    public enum " + enumerationName + " : " + baseType);
        pw.println("    {");
    }

    private static void writeFileHeaders(PrintWriter pw, Boolean includeOpenDisUtilitiesNamespace) {
        pw.println("// Copyright 2008-2010. This work is licensed under the BSD license, available at");
        pw.println("// http://www.movesinstitute.org/licenses");
        pw.println("//");
        pw.println("// @author DMcG, Jason Nelson");
        pw.println("// Modified for use with C#:");
        pw.println("// - Peter Smith (Naval Air Warfare Center - Training Systems Division)");
        pw.println("// - Zvonko Bostjancic (Blubit d.o.o. - zvonko.bostjancic@blubit.si)");
        pw.println();
        pw.println("using System;");
        pw.println("using System.ComponentModel;");
        pw.println("using System.Diagnostics.CodeAnalysis;");
        pw.println("using System.Reflection;");

        if (includeOpenDisUtilitiesNamespace)
        {
            pw.println("using OpenDis.Utilities;");
        }

        pw.println();
    }

    private static void writeEnumValue(PrintWriter pw, String enumName, int enumValue, String description, Boolean isLast, Boolean isFirst, String additionalAttributes)
    {
        if (!isFirst)
        {
            pw.println(",");
            pw.println();
        }

        description = description.replace("\"", "");

        pw.println("        /// <summary>");
        pw.println("        /// " + description.trim());
        pw.println("        /// </summary>");
        pw.println("        [SuppressMessage(\"Microsoft.Naming\", \"CA1702:CompoundWordsShouldBeCasedCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("        [SuppressMessage(\"Microsoft.Naming\", \"CA1704:IdentifiersShouldBeSpelledCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("        [SuppressMessage(\"Microsoft.Naming\", \"CA1707:IdentifiersShouldNotContainUnderscores\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("        [SuppressMessage(\"Microsoft.Naming\", \"CA1709:IdentifiersShouldBeCasedCorrectly\", Justification = \"Due to SISO standardized naming.\")]");
        pw.println("        [Description(\"" + description.trim() + "\")]");
        pw.println(additionalAttributes);
        pw.print("        " + enumName + " = " + enumValue);

        if(isLast)
        {
            pw.println("");
            pw.println("    }");
        }
    }

    /** Special case of country enumeration--we also want the two character internet code
     * for the country, eg "US", "UK", "FR", etc. The lookup algorithm for finding the
     * country is not perfect.
     * 
     * @param enumerationName
     * @param enumerationFile
     * @param anEnumeration
     */
    private void writeCountryEnumeration(String enumerationName, EnumT anEnumeration)
        throws java.io.IOException
    {
        String enumerationFile = "src/main/Csharp/disenum2/" + enumerationName + ".cs";

        File outputFile = new File(enumerationFile);
        outputFile.createNewFile();
        PrintWriter pw = new PrintWriter(outputFile);
        int maxValue = 0;

        // Properties file containing the key (two character internet domain name for
        // the country) and the value (text description of the country).
        Properties internetCountries = new Properties();
        FileInputStream fis = new FileInputStream(new File("data/countryCodes.properties"));
        internetCountries.load(fis);

        // write file headers
        writeFileHeaders(pw, true);

        // write namespace and enum declaration
        writeEnumDeclaration(pw, "OpenDis.Enumerations", enumerationName, anEnumeration, false, "int");

        List<EnumrowT> l = anEnumeration.getEnumrow();
        for(int idx = 0; idx < l.size(); idx++)
        {
            EnumrowT er = l.get(idx);
          
            // mark first entry (for output formatting)
            Boolean isFirst = idx == 0;
            Boolean isLast = idx == l.size() - 1;

            String description = er.getDescription();
            String enumValueName = enumifyString(description);
            int enumValue = (int)er.getId();
            String internetDomainCode = "Unknown";

            Set entrySet = internetCountries.entrySet();
            Iterator it = entrySet.iterator();
            while(it.hasNext())
            {
                Map.Entry<String, String> anEntry = (Map.Entry<String, String>)it.next();
                if(anEntry.getValue().equalsIgnoreCase(description))
                {
                    internetDomainCode = anEntry.getKey();
                    break;
                }
            }

            String additionalAttributes = "        [InternetDomainCode(\"" + internetDomainCode + "\")]";
            writeEnumValue(pw, enumValueName, enumValue, description, isLast, isFirst, additionalAttributes);
        }

        pw.println("} ");     //End Namespace

        pw.flush();
        pw.close();
    }

    public static String camelCaseCapIgnoreUnderscores(String aString) {
        StringBuffer stb = new StringBuffer();

        if (aString.length() > 0){
            stb.append(Character.toUpperCase(aString.charAt(0)));

            boolean previousIsSpace = false;
            for (int i = 1; i < aString.length(); i++)
            {
                boolean currentIsSpace = aString.charAt(i) == '_';

                if (previousIsSpace)
                {
                    stb.append(Character.toUpperCase(aString.charAt(i)));
                }
                else if (!currentIsSpace)
                {
                    stb.append(aString.charAt(i));
                }

                previousIsSpace = currentIsSpace;
            }
        }

        String newString = new String(stb);
        //System.out.println(newString);

        return newString;
    }

    /**
     *  Changes an input string like "Entity State PDU" into "ENTITY_STATE_PDU"
     * 
     * @param text
     * @return
     */
    private static String enumifyString(String text)
    {
        if (text != null && !text.equals(""))
        {
            String enumValue = text.trim();

            enumValue = enumValue.replace(" ", "_");
            enumValue = enumValue.replace("-", "_");
            enumValue = enumValue.replace("/", "_");
            enumValue = enumValue.replace("(", "_");
            enumValue = enumValue.replace(")", "_");
            enumValue = enumValue.replace(",", "_");
            enumValue = enumValue.replace("'", "_");
            enumValue = enumValue.replace("\"", "_");
            enumValue = enumValue.replace(".", "_");
            enumValue = enumValue.replace(";", "_");
            enumValue = enumValue.replace(":", "_");
            enumValue = enumValue.replace("&", "_");
            enumValue = enumValue.replace("{", "_");
            enumValue = enumValue.replace("}", "_");
            enumValue = enumValue.replace("#", "_");
            enumValue = enumValue.replace("^", "Caret");
            enumValue = enumValue.replace("<", "LowerThan");
            enumValue = enumValue.replace(">", "GreaterThan");

            // If it starts with a number, that's not a valid identifier.
            // replace it with a leading character. Ack--there should be
            // a better regexp to cover this, but getting back references
            // working is not working for me.

            enumValue = enumValue.replaceAll("^_", "");
            enumValue = enumValue.replaceAll("^0", "_0");
            enumValue = enumValue.replaceAll("^1", "_1");
            enumValue = enumValue.replaceAll("^2", "_2");
            enumValue = enumValue.replaceAll("^3", "_3");
            enumValue = enumValue.replaceAll("^4", "_4");
            enumValue = enumValue.replaceAll("^5", "_5");
            enumValue = enumValue.replaceAll("^6", "_6");
            enumValue = enumValue.replaceAll("^7", "_7");
            enumValue = enumValue.replaceAll("^8", "_8");
            enumValue = enumValue.replaceAll("^9", "_9");

            // Finally, replace repeated instances of _ with a single underscore
            enumValue = enumValue.replaceAll("(_+)", "_");

            enumValue = camelCaseCapIgnoreUnderscores(enumValue);

            return enumValue;
        }
        else
        {
            return "Unknown";
        }
    }
}
