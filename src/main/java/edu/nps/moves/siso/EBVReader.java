
package edu.nps.moves.siso;

import java.io.*;
import java.math.*;
import java.nio.channels.FileChannel;
import java.text.BreakIterator;
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
 */
public class EBVReader 
{
    /** Location of EBV document. This should match up with the schema available
     * in the data directory. JAXB was used to generate the classes in 
     * edu.nps.moves.siso.jaxb, which is used to parse and databind the 
     * xml document--if the schema changes, you'll have to regenerate those
     * classes.
     */
    public static final String EBV_XML_DOCUMENT = "data/siso-std-010.xml";
    
    public static final String CPP_TEMPLATES_DIR = "src/main/resources/disenums/cpp/templates";
    
    public static final String GEN_JAVA_SOURCE_OUTPUT_DIR = "src/main/java/edu/nps/moves/disenum/";
    public static final String GEN_CPP_SOURCE_OUTPUT_DIR = "src/main/cpp/disenum/";
    
    public static void main(String args[])
    {
        try
        {
            
            // Parse the EBV XML document
             JAXBContext context = JAXBContext.newInstance("edu.nps.moves.siso.jaxb");
             Unmarshaller unmarshaller = context.createUnmarshaller();
             Ebv data = (Ebv)unmarshaller.unmarshal(new FileInputStream(EBV_XML_DOCUMENT));
             
             // Create folders to write the generated files in.
             new File(GEN_JAVA_SOURCE_OUTPUT_DIR).mkdirs();
             new File(GEN_CPP_SOURCE_OUTPUT_DIR).mkdirs();
             
             // write the common header
             writeCppEnumerationCommon();
             
             // Retrieve the enumerations             
             List<GenerictableT> genericList = data.getEnumOrBitmaskOrCet();       
             for(int idx = 0; idx < genericList.size(); idx++)
             {
                 GenerictableT gen = genericList.get(idx);

                // System.out.println("generic table ID " + gen.getId() + " Name=" + gen.getName() + " cname=" + gen.getCname());
                 // For each enumeration in the XML that we are interested in, 
                 // generate a Java enumeration class
                 if(gen instanceof EnumT)
                 {
                     //System.out.println("generic table is an EnumT wtih cname " + gen.getCname());
                     EnumT en = (EnumT)gen;
                     List<EnumrowT> rows = en.getEnumrow();
                     //System.out.println("row ID=" + rows.get(0).getId());
                     //System.out.println("header length is " + en.getHeader().size());
                     //if(en.getHeader().size() == 0)
                     //    continue;
                     //HeaderT header = en.getHeader().get(0);
                     //ColT col = header.getCol().get(0);
                     
                     //System.out.println("column:" + gen.getCname());
                     
                    // Pdu Type
                     if(gen.getCname().equalsIgnoreCase("pduheader.pdutype"))
                     {
                         //System.out.println("PDU Type");
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PduType",  en);
                     }
                     
                     // Country. this uses a special writer so that we can also pick up the internet code for
                     // that country, eg US, UK, DE, etc.
                     if(gen.getCname().equalsIgnoreCase("es.type.country"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeCountryEnumeration("CountryType", en); 
                     }
                     
                     // Protocol family (entity interaction, logistics, etc
                     if(gen.getCname().equalsIgnoreCase("pduheader.protocolfamily"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ProtocolFamily",  en); 
                     }
                     
                     // Force ID (friendly, enemy, neutral, etc.)
                     if(gen.getCname().equalsIgnoreCase("es.forceid"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ForceID",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("EntityKind",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain.1.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatformLand",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain.2.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatformAir",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain.3.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatformSurface",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain.4.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatformSubSurface",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain.5.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatformSpace",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.2.domain"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("MunitionDomain",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.2.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("MunitionCategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.225.kind.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("USWeaponsForLifeForms",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.222.kind.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CISWeaponsForLifeForms",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.224.kind.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("UKWeaponsForLifeForms", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.71.kind.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FrenchWeaponsForLifeForms", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.78.kind.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("GermanWeaponsForLifeForms",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("pduheader.protocolversion"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ProtocolVersion",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.1.domain"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("EntityDomain",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.4.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("EnvironmentalKind",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.type.kind.7.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RadioCategory",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.type.kind.7.version"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RadioNomenclatureVersion",  en); 
                     }
                    
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.7.nomenclature"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RadioNomenclature",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.type.kind.8.domain.2.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ExpendableAirCategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.8.domain.3.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ExpendableSurfaceCategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.8.domain.4.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ExpendableSubsurfaceCategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.type.kind.9.cat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SensorEmitterCategory",  en); 
                     }
                                          
                     if(gen.getCname().equalsIgnoreCase("es.dra"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DeadReckoningAlgorithm",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("EntityMarking",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.div"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DivisionCorpsDesignation",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.1cavunit"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FirstCavHighLevelUnit",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.1infunit"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FirstInfHighLevelUnit",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.company"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CompanyBatteryTroop",  en); 
                     }
                    
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.platoon"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PlatoonSection", en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.vehicle"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Vehicle",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.symbol1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Bytes8_9_10_12",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.cctt.symbol2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Byte11",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.markingtext.chevron.symbol"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DigitChevronCode",  en); 
                     }
                    
                    if(gen.getCname().equalsIgnoreCase("es.vp.type"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ParameterTypeDesignator",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.vp.type.1.attached"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AttachedParts",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.vp.type.0.articulated.offset"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ArticulatedPartsOffsetNumber",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("es.vp.type.0.articulated.index"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ArticulatedPartsIndexNumber",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("warfare.burstdescriptor.warhead"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Warhead", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("warfare.burstdescriptor.fuse"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Fuse",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("warfare.detonationresult"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetonationResult",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.servicerequest"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ServiceRequestPDU",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.general"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("GeneralRepairCode",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.drivetrain"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DriveTrain",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.hull"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("HullAirframeBody",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.environment"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("InterfacesWithEnvironment",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.weapons"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Weapons",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.fuelsystem"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FuelSystems",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.electronics"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Electronics",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.lifesupport"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("LifeSupportSystems",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.hydraulic"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("HydraulicSystemsAndActuators", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repaircomplete.auxilary"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AuxiliaryCraft",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("log.repairresponse"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RepairResponsePDU",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.datumid"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DatumSpecificationRecord",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.stop.reason"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Reason",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.ack.ackflag"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AcknowledgeFlag",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.ack.responseflag"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ResponseFlag",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.actionrequest.actionid"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ActionID",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.actionresponse.status"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RequestStatus",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.eventreport.eventtype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("EventType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("simman.reliability.service"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RequiredReliabilityService",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.name.electro"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ElectromagneticEmitters",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.name.acoustic"))
                     {
                         EBVReader reader = new EBVReader();
                         System.out.println("Enumeration row list length = " + en.getEnumrow().size());
                         reader.writeStandardEnumeration("AcousticEmitters",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.name.other"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("OtherAcousticEmitters",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.function"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Function",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.stateupdate"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("StateUpdateIndicator",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.beamfunction"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("BeamFunction",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.emission.hdtj"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("HighDensityTrackJam",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.designator.codename"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CodeName",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.designator.code"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DesignatorCode",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SystemType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.name"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SystemName",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.mode"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SystemMode",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.layerspecific"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("LayerSpecificInformation",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.1.fop.altp4"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type1AltParameter4",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.1.sop.param1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type1OperationalParameter1",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.1.sop.param2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type1OperationalParameter2",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.2.fop.altp4"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type2AltParameter4",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.2.sop.param1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type2OperationalParameter1",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.2.sop.param2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type2OperationalParameter2",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.3.fop.altp4"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type3AltParameter4",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.3.sop.param1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type3OperationalParameter1",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.3.sop.param2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type3OperationalParameter2",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.4.fop.altp4"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type4AltParameter4",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.4.sop.param1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type4OperationalParameter1",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.4.sop.param2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type4OperationalParameter2",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.5.fop.altp4"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type5AltParameter4",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.5.sop.param1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type5OperationalParameter1",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.iff.type.5.sop.param2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Type5OperationalParameter2",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.statechangeupdate"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("StateChangeUpdateIndicator",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.systemname"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AcousticSystemName",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.function"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Function",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.activeparameterindex"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ActiveEmissionParameterIndex",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.scanpattern"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ScanPattern",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.passiveparameterindex"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("PassiveParameterIndex",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.ua.apaparameterindex"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AdditionalPassiveActivity",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.sees.power.aircraft"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Aircraft",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.sees.power.helicopters"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Helicopters", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("der.sees.power.tanks"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Tanks",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("MajorModulation",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.1.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModAmpMod",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.2.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModAmpAndAngle",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.3.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModAngleMod",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.4.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModCombinationMod",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.5.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModPulseMod",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.6.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModUnmodulatedMod",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.major.7.detail"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DetailedModCarrierPhaseShift",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.mod.system"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RadioSystem",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.state"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("TransmitState",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.inputsource"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("InputSource",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.cryptosystem"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CryptoSystem",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.antennapatterntype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AntennaPatternType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.referencesystem"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ReferenceSystem",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.param.cctt.start"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("MessageStart",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.param.cctt.clear"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ClearChannel",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.param.jtids.mode1"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("XmitTermPriMode",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.param.jtids.mode2"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("XmitTermSecMode",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.param.jtids.sync"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SynchronizationState",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.protocolid"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("UserProtocolIDNum",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.tx.tdltype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("TDLType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.rx.state"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ReceiverState", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.controltype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ControlType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.commtype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CommunicationType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.command"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Command", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.transmitstate"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("XmitLineState",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.deststate"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DestLineState",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("radio.ic.param.type"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RecordType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.collision.type"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CollisionType", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SensorTypes",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.1.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Optical",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.2.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FLIR", en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.3.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RADAR",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.4.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Magnetic",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.5.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Laser",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.6.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SONAR",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.7.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Physical",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("entity.mine.sensortype.8.subcat"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Multispectral",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.aggregate.state"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AggregateState",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.aggregate.formation"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Formation",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.aggregate.type.kind"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("AggregateKind",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.aggregate.type.subcategory"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Subcategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.aggregate.type.specific"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Specific",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.ispartof.nature"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Nature",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.ispartof.position"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("Position",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.ispartof.stationname"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("StationName",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.isgroupof.category"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("GroupedEntityCategory",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.isgroupof.reststatus"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("RestStatus",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("eman.tc.transfertype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("TransferType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.obj.objecttype.kind"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ObjectKind",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.gridded.fieldnumber"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("FieldNumber",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.gridded.coordinatesystem"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("CoordinateSystem",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.gridded.constantgrid"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ConstantGrid",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.gridded.sampletype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("SampleType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.gridded.datarepresentation"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("DataRepresentation",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.process.modeltype"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("ModelType",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.process.type.geometryrecord"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("GeometryRecordTypeField",  en); 
                     }
                     
                     if(gen.getCname().equalsIgnoreCase("env.process.type.staterecord"))
                     {
                         EBVReader reader = new EBVReader();
                         reader.writeStandardEnumeration("StateRecordTypeField",  en); 
                     }
                     
                     
                 }
                 else if (gen instanceof BitmaskT) {
                   BitmaskT en = (BitmaskT)gen;
                   //List<BitmaskrowT> rows = en.getBitmaskrow();                   
                   //System.out.println("Bitmak: " + gen.getCname());
                   EBVReader reader = new EBVReader();
                   reader.writeBitmask(gen.getCname(),  en);
                 }
             }   
        }
        catch(Exception e)
        {
            System.out.println("oops, problem creating files");
        }
        
    }  
    
    private static String titleCase(String str){
      BreakIterator wordBreaker = BreakIterator.getWordInstance();      
      wordBreaker.setText(str);
      int end = 0;
      System.out.println("full str: " + str);
      for(int start = wordBreaker.first();
      (end= wordBreaker.next()) != BreakIterator.DONE; start=end){
        String word = str.substring(start, end);
        System.out.println("word: ["+ word + "]");
      }
      return str;

    }
    
    
    //http://snippets.dzone.com/posts/show/1335
    private static String readFileAsString(String filePath)
    throws java.io.IOException{
        StringBuilder fileData = new StringBuilder(2000);       
        BufferedReader reader = new BufferedReader(
                new FileReader(filePath));
   
        char[] buf = new char[1024];
        int numRead=0;
        while((numRead=reader.read(buf)) != -1){
            fileData.append(buf, 0, numRead);
        }
        reader.close();
        return fileData.toString();
    }    
    
    //http://www.exampledepot.com/egs/java.nio/File2File.html
    private static void copyFile(String srcFilename, String dstFilename){
      try {
        // Create channel on the source
        FileChannel srcChannel = new FileInputStream(srcFilename).getChannel();
    
        // Create channel on the destination
        FileChannel dstChannel = new FileOutputStream(dstFilename).getChannel();
    
        // Copy file contents from source to destination
        dstChannel.transferFrom(srcChannel, 0, srcChannel.size());
    
        // Close the channels
        srcChannel.close();
        dstChannel.close();
    } catch (IOException e) {
      System.out.println("Error copying file " + srcFilename + " to " + dstFilename + ": " + e);
    }

    }
    
    
    private static void writeCppEnumerationCommon(){
      try {
        String enumerationFile = "Enumeration.h";
        System.out.println("Writing common enumeration header" + enumerationFile);
        copyFile(CPP_TEMPLATES_DIR + enumerationFile, GEN_CPP_SOURCE_OUTPUT_DIR+ enumerationFile);
        enumerationFile = "enumcfg.h";
        System.out.println("Writing common enumeration header" + enumerationFile);
        copyFile(CPP_TEMPLATES_DIR + enumerationFile, GEN_CPP_SOURCE_OUTPUT_DIR+ enumerationFile);
        
      }
      catch(Exception e) {
        System.out.println("writeEnumerationCommon exception:" + e);
      }
    }
    
    private void writeCppEnumeration(String enumerationName, EnumT anEnumeration, boolean isCountry) {
      try
      {        
        // enumeration names we have used so far
        // (creating a list just to keep the insertion order)
        List<String> enumNamesUsed = new ArrayList<String>(); 
        HashMap<String, Integer> enumValues = new HashMap<String, Integer>();
        HashMap<String, String>  enumDescriptions = new HashMap<String, String>();
        // Especial case for countries
        // Properties file containing the key (two character internet domain name for
        // the country) and the value (text description of the country). 
        HashMap<String, String>  enumInternetCodes = new HashMap<String, String>();
        Properties internetCountries = new Properties();
        FileInputStream fis = new FileInputStream(new File("data/countryCodes.properties"));        
        if (isCountry) {         
          internetCountries.load(fis);                  
        }              
        
        int maxValue = 0; 
        int usedCount = 1;        
        List<EnumrowT> l = anEnumeration.getEnumrow();
        for(int idx = 0; idx < l.size(); idx++)
        {
          EnumrowT er = l.get(idx);
          // Some entries in the EBV have missing descriptions. If that's the case, we just
          // make up a description; we may get something on the wire with that enumerated
          // value, and we want a valid enumeration object to match that, even if we don't
          // have a good name or description for it.
          String description = er.getDescription();
          if((description == null) || description.equals(""))
              description = "Missing Description";
          String enumName = this.enumifyString(description, true);
          int enumValue = (int)er.getId();
                         
          // If we've seen this enumeration name before, add some extra text
          // onto the end to make it unique
          if(enumNamesUsed.contains(enumName))
          {
             enumName = enumName + "_" + usedCount; // eg M1_RIFLE to M1_RIFLE_1
             usedCount++;
          }
          enumNamesUsed.add(enumName);
          enumValues.put(enumName, enumValue);        
          
          // Remove embedded quotes from the description, screws up generated code
          description = description.replace("\"", "");
          enumDescriptions.put(enumName, description);

          String internetDomainCode = "Unknown"; 
          if (isCountry)
          {                    
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
            enumInternetCodes.put(enumName, internetDomainCode);            
          }
                                      
          if(maxValue < enumValue)
          {
             maxValue = enumValue;
          }           
        }        
        maxValue++;
        // ----------- Write .h file -----------------    
        File outputFile = new File(GEN_CPP_SOURCE_OUTPUT_DIR + enumerationName + ".h");
        outputFile.createNewFile();
        System.out.println("Writing enumeration " + outputFile.getPath());        
        PrintWriter pw = new PrintWriter(outputFile);
        String template = new String();
        StringBuilder allEnums = new StringBuilder();
        Iterator<String> enumsIter = enumNamesUsed.iterator();
        
        if (isCountry){
          template = readFileAsString(CPP_TEMPLATES_DIR + "/countryEnumTemplate.h");
        }
        else {
          template = readFileAsString(CPP_TEMPLATES_DIR + "/enumTemplate.h");
        }

        for(int idx = 0; idx < enumNamesUsed.size(); idx++)
        {
          String enumName = enumsIter.next();
          allEnums.append("static " + enumerationName + " " + enumName  + ";\n    ");          
        }

        
        template = template.replaceAll("@ENUMERATIONNAME", enumerationName);
        template = template.replaceAll("@ENUMUPPERCASE", enumerationName.toUpperCase());
        template = template.replaceAll("@ENUMS", allEnums.toString());        
        pw.print(template);
        pw.flush();
        pw.close();
        
        // ----------- Write .cpp file -----------------    
        outputFile = new File(GEN_CPP_SOURCE_OUTPUT_DIR + enumerationName + ".cpp");
        outputFile.createNewFile();
        System.out.println("Writing enumeration " + outputFile.getPath());
        pw = new PrintWriter(outputFile);
        template = new String();
        allEnums = new StringBuilder();
        enumsIter = enumNamesUsed.iterator();
        
        if (isCountry){
          template = readFileAsString(CPP_TEMPLATES_DIR + "/countryEnumTemplate.cpp");
          for(int idx = 0; idx < enumNamesUsed.size(); idx++)
          {
            String enumName = enumsIter.next();
            String enumInternetCode = enumInternetCodes.get(enumName);
            int enumValue = enumValues.get(enumName);
            String enumDescription = enumDescriptions.get(enumName);
            allEnums.append(enumerationName + " " + enumerationName + "::"+ enumName + "(" + enumValue + ", " + "\"" + enumDescription + "\",\"" + enumInternetCode + "\");\n");          
          }
        }
        else {
          template = readFileAsString(CPP_TEMPLATES_DIR + "/enumTemplate.cpp");
          for(int idx = 0; idx < enumNamesUsed.size(); idx++)
          {
            String enumName = enumsIter.next();            
            int enumValue = enumValues.get(enumName);
            String enumDescription = enumDescriptions.get(enumName);
            allEnums.append(enumerationName + " " + enumerationName + "::"+ enumName + "(" + enumValue + ", " + "\"" + enumDescription + "\");\n");          
          }          
        }
        
        template = template.replaceAll("@ENUMERATIONNAME", enumerationName);
        template = template.replaceAll("@MAXVALUE", Integer.toString(maxValue));
        template = template.replaceAll("@ENUMSINIT", allEnums.toString());        
        pw.print(template);
        pw.flush();
        pw.close();      
        
      }
      catch(Exception e)
      {
          System.out.println("writeStandard exception:" + e);
      }
        
    }
    
    private void writeJavaStandardEnumeration(String enumerationName, EnumT anEnumeration)
    {
        String enumerationFile = GEN_JAVA_SOURCE_OUTPUT_DIR + enumerationName + ".java";
        System.out.println("Writing standard enumeration " + enumerationFile );
        try
        {
              File outputFile = new File(enumerationFile);
              outputFile.createNewFile();
              PrintWriter pw = new PrintWriter(outputFile);
              int maxValue = 0;
            
              pw.println("package edu.nps.moves.disenum;");
              pw.println();
              pw.println("import java.util.HashMap;");
              pw.println("import edu.nps.moves.siso.EnumNotFoundException;");
              pw.println();
              pw.println("/** Enumeration values for " + enumerationName);
              pw.println(" * The enumeration values are generated from the SISO DIS XML EBV document (R35), which was");
              pw.println(" * obtained from http://discussions.sisostds.org/default.asp?action=10&fd=31<p>");
              pw.println(" *");
              pw.println(" * Note that this has two ways to look up an enumerated instance from a value: a fast");
              pw.println(" * but brittle array lookup, and a slower and more garbage-intensive, but safer, method.");
              pw.println(" * if you want to minimize memory use, get rid of one or the other.<p>");
              pw.println(" *");
              pw.println(" * Copyright 2008-2009. This work is licensed under the BSD license, available at");
              pw.println(" * http://www.movesinstitute.org/licenses<p>");
              pw.println(" *");
              pw.println(" * @author DMcG, Jason Nelson");
              pw.println(" */");
              pw.println();
              pw.flush();
              
              pw.println("public enum " + enumerationName + " \n{\n");
            
              BigInteger val = anEnumeration.getId();
            
            boolean ofInterest = false;
            if(val.intValue() == 83)
                ofInterest = true;
              
              // enumeration names we have used so far
              Set enumNamesUsed = new HashSet();
              int usedCount = 1;
              
              List<EnumrowT> l = anEnumeration.getEnumrow();
              for(int idx = 0; idx < l.size(); idx++)
              {
                 EnumrowT er = l.get(idx);
                 
                  // Some entries in the EBV have missing descriptions. If that's the case, we just
                  // make up a description; we may get something on the wire with that enumerated
                  // value, and we want a valid enumeration object to match that, even if we don't
                  // have a good name or description for it.
                 String description = er.getDescription();
                  if((description == null) || description.equals(""))
                      description = "Missing Description";
                 String enumName = this.enumifyString(description, true);
                 int enumValue = (int)er.getId();
                                   
                 // If we've seen this enumeration name before, add some exra text
                 // onto the end to make it unique
                 if(enumNamesUsed.contains(enumName))
                 {
                     enumName = enumName + "_" + usedCount; // eg M1_RIFLE to M1_RIFLE_1
                     usedCount++;
                 }
                 enumNamesUsed.add(enumName);
                 
                 // Remove embedded quotes from the description, screws up generated code
                 description = description.replace("\"", "");

                 
                 if(maxValue < enumValue)
                 {
                     maxValue = enumValue;
                 }
                 
                 pw.print("    " + enumName + "(" + enumValue + ", " + "\"" + description + "\")" ) ;
                 if(idx != l.size() -1)
                 {
                     pw.print(",");
                 }
                 else
                 {
                     pw.print(";");
                 }
                 pw.println();
                 
             }
            pw.println();
            pw.flush();
            
            pw.println("    /** The enumerated value */");
            pw.println("    public final int value;");
            pw.println("");
            pw.println("    /** Text/english description of the enumerated value */");
            pw.println("    public final String description;");
            pw.println();
            
            pw.println("/** This is an array, with each slot corresponding to an enumerated value. This is a fast but brittle way to look up");
            pw.println(" * enumerated values. If there is no enumeration corresponding to the value it will fail, and it will also fail if the");
            pw.println(" * index it out of range of the array. But it is fast, and generates less garbage than the alternative of using ");
            pw.println(" * getEnumerationForValue(). It should be used only in real-time environments, and be careful even then.<p>");
            pw.println(" * Use as " + enumerationName + ".lookup[aVal] to get the enumeration that corresponds to a value.<p>");
            pw.println(" * In non-realtime environments, the prefered method is getEnumerationForValue().");
            pw.println(" */");
            maxValue++;
            pw.println("static public " + enumerationName + " lookup[] = new " + enumerationName + "[" + maxValue + "];");
            pw.println();
            
            pw.println("static private HashMap<Integer, " + enumerationName + ">enumerations = new HashMap<Integer, " + enumerationName + ">();");
            pw.println();
            
            
            pw.println("/* initialize the array and hash table at class load time */");
            pw.println("static \n{");
            pw.println("    for(" + enumerationName + " anEnum:" +  enumerationName + ".values())");
            pw.println("    {");
            pw.println("        lookup[anEnum.value] = anEnum;");
            pw.println("        enumerations.put(new Integer(anEnum.getValue()), anEnum);");
            pw.println("    }");
            pw.println("}\n");
            
            pw.println("/** Constructor */");
            pw.println(enumerationName + "(int value, String description)");
            pw.println("{");
            pw.println("    this.value = value;");
            pw.println("    this.description = description;");
            pw.println("}");
            
            pw.println();
            pw.println("/** Returns the string description associated with the enumerated instance with this value. ");
            pw.println(" * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.");
            pw.println("*/");
            pw.println("static public String getDescriptionForValue(int aVal)");
            pw.println("{");
            pw.println("  String desc;");
            pw.println();
            pw.println("    " + enumerationName + " val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("        desc = \"Invalid enumeration: \" + (new Integer(aVal)).toString();");
            pw.println("      else");
            pw.println("         desc = val.getDescription();");
            pw.println();
            pw.println("      return desc;");
            pw.println("}");

            pw.println();
            pw.println("/** Returns the enumerated instance with this value. ");
            pw.println(" * If there is no enumerated instance for this value, the exception is thrown.");
            pw.println("*/");
            pw.println("static public " + enumerationName + " getEnumerationForValue(int aVal) throws EnumNotFoundException");
            pw.println("{");
            pw.println("    " + enumerationName + " val;");
            pw.println("      val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("         throw new EnumNotFoundException(\"no enumeration found for value \" + aVal + \" of enumeration " + enumerationName + "\");");
            pw.println("      return val;");
            pw.println("}");

            pw.println();
            pw.println("/** Returns true if there is an enumerated instance for this value, false otherwise. ");
            pw.println("*/");
            pw.println("static public boolean enumerationForValueExists(int aVal)");
            pw.println("{");
            pw.println("    " + enumerationName + " val;");
            pw.println("      val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("         return false;");
            pw.println("      return true;");
            pw.println("}");
                       

            pw.println();
            pw.println("/** Returns the enumerated value for this enumeration */");
            pw.println("public int getValue()");
            pw.println("{");
            pw.println("  return value;");
            pw.println("}");
            pw.println();
            
            pw.println();
            pw.println("/** Returns a text descriptioni for this enumerated value. This is usually used as the basis for the enumeration name. */");
            pw.println("public String getDescription()");
            pw.println("{");
            pw.println("  return description;");
            pw.println("}");
            pw.println();
              
              pw.println("}");
            
          
              pw.flush();
              pw.close();
        }
        catch(Exception e)
        {
            System.out.println("writeStandard exception:" + e);
        }
        
    }

    private void writeStandardEnumeration(String enumerationName, EnumT anEnumeration)
    {

      writeJavaStandardEnumeration(enumerationName, anEnumeration);      
      writeCppEnumeration(enumerationName,  anEnumeration, false);      
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
    {
      writeJavaCountryEnumeration(enumerationName, anEnumeration);
      writeCppEnumeration(enumerationName, anEnumeration, true);
    }
    
    private void writeJavaCountryEnumeration(String enumerationName, EnumT anEnumeration)
    {
        try
        {
              String enumerationFile = GEN_JAVA_SOURCE_OUTPUT_DIR + enumerationName + ".java";
              File outputFile = new File(enumerationFile);
              outputFile.createNewFile();
              PrintWriter pw = new PrintWriter(outputFile);
              int maxValue = 0;
              
              // Properties file containing the key (two character internet domain name for
              // the country) and the value (text description of the country). 
              Properties internetCountries = new Properties();
              FileInputStream fis = new FileInputStream(new File("data/countryCodes.properties"));
              internetCountries.load(fis);
              
            
              pw.println("package edu.nps.moves.disenum;");
              pw.println();
               pw.println("import java.util.HashMap;");
              pw.println("import edu.nps.moves.siso.EnumNotFoundException;");
              pw.println();
              pw.println("/** Enumeration values for " + enumerationName);
              pw.println(" * The enumeration values are generated from the SISO DIS XML EBV document (R35), which was");
              pw.println(" * obtained from http://discussions.sisostds.org/default.asp?action=10&fd=31<p>");
              pw.println(" *");
              pw.println(" * Note that this has two ways to look up an enumerated instance from a value: a fast");
              pw.println(" * but brittle array lookup, and a slower and more garbage-intensive, but safer, method.");
              pw.println(" * if you want to minimize memory use, get rid of one or the other.<p>");
              pw.println(" *");
              pw.println(" * Copyright 2008-2009. This work is licensed under the BSD license, available at");
              pw.println(" * http://www.movesinstitute.org/licenses<p>");
              pw.println(" *");
              pw.println(" * @author DMcG, Jason Nelson");
              pw.println(" */");
              pw.println();
              
              pw.println("public enum " + enumerationName + " \n{\n");
              
              List<EnumrowT> l = anEnumeration.getEnumrow();
              for(int idx = 0; idx < l.size(); idx++)
              {
                 EnumrowT er = l.get(idx);
                 
                 String description = er.getDescription();
                 String enumName = this.enumifyString(description, true);
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
                 
                 // Keep track of this to find max index for lookup array
                 if(maxValue < enumValue)
                 {
                     maxValue = enumValue;
                 }
                 
                 pw.print("    " + enumName + "(" + enumValue + ", " + "\"" + description + "\"" + ", " + "\"" + internetDomainCode + "\")") ;
                 if(idx != l.size() -1)
                 {
                     pw.print(",");
                 }
                 else
                 {
                     pw.print(";");
                 }
                 pw.println();
                 
             }
            pw.println();
            
            pw.println("    /** The enumerated value */");
            pw.println("    public final int value;");
            pw.println("");
            pw.println("    /** Text/english description of the enumerated value */");
            pw.println("    public final String description;");
            pw.println();
            pw.println("    /** Internet domain code (US, FR, UK, CA, etc). This is a guess for many countries */");
            pw.println("    public final String internetDomainCode;");
            pw.println();
            
            pw.println("/** This is an array, with each slot corresponding to an enumerated value");
            pw.println(" * and that slot containing the enumerated object. Use to look up enumerated object when you have the value");
            pw.println(" */");
            maxValue++;
            pw.println("static public " + enumerationName + " lookup[] = new " + enumerationName + "[" + maxValue + "];");
            pw.println("static private HashMap<Integer, " + enumerationName + ">enumerations = new HashMap<Integer, " + enumerationName + ">();");
            pw.println();


            pw.println("/* initialize the array and hash table at class load time */");
            pw.println("static \n{");
            pw.println("    for(" + enumerationName + " anEnum:" +  enumerationName + ".values())");
            pw.println("    {");
            pw.println("        lookup[anEnum.value] = anEnum;");
            pw.println("        enumerations.put(new Integer(anEnum.getValue()), anEnum);");
            pw.println("    }");
            pw.println("}\n");
            
            pw.println("/** Constructor */");
            pw.println(enumerationName + "(int value, String description, String internetDomainCode)");
            pw.println("{");
            pw.println("    this.value = value;");
            pw.println("    this.description = description;");
            pw.println("    this.internetDomainCode = internetDomainCode;");
            pw.println("}");

             pw.println();
            pw.println("/** Returns the string description associated with the enumerated instance with this value. ");
            pw.println(" * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.");
            pw.println("*/");
            pw.println("static public String getDescriptionForValue(int aVal)");
            pw.println("{");
            pw.println("  String desc;");
            pw.println();
            pw.println("    " + enumerationName + " val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("        desc = \"Invalid enumeration: \" + (new Integer(aVal)).toString();");
            pw.println("      else");
            pw.println("         desc = val.getDescription();");
            pw.println();
            pw.println("      return desc;");
            pw.println("}");

            pw.println();
            pw.println("/** Returns the enumerated instance with this value. ");
            pw.println(" * If there is no enumerated instance for this value, the exception is thrown.");
            pw.println("*/");
            pw.println("static public " + enumerationName + " getEnumerationForValue(int aVal) throws EnumNotFoundException");
            pw.println("{");
            pw.println("    " + enumerationName + " val;");
            pw.println("      val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("         throw new EnumNotFoundException(\"no enumeration found for value \" + aVal + \" of enumeration " + enumerationName + "\");");
            pw.println("      return val;");
            pw.println("}");

            pw.println();
            pw.println("/** Returns true if there is an enumerated instance for this value, false otherwise. ");
            pw.println("*/");
            pw.println("static public boolean enumerationForValueExists(int aVal)");
            pw.println("{");
            pw.println("    " + enumerationName + " val;");
            pw.println("      val = enumerations.get(new Integer(aVal));");
            pw.println("      if(val == null)");
            pw.println("         return false;");
            pw.println("      return true;");
            pw.println("}");
            
            pw.println();
            pw.println("/** Returns the enumerated value for this enumeration */");
            pw.println("public int getValue()");
            pw.println("{");
            pw.println("  return value;");
            pw.println("}");
            
            pw.println();
            pw.println("/** Returns the string description for this enumeration. */");
            pw.println("public String getDescription()");
            pw.println("{");
            pw.println("  return description;");
            pw.println("}");
            pw.println();
            
            pw.println("/** As an alternative, returns the internet domain code for this country, if it exists. */");
            pw.println("public String getInternetDomainCode()");
            pw.println("{");
            pw.println("  return internetDomainCode;");
            pw.println("}");
            pw.println();
              
              pw.println("}");
            
          
              pw.flush();
              pw.close();
        }
        catch(Exception e)
        {
            System.out.println();
        }
        
    }
    
    /**
     *  Changes an input string like "Entity State PDU" into "ENTITY_STATE_PDU"
     * 
     * @param text
     * @return
     */
    public String enumifyString(String text, boolean uppercase)
    {
        String enumValue = text.trim();
        if (uppercase) enumValue = enumValue.toUpperCase();
        enumValue = enumValue.replace(" ", "_");
        enumValue = enumValue.replace("-", "_");
        enumValue = enumValue.replace("/", "_");
        enumValue = enumValue.replace("(", "");
        enumValue = enumValue.replace(")", "");
        enumValue = enumValue.replace(",", "");
        enumValue = enumValue.replace("'", "");
        enumValue = enumValue.replace("\"", "");
        enumValue = enumValue.replace(".", "");
        enumValue = enumValue.replace(";", "");
        enumValue = enumValue.replace(":", "");
        enumValue = enumValue.replace("&", "");
        enumValue = enumValue.replace("{", "_");
        enumValue = enumValue.replace("}", "_");
        enumValue = enumValue.replace("#", "_");
        if (uppercase) {
          enumValue = enumValue.replace("^", "_CARET_");
          enumValue = enumValue.replace("<", "_LT_");
          enumValue = enumValue.replace(">", "_GT_");
          enumValue = enumValue.replace("=", "_EQ_");
          enumValue = enumValue.replace("%", "_PCT_");
        }
        else {
          enumValue = enumValue.replace("^", "_caret_");
          enumValue = enumValue.replace("<", "_lt_");
          enumValue = enumValue.replace(">", "_gt_");
          enumValue = enumValue.replace("=", "_eq_");
          enumValue = enumValue.replace("%", "_pct_");          
        }
        
        
        // If it starts with a number, that's not a valid identifier. 
        // replace it with a leading character. Ack--there should be
        // a better regexp to cover this, but getting back references
        // working is not working for me.
        
        enumValue = enumValue.replaceAll("^0", "X_0");
        enumValue = enumValue.replaceAll("^1", "X_1");
        enumValue = enumValue.replaceAll("^2", "X_2");
        enumValue = enumValue.replaceAll("^3", "X_3");
        enumValue = enumValue.replaceAll("^4", "X_4");
        enumValue = enumValue.replaceAll("^5", "X_5");
        enumValue = enumValue.replaceAll("^6", "X_6");
        enumValue = enumValue.replaceAll("^7", "X_7");
        enumValue = enumValue.replaceAll("^8", "X_8");
        enumValue = enumValue.replaceAll("^9", "X_9");
        
        // Finally, replace repeated instances of _ with a single underscore
        enumValue = enumValue.replaceAll("(_+)", "_");
        
        return enumValue;
    }
    
    
    /** Bitmasks **/
    private void writeBitmask(String cname, BitmaskT aBitmask)
    {       
      cname = cname.replace(".", "_");      
      cname = enumifyString(cname, false);    
      cname = cname.toLowerCase();
      writeCppBitmask(cname,  aBitmask);       
    }

    private void writeCppBitmask(String bitmaskName, BitmaskT bitmask) {
      try
      { 
        System.out.println("Bitmask: " + bitmaskName);
        List<BitmaskrowT> subfieldsL = bitmask.getBitmaskrow();
        StringBuilder bitfieldsHeader = new StringBuilder();
        StringBuilder subfieldsHeader = new StringBuilder();
        StringBuilder subfieldsImpl   = new StringBuilder();  
        int maxidlength = 0;
        
        int length = bitmask.getLength().intValue();
        // round up to the nearest power of two
        //http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2Float
        length--;
        length |= length >> 1;
        length |= length >> 2;
        length |= length >> 4;
        length |= length >> 8;
        length |= length >> 16;
        length++;        
        
        String valueType;
        switch(length){
        case(2):
        case(8): valueType = "unsigned char"; break;
        case(16): valueType = "unsigned short"; break;
        case(32): valueType = "unsigned int"; break;
        case(64): valueType = "unsigned long"; break;
        default: throw new Exception("unknown length ("+ length + "), bitmask: " + bitmaskName);
        }

        int unusedRows = 0;
        for (int j = 0; j < subfieldsL.size(); j++) {
          BitmaskrowT subField = subfieldsL.get(j);
          boolean unused;           
          if ( subField.isUnused() == null) unused=false;
          else unused = subField.isUnused();          
          
          BigInteger startBit = subField.getId();
          BigInteger endBit = subField.getId2();
          if (endBit == null) endBit = startBit;
          int fieldWidth = endBit.subtract(startBit).intValue() + 1;
          
          String enumerationName;
          if (unused) {
            enumerationName = "unused";
            unusedRows++;
            if (unusedRows>1) 
              enumerationName = enumerationName + "_" + unusedRows;
          }
          else {
            enumerationName = subField.getName(); 
            enumerationName = enumerationName.replace(" ", "");            
            enumerationName = enumifyString(enumerationName, false);            
          }          
          
          bitfieldsHeader.append("    unsigned int " + enumerationName + ":" + fieldWidth+";\n"); 
          //System.out.println("  subfield: " + enumerationName);
          
          // enumeration names we have used so far
          // (creating a list just to keep the insertion order)
          List<String> enumNamesUsed = new ArrayList<String>(); 
          HashMap<String, Integer> enumValues = new HashMap<String, Integer>();
          HashMap<String, String>  enumDescriptions = new HashMap<String, String>();
          
          int maxValue = 0; 
          int usedCount = 1;        
          List<EnumrowT> l = subField.getEnumrow();
          int lsize;
          if (l == null) lsize = 0;
          else lsize = l.size();
          for(int idx = 0; idx < lsize; idx++)
          {            
            EnumrowT er = l.get(idx);           
            
            StringBuilder u = new StringBuilder();
            u.append(er.isUnused());
            boolean enumUnused = Boolean.parseBoolean(u.toString());
            if  (enumUnused) continue;
            
            // Some entries in the EBV have missing descriptions. If that's the case, we just
            // make up a description; we may get something on the wire with that enumerated
            // value, and we want a valid enumeration object to match that, even if we don't
            // have a good name or description for it.
            String description = er.getDescription();
            if((description == null) || description.equals(""))
                description = "Missing Description";
            String enumName = this.enumifyString(description, true);
            maxidlength = Math.max(maxidlength, enumName.length());
            int enumValue = (int)er.getId();
                           
            // If we've seen this enumeration name before, add some extra text
            // onto the end to make it unique
            if(enumNamesUsed.contains(enumName))
            {
               enumName = enumName + "_" + usedCount; // eg M1_RIFLE to M1_RIFLE_1
               usedCount++;
            }
            enumNamesUsed.add(enumName);
            enumValues.put(enumName, enumValue);        
            
            // Remove embedded quotes from the description, screws up generated code
            description = description.replace("\"", "");
            enumDescriptions.put(enumName, description);
                                       
            if(maxValue < enumValue)
            {
               maxValue = enumValue;
            }
            
            //System.out.println("    enum: " + enumName);
          }
          
          maxValue++;
          if (!unused) 
          {
            // ----------- Write header portion of this enumeration -----------------
            //System.out.println("  writing header for " + enumerationName);
            
            String template = new String();
            StringBuilder allEnums = new StringBuilder();
            Iterator<String> enumsIter = enumNamesUsed.iterator();
            
            template = readFileAsString(CPP_TEMPLATES_DIR + "/subfieldEnumTemplate.h");
    
            for(int idx = 0; idx < enumNamesUsed.size(); idx++)
            {
              String enumName = enumsIter.next();
              allEnums.append("    static " + enumerationName + " " + enumName  + ";\n");          
            }
              
            template = template.replaceAll("@SUBFIELDNAME", enumerationName);
            template = template.replaceAll("@ENUMS", allEnums.toString());
            subfieldsHeader.append(template);
            
             
            // ----------- Write implementation portion of this enumeration -----------------   
            //System.out.println("  writing implementation for " + enumerationName);
            template = new String();
            allEnums = new StringBuilder();
            enumsIter = enumNamesUsed.iterator();          
            
            template = readFileAsString(CPP_TEMPLATES_DIR + "/subfieldEnumTemplate.cpp");
            for(int idx = 0; idx < enumNamesUsed.size(); idx++)
            {
              String enumName = enumsIter.next();            
              int enumValue = enumValues.get(enumName);
              String enumDescription = enumDescriptions.get(enumName);
              allEnums.append(" "+ enumerationName + " " + enumerationName + "::"+ enumName + "(" + enumValue + ", " + "\"" + enumDescription + "\");\n");          
            }          
                    
            template = template.replaceAll("@SUBFIELDNAME", enumerationName);
            template = template.replaceAll("@STARTBIT", startBit.toString());
            template = template.replaceAll("@ENDBIT", endBit.toString());
            template = template.replaceAll("@ENUMSINIT", allEnums.toString());   
            subfieldsImpl.append(template);
          }
        }
        
        
        // ----------- Write <bitmask>.h -----------------
        File outputFile = new File(GEN_CPP_SOURCE_OUTPUT_DIR + bitmaskName + ".h");
        outputFile.createNewFile();
        System.out.println("  Writing bitmask " + outputFile.getPath());        
        PrintWriter pw = new PrintWriter(outputFile);
        String template = new String();
        template = readFileAsString(CPP_TEMPLATES_DIR + "/bitmaskTemplate.h");
        
        template = template.replaceAll("@BITMASKUPPERCASE", bitmaskName.toUpperCase());
        template = template.replaceAll("@BITMASK", bitmaskName);  
        template = template.replaceAll("@BITFIELDS", bitfieldsHeader.toString());
        template = template.replaceAll("@TYPE", valueType);
        template = template.replaceAll("@ENUMSHEADER", subfieldsHeader.toString());
        
        pw.print(template);
        pw.flush();
        pw.close();      

        
        
        // ----------- Write <bitmask>.cpp -----------------
        outputFile = new File(GEN_CPP_SOURCE_OUTPUT_DIR + bitmaskName + ".cpp");
        outputFile.createNewFile();
        System.out.println("  Writing bitmask " + outputFile.getPath());
        pw = new PrintWriter(outputFile);
        template = new String();
        template = readFileAsString(CPP_TEMPLATES_DIR + "/bitmaskTemplate.cpp");
        
        template = template.replaceAll("@BITMASK", bitmaskName);
        template = template.replaceAll("@TYPE", valueType);
        template = template.replaceAll("@ENUMSIMPL", subfieldsImpl.toString());
        
        pw.print(template);
        pw.flush();
        pw.close();
        
        //System.out.println("  max id length:" + maxidlength);
      }
      catch(Exception e)
      {
          System.out.println("writeBitmask exception:" + e);
      }      
      
    }  
    
}
