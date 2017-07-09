<?xml version="1.0"?>
<!--
  xml2docbook.xslt
  Transform EBV-MR XML file to DocBook file
  peter.ross@dsto.defence.gov.au
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="xml" doctype-system="http://www.oasis-open.org/docbook/xml/4.2/docbookx.dtd" doctype-public="-//OASIS//DTD DocBook XML V4.2//EN"/>
  <xsl:strip-space elements="*"/>
  <xsl:template match="ebv">
    <book>
      <bookinfo>
        <title>***DRAFT MACHINE READABLE*** Enumeration and Bit Encoded Values for use with Protocols for Distributed Interactive Simulation Applications</title>
        <subtitle>This document accompanies IEEE Std 1278.1-1995 and IEEE Std 1278.1A-1998</subtitle>
        <corpauthor>
          <xsl:value-of select="@organisation"/>
        </corpauthor>
        <pubsnumber>
          <xsl:value-of select="@title"/>
        </pubsnumber>
        <releaseinfo>
          <xsl:value-of select="@release"/>
        </releaseinfo>
        <legalnotice>
          <para>
            <literallayout>
              Copyright (c) 2007 by the Simulation Interoperability Standards Organization, Inc.
              P.O. Box 781238
              Orlando, FL 32878-1238, USA
              All rights reserved.
            </literallayout>
            This document is an approved product of Simulation Interoperability Standards Organization (SISO), Inc. and therefore the copyright of this document belongs to SISO, Inc. Permission is hereby granted for this document to be used for production of both commercial and non-commercial products. Removal of this copyright statement and claiming rights to this document is prohibited. In addition, permission is hereby granted for this document to be distributed in its original or modified format (e.g. as part of a database; however, modification does not imply to the content of this document) provided that no charge is invoked for the provision. Permission is hereby granted by SISO for modification and extension of products produced from this document providing that SISO's copyright is acknowledged on the products developed.
            <literallayout>
              SISO EXCOM
              P.O. Box 781238
              Orlando, FL 32878-1238, USA
            </literallayout>
          </para>
        </legalnotice>
      </bookinfo>
      <chapter>
        <title>Introduction</title>
        <para>This document specifies the numerical values and associated definitions for those Distributed Interactive Simulation (DIS) Protocol Data Units (PDUs) fields that are identified as enumerations in IEEE 1278.1-1995 and IEEE 1278.1A-1998. Compliance with this document is mandatory for participation in a DIS exercise.</para>
        <para>The various fields are grouped according to the PDUs in which they appear, and the PDUs are then grouped by PDU family, constituting Sections 3-12 below.</para>
        <para>The original contents of this document began as a set of separate appendices to the early versions of the Standard for Distributed Interactive Simulation (DIS) Protocol Data Units (PDUs). These appendices were eventually bound together under common cover with a single title and published as IST-CR-93-19. Stewardship of this document was then temporarily transferred to the Joint Interoperability Engineering Organization (JIEO), which substantially increased the level and amount of detail. The next revision by IST, published as IST-CR-93-46, retained the many substantive contributions of JIEO, while restructuring the document for the first time as the single, integrated source for all enumeration fields found in the DIS PDUs. At that time a change control process was initiated for all changes to this document.</para>
        <xsl:apply-templates select="revisions"/>
        <section>
          <title>Notes</title>
          <para>
            <orderedlist numeration="arabic">
              <listitem>
                <para>The URL for the document library containing this document and prior issues, as well as the Change Request form is: <ulink url="http://www.sisostds.org/doclib/doclib.cfm?SISO_RID_1003262">http://www.sisostds.org/doclib/doclib.cfm?SISO_RID_1003262</ulink></para>
              </listitem>
              <listitem>
                <para>To subscribe to the e-mail reflector associated with the continued development of this Enumerations document go to <ulink url="http://www.sisostds.org/">http://www.sisostds.org/</ulink>, click on the word Discussions, select SISO-ENUM and click on submit.</para>
              </listitem>
            </orderedlist>
          </para>
        </section>
      </chapter>
      <chapter>
        <title>Acronyms</title>
        <xsl:apply-templates select="acronyms"/>
      </chapter>
      <chapter>
        <title>PDU Header</title>
        <section>
          <title>Protocol version</title>
          <para>This section specifies the 8-bit enumeration for the Protocol-Version field in the PDU-Header record.</para>
          <xsl:apply-templates select="enum[@cname='pduheader.protocolversion']"/>
        </section>
        <section>
          <title>PDU Type</title>
          <para>This section specifies the 8-bit enumeration for the PDU-Type field in the PDU Header record.</para>
          <xsl:apply-templates select="enum[@cname='pduheader.pdutype']"/>
        </section>
        <section>
          <title>Protocol Family</title>
          <para>This section specifies the 8-bit enumeration for the Protocol-Family field in the PDU-Header record.</para>
          <xsl:apply-templates select="enum[@cname='pduheader.protocolfamily']"/>
        </section>
      </chapter>
      <chapter>
        <title>Entity State PDU</title>
        <section>
          <title>Force ID</title>
          <para>This section specifies the 8-bit enumeration for the Force-ID field in the Entity-State PDU.</para>
          <xsl:apply-templates select="enum[@cname='es.forceid']"/>
        </section>
        <section id="es.type">
          <title>Entity Type record</title>
          <para>This section specifies the 64-bit enumeration for the Entity-Type record of the Entity State PDU. Individual fields in this record are discussed separately in the subsections below. Entity Types are arranged in a hierarchical order such that higher-fidelity simulations may depict detailed representations of an entity (such as an F-16B) while lower-fidelity simulations may depict the same entity in a more generic manner (such as an F-16 or a Fighter Aircraft).</para>
          <section id="es.type.kind">
            <title>Entity Kind</title>
            <para>This section specifies the 8-bit enumeration for the Entity-Kind field.</para>
            <xsl:apply-templates select="enum[@cname='es.type.kind']"/>
            <section>
              <title>Platform</title>
              <para>The Platform kind refers to vehicles such as ships, tanks, aircraft and submarines. Fields used to further describe platforms are detailed in the paragraphs that follow.</para>
              <section id="es.type.kind.1.domain">
                <title>Domain</title>
                <para>The Domain field is an 8-bit enumeration. The defined values for a platform's domain are:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain']"/>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration representing the country to which a particular platform's design is attributed. The defined values for this field are contained in <xref linkend="es.type.country"/></para>
              </section>
              <section>
                <title>Category</title>
                <para>The Category field is an 8-bit enumeration. The field values for Land, Air, Surface, Subsurface and Space domains are given below.</para>
                <section>
                  <title>Land</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain.1.cat']"/>
                </section>
                <section>
                  <title>Air</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain.2.cat']"/>
                </section>
                <section>
                  <title>Surface</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain.3.cat']"/>
                </section>
                <section>
                  <title>Subsurface</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain.4.cat']"/>
                </section>
                <section>
                  <title>Space</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.1.domain.5.cat']"/>
                </section>
              </section>
            </section>
            <section>
              <title>Muntion</title>
              <para>The Munition kind includes entities such as missiles, ballistic rounds, bullets and torpedoes. Fields used to further describe munitions are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>The Domain field is an 8-bit enumeration reflecting a munition's normal role. The defined values for a munition's domain are:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.2.domain']"/>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration representing the country to which a particular munition's design is attributed. The defined values for this field are contained in <xref linkend="es.type.country"/>.</para>
              </section>
              <section>
                <title>Category</title>
                <para>The Category field is an 8-bit enumeration. The field values for munitions of all domains are:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.2.cat']"/>
              </section>
              <section>
                <title>Fuse and warhead</title>
                <para>Munitions are further identified in the Detonation PDU in terms of their fuse and warhead. The values for these fields are contained in <xref linkend="warfare.burstdescriptor.fuse"/> and <xref linkend="warfare.burstdescriptor.warhead"/> respectively.</para>
              </section>
            </section>
            <section>
              <title>Life Form</title>
              <para>The Life-Form kind refers to dismounted infantry, scouts, SEALS, or other humans, as well as animals like whales and shrimp. Life forms are treated similarly to platforms since they can move and (some) can fire munitions. Fields used to further define life forms are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>The Domain field is an 8-bit enumeration. The defined values for a life form's domain are identical to a platform's. See <xref linkend="es.type.kind.1.domain"/>.</para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration defining a life form's country of origin. The defined values for this field are found in <xref linkend="es.type.country"/>.</para>
              </section>
              <section>
                <title>Specific Life-Form definition</title>
                <para>The remaining fields of the Entity-Type record further define all life forms. The Subcategory field specifying the number of individuals allows representation of one or more life forms using one PDU.</para>
                <section id="es.type.kind.3.subcat">
                  <title>Subcategory</title>
                  <para>This section defines the weapons that may be carried by life forms.</para>
                  <section>
                    <title>U.S. Weapons for Life Forms</title>
                    <xsl:apply-templates select="enum[@cname='es.type.225.kind.3.subcat']"/>
                  </section>
                  <section>
                    <title>C.I.S Weapons for Life Forms</title>
                    <xsl:apply-templates select="enum[@cname='es.type.222.kind.3.subcat']"/>
                  </section>
                  <section>
                    <title>U.K. Weapons for Life Forms</title>
                    <xsl:apply-templates select="enum[@cname='es.type.224.kind.3.subcat']"/>
                  </section>
                  <section>
                    <title>French Weapons for Life Forms</title>
                    <xsl:apply-templates select="enum[@cname='es.type.71.kind.3.subcat']"/>
                  </section>
                  <section>
                    <title>German Weapons for Life Forms</title>
                    <xsl:apply-templates select="enum[@cname='es.type.78.kind.3.subcat']"/>
                  </section>
                </section>
              </section>
            </section>
            <section>
              <title>Environmental</title>
              <para>The Environmental kind refers to entities in the usual physical-object sense, e.g. clouds and ice bergs, as well as inherent characteristics of a particular environment, such as sea state or transmissivity profile. Fields used to further describe environmental entities are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>
                  The Domain field is an 8-bit enumeration. The defined values for Environmental domain are identical to a platform's. See <xref linkend="es.type.kind.1.domain"/>.
                </para>
              </section>
              <section>
                <title>Country</title>
                <para>
                  The Country field is unused.
                </para>
              </section>
              <section>
                <title>Specific Environmental definition</title>
                <para>The remaining fields of the Entity-Type record further define all environmentals. The Subcategory field defines the size of the environmental entity.</para>
                <section>
                  <title>Subcategory</title>
                  <para>For environmental entities the Subcategory field indicates the entity's size, with the following enumerated values:</para>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.4.subcat']"/>
                </section>
              </section>
            </section>
            <section>
              <title>Cultural Feature</title>
              <para>The Cultural-Feature kind refers to engineering and natural effects such as craters, bridges, vehicle tracks, etc. Fields used to further describe cultural features are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>
                  The Domain field is an 8-bit enumeration. The defined values for a cultural feature's domain are identical to a platform's. See <xref linkend="es.type.kind.1.domain"/>.
                </para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is unused.</para>
              </section>
              <section>
                <title>Specific Cultural-Feature definition</title>
                <para>The remaining fields of the Entity-Type record further define all cultural features.</para>
              </section>
            </section>
            <section>
              <title>Supply</title>
              <para>The Supply kind refers to supplies other than munitions, such as fuel, food and personnel. Fields used to further describe supplies are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>The Domain field is unused.</para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is unused.</para>
              </section>
              <section>
                <title>Specific Supply definition</title>
                <para>The remaining fields of the Entity-Type record further define all supplies.</para>
              </section>
            </section>
            <section>
              <title>Radio</title>
              <para>The Radio kind refers to electronic devices for the communication of both audio and data. Fields used to further describe radios are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para>The Domain field is an 8-bit enumeration. The value is based on the operating domain of the platform carrying the radio. Specific enumerations are defined in <xref linkend="es.type.kind.1.domain"/>.</para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration defining the radio's country of origin. The defined values for this field are found in <xref linkend="es.type.country"/>.</para>
              </section>
              <section>
                <title>Category</title>
                <para>The Category field is an 8-bit enumeration. The Category field is based on the primary information type broadcast/received by the radio when in operation. The defined values for all domains are as follows:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.7.cat']"/>
              </section>
              <section>
                <title>Nomenclature Version</title>
                <para>The Nomenclature Version field is an 8-bit enumeration. The field indicates the naming convention applied to the radio system by the manufacturer/controlling agency. The defined values are as follows:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.7.version']"/>
              </section>
              <section>
                <title>Nomenclature</title>
                <para>The Nomenclature field is a 16-bit enumeration. The field indicates the specific radio system. The defined values are as follows:</para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.7.nomenclature']"/>
              </section>
            </section>
            <section>
              <title>Expendable</title>
              <para>The Expendable kind refers to countermeasures devices that are dispensed from another entity. The devices may be active emitters or passive reflectors of energy. Fields used to further describe expendable entities are detailed in the paragraphs which follow.</para>
              <section>
                <title>Domain</title>
                <para>The Domain field is an 8-bit enumeration. The defined values for an expendable's domain are identical to a platform's. See <xref linkend="es.type.kind.1.domain"/>.</para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration defining the expendable's country of origin. The defined values for this field are found in <xref linkend="es.type.country"/>.</para>
              </section>
              <section>
                <title>Category</title>
                <para>The Category field is an 8-bit enumeration. The field values for expendables for Air, Surface, and Subsurface domains are given below.</para>
                <section>
                  <title>Air</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.8.domain.2.cat']"/>
                </section>
                <section>
                  <title>Surface</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.8.domain.3.cat']"/>
                </section>
                <section>
                  <title>Subsurface</title>
                  <xsl:apply-templates select="enum[@cname='es.type.kind.8.domain.4.cat']"/>
                </section>
              </section>
            </section>
            <section>
              <title>Sensor/Emitter</title>
              <para>The Sensor/Emitter kind refers to sensors and emitters, such as stand-alone radars, jammers, and detection systems, that are not part of another platform or system described by another Entity Kind. Fields used to further describe sensors/emitters are detailed in the paragraphs that follow.</para>
              <section>
                <title>Domain</title>
                <para> The Domain field is an 8-bit enumeration. The defined values for a sensor/emitter's domain are identical to a platform's. See <xref linkend="es.type.kind.1.domain"/>.</para>
              </section>
              <section>
                <title>Country</title>
                <para>The Country field is a 16-bit enumeration defining a sensor/emitter's country of origin. The defined values for this field are found in <xref linkend="es.type.country"/>.</para>
              </section>
              <section>
                <title>Category</title>
                <para>The Category field is an 8-bit enumeration. The defined values for this field for all domains are: </para>
                <xsl:apply-templates select="enum[@cname='es.type.kind.9.cat']"/>
              </section>
              <section>
                <title>Subcategory</title>
                <para>The Subcategory-field is an 8-bit enumeration. The defined values for this field for all domains can be found in <xref linkend="der.emission.function"/>.</para>
              </section>
            </section>
          </section>
          <section id="es.type.country">
            <title>Country</title>
            <para>This section specifies the 16-bit enumeration for the Country field.</para>
            <xsl:apply-templates select="enum[@cname='es.type.country']"/>
          </section>
          <section>
            <title>Comprehensive Entity-Type tables</title>
            <para>The following tables list the correct field values of the Entity-Type record for many specific entities in a typical DIS exercise. The header on each page contains the Kind-, Domain-, and Country-field values for all entities on that page, as specified in <xref linkend="es.type.kind"/>. The remaining field values (Category, Subcategory, Specific) are nested in numerical order (with occasional exceptions due to correction or update) with specific definitions appropriate to the entity's kind, domain, and country. The value of zero used in a category, subcategory, or specific field in this enumerations in this section and associated subsections shall mean .other. in all cases whether explicitly stated or not. Any unused field shall be 0-filled.</para>
            <xsl:apply-templates select="cet[@cname='es.type.cet']"/>
          </section>
        </section>
        <section>
          <title>Entity Appearance</title>
          <para>This section specifies the 32-bit enumeration for the Entity Appearance field in the Entity State PDU. This field is kind and domain specific, and as applicable, specific bits are designated to common bit locations. The following sections describe the specific bit definitions for all entity kinds. The Entity-Kind field is found in the Entity-Type Record, as defined in IEEE 1278.1-1995. Entity-kind values are defined in section <xref linkend="es.type.kind"/> of this document.</para>
          <section>
            <title>Platform Kind</title>
            <section>
              <title>Platforms of the Land Domain</title>
              <para>The bits of the Entity Appearance field for land platforms are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='es.appear.platform.land']"/>
            </section>
            <section>
              <title>Platforms of the Air Domain</title>
              <para>The bits of the Entity-Appearance field for air platforms are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='es.appear.platform.air']"/>
            </section>
            <section>
              <title>Platforms of the Surface Domain</title>
              <para>The bits of the Entity-Appearance field for surface platforms are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='es.appear.platform.surface']"/>
            </section>
            <section>
              <title>Platforms of the Subsurface Domain</title>
              <para>The bits of the Entity-Appearance field for subsurface platforms are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='es.appear.platform.subsurface']"/>
            </section>
            <section>
              <title>Platforms of the Space Domain</title>
              <para>The bits of the Entity-Appearance field for space platforms are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='es.appear.platform.space']"/>
            </section>
          </section>
          <section>
            <title>Munition Kind</title>
            <para>The bits of the Entity-Appearance field for munitions are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.munition']"/>
          </section>
          <section>
            <title>Life Forms Kind</title>
            <para>The bits of the Entity-Appearance field for life forms are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.lifeform']"/>
          </section>
          <section>
            <title>Environmentals Kind</title>
            <para>The bits of the Entity-Appearance field for environmentals are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.environmental']"/>
          </section>
          <section>
            <title>Cultural Features Kind</title>
            <para>The bits of the Entity-Appearance field for Cultural Features are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.cultural']"/>
          </section>
          <section>
            <title>Supplies Kind</title>
            <para>The bits of the Entity-Appearance field for Supplies are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.supplies']"/>
          </section>
          <section>
            <title>Radios Kind</title>
            <para>The bits of the Entity-Appearance field for Radios are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.radios']"/>
          </section>
          <section>
            <title>Expendables Kind</title>
            <para>The bits of the Entity-appearance field for Expendables are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.expendables']"/>
          </section>
          <section>
            <title>Sensor/Emitter Kind</title>
            <para>The bits of the Entity Appearance field for Sensor/Emitters are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='es.appear.sensoremitter']"/>
          </section>
        </section>
        <section>
          <title>Dead-Reckoning Algorithm</title>
          <para>This section specifies the 8-bit enumeration for the Dead-Reckoning-Algorithm field in the Entity State PDU.</para>
          <xsl:apply-templates select="enum[@cname='es.dra']"/>
        </section>
        <section>
          <title>Entity Marking</title>
          <para>This section specifies the 8-bit enumeration for Character Set, found in the Entity-Marking field in the Entity State PDU.</para>
          <xsl:apply-templates select="enum[@cname='es.markingtext']"/>
          <section>
            <title>Codes for Entity Marking Field (Army Marking - Character Set code = 2)</title>
            <section>
              <title>Byte 1</title>
              <para>Byte 1 Character set code = 2</para>
            </section>
            <section>
              <title>Bytes 2 through 7</title>
              <para>Bytes 2 through 7 contain a Division or Corps designation and an encoded bumper number.</para>
            </section>
            <section>
              <title>Byte 2- Division /Corps designation</title>
              <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.div']"/>
            </section>
            <section>
              <title>Byte 3 - High Level Unit </title>
              <para>1 to 255 are codes for a High Level Unit such as Battalion, Brigade or Division headquarters within the Division/Corp specified by the contents of Byte 2 (for example, Byte 2 = 1 and Byte 3 = 1 means the 1-7CAV for 1st Cavalry Division).</para>
              <section>
                <title>Byte 3 - High Level Unit (Byte 2 = 1 - 1st Cavalry)</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.1cavunit']"/>
              </section>
              <section>
                <title>Byte 3 - High Level Unit (Byte 2 = 2 - 1st Infantry)</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.1infunit']"/>
              </section>
            </section>
            <section>
              <title>Bytes 4 through 7</title>
              <para>These are codes for the portion of a bumper number representing a) Company, Battery, Troop; b) Platoon, Section; and c) Vehicle.</para>
              <section>
                <title>Byte 4 - Company, Battery, Troop</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.company']"/>
              </section>
              <section>
                <title>Byte 5 - Platoon, Section</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.platoon']"/>
              </section>
              <section>
                <title>Byte 6 and 7 - Vehicle</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.vehicle']"/>
              </section>
            </section>
            <section>
              <title>Bytes 8 through 12</title>
              <para>Bytes 8 through 12 contain entity marking codes shown below for a digit / chevron marking system. Note that for character set 2 the digit / chevron marks are restricted to bytes 8 - 12 of the Marking field.</para>
              <section>
                <title>Bytes 8, 9, 10 and 12</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.symbol1']"/>
              </section>
              <section>
                <title>Byte 11</title>
                <xsl:apply-templates select="enum[@cname='es.markingtext.cctt.symbol2']"/>
                <para>
                  Bytes 8 and 9 are codes for high level unit (for example, Battalion) marking.
                  Byte 10 is a code for company marking.
                  Byte 11 is a code for platoon marking.
                  Byte 12 is used for Dismounted Infantry Marking
                </para>
              </section>
            </section>
          </section>
          <section>
            <title>Codes for Entity Marking Field (Digit / Chevron - Character Set code = 3)</title>
            <section>
              <title>Byte 1</title>
              <para>Byte 1 Character set code = 3</para>
            </section>
            <section>
              <title>Byte 2 through 12</title>
              <para>Bytes 2 through 12 contain digit/chevron codes.</para>
              <xsl:apply-templates select="enum[@cname='es.markingtext.chevron.symbol']"/>
            </section>
          </section>
        </section>
        <section>
          <title>Entity Capabilities record</title>
          <para>This section specifies the 32-bit Boolean array of the Entity Capabilities record in the Entity State PDU. Any individual bit set to one indicates that the entity has the corresponding capability.</para>
          <xsl:apply-templates select="bitmask[@cname='es.capabilities']"/>
        </section>
        <section>
          <title>Parameter Type</title>
          <para>This section specifies the 32-bit enumeration for the Parameter-Type field in the Articulation-Parameter record of the Entity State and Detonation PDUs.</para>
          <section>
            <title>Parameter Type Designator</title>
            <para>This section specifies the 8-bit enumeration for the Parameter Type Designator field in the articulated Parts Record.</para>
            <xsl:apply-templates select="enum[@cname='es.vp.type']"/>
            <section id="es.vp.type.1.attached">
              <title>Attached parts</title>
              <para>Following are the enumeration values for attached-parts stations. These values are used when the Parameter Type Designator is equal to one, signifying an attached part.</para>
              <xsl:apply-templates select="enum[@cname='es.vp.type.1.attached']"/>
            </section>
            <section>
              <title>Articulated parts</title>
              <para>Following are the enumeration values for articulated-parts parameters. These values are used when the Parameter Type Designator is equal to zero, signifying an articulated part.</para>
              <section>
                <title>Articulated parts offset number</title>
                <xsl:apply-templates select="enum[@cname='es.vp.type.0.articulated.offset']"/>
              </section>
              <section id="es.vp.type.0.articulated.index">
                <title>Articulated parts index number</title>
                <xsl:apply-templates select="enum[@cname='es.vp.type.0.articulated.index']"/>
              </section>
              <section>
                <title>Example #1</title>
                <para>To represent the articulation of a tank gun, azimuth of the turret is required as well as the elevation of the gun. This represents two articulated parts. The turret is attached to the tank. It has ID - Part Attached to = 0 because it is attached directly to the tank. We wish to dead reckon the position of the turret, so we require two articulation parameters for the turret: the azimuth and the azimuth rate. Azimuth will be articulation parameter #1 and azimuth rate will be articulation parameter #2. The gun is attached to the turret. It has ID - Part Attached to = 1 because it is attached to the turret. The gun has one articulation parameter, namely the elevation of the gun. Elevation will be articulation parameter #3.</para>
                <para>For the turret, parameter #1 is the azimuth. The value to represent this is 4107:  4096 (primary turret) + 11 (azimuth of that turret). Parameter #2 is the azimuth rate. The value to represent this is 4108: 4096 + 12 (azimuth rate). For the gun, parameter #1 is elevation. The value to represent this is 4429: 4416 (primary gun) + 13 (elevation).</para>
                <para>Suppose the turret is slewed but the elevation is unchanged. Then the three Articulation Parameter records would be:</para>
                <informaltable>
                  <tgroup cols="2">
                    <tbody>
                      <row>
                        <entry>Change indicator:</entry>
                        <entry>(value increment to indicate a change)</entry>
                      </row>
                      <row>
                        <entry>ID - Part Attached to:</entry>
                        <entry>0 (tank)</entry>
                      </row>
                      <row>
                        <entry>Parameter #1 type:</entry>
                        <entry>4107</entry>
                      </row>
                      <row>
                        <entry>Parameter value:</entry>
                        <entry>(an angle in radian)</entry>
                      </row>
                    </tbody>
                  </tgroup>
                </informaltable>
                <informaltable>
                  <tgroup cols="2">
                    <tbody>
                      <row>
                        <entry>Change indicator:</entry>
                        <entry>(value increment to indicate a change)</entry>
                      </row>
                      <row>
                        <entry>ID - Part Attached to:</entry>
                        <entry>0 (tank)</entry>
                      </row>
                      <row>
                        <entry>Parameter #2 type:</entry>
                        <entry>4108</entry>
                      </row>
                      <row>
                        <entry>Parameter value:</entry>
                        <entry>(rate in radian/sec)</entry>
                      </row>
                    </tbody>
                  </tgroup>
                </informaltable>
                <informaltable>
                  <tgroup cols="2">
                    <tbody>
                      <row>
                        <entry>Change indicator:</entry>
                        <entry>(value unchanged to indicate no change)</entry>
                      </row>
                      <row>
                        <entry>ID - Part Attached to:</entry>
                        <entry>1 (turret)</entry>
                      </row>
                      <row>
                        <entry>Parameter #2 type:</entry>
                        <entry>4213</entry>
                      </row>
                      <row>
                        <entry>Parameter value:</entry>
                        <entry>(zero)</entry>
                      </row>
                    </tbody>
                  </tgroup>
                </informaltable>
              </section>
              <section>
                <title>Example #2</title>
                <para>To represent an air-to-surface missile on an aircraft it is necessary to specify the station to which the missile is attached and the type of missile. For example, for a missile on the first left-wing station, the parameter type would be 0640. (The Parameter-Value field would indicate the type of munition attached to that station.) The Articulation Parameter record would then appear as:</para>
                <informaltable>
                  <tgroup cols="2">
                    <tbody>
                      <row>
                        <entry>Change indicator:</entry>
                        <entry>(value unchanged to indicate no change)</entry>
                      </row>
                      <row>
                        <entry>ID - Part Attached to:</entry>
                        <entry>0 (aircraft)</entry>
                      </row>
                      <row>
                        <entry>Parameter #1 type:</entry>
                        <entry>0640</entry>
                      </row>
                      <row>
                        <entry>Parameter value:</entry>
                        <entry>(type of missile from 64-bit munition type)</entry>
                      </row>
                    </tbody>
                  </tgroup>
                </informaltable>
                <para>If the missile was fired, the next Entity State PDU would have an Articulation Parameter record with the following information on the launched missile:</para>
                <informaltable>
                  <tgroup cols="2">
                    <tbody>
                      <row>
                        <entry>Change indicator:</entry>
                        <entry>(value increment to indicate a change)</entry>
                      </row>
                      <row>
                        <entry>ID - Part Attached to:</entry>
                        <entry>0 (aircraft)</entry>
                      </row>
                      <row>
                        <entry>Parameter #1 type:</entry>
                        <entry>0640</entry>
                      </row>
                      <row>
                        <entry>Parameter value:</entry>
                        <entry>(type of missile from 64-bit munition type)</entry>
                      </row>
                    </tbody>
                  </tgroup>
                </informaltable>
                <para>The change indicator specifies that the munition that was present is no longer present.</para>
              </section>
            </section>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Warfare</title>
        <section>
          <title>Burst Descriptor record</title>
          <para>This section specifies the 16-bit enumerations for the Fuse (also called Detonator) and Warhead fields in the Burst Descriptor Record of the Fire and Detonation PDUs.</para>
          <section id="warfare.burstdescriptor.warhead">
            <title>Warhead</title>
            <para>Values for this field are:</para>
            <xsl:apply-templates select="enum[@cname='warfare.burstdescriptor.warhead']"/>
          </section>
          <section id="warfare.burstdescriptor.fuse">
            <title>Fuse (detonator)</title>
            <para>Values for this field are:</para>
            <xsl:apply-templates select="enum[@cname='warfare.burstdescriptor.fuse']"/>
          </section>
        </section>
        <section>
          <title>Detonation Result</title>
          <para>This section specifies the 8-bit enumeration for the Detonation-Result field in the Detonation PDU.</para>
          <xsl:apply-templates select="enum[@cname='warfare.detonationresult']"/>
        </section>
      </chapter>
      <chapter>
        <title>Logistics</title>
        <section>
          <title>Service Request PDU</title>
          <para>This section specifies the 8-bit enumeration for the Service-Type-Requested field in the Service-Request PDU.</para>
          <xsl:apply-templates select="enum[@cname='log.servicerequest']"/>
        </section>
        <section>
          <title>Repair Complete PDU</title>
          <para>This section specifies the 16-bit enumeration for the Repair field in the Repair Complete PDU.</para>
          <section>
            <title>General repair codes</title>
            <para>These codes apply to all entities that may have requested repair:</para>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.general']"/>
          </section>
          <section>
            <title>Drive train</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.drivetrain']"/>
          </section>
          <section>
            <title>Hull/Airframe/B</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.hull']"/>
          </section>
          <section>
            <title>Interfaces with environment</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.environment']"/>
          </section>
          <section>
            <title>Weapons</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.weapons']"/>
          </section>
          <section>
            <title>Fuel systems</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.fuelsystem']"/>
          </section>
          <section>
            <title>Electronics</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.electronics']"/>
          </section>
          <section>
            <title>Life support systems</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.lifesupport']"/>
          </section>
          <section>
            <title>Hydraulic systems and actuators</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.hydraulic']"/>
          </section>
          <section>
            <title>Auxiliary craft</title>
            <xsl:apply-templates select="enum[@cname='log.repaircomplete.auxilary']"/>
          </section>
        </section>
        <section>
          <title>Repair Response PDU</title>
          <para>This section specifies the 8-bit enumeration for the Repair-Result field in the Repair-Response PDU.</para>
          <xsl:apply-templates select="enum[@cname='log.repairresponse']"/>
        </section>
      </chapter>
      <chapter>
        <title>Simulation Management family</title>
        <section>
          <title>Datum Specification record</title>
          <para>This section specifies the 32-bit enumerations for Datum ID in the Datum Specification Record, as found in the Action-Request, Action-Response, Data-Query, Set-Data, Data, Event-Report, and Message PDUs. Also shown for each datum are its type, length, units, and an abbreviated description.</para>
          <xsl:apply-templates select="enum[@cname='simman.datumid']"/>
        </section>
        <section>
          <title>Stop/Freeze PDU</title>
          <section>
            <title>Reason</title>
            <para>This section specifies the 8-bit enumeration for the Reason field in the Stop/Freeze PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.stop.reason']"/>
          </section>
          <section>
            <title>Frozen Behavior</title>
            <para>This section specifies the 8-bit Boolean array of the Frozen-Behavior field in the Stop/Freeze PDU. Any individual bit set to one indicates that the simulation application is to continue the corresponding activity in the frozen state; a bit set to zero indicates that the activity is to cease in the frozen state.</para>
            <xsl:apply-templates select="bitmask[@cname='simman.stop.frozenbehavior']"/>
          </section>
        </section>
        <section>
          <title>Acknowledge PDU</title>
          <section>
            <title>Acknowledge Flag</title>
            <para>This section specifies the 16-bit enumeration for the Acknowledge-Flag field in the Acknowledge PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.ack.ackflag']"/>
          </section>
          <section>
            <title>Response Flag</title>
            <para>This field specifies the 16-bit enumeration for the Response Flag field in the Acknowledge PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.ack.responseflag']"/>
          </section>
        </section>
        <section>
          <title>Action Request PDU</title>
          <section>
            <title>Action ID</title>
            <para>This section specifies the 32-bit enumeration for the Action-ID field in the Action-Request PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.actionrequest.actionid']"/>
          </section>
        </section>
        <section>
          <title>Action Response PDU</title>
          <section>
            <title>Request Status</title>
            <para>This section specifies the 32-bit enumeration for the Request-Status field in the Action-Response PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.actionresponse.status']"/>
          </section>
        </section>
        <section>
          <title>Event Report PDU</title>
          <section>
            <title>Event Type</title>
            <para>This section specifies the 32-bit enumeration for the Event-Type field in the Event-Report PDU.</para>
            <xsl:apply-templates select="enum[@cname='simman.eventreport.eventtype']"/>
          </section>
        </section>
        <section>
          <title>Simulation Management w/Reliability family</title>
          <para>The enumerations in this section are specific to the Simulation Management w/Reliability protocol.</para>
          <section>
            <title>Required Reliability Service</title>
            <para>This field specifies the 8-bit enumeration for the Required Reliability Service field in the Create Entity-R, Remove Entity-R, Start/Resume-R, Stop/Freeze-R, Action Request-R, Data Query-R, Set Data-R, Data-R, Record Query-R, Set Record-R, and Record-R PDUs.</para>
            <xsl:apply-templates select="enum[@cname='simman.reliability.service']"/>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Distributed Emission Regeneration family</title>
        <section>
          <title>Electromagnetic Emission PDU</title>
          <section>
            <title>Emitter Name</title>
            <para>This section specifies the 16-bit enumeration for the Emitter-Name field in the Emitter System record of the Electromagnetic Emission PDU. The number space in divided into three segments electromagnetic emitters, acoustic emitters, and other emitter.</para>
            <section>
              <title>Electromagnetic emitters</title>
              <xsl:apply-templates select="enum[@cname='der.emission.name.electro']"/>
            </section>
            <section>
              <title>Acoustic emitters</title>
              <xsl:apply-templates select="enum[@cname='der.emission.name.acoustic']"/>
            </section>
            <section>
              <title>Acoustic emitters</title>
              <xsl:apply-templates select="enum[@cname='der.emission.name.other']"/>
            </section>
          </section>
          <section id="der.emission.function">
            <title>Function</title>
            <para>This section specifies the 8-bit enumeration for the Function field in the Emitter-System record of the Electromagnetic Emission PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.emission.function']"/>
          </section>
          <section>
            <title>State Update Indicator</title>
            <para>This section specifies the 8-bit enumeration for the State Update Indicator field in the Electromagnetic Emission PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.emission.stateupdate']"/>
          </section>
          <section>
            <title>Beam Function</title>
            <para>This section specifies the 8-bit enumeration for the Beam Function field in the Electromagnetic Emission PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.emission.beamfunction']"/>
          </section>
          <section>
            <title>High Density Track/Jam</title>
            <para>This section specifies the 8-bit enumeration for the High Density Track/Jam field in the Electromagnetic Emission PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.emission.hdtj']"/>
          </section>
        </section>
        <section>
          <title>Designator PDU</title>
          <section>
            <title>Code Name</title>
            <para>This section specifies the 16-bit enumeration for the Code-Name field in the Designator PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.designator.codename']"/>
          </section>
          <section>
            <title>Designator Code</title>
            <para>This section specifies the 16-bit enumeration for the Designator-Code field in the Designator PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.designator.code']"/>
          </section>
        </section>
        <section>
          <title>IFF/ATC/NAVAIDS PDU</title>
          <para>The enumerations for the IFF/ATC/NAVAIDS PDU are listed by system type. There are currently no enumerations for System Type = 0 (Other) or for NAVAIDS.</para>
          <para>For IFF Mode 1, 2, and 3 code elements, the IFF code is placed in the code elements reading right to left. For example a Mode 2 code of 2376 would be placed in the Parameter 2 code elements as follows: Code element 1 = 6, Code element 2 = 7, Code element 3 = 3 and Code element 4 = 2. The entire 16-bit Code/Status field is then passed as an unsigned integer.</para>
          <section>
            <title>System ID</title>
            <section>
              <title>System Type</title>
              <para>This section specifies the 16-bit enumeration for the System Type field in the System Identifier record of the IFF/ATC/NAVAIDS PDU.</para>
              <xsl:apply-templates select="enum[@cname='der.iff.type']"/>
            </section>
            <section>
              <title>System Name</title>
              <para>This section specifies the 16-bit enumeration for the System Name field in the System Identifier record of the IFF/ATC/NAVAIDS PDU.</para>
              <xsl:apply-templates select="enum[@cname='der.iff.name']"/>
            </section>
            <section>
              <title>System Mode</title>
              <para>This section specifies the 8-bit enumeration for the System Mode field in the System Identifier record of the IFF/ATC/NAVAIDS PDU.</para>
              <xsl:apply-templates select="enum[@cname='der.iff.mode']"/>
            </section>
          </section>
          <section>
            <title>System Type 1 (Mark X/XII/ATCRBS/MODE S Transponder)</title>
            <section>
              <title>System ID</title>
              <section>
                <title>Change/Options</title>
                <para>This section specifies the 8-bit Boolean array for the Change/Options field in the System ID record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.changeoptions']"/>
              </section>
            </section>
            <section>
              <title>Fundamental Operational Data</title>
              <section>
                <title>System Status</title>
                <para>This section specifies the 8-bit Boolean array for the System Status field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.fop.status']"/>
              </section>
              <section>
                <title>Parameter 1 - Mode 1 Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param1']"/>
              </section>
              <section>
                <title>Parameter 2 - Mode 2 Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param2']"/>
              </section>
              <section>
                <title>Parameter 3 - Mode 3 Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param3']"/>
              </section>
              <section>
                <title>Parameter 4 - Mode 4 Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param4']"/>
              </section>
              <section>
                <title>Parameter 5 - Mode C Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param5']"/>
              </section>
              <section>
                <title>Parameter 6 - Mode S Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.param6']"/>
              </section>
              <section>
                <title>Modifier</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.1.fop.modifier']"/>
              </section>
              <section>
                <title>Alternate Parameter 4</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.1.fop.altp4']"/>
              </section>
              <section>
                <title>Information Layers</title>
                <para>This section specifies the 8-bit Boolean array for the Information Layer Field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.infolayers']"/>
              </section>
            </section>
            <section>
              <title>Layer Header</title>
              <section>
                <title>Layer Specific Information</title>
                <para>This section specifies the 8-bit enumeration for the Layer Specific Information field in the Layer Header record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="enum[@cname='der.iff.layerspecific']"/>
              </section>
            </section>
            <section>
              <title>Secondary Operational Data</title>
              <para>This section specifies the 8-bit enumeration of the Operational Parameters 1 and 2 in the Secondary Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
              <section>
                <title>Operational Parameter 1</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.1.sop.param1']"/>
              </section>
              <section>
                <title>Operational Parameter 2</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.1.sop.param2']"/>
              </section>
            </section>
          </section>
          <!-- System Type 1 (Mark X/XII/ATCRBS/MODE S Transponder -->
          <section>
            <title>System Type 2 (Mark X/II/ATCRBS/MODE S Interrogator)</title>
            <section>
              <title>System ID</title>
              <section>
                <title>Change/Options</title>
                <para>This section specifies the 8-bit Boolean array for the Change/Options field in the System ID record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.changeoptions']"/>
              </section>
            </section>
            <section>
              <title>Fundamental Operational Data</title>
              <section>
                <title>System Status</title>
                <para>This section specifies the 8-bit Boolean array for the System Status field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.fop.status']"/>
              </section>
              <section>
                <title>Parameter 1 - Mode 1 Interrogator Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param1']"/>
              </section>
              <section>
                <title>Parameter 2 - Mode 2 Interrogator Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param2']"/>
              </section>
              <section>
                <title>Parameter 3 - Mode 3 Interrogator Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param3']"/>
              </section>
              <section>
                <title>Parameter 4 - Mode 4 Interrogator Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param4']"/>
              </section>
              <section>
                <title>Parameter 5 - Mode C Interrogator Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param5']"/>
              </section>
              <section>
                <title>Parameter 6 - Mode S Code/Status</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.param6']"/>
              </section>
              <section>
                <title>Modifier</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.2.fop.modifier']"/>
              </section>
              <section>
                <title>Alternate Parameter 4</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.2.fop.altp4']"/>
              </section>
              <section>
                <title>Information Layers</title>
                <para>This section specifies the 8-bit Boolean array for the Information Layer Field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.infolayers']"/>
              </section>
            </section>
            <section>
              <title>Layer Header</title>
              <section>
                <title>Layer Specific Information</title>
                <para>This section specifies the 8-bit enumeration for the Layer Specific Information field in the Layer Header record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="enum[@cname='der.iff.layerspecific']"/>
              </section>
            </section>
            <section>
              <title>Secondary Operational Data</title>
              <para>This section specifies the 8-bit enumeration of the Operational Parameters 1 and 2 in the Secondary Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
              <section>
                <title>Operational Parameter 1</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.2.sop.param1']"/>
              </section>
              <section>
                <title>Operational Parameter 2</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.2.sop.param2']"/>
              </section>
            </section>
          </section>
          <!-- System Type 2 (Mark X/II/ATCRBS/MODE S Interrogator) -->
          <section>
            <title>System Type 3 (Soviet Transponder)</title>
            <section>
              <title>System ID</title>
              <section>
                <title>Change/Options</title>
                <para>This section specifies the 8-bit Boolean array for the Change/Options field in the System ID record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.changeoptions']"/>
              </section>
            </section>
            <section>
              <title>Fundamental Operational Data</title>
              <section>
                <title>System Status</title>
                <para>This section specifies the 8-bit Boolean array for the System Status field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.fop.status']"/>
              </section>
              <section>
                <title>Parameter 1</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param1']"/>
              </section>
              <section>
                <title>Parameter 2</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param2']"/>
              </section>
              <section>
                <title>Parameter 3</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param3']"/>
              </section>
              <section>
                <title>Parameter 4</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param4']"/>
              </section>
              <section>
                <title>Parameter 5</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param5']"/>
              </section>
              <section>
                <title>Parameter 6</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.param6']"/>
              </section>
              <section>
                <title>Modifier</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.3.fop.modifier']"/>
              </section>
              <section>
                <title>Alternate Parameter 4</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.3.fop.altp4']"/>
              </section>
              <section>
                <title>Information Layers</title>
                <para>This section specifies the 8-bit Boolean array for the Information Layer Field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.infolayers']"/>
              </section>
            </section>
            <section>
              <title>Layer Header</title>
              <section>
                <title>Layer Specific Information</title>
                <para>This section specifies the 8-bit enumeration for the Layer Specific Information field in the Layer Header record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="enum[@cname='der.iff.layerspecific']"/>
              </section>
            </section>
            <section>
              <title>Secondary Operational Data</title>
              <para>This section specifies the 8-bit enumeration of the Operational Parameters 1 and 2 in the Secondary Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
              <section>
                <title>Operational Parameter 1</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.3.sop.param1']"/>
              </section>
              <section>
                <title>Operational Parameter 2</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.3.sop.param2']"/>
              </section>
            </section>
          </section>
          <!-- System Type 3 (Soviet Transponder) -->
          <section>
            <title>System Type 4 (Soviet Interrogator)</title>
            <section>
              <title>System ID</title>
              <section>
                <title>Change/Options</title>
                <para>This section specifies the 8-bit Boolean array for the Change/Options field in the System ID record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.changeoptions']"/>
              </section>
            </section>
            <section>
              <title>Fundamental Operational Data</title>
              <section>
                <title>System Status</title>
                <para>This section specifies the 8-bit Boolean array for the System Status field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.fop.status']"/>
              </section>
              <section>
                <title>Parameter 1</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param1']"/>
              </section>
              <section>
                <title>Parameter 2</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param2']"/>
              </section>
              <section>
                <title>Parameter 3</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param3']"/>
              </section>
              <section>
                <title>Parameter 4</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param4']"/>
              </section>
              <section>
                <title>Parameter 5</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param5']"/>
              </section>
              <section>
                <title>Parameter 6</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.param6']"/>
              </section>
              <section>
                <title>Modifier</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.4.fop.modifier']"/>
              </section>
              <section>
                <title>Alternate Parameter 4</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.4.fop.altp4']"/>
              </section>
              <section>
                <title>Information Layers</title>
                <para>This section specifies the 8-bit Boolean array for the Information Layer Field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.infolayers']"/>
              </section>
            </section>
            <section>
              <title>Layer Header</title>
              <section>
                <title>Layer Specific Information</title>
                <para>This section specifies the 8-bit enumeration for the Layer Specific Information field in the Layer Header record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="enum[@cname='der.iff.layerspecific']"/>
              </section>
            </section>
            <section>
              <title>Secondary Operational Data</title>
              <para>This section specifies the 8-bit enumeration of the Operational Parameters 1 and 2 in the Secondary Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
              <section>
                <title>Operational Parameter 1</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.4.sop.param1']"/>
              </section>
              <section>
                <title>Operational Parameter 2</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.4.sop.param2']"/>
              </section>
            </section>
          </section>
          <!-- System Type 4 (Soviet Interrogator) -->
          <section>
            <title>System Type 5 (RRB Transponder)</title>
            <section>
              <title>System ID</title>
              <section>
                <title>Change/Options</title>
                <para>This section specifies the 8-bit Boolean array for the Change/Options field in the System ID record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.changeoptions']"/>
              </section>
            </section>
            <section>
              <title>Fundamental Operational Data</title>
              <section>
                <title>System Status</title>
                <para>This section specifies the 8-bit Boolean array for the System Status field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.fop.status']"/>
              </section>
              <section>
                <title>Parameter 1 - RRB Response</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param1']"/>
              </section>
              <section>
                <title>Parameter 2</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param2']"/>
              </section>
              <section>
                <title>Parameter 3</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param3']"/>
              </section>
              <section>
                <title>Parameter 4</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param4']"/>
              </section>
              <section>
                <title>Parameter 5</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param5']"/>
              </section>
              <section>
                <title>Parameter 6</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.param6']"/>
              </section>
              <section>
                <title>Modifier</title>
                <xsl:apply-templates select="bitmask[@cname='der.iff.type.5.fop.modifier']"/>
              </section>
              <section>
                <title>Alternate Parameter 4</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.5.fop.altp4']"/>
              </section>
              <section>
                <title>Information Layers</title>
                <para>This section specifies the 8-bit Boolean array for the Information Layer Field in the Fundamental Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="bitmask[@cname='der.iff.infolayers']"/>
              </section>
            </section>
            <section>
              <title>Layer Header</title>
              <section>
                <title>Layer Specific Information</title>
                <para>This section specifies the 8-bit enumeration for the Layer Specific Information field in the Layer Header record of the IFF/ATC/NAVAIDS PDU.</para>
                <xsl:apply-templates select="enum[@cname='der.iff.layerspecific']"/>
              </section>
            </section>
            <section>
              <title>Secondary Operational Data</title>
              <para>This section specifies the 8-bit enumeration of the Operational Parameters 1 and 2 in the Secondary Operational Data record of the IFF/ATC/NAVAIDS PDU.</para>
              <section>
                <title>Operational Parameter 1</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.5.sop.param1']"/>
              </section>
              <section>
                <title>Operational Parameter 2</title>
                <xsl:apply-templates select="enum[@cname='der.iff.type.5.sop.param2']"/>
              </section>
            </section>
          </section>
          <!-- System Type 5 (RRB Transponder) -->
          <section>
            <title>Specific Issuance/Receipt Rules</title>
            <section>
              <title>Issuance Rules: System Type 1 (Mark X/XII/ATCRBS/Mode S Transponder)</title>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>System ID Record: Alternate Mode 4. Any application that transmits Mode 4 shall always set the Alternate Mode 4 field to the appropriate value in the Fundamental Data Record and shall set the Alternate Mode 4 field in the System ID Record to 1. The application may also send a "pseudo-crypto" value in the Mode 4 parameter if coordinated with other sites prior to the exercise.</para>
                </listitem>
                <listitem>
                  <para>System ID Record: Alternate Mode C. Any application that transmits Mode C shall always set the Alternate Mode C field to the appropriate value in the Fundamental Data Record and shall set the Alternate Mode C field in the System ID Record to 1. The application may also send the actual Mode C encoded altimeter in the Mode C parameter.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: System Status: System On/Off. The System On/Off Status shall be set to 1 if any of the Modes (Parameters 1-6) are set to On. Otherwise the status shall be set to Off. If the Entity State PDU Appearance Damage Status value = 3 (Destroyed) for the associated entity and the entity is not canceled at the time it is destroyed, the System Status/System On/Off field and all Parameter 1-6 Status fields (Bit 13) for Capable modes shall be set to 1 (Off). This change in status shall be automatically set within 10 seconds of the simulation determining that the entity could no longer transmit a reply to an interrogation. For the destroyed case, it is not required that the Operational Status field be set to System Failed or the Parameter 1-6 Damage or Malfunction Status fields be set to 1. However, these fields can be set if desired. At least three periodic updates shall be sent for the IFF/ATC/NAVAIDS PDU following the change to Off status due to the entity being destroyed. After the three periodic updates are sent, a simulation may either continue to send periodic updates or cease sending them.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: System Status: Capable Parameters 1-6 Any application that transmits an IFF/ATC/NAVAIDS PDU with System Type =1 shall set the Capable Parameters 1-6 to report which modes are capable and not capable of being transponded by the emitting entity. </para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Operational Status. This status shall be set to 1 (System failed) if no Parameter 1-6 or Modifier parameter (Emergency, Squawk Flash, STI) can be transponded regardless of the System Status/System On/Off field setting. Otherwise, the status shall be set to 0.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Parameter 1-6 Codes. Codes shall reflect the present code settings for an entity at the time an IFF/ATC/NAVAIDS PDU is transmitted and are independent of the present Mode Status settings. Code 0 shall not be used to indicate off for a mode. However, code zero may be transmitted for a mode if that is the setting for the transponder. Mode 1, 2, and 3 codes represent octal values that are set into the appropriate code elements. Each associated parameter is an unsigned integer that includes both the code and status values. When decoded, the code elements are converted back to the appropriate octal values. If actual Mode C encoded altitude is being transmitted, an IFF/ATC/NAVAIDS PDU shall be transmitted once for each 100-foot change in entity altitude.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Modifier Parameters. When a Modifier parameter is set to on to report truth data not related to a specific interrogation reported in an IFF/ATC/NAVIADS PDU, and the condition is transitory, such as the Squawk Flash, the issuing application shall ensure that an IFF/ATC/NAVAIDS PDU is transmitted with the parameter set to off when the transitory condition has ended. For Squawk Flash, the On state shall be for 30 seconds when not responding to a specific interrogation.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Alternate Mode 4. The Alternate Mode 4 values shall be set to 1, 2 or 3 if the entity is capable of transmitting Mode 4 as reflected in the Capable parameter regardless of whether Actual Mode 4 Pseudo-Crypto is also included in the Parameter 4.</para>
                </listitem>
                <listitem>
                  <para>System ID Record: Change Indicator. The Change Indicator shall be set to 1 for all initial reports and whenever a change is a being reported even if the change coincides with a periodic update report. For all other cases, the Change indicator shall be set to 0.</para>
                </listitem>
              </orderedlist>
            </section>
            <section>
              <title>Receipt Rules: System Type 1 (Mark X/XII/ATCRBS/Mode S Transponder)</title>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>System ID Record: Alternate Mode 4. Any application that can receive Mode 4 data shall be able, as a minimum, to process the Alternate Mode 4 field to derive the present Mode 4 value. If an application can also process any "pseudo-crypto" value contained in the Mode 4 parameter, it may either process the Mode 4 value or the Alternate Mode 4 value. If an application can detect a conflict in the Valid/ Invalid setting between the values in the two fields, the Alternate Mode 4 field value shall be the value that is accepted.</para>
                </listitem>
                <listitem>
                  <para>System ID Record: Alternate Mode C. Any application that can receive Mode C shall be able, as a minimum, to process the Alternate Mode C field in the Fundamental Data Record. If an application can also process an encoded altimeter value contained in the Mode C parameter, it may either process the Mode C value or the Alternate Mode C value (i.e., use the entity's altitude value derived from the Entity State PDU.) If an application can detect a conflict in the values contained in the two fields, the Mode C field value shall be the value that is accepted and not the entity altitude from the Entity State PDU.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: System Status: Capable Parameters 1-5. If the Not Capable field is set for a specific parameter (1-5), the receiving site/application need not process that Parameter's values in the Fundamental Operational Data Record. </para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Parameter 1-3 Codes. Mode 1, 2 and 3 code values of zero shall be valid and shall not be interpreted as a Mode Off status. </para>
                </listitem>
                <listitem>
                  <para>If a receiving site/application has the capability to set transponder data for received entities for distribution to other applications not directly connected on the DIS network, receipt of transponder data on the received entity shall always override locally entered data for the received entity.</para>
                </listitem>
                <listitem>
                  <para>A receiving site/application may perform validity checks on parameter data to ensure they are within the limits specified in the DIS enumeration document. Only invalid data for the specific parameter processed shall be ignored. Any previously accepted data for that parameter may either be retained or cleared.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Mode Status. The Mode Status - Damage and Malfunction field values shall be processed upon receipt as agreed to by participants prior to a DIS exercise.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Parameter 6.  Mode S data elements shall be agreed to by participants prior to a DIS Exercise.</para>
                </listitem>
              </orderedlist>
            </section>
            <section>
              <title>Issuance Rules: System Type 5 (RRB Transponder)</title>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>Fundamental Operational Data Record: System Status: Capable. All RRB Transponders shall set the Parameter 1 system status bit to 0 (Capable) and the Parameters 2-6 system status bits to 1 (Not Capable).</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: System Status: System On/Off. The System On/Off Status shall be set to 1 (On) if the RRB Response Status (bit 13 in Parameter 1) is set to 1 (On), the RRB Response Damage (bit 14 in Parameter 1) is set to 0 (No Damage) and the RRB Response Malfunction (bit 15 in Parameter 1) is set to 0 (no malfunction). Otherwise the status shall be set to 0 (Off). If the Entity State PDU Appearance Damage Status value = 3 (Destroyed) for the associated entity and the entity is not canceled at the time it is destroyed, the System Status/System On/Off field and the Parameter 1 Status fields (Bit 13) shall be set to 0 (Off). This change in status shall be automatically set within 10 seconds of the simulation determining that the entity could no longer transmit a reply to an interrogation. For the destroyed case, it is not required that the Operational Status field be set to System Failed or the Parameter 1 Damage or Malfunction Status fields be set to 1. However, these fields can be set if desired. At least three periodic updates shall be sent for the IFF/ATC/NAVAIDS PDU following the change to Off status due to the entity being destroyed. After the three periodic updates are sent, a simulation may either continue to send periodic updates or cease sending them.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Operational Status. This status shall be set to 1 (System failed) if the RRB Response Damage bit (bit 14 in Parameter 1) is set to 1 (Damaged) or the RRB Reponse Malfunction bit (bit 15 in Parameter 1) is set to 1 (Malfunction). Otherwise, the status shall be set to 0.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Parameter 1 Code. Codes shall reflect the present code settings for an entity at the time an IFF/ATC/NAVAIDS PDU is transmitted and are independent of the present Mode Status settings. Code 0 shall not be used to indicate off for a mode. However, code zero may be transmitted for a mode if that is the setting for the transponder.</para>
                </listitem>
                <listitem>
                  <para>System ID Record: Change Indicator.  The Change Indicator shall be set to 1 for all initial reports and whenever a change is a being reported even if the change coincides with a periodic update report.  For all other cases, the Change indicator shall be set to 0.</para>
                </listitem>
              </orderedlist>
            </section>
            <section>
              <title>Receipt Rules: System Type 5 (RRB Transponder)</title>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>Fundamental Operational Data Record: Parameter 1 Codes. Code values of zero shall be valid and shall not be interpreted as a Mode Off status.</para>
                </listitem>
                <listitem>
                  <para>If a receiving site/application has the capability to set transponder data for received entities for distribution to other applications not directly connected on the DIS network, receipt of transponder data on the received entity shall always override locally entered data for the received entity.</para>
                </listitem>
                <listitem>
                  <para>A receiving site/application may perform validity checks on parameter data to ensure they are within the limits specified in the DIS enumeration document. Only invalid data for the specific parameter processed shall be ignored. Any previously accepted data for that parameter may either be retained or cleared.</para>
                </listitem>
                <listitem>
                  <para>Fundamental Operational Data Record: Mode Status. The Mode Status - Damage and Malfunction field values shall be processed upon receipt as agreed to by participants prior to a DIS exercise.</para>
                </listitem>
              </orderedlist>
            </section>
          </section>
        </section>
        <section>
          <title>Underwater Acoustic PDU</title>
          <section>
            <title>State/Change Update indicator</title>
            <para>This section specifies the 8-bit enumeration for the State/Change Update Indicator in the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.statechangeupdate']"/>
          </section>
          <section>
            <title>Acoustic System Name</title>
            <para>This section specifies the 16-bit enumeration for the Acoustic System Name field of the Acoustic Emitter System record of the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.systemname']"/>
          </section>
          <section>
            <title>Function</title>
            <para>This section specifies the 8-bit enumeration for the Function field of the Acoustic Emitter System record of the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.function']"/>
          </section>
          <section>
            <title>Active Emission Parameter Index</title>
            <para>This section specifies the 16-bit enumeration for the Active Emission Parameter Index field in the Underwater Acoustics Fundamental Parameter Data record of the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.activeparameterindex']"/>
          </section>
          <section>
            <title>Scan Pattern</title>
            <para>This section specifies the 16-bit enumeration for the Scan Pattern field in the Underwater Acoustics Fundamental Parameter Data record of the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.scanpattern']"/>
          </section>
          <section>
            <title>Passive Parameter Index</title>
            <para>This section specifies the 16-bit enumeration for the Passive Parameter Index field in the Underwater Acoustics PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.passiveparameterindex']"/>
          </section>
          <section>
            <title>Propulsion Plant Configuration</title>
            <para>This section specifies the 7-bit enumerations for the Propulsion Plant Configuration field of the Underwater Acoustics PDU. Bit 7 of the Propulsion Plant Configuration field is a Hull Mounted Masker status bit.</para>
            <xsl:apply-templates select="bitmask[@cname='der.ua.ppcfg']"/>
          </section>
          <section>
            <title>Additional Passive Activity Parameter Index</title>
            <para>This section specifies the 16-bit enumerations for the Additional Passive Activity Parameter Index field in the Underwater Acoustic PDU.</para>
            <xsl:apply-templates select="enum[@cname='der.ua.apaparameterindex']"/>
          </section>
        </section>
        <section>
          <title>SEES PDU</title>
          <section>
            <title>Engine Power Setting Values</title>
            <para>This section specifies the 32-bit floating point enumerations for the Engine Power Settings in the SEES Propulsion System Data record of the SEES PDU.</para>
            <section>
              <title>Aircraft</title>
              <xsl:apply-templates select="enum[@cname='der.sees.power.aircraft']"/>
            </section>
            <section>
              <title>Helicopters</title>
              <xsl:apply-templates select="enum[@cname='der.sees.power.helicopters']"/>
            </section>
            <section>
              <title>Tanks</title>
              <xsl:apply-templates select="enum[@cname='der.sees.power.tanks']"/>
            </section>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Radio Communications family</title>
        <section>
          <title>Transmitter PDU</title>
          <section>
            <title>Modulation Type record</title>
            <section>
              <title>Spread Spectrum</title>
              <para>This section specifies the 16-bit Boolean array for the Spread-Spectrum field in the Modulation-Type record of the Transmitter PDU. All bits set to zero indicates that spread-spectrum modulation is not in use. Individual bits set to one indicate the use of spread spectrum as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='radio.tx.mod.spreadspectrum']"/>
              <para>More than one bit set to one indicates that distinct methods are simultaneously in use.</para>
            </section>
            <section>
              <title>Major Modulation</title>
              <para>This section specifies the 16-bit enumeration for the Major-Modulation field in the Modulation-Type record of the Transmitter PDU.</para>
              <xsl:apply-templates select="enum[@cname='radio.tx.mod.major']"/>
            </section>
            <section>
              <title>Detail</title>
              <para>This section defines the 16-bit enumerations for the Detail field in the Transmitter PDU.</para>
              <section>
                <title>Detailed modulation for amplitude modulation</title>
                <para>The 16-bit Detailed modulation types for Amplitude Modulation are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.1.detail']"/>
              </section>
              <section>
                <title>Detailed modulation for amplitude and angle modulation</title>
                <para>The 16-bit Detailed modulation types for Amplitude and Angle Modulation are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.2.detail']"/>
              </section>
              <section>
                <title>Detailed modulation for angle modulation</title>
                <para>The 16-bit Detailed modulation types for Angle Modulation are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.3.detail']"/>
              </section>
              <section>
                <title>Detailed modulation for combination modulation</title>
                <para>The 16-bit Detailed modulation types for Combination Modulation are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.4.detail']"/>
              </section>
              <section>
                <title>Detailed modulation for pulse modulation</title>
                <para>The 16-bit Detailed modulation types for Pulse Modulation are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.5.detail']"/>
              </section>
              <section>
                <title>Detailed modulation for unmodulated modulation</title>
                <para>The 16-bit Detailed modulation types for an unmodulated carrier are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.6.detail']"/>
              </section>
              <section>
                <title>Detailed Modulation for Carrier Phase Shift</title>
                <para>The 16-bit Detailed modulation types for carrier phase shift modulation (CSPM) are defined as follows:</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.mod.major.7.detail']"/>
              </section>
            </section>
            <section>
              <title>System</title>
              <para>This section specifies the 16-bit enumeration for the System field in the Modulation-Type record of the Transmitter PDU.</para>
              <xsl:apply-templates select="enum[@cname='radio.tx.mod.system']"/>
            </section>
          </section>
          <section>
            <title>Transmit State</title>
            <para>This section specifies the 8-bit enumeration for the Transmit-State field in the Transmitter PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.state']"/>
          </section>
          <section>
            <title>Input Source</title>
            <para>This section specifies the 8-bit enumeration for the Input-Source field in the Transmitter PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.inputsource']"/>
          </section>
          <section>
            <title>Crypto System</title>
            <para>This section specifies the 16-bit enumeration for the Crypto-System field in the Transmitter PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.cryptosystem']"/>
          </section>
          <section>
            <title>Antenna Pattern Type</title>
            <para>This section specifies the 16-bit enumeration for the Antenna Pattern Type field in the Transmitter PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.antennapatterntype']"/>
          </section>
          <section>
            <title>Reference System</title>
            <para>This section specifies the 8-bit enumeration for the Reference System field in the Beam Antenna Pattern record and the Spherical Harmonic Pattern Record in the Transmitter PDU. The enumeration for the Reference System are limited to the two listed below.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.referencesystem']"/>
          </section>
          <section>
            <title>Modulation Parameters, used in the Transmitter PDU</title>
            <para>This section specifies the Modulation Parameters in the Transmitter PDU.</para>
            <section>
              <title>CCTT SINCGARS Modulation Parameters</title>
              <para>Detailed information about the CCTT SINCGARS (Radio System Type 6) shall be communicated by using the Modulation Parameters in the Transmitter PDU. The Modulation Parameters shall contain the following fields:</para>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>FH Data - These fields are only used when the SINCGARS radio is in FH mode. They determine the hopping pattern of the SINCGARS radio. If any one of these fields is different, except FH Synchronization Time Offset, the hopping pattern is different. Radios on different hopping patterns shall not communicate.</para>
                  <orderedlist numeration="loweralpha">
                    <listitem>
                      <para>FH Net ID - This field shall identify the frequency hopping network.</para>
                    </listitem>
                    <listitem>
                      <para>Hop Set ID - This field shall identify the set of frequencies used when creating a hopping pattern. The frequencies in the hop set are transmitted by a method outside the scope of this standard.</para>
                    </listitem>
                    <listitem>
                      <para>Lockout Set ID - This field shall identify the set of frequencies that are excluded from the hopping pattern. The frequencies in the lockout set are transmitted by a method outside the scope of this standard.</para>
                    </listitem>
                    <listitem>
                      <para>Transmission Security Key - This field shall identify the transmission security key that is used when generating the hopping pattern. (Not currently implemented, field added for future use).</para>
                    </listitem>
                    <listitem>
                      <para>FH Synchronization Time Offset - This field shall identify the offset to exercise time in seconds for the clock in the SINCGARS radio. SINCGARS radio clock must be synchronized for the radios to communicate. (Not currently implemented, field added for future use).</para>
                    </listitem>
                  </orderedlist>
                </listitem>
                <listitem>
                  <para>Start of Message - This field shall specify whether the radio is starting or continuing a transmission. A SINCGARS radio shall not receive any part of an FH transmission if the Start of Message is missed. Start of message may be missed if the radio was transmitting, receiving a different radio or otherwise not ready to start receiving a transmission.</para>
                </listitem>
                <listitem>
                  <para>Clear Channel - This field shall specify that the transmission is not subject to propagation loss, interference, comsec or any other form of signal degradation. Clear channels are used for interoperability with older systems and for control purposes.</para>
                </listitem>
              </orderedlist>
              <xsl:apply-templates select="record[@cname='radio.tx.modparam.cctt']"/>
              <section>
                <title>Start of Message</title>
                <para>This section specifies the 8-bit enumeration for the Start of Message field in the CCTT SINCGARS Modulation Parameters.</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.param.cctt.start']"/>
              </section>
              <section>
                <title>Clear Channel</title>
                <para>This section specifies the 8-bit enumeration for the Clear Channel field in the CCTT SINCGARS Modulation Parameters.</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.param.cctt.clear']"/>
              </section>
            </section>
            <section>
              <title>JTIDS/MIDS Modulation Parameters</title>
              <para>Detailed information about the JTIDS/MIDS (Radio System Type 8) shall be communicated by using the Modulation Parameters in the Transmitter PDU. The Modulation Parameters shall contain the following fields:</para>
              <orderedlist numeration="arabic">
                <listitem>
                  <para>Time Slot Allocation Mode - Defines the fidelity level to be used (range 0 to 4)</para>
                </listitem>
                <listitem>
                  <para>Transmitting Terminal Primary Mode - Defines the primary mode of operation of the transmitting terminal. See section 9.1.7.2.1 for details</para>
                </listitem>
                <listitem>
                  <para>Transmitting Terminal Secondary Mode - Defines the secondary mode of operation of the transmitting terminal. See section 9.1.7.2.2 for details</para>
                </listitem>
                <listitem>
                  <para>Synchronization State - Defines the current synchronization state of the transmitting terminal</para>
                </listitem>
                <listitem>
                  <para>Network Synchronization ID - For TSA modes 0-2, it <emphasis>shall</emphasis> be set to default. For TSA modes 3-4, it <emphasis>shall</emphasis> be a 32-bit random integer generated by using the DIS timestamp as the seed. Only an NTR can generate a Network Synchronization ID; all other participants <emphasis>shall</emphasis> use the ID obtained from the NTR to which they are synchronized</para>
                </listitem>
              </orderedlist>
              <xsl:apply-templates select="record[@cname='radio.tx.modparam.jtids']"/>
              <section>
                <title>Transmitting Terminal Primary Mode</title>
                <para>This section specifies the 8-bit enumeration for the Transmitting Terminal Primary Mode field in the JTIDS/MIDS Modulation Parameters.</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.param.jtids.mode1']"/>
              </section>
              <section>
                <title>Transmitting Terminal Secondary Mode</title>
                <para>This section specifies the 8-bit enumeration for the Transmitting Terminal Secondary Mode field in the JTIDS/MIDS Modulation Parameters.</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.param.jtids.mode2']"/>
              </section>
              <section>
                <title>Synchronization State</title>
                <para>This section specifies the 8-bit enumeration for the Synchronization State field in the JTIDS/MIDS Modulation Parameters.</para>
                <xsl:apply-templates select="enum[@cname='radio.tx.param.jtids.sync']"/>
              </section>
            </section>
          </section>
          <section>
            <title>Radio signal encoding</title>
            <xsl:apply-templates select="bitmask[@cname='radio.tx.encoding']"/>
          </section>
          <section>
            <title>User Protocol Identification Number</title>
            <para>The first sub-field of the Signal PDU Data Field contains a User Protocol Identification Number when the Encoding Class field indicates Application Specific Data. The enumerations for the User Protocol Identification are as follows:</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.protocolid']"/>
          </section>
          <section>
            <title>TDL Type</title>
            <para>This section specifies the 16-bit enumeration for the TDL Type field in the Signal PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.tx.tdltype']"/>
          </section>
        </section>
        <section>
          <title>Receiver PDU</title>
          <section>
            <title>Receiver State</title>
            <para>This section specifies the 16-bit enumeration for the Receiver-State field in the Receiver PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.rx.state']"/>
          </section>
        </section>
        <section>
          <title>Intercom Control PDU</title>
          <section>
            <title>Control Type</title>
            <para>This section specifies the 8-bit enumeration for the Control Type field in the Intercom Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.ic.controltype']"/>
          </section>
          <section>
            <title>Communications Type</title>
            <para>This section specifies the 7-bit enumeration for the Communications Type sub-field of the Communications Channel Type field in the Intercom Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.ic.commtype']"/>
          </section>
          <section>
            <title>Command</title>
            <para>This section specifies the 8-bit enumeration for the Command field in the Intercom Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.ic.command']"/>
          </section>
          <section>
            <title>Transmit Line State</title>
            <para>This section specifies the 8-bit enumeration for the Transmit Line State field in the Intercom Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.ic.transmitstate']"/>
          </section>
          <section>
            <title>Destination Line State Command</title>
            <para>This section specifies the 8-bit enumeration for the Destination Line State field in the optional Intercom Communications Parameters records (see <xref linkend="radio.ic.paramrecords"/>) in the Intercom Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='radio.ic.deststate']"/>
          </section>
          <section>
            <title>Intercom Communications Parameters records</title>
            <section>
              <title>Record type</title>
              <para>This section specifies the 16-bit enumerations for the Record Type field in the Intercom Communications Parameters record of the Intercom Control PDU.</para>
              <xsl:apply-templates select="enum[@cname='radio.ic.param.type']"/>
            </section>
            <section id="radio.ic.paramrecords">
              <title>Intercom Communications Parameters records</title>
              <para>This section contains the specification of specific Intercom Communications Parameters records for use in the Intercom Control PDU.</para>
              <section>
                <title>Entity Destination record</title>
                <para>This record shall be used to send an Intercom Control PDU directly to a specific entity.</para>
                <xsl:apply-templates select="record[@cname='radio.ic.paramrecords.dest']"/>
              </section>
              <section>
                <title>Group Destination record</title>
                <para>This record shall be used to send an Intercom Control PDU to an arbitrary group.</para>
                <xsl:apply-templates select="record[@cname='radio.ic.paramrecords.groupdest']"/>
              </section>
              <section>
                <title>Group Assignment record</title>
                <para>This record shall be used to assign a group bit field to a specific entity. A bit set to one shall indicate membership in the corresponding group. Multiple bits can be set to indicate membership in multiple groups.</para>
                <xsl:apply-templates select="record[@cname='radio.ic.paramrecords.gassign']"/>
              </section>
            </section>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Entity Information/Interaction family</title>
        <section>
          <title>Collision PDU</title>
          <section>
            <title>Collision Type</title>
            <para>This field specifies the 8-bit record of enumeration for the Collision Type-field in the Collision PDU</para>
            <xsl:apply-templates select="enum[@cname='entity.collision.type']"/>
          </section>
        </section>
        <section>
          <title>Minefield Data PDU</title>
          <section>
            <title>Appearance Bit Map</title>
            <para>The bits of the Minefield State PDU Appearance bit map are defined as follows:</para>
            <xsl:apply-templates select="bitmask[@cname='entity.mine.appear']"/>
          </section>
          <section>
            <title>Data Filter</title>
            <para>This section specifies the 32-bit enumeration for the Data Filter field of the Minefield Query PDU and the Minefield Data PDU</para>
            <xsl:apply-templates select="bitmask[@cname='entity.mine.datafilter']"/>
          </section>
          <section>
            <title>Fusing</title>
            <para>This section specifies the 16-bit enumeration for the Fusing field of the Minefield Data PDU</para>
            <xsl:apply-templates select="bitmask[@cname='entity.mine.fusing']"/>
          </section>
          <section>
            <title>Sensor Types</title>
            <para>This section specifies the 16-bit enumeration for the Sensor Types field of the Minefield Query PDU and the Minefield Data PDU. Bits 0-3 identify the category of the sensor type and bits 4-15 identify the subcategory within the specified category.</para>
            <xsl:apply-templates select="enum[@cname='entity.mine.sensortype']"/>
            <section>
              <title>Optical subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.1.subcat']"/>
            </section>
            <section>
              <title>FLIR subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.2.subcat']"/>
            </section>
            <section>
              <title>RADAR subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.3.subcat']"/>
            </section>
            <section>
              <title>Magnetic subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.4.subcat']"/>
            </section>
            <section>
              <title>Laser subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.5.subcat']"/>
            </section>
            <section>
              <title>SONAR subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.6.subcat']"/>
            </section>
            <section>
              <title>Physical subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.7.subcat']"/>
            </section>
            <section>
              <title>Multispectral subcategory</title>
              <xsl:apply-templates select="enum[@cname='entity.mine.sensortype.8.subcat']"/>
            </section>
          </section>
          <section>
            <title>Paint Scheme</title>
            <para>This section specifies the 8-bit enumeration for the Paint Scheme field of the Minefield Data PDU.</para>
            <xsl:apply-templates select="bitmask[@cname='entity.mine.paintscheme']"/>
          </section>
          <section>
            <title>Protocol Mode</title>
            <para>This section specifies the 2-bit enumeration for the Protocol Mode field of the Minefield State PDU.</para>
            <xsl:apply-templates select="bitmask[@cname='entity.mine.protocolmode']"/>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Entity Management family</title>
        <section>
          <title>Aggregate State PDU</title>
          <section>
            <title>Aggregate State</title>
            <para>This section specifies the 8-bit enumeration for the Aggregate State-field in the Aggregate State PDU.</para>
            <xsl:apply-templates select="enum[@cname='eman.aggregate.state']"/>
          </section>
          <section>
            <title>Formation</title>
            <para>This section specifies the 32-bit enumeration for the Formation-field in the Aggregate State PDU</para>
            <xsl:apply-templates select="enum[@cname='eman.aggregate.formation']"/>
          </section>
          <section>
            <title>Aggregate Type record</title>
            <para>This section specifies the 64-bit enumerations for the Aggregate Type record of the Aggregate State PDU. Aggregate types are arranged in hierarchical order.</para>
            <section>
              <title>Aggregate Kind</title>
              <para>This section specifies the 8-bit enumerations for the Aggregate Kind field for the Aggregate Type record.</para>
              <xsl:apply-templates select="enum[@cname='eman.aggregate.type.kind']"/>
            </section>
            <section>
              <title>Domain and Country</title>
              <para>The Domain-field and the Country-field enumeration are the same as used for the Entity Type record (see <xref linkend="es.type"/>).</para>
            </section>
            <section>
              <title>Aggregate Types</title>
              <para>The Category field enumerations for Kind-field = Military Hierarchy specify the Echelon Level of the aggregate, and are enumerated as follows:</para>
              <xsl:apply-templates select="cet[@cname='eman.aggregate.type.types']"/>
              <section>
                <title>Subcategory</title>
                <para>The Subcategory field enumerations for Kind field = Military Hierarchy specify the Echelon Type of the aggregate, and are enumerated as follows. Not all of the following echelon types are applicable to each of the above enumerated Categories.</para>
                <xsl:apply-templates select="enum[@cname='eman.aggregate.type.subcategory']"/>
              </section>
              <section>
                <title>Specific</title>
                <para>The Specific field enumerations for Kind field = Military Hierarchy specify whether the aggregate unit contains a headquarters, and is enumerated as follows</para>
                <xsl:apply-templates select="enum[@cname='eman.aggregate.type.specific']"/>
              </section>
            </section>
          </section>
        </section>
        <section>
          <title>IsPartOf PDU</title>
          <section>
            <title>Nature</title>
            <para>This section specifies the 16-bit enumeration for the Nature-field of the Relationship record.</para>
            <xsl:apply-templates select="enum[@cname='eman.ispartof.nature']"/>
          </section>
          <section id="eman.ispartof.position">
            <title>Position</title>
            <para>This section specifies the 16-bit enumeration for the Position-field of the Relationship record.</para>
            <xsl:apply-templates select="enum[@cname='eman.ispartof.position']"/>
          </section>
          <section>
            <title>Station Name</title>
            <para>This section specifies the 16-bit enumeration for the Station Name-field of the Named Station Identification record.</para>
            <xsl:apply-templates select="enum[@cname='eman.ispartof.stationname']"/>
          </section>
        </section>
        <section>
          <title>IsGroupOf PDU</title>
          <section>
            <title>Grouped Entity Category</title>
            <para>This section specifies the 8-bit enumeration for the Grouped Entity Category field of the IsGroupOf PDU.</para>
            <xsl:apply-templates select="enum[@cname='eman.isgroupof.category']"/>
          </section>
          <section>
            <title>Rest Status</title>
            <para>This section specifies the 8-bit enumeration for the Rest Status field in the Grouped Entity Description record for the Enhanced Ground Combat Soldier.</para>
            <xsl:apply-templates select="enum[@cname='eman.isgroupof.reststatus']"/>
          </section>
          <section>
            <title>Grouped Entity Description records</title>
            <para>The specification of the entity state information about various categories of grouped entities within an IsGroupOf PDU shall be represented by a Grouped Entity Description record.</para>
            <section>
              <title>Grouped Entity Description record 1 - Basic Ground Combat Vehicle</title>
              <para>The specification of entity state information about an individual entity within a group of ground combat vehicles shall be represented by a Grouped Entity Description record 1 - Basic Ground Combat Vehicle.  The Grouped Entity Description record 1 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>Entity Identifier. Each entity within a group shall be assigned an entity identifier unique within that group.  The Site Identifier and Application Identifiers shall be the same as those designated in the Group Entity ID field, and shall not be transmitted.  The Entity Identifier shall be represented by a 16-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Location. Location of a grouped entity shall be specified by a set of three offsets: x-offset, y-offset, and z-offset.  These offsets shall be determined by the difference, in meters, of the grouped entity from the Group Reference Point.  Each offset shall be represented by a 16-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>ntity Appearance. Appearance of a grouped entity shall be identical to that specified by an Entity State PDU Appearance record.  This record shall be defined as a 32-bit record of enumerations (see 5.2.12 in IEEE Std 1278.1-1995).  Values for the fields contained in this record are defined in Section 4 of this document.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Orientation. Orientation of a grouped entity shall be specified by three Euler angles, psi, theta and phi, in 25 milliradian increments.  Each  angle shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Speed. Speed of a grouped entity shall be the signed magnitude value of the entity's absolute velocity vector.  A negative value shall indicate that the entity is moving backwards.  Entity Speed shall be specified in meters per second and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Turret Azimuth. Turret Azimuth shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Gun Elevation. Gun Elevation shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Turret Slew Rate. Turret Slew Rate shall be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Gun Elevation Rate. Gun Elevation Rate shall be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 1 - Basic Ground Combat Vehicle shall be as shown in <xref linkend="eman.isgroupof.record1"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record1']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 2 - Enhanced Ground Combat Vehicle</title>
              <para>The specification of entity state and logistics information about an individual entity within a group of ground combat vehicles shall be represented by a Grouped Entity Description record 2 - Enhanced Ground Combat Vehicle.  The Grouped Entity Description record 2 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Grouped Entity Description record 1 - Basic Ground Combat Vehicle.  See 11.3.3.1.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Fuel Status. Fuel Status of a grouped entity shall be the amount of fuel remaining.  Fuel Status shall be specified in 10 liter increments, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Ground Maintenance Status. Ground Maintenance Status of a grouped entity shall be the distance traveled since the last failure.  Ground Maintenance Status shall be specified in tens of kilometers, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Primary Ammunition. Primary Ammunition of a grouped entity shall be the amount of primary ammunition remaining.  Primary Ammunition shall be specified in natural ammunition units for the primary weapon system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Secondary Ammunition. Secondary Ammunition of a grouped entity shall be the amount of secondary ammunition remaining.  Secondary Ammunition shall be specified in natural ammunition units for the secondary weapon system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
              </orderedlist>
              <para>The format of the Grouped Entity Description record 2 - Enhanced Ground Combat Vehicle shall be as shown in <xref linkend="eman.isgroupof.record2"/>.</para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record2']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 3 - Basic Ground Combat Soldier</title>
              <para>
                The specification of entity state information about an individual entity within a group of ground combat soldiers shall be represented by a Grouped Entity Description record 3 - Basic Ground Combat Soldier.  The Grouped Entity Description record 3 shall contain the following fields:
              </para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>Entity Identifier. Each entity within a group shall be assigned an entity identifier unique within that group.  The Site Identifier and Application Identifiers shall be the same as those designated in the Group Entity ID field, and shall not be transmitted.  The Entity Identifier shall be represented by a 16-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Location. Location of a grouped entity shall be specified by a set of three offsets: x-offset, y-offset, and z-offset.  These offsets shall be determined by the difference, in meters, of the grouped entity from the Group Reference Point.  Each offset shall be represented by a 16-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Entity Appearance. Appearance of a grouped entity shall be identical to that specified by an Entity State PDU Appearance record.  This record shall be defined as a 32-bit record of enumerations (see 5.2.12 in IEEE Std 1278.1-1995).  Values for the fields contained in this record are defined in Section 4 of this document.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Orientation. Orientation of a grouped entity shall be specified by three Euler angles, psi, theta and phi, in 25 milliradian increments.  Each angle shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Speed. Speed of a grouped entity shall be the signed magnitude value of the entity's absolute velocity vector.  A negative value shall indicate that the entity is moving backwards.  Entity Speed shall be specified in meters per second and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Head Azimuth. Head Azimuth shall be specified in 25 milliradian increments, and shall represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Head Elevation. Head Elevation shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Head Scan Rate. Head Scan Rate shall be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Head Elevation Rate. Head Elevation Rate shall be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 3 - Basic Ground Combat Soldier shall be as shown in <xref linkend="eman.isgroupof.record3"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record3']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 4 - Enhanced Ground Combat Soldiers</title>
              <para>The specification of entity state and logistics information about an individual entity within a group of ground combat soldiers shall be represented by a Grouped Entity Description record 4 - Enhanced Ground Combat Soldier.  The Grouped Entity Description record 4 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Grouped Entity Description record 3 - Basic Ground Combat Soldier. See 11.3.3.3.
                  </para>
                </listitem>
                <listitem>
                  <para>Water Status. Water Status of a grouped entity shall be the amount of water on hand.  Water Status shall be specified in one ounce increments, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Rest Status. Rest Status of a grouped entity shall be represented by an 8-bit enumeration (see Section 11.3.2).
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Primary Ammunition. Primary Ammunition of a grouped entity shall be the amount of primary ammunition remaining.  Primary Ammunition shall be specified in natural ammunition units for the primary weapon system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Secondary Ammunition. Secondary Ammunition of a grouped entity shall be the amount of secondary ammunition remaining.  Secondary Ammunition shall be specified in natural ammunition units for the secondary weapon system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 4 - Enhanced Ground Combat Soldier shall be as shown in <xref linkend="eman.isgroupof.record4"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record4']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 5 - Basic Rotor Wing Aircraft</title>
              <para>The specification of entity state information about an individual entity within a group of rotor wing aircraft shall be represented by a Grouped Entity Description record 5 - Basic Rotor Wing Aircraft.  The Grouped Entity Description record 5 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Entity Identifier. Each entity within a group shall be assigned an entity identifier unique within that group.  The Site Identifier and Application Identifiers shall be the same as those designated in the Group Entity ID field, and shall not be transmitted.  The Entity Identifier shall be represented by an unsigned 16-bit integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Entity Location. Location of a grouped entity shall be specified by a set of three offsets: x-offset, y-offset, and z-offset.  These offsets shall be determined by the difference, in meters, of the grouped entity from the Group Reference Point.  Each offset shall be represented by a 16-bit signed integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Appearance. Appearance of a grouped entity shall be identical to that specified by an Entity State PDU Appearance record. This record shall be defined as a 32-bit record of enumerations (see 5.2.12 in IEEE Std 1278.1-1995).  Values for the fields contained in this record are defined in Section 4 of this document.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Orientation. Orientation of a grouped entity shall be specified by three Euler angles, psi, theta and phi, in 25 milliradian increments.  Each angle shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Fuel Status. Fuel Status of a grouped entity shall be the amount of primary fuel remaining.  Fuel Status shall be specified in natural units of the specific system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Movement Direction. Movement Direction shall be specified as a horizontal and a vertical deviation from the Entity Orientation.  Each deviation shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Movement Speed. Speed of a grouped entity shall be the signed magnitude value of the entity's absolute velocity vector.  A negative value shall indicate that the entity is moving backwards.  Entity Speed shall be specified in 0.1 meter per second increments and shall be represented by a 16-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Turret Azimuth. Turret Azimuth shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Gun Elevation. Gun Elevation shall be specified in 25 milliradian increments, and shall be  represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Turret Slew Rate. Turret Slew Rate shall be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Gun Elevation Rate. Gun Elevation Rate is to be specified in 25 milliradian per second increments, and shall be represented by an 8-bit signed integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 5 - Basic Rotor Wing Aircraft shall be as shown in <xref linkend="eman.isgroupof.record5"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record5']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 6 - Enhanced Rotary Wing Aircraft</title>
              <para>The specification of entity state and logistics information about an individual entity within a group of rotor wing aircraft shall be represented by a Grouped Entity Description record 6 - Enhanced Rotor Wing Aircraft.  The Grouped Entity Description record 6 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Grouped Entity Description record 5 - Basic Rotor Wing Aircraft.  See 11.3.3.5.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Supplemental Fuel Status. Supplemental Fuel Status of a grouped entity shall be the amount of supplemental fuel remaining.  Supplemental Fuel Status shall be specified in the natural units of the specific system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Air Maintenance Status. Air Maintenance Status of a grouped entity shall be the time since the last maintenance was completed.  Air Maintenance Status shall be specified in hours, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Primary Ammunition. Primary Ammunition of a grouped entity shall be the amount of primary ammunition remaining.  Primary Ammunition shall be specified in natural ammunition units for the primary weapon system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Secondary Ammunition. Secondary Ammunition of a grouped entity shall be the amount of secondary ammunition remaining.  Secondary Ammunition shall be specified in natural ammunition units for the secondary weapon system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 6 - Enhanced Rotor Wing Aircraft shall be as shown in <xref linkend="eman.isgroupof.record6"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record6']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 7 - Basic Fixed Wing Aircraft</title>
              <para>The specification of entity state information about an individual entity within a group of fixed wing aircraft shall be represented by a Grouped Entity Description record 7 - Basic Fixed Wing Aircraft.  The Grouped Entity Description record 7 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>Entity Identifier. Each entity within a group shall be assigned an entity identifier unique within that group. The Site Identifier and Application Identifiers shall be the same as those designated in the Group Entity ID field, and shall not be transmitted.  The Entity Identifier shall be represented by a 16-bit integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Entity Location. Location of a grouped entity shall be specified by a set of three offsets: x-offset, y-offset, and z-offset.  These offsets shall be determined by the difference, in meters, of the grouped entity from the Group Reference Point.  Each offset shall be represented by a 16-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Appearance. Appearance of a grouped entity shall be identical to that specified by an Entity State PDU Appearance record.  This record shall be defined as a 32-bit record of enumerations (see 5.2.12 in IEEE Std 1278.1-1995).  Values for the fields contained in this record are defined in Section 4 of this document.
                  </para>
                </listitem>
                <listitem>
                  <para>Entity Orientation. Orientation of a grouped entity shall be specified by three Euler angles, psi, theta and phi, in 25 milliradian increments.  Each angle shall be represented by an 8-bit signed integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Fuel Status. Fuel Status of a grouped entity shall be the amount of primary fuel remaining.  Fuel Status shall be  specified in natural units of the specific system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Movement Direction. Movement Direction shall be specified as a horizontal and a vertical deviation from the Entity Orientation.  Each deviation shall be specified in 25 milliradian increments, and shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Movement Speed. Speed of a grouped entity shall be a signed magnitude value of the entity's absolute velocity vector.  A negative value shall indicate that the entity is moving backwards.  Movement Speed shall be specified in 0.1 meter per second increments, and shall be represented by a 16-bit signed integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 7 - Basic Fixed Wing Aircraft shall be as shown in <xref linkend="eman.isgroupof.record7"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record7']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 8 - Enhanced Fixed Wing Aircraft</title>
              <para>The specification of entity state and logistics information about an individual entity within a group of fixed wing aircraft shall be represented by a Grouped Entity Description record 8 - Enhanced Fixed Wing Aircraft.  Grouped Entity Description record 8 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Grouped Entity Description record 7 - Basic Fixed Wing Aircraft.  See 11.3.3.7.
                  </para>
                </listitem>
                <listitem>
                  <para>Supplemental Fuel Status. Supplemental Fuel Status of a grouped entity shall be the amount of supplemental fuel remaining. Supplemental Fuel Status shall be specified in the natural units of the specific system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>Air Maintenance Status. Air Maintenance Status of a grouped entity shall be the time since the last maintenance was completed.  Air Maintenance Status shall be specified in hours, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
                <listitem>
                  <para>
                    Primary Ammunition. Primary Ammunition of a grouped entity shall be the amount of primary ammunition remaining.  Primary Ammunition shall be specified in natural ammunition units for the primary weapon system, and shall be represented by an 8-bit unsigned integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Secondary Ammunition. Secondary Ammunition of a grouped entity shall be the amount of secondary ammunition remaining.  Secondary Ammunition shall be specified in natural ammunition units for the secondary weapon system, and shall be represented by an 8-bit unsigned integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 8 - Enhanced Fixed Wing Aircraft shall be as shown in <xref linkend="eman.isgroupof.record8"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record8']"/>
            </section>
            <section>
              <title>Grouped Entity Description record 9 - Ground Logistics Vehicle</title>
              <para>The specification of entity state information about an individual entity within a group of ground logistics vehicles shall be represented by a Grouped Entity Description record 9 - Ground Logistics Vehicle.  The Grouped Entity Description record 9 shall contain the following fields:</para>
              <orderedlist numeration="loweralpha">
                <listitem>
                  <para>
                    Entity Identifier. Each entity within a group shall be assigned an entity identifier unique within that group.  The Site Identifier and Application Identifiers shall be the same as those designated in the Group Entity ID, and shall not be transmitted.  The Entity Identifier shall be represented by a 16-bit integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Location. Location of a grouped entity shall be specified by a set of three offsets: x-offset, y-offset, and z-offset.  These offsets shall be determined by the difference, in meters, of the grouped entity from the Group Reference Point.  Each offset shall be represented by a 16-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Appearance. Entity Appearance of a grouped entity shall be identical to that specified by an Entity State PDU Appearance record.  This record shall be defined as a 32-bit record of enumerations (see 5.2.12 in IEEE Std 1278.1-1995).  Values for the fields contained in this record are defined in Section 4 of this document.
                  </para>
                </listitem>
                <listitem>
                  <para>
                    Entity Orientation. Orientation of a grouped entity shall be specified by three Euler angles, psi, theta and phi, in 25 milliradian increments. Each  angle shall be represented by an 8-bit signed integer.
                  </para>
                </listitem>
                <listitem>
                  <para>Entity Speed. Speed of a grouped entity shall be the signed magnitude value of the entity's absolute velocity vector.  A negative value shall indicate that the entity is moving backwards. Entity Speed shall be specified in meters per second, and shall be represented by an 8-bit signed integer.</para>
                </listitem>
              </orderedlist>
              <para>
                The format of the Grouped Entity Description record 9 - Ground Logistics Vehicle shall be as shown in <xref linkend="eman.isgroupof.record9"/>.
              </para>
              <xsl:apply-templates select="record[@cname='eman.isgroupof.record9']"/>
            </section>
          </section>
        </section>
        <section>
          <title>Transfer Control PDU</title>
          <section>
            <title>Transfer Type</title>
            <para>This section specifies the 8-bit enumeration for the Transfer Type field of the Transfer Control PDU.</para>
            <xsl:apply-templates select="enum[@cname='eman.tc.transfertype']"/>
          </section>
        </section>
      </chapter>
      <chapter>
        <title>Environment family</title>
        <section>
          <title>Point, Linear, Areal Object State PDU</title>
          <section>
            <title>Object Type record</title>
            <para>This section specifies the 32-bit enumerations for the Object Type record of the Point Object, Linear Object and Areal Object State PDUs. Object Types are arranged in a hierarchical order.</para>
            <section>
              <title>Domain</title>
              <para>The domain enumerations are the same as used for the Entity Type record (see <xref linkend="es.type"/>).</para>
            </section>
            <section>
              <title>Object Kind</title>
              <para>This section specifies the 8-bit enumeration for the Object Kind field.</para>
              <xsl:apply-templates select="enum[@cname='env.obj.objecttype.kind']"/>
            </section>
            <section>
              <title>Point Object State PDU Object Types</title>
              <xsl:apply-templates select="cot[@cname='env.obj.objecttype.point']"/>
            </section>
            <section>
              <title>Linear Object State PDU Object Types</title>
              <xsl:apply-templates select="cot[@cname='env.obj.objecttype.linear']"/>
            </section>
            <section>
              <title>Areal Object State PDU Object Types</title>
              <xsl:apply-templates select="cot[@cname='env.obj.objecttype.areal']"/>
            </section>
          </section>
          <section>
            <title>Appearance record</title>
            <para>This section specifies the 48-bit enumeration for the Appearance record of the Point Object, Linear Object, and Areal Object State PDUs. This field consists of a general part comprising the lower 16 bits, and a PDU specific portion comprising the remaining 32 bits.</para>
            <section>
              <title>General</title>
              <xsl:apply-templates select="bitmask[@cname='env.obj.appear.general']"/>
            </section>
            <section>
              <title>Point Object State PDU Appearance Records</title>
              <para>The upper 32 bits of the Point Object Appearance field are defined specifically for each category. The following sections describe the specific bit definitions for all categories.</para>
              <section>
                <title>Building / structure, Building rubble, Stationary bridge, and AVLB</title>
                <para>The upper 32 bits of the Point Object Appearance field for categories Building / structure, Building rubble, Stationary bridge, and AVLB are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.point.building']"/>
              </section>
              <section>
                <title>Log crib, Abatis, Vehicle defilade, and Infantry fighting position</title>
                <para>The upper 32 bits of the Point Object Appearance field for the categories Log crib, Abatis, Vehicle defilade, and Infantry fighting position are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.point.breach']"/>
              </section>
              <section>
                <title>Air burst, Ground burst</title>
                <para>The upper 32 bits of the Point Object Appearance field for the categories Air burst and Ground burst are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.point.burst']"/>
              </section>
              <section>
                <title>Crater</title>
                <para>The upper 32 bits of the Point Object Appearance field for the category Crater are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.point.crater']"/>
              </section>
              <section>
                <title>Ribbon Bridge</title>
                <para>The upper 32 bits of the Point Object Appearance field for the category Ribbon bridge are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.point.bridge']"/>
              </section>
            </section>
            <section>
              <title>Linear Object State PDU Appearance Records</title>
              <para>The upper 32 bits of the Linear Object Appearance field are defined specifically for each category. The following sections describe the specific bit definitions for all categories.</para>
              <section>
                <title>Tank ditch, and Concertina Wire</title>
                <para>The upper 32 bits of the Linear Object Appearance field for the categories Tank ditch and Concertina wire are defined as follows</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.linear.tankditch']"/>
              </section>
              <section>
                <title>Exhaust smoke</title>
                <para>The upper 32 bits of the Linear Object Appearance field for the category Exhaust smoke are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.linear.exhaust']"/>
              </section>
              <section>
                <title>Minefield Lane Marker</title>
                <para>The upper 32 bits of the Linear Object Appearance field for the category Minefield lane marker are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.linear.marker']"/>
              </section>
              <section>
                <title>Breach</title>
                <para>The upper 32 bits of the Linear Object Appearance field for the category Breach are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.linear.breach']"/>
              </section>
            </section>
            <section>
              <title>Areal Object State PDU Appearance Records</title>
              <para>The upper 32 bits of the Areal Object Appearance field are defined specifically for each category. The following sections describe the specific bit definitions for all categories.</para>
              <section>
                <title>Minefield</title>
                <para>The upper 32 bits of the Areal Object Appearance field for the category Minefield are defined as follows:</para>
                <xsl:apply-templates select="bitmask[@cname='env.obj.appear.areal.minefield']"/>
              </section>
            </section>
          </section>
          <section>
            <title>Modification field</title>
            <section>
              <title>Point Object State PDU Modification Field</title>
              <para>This section specifies the 8-bit enumerations for the Modification field of the Point Object State PDU. The bits are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='env.obj.mod.point']"/>
            </section>
            <section>
              <title>Linear Object State PDU Modification Field</title>
              <para>This section specifies the 8-bit enumerations for the Segment Modification field of the Linear Segment Parameter record of the Linear Object State PDU. The bits are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='env.obj.mod.linear']"/>
            </section>
            <section>
              <title>Areal Object State PDU Modification Field</title>
              <para>This section specifies the 8-bit enumerations for the Modification field of the Areal Object State PDU. The bits are defined as follows:</para>
              <xsl:apply-templates select="bitmask[@cname='env.obj.mod.areal']"/>
            </section>
          </section>
        </section>
        <section>
          <title>Gridded Data PDU</title>
          <section>
            <title>Field Number</title>
            <para>This section specifies the 16-bit enumeration for the Field Number field of the Grid Data Record</para>
            <xsl:apply-templates select="enum[@cname='env.gridded.fieldnumber']"/>
          </section>
          <section>
            <title>Coordinate System</title>
            <para>This section specifies the 16-bit enumeration for the Coordinate System field of the Grid Data Record.</para>
            <xsl:apply-templates select="enum[@cname='env.gridded.coordinatesystem']"/>
          </section>
          <section>
            <title>Constant Grid</title>
            <para>This section specifies the 8-bit enumeration for the Constant Grid field of the Grid Data Record.</para>
            <xsl:apply-templates select="enum[@cname='env.gridded.constantgrid']"/>
          </section>
          <section>
            <title>Sample Type</title>
            <para>This section specifies the 16-bit enumeration for the Sample Type field of the Grid Data Record.</para>
            <xsl:apply-templates select="enum[@cname='env.gridded.sampletype']"/>
          </section>
          <section>
            <title>Data Representation</title>
            <para>This section specifies the 16-bit enumeration for the Data Representation field of the Grid Data Record.</para>
            <xsl:apply-templates select="enum[@cname='env.gridded.datarepresentation']"/>
          </section>
        </section>
        <section>
          <title>Environmental Process PDU</title>
          <section>
            <title>Model Type</title>
            <para>This section specifies the 8-bit enumeration for the Model Type field.</para>
            <xsl:apply-templates select="enum[@cname='env.process.modeltype']"/>
          </section>
          <section>
            <title>Environment Status</title>
            <para>This section specifies the 8-bit Boolean array for the Environment Status. Any individual bit set to one indicates that the Environmental Process has the corresponding status.</para>
            <xsl:apply-templates select="bitmask[@cname='env.process.environmentstatus']"/>
          </section>
          <section>
            <title>Type</title>
            <para>This section specifies the 32-bit enumerations for the Type field of the Environment record for both the Geometry and State records.</para>
            <section>
              <title>Type field values for Geometry record</title>
              <xsl:apply-templates select="enum[@cname='env.process.type.geometryrecord']"/>
            </section>
            <section>
              <title>Type field values for State record</title>
              <xsl:apply-templates select="enum[@cname='env.process.type.staterecord']"/>
            </section>
          </section>
          <section>
            <title>Geometry record</title>
            <para>This section contains the definition of the Geometry records of the Environment record.</para>
            <section>
              <title>Point Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.point1']"/>
            </section>
            <section>
              <title>Point Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.point2']"/>
            </section>
            <section>
              <title>Line Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.line1']"/>
            </section>
            <section>
              <title>Line Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.line2']"/>
            </section>
            <section>
              <title>Bounding Sphere Record</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.boundingsphere']"/>
            </section>
            <section>
              <title>Sphere Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.sphere1']"/>
            </section>
            <section>
              <title>Sphere Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.sphere2']"/>
            </section>
            <section>
              <title>Ellipsoid Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.ellipsoid1']"/>
            </section>
            <section>
              <title>Ellipsoid Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.ellipsoid2']"/>
            </section>
            <section>
              <title>Cone Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.cone1']"/>
            </section>
            <section>
              <title>Cone Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.cone2']"/>
            </section>
            <section>
              <title>Rectangular Volume Record 1</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.rect1']"/>
            </section>
            <section>
              <title>Rectangular Volume Record 2</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.rect2']"/>
            </section>
            <section>
              <title>Gaussian Plume Record</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.gplume']"/>
            </section>
            <section>
              <title>Gaussian Puff Record</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.gpuff']"/>
            </section>
            <section>
              <title>Uniform Geometry Record</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.uniform']"/>
            </section>
            <section>
              <title>Rectangular Volume Record 3</title>
              <xsl:apply-templates select="record[@cname='env.process.geom.rect3']"/>
            </section>
          </section>
          <section>
            <title>State record</title>
            <para>This section contains the definition of the State records of the Environment record.</para>
            <section>
              <title>COMBIC State</title>
              <xsl:apply-templates select="record[@cname='env.process.state.combic']"/>
            </section>
            <section>
              <title>Flare State</title>
              <xsl:apply-templates select="record[@cname='env.process.state.flare']"/>
            </section>
          </section>
        </section>
      </chapter>
    </book>
  </xsl:template>
  <!--=== Revisions ===-->
  <xsl:template match="revisions">
    <table>
      <title>Change History</title>
      <tgroup cols="3">
        <thead>
          <row>
            <entry>Document Number</entry>
            <entry>Publication Date</entry>
            <entry>Change Requests Incoprorated</entry>
          </row>
        </thead>
        <tbody>
          <xsl:apply-templates select="revision"/>
        </tbody>
      </tgroup>
    </table>
  </xsl:template>
  <xsl:template match="revision">
    <row>
      <entry>
        <xsl:value-of select="@title"/>
      </entry>
      <entry>
        <xsl:value-of select="@date"/>
      </entry>
      <entry>
        <xsl:value-of select="@cr"/> - <xsl:value-of select="@cr2"/>
      </entry>
    </row>
  </xsl:template>
  <!--=== Acronyms ===-->
  <xsl:template match="acronyms">
    <para>
      <informaltable>
        <tgroup cols="2">
          <colspec colnum="1" colwidth="75pc"/>
          <tbody>
            <xsl:apply-templates select="acronym"/>
          </tbody>
        </tgroup>
      </informaltable>
    </para>
  </xsl:template>
  <xsl:template match="acronym">
    <row>
      <entry>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:value-of select="@description"/>
      </entry>
    </row>
  </xsl:template>
  <!--=== Enum ===-->
  <xsl:template match="enum">
    <xsl:if test="enumrow">
      <informaltable>
        <tgroup cols="{2 + count(header/col)}">
          <colspec colnum="1" colwidth="75pc"/>
          <thead>
            <row>
              <entry>Field Value</entry>
              <entry>Description</entry>
              <!-- output meta data headers -->
              <xsl:apply-templates select="header"/>
            </row>
          </thead>
          <tbody>
            <xsl:apply-templates select="enumrow"/>
          </tbody>
        </tgroup>
      </informaltable>
    </xsl:if>
  </xsl:template>
  <xsl:template match="header">
    <xsl:apply-templates select="col"/>
  </xsl:template>
  <xsl:template match="col">
    <entry>
      <xsl:value-of select="@name"/>
    </entry>
  </xsl:template>
  <xsl:template match="enumrow">
    <row>
      <entry>
        <!-- if id2 supplied, output range -->
        <xsl:value-of select="@id"/>
        <xsl:if test="@id2"> - <xsl:value-of select="@id2"/></xsl:if>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
      <!-- output meta data -->
      <xsl:if test="../header">
        <xsl:variable name="tmpnode" select="."/>
        <xsl:for-each select="../header/col">
          <xsl:variable name="tmpid" select="@id"/>
          <entry>
            <xsl:value-of select="$tmpnode/meta[@id=$tmpid]/@value"/>
          </entry>
        </xsl:for-each>
      </xsl:if>
    </row>
  </xsl:template>
  <!--=== Bitmask ===-->
  <xsl:template match="bitmask">
    <informaltable>
      <tgroup cols="4">
        <colspec colnum="1" colwidth="2*"/>
        <colspec colnum="3" colname="c3"/>
        <colspec colnum="4" colname="c4" colwidth="4*"/>
        <thead>
          <row>
            <entry>Name</entry>
            <entry>Bits</entry>
            <entry namest="c3" nameend="c4">Purpose</entry>
          </row>
        </thead>
        <tbody>
          <xsl:apply-templates/>
        </tbody>
      </tgroup>
    </informaltable>
  </xsl:template>
  <xsl:template match="bitmaskrow">
    <row>
      <entry morerows="{count(enumrow)}">
        <xsl:value-of select="@name"/>
      </entry>
      <entry morerows="{count(enumrow)}">
        <!-- if id2 supplied, output range -->
        <xsl:if test="@id2"><xsl:value-of select="@id2"/> - </xsl:if>
        <xsl:value-of select="@id"/>
      </entry>
      <entry namest="c3" nameend="c4">
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <!-- output enumerations associated with this range -->
    <xsl:if test="enumrow">
      <xsl:apply-templates mode="bitmaskrow"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="enumrow" mode="bitmaskrow">
    <row>
      <entry>
        <!-- if id2 supplied, output range -->
        <xsl:if test="@id2"><xsl:value-of select="@id2"/> - </xsl:if>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
  </xsl:template>
  <!--=== CET ====-->
  <xsl:template match="cet">
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="entity" mode="dotable">
    <informaltable>
      <tgroup cols="2">
        <colspec colnum="2" colwidth="4*"/>
        <thead>
          <row>
            <entry>Field Value</entry>
            <entry>Description</entry>
          </row>
        </thead>
        <tbody>
          <row>
            <entry>
              <xsl:value-of select="@kind"/>
              <xsl:text>.</xsl:text>
              <xsl:value-of select="@domain"/>
              <xsl:text>.</xsl:text>
              <xsl:value-of select="@country"/>
            </entry>
          </row>
          <xsl:apply-templates select="category"/>
        </tbody>
      </tgroup>
    </informaltable>
  </xsl:template>

  <xsl:template match="entity" mode="doheading">
    <xsl:variable name="thiskind" select="@kind"/>
    <xsl:variable name="thiscountry" select="@country"/>
    <xsl:variable name="thisdomain" select="@domain"/>
    <xsl:choose>
      <xsl:when test="(preceding-sibling::*[1]/@kind=$thiskind) and (preceding-sibling::*[1]/@country=$thiscountry) and (preceding-sibling::*[1]/@domain=$thisdomain)">
      </xsl:when>
      <xsl:otherwise>
        <section>
          <title>
            <xsl:choose>
              <xsl:when test="/ebv/enum[@cname=concat('es.type.kind.',$thiskind,'.domain')]">
                <xsl:value-of select="/ebv/enum[@cname=concat('es.type.kind.',$thiskind,'.domain')]/enumrow[@id=$thisdomain]/@description"/>
              </xsl:when>
              <xsl:otherwise>
                <xsl:value-of select="/ebv/enum[@cname='es.type.kind.1.domain']/enumrow[@id=$thisdomain]/@description"/>
              </xsl:otherwise>
            </xsl:choose>
          </title>
          <xsl:apply-templates select="../*[(@kind=$thiskind) and (@country=$thiscountry) and (@domain=$thisdomain)]" mode="dotable"/>
        </section>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="entity">
    <xsl:variable name="thiskind" select="@kind"/>
    <xsl:variable name="thiscountry" select="@country"/>
    <xsl:choose>
      <xsl:when test="(preceding-sibling::*[1]/@kind=$thiskind) and (preceding-sibling::*[1]/@country=$thiscountry)">
      </xsl:when>
      <xsl:otherwise>
        <section>
          <title>
            <xsl:if test="$thiscountry&gt;0">
              <xsl:value-of select="/ebv/enum[@cname='es.type.country']/enumrow[@id=$thiscountry]/@description"/>
              <xsl:text> </xsl:text>
            </xsl:if>
            <xsl:value-of select="/ebv/enum[@cname='es.type.kind']/enumrow[@id=$thiskind]/@description"/>
          </title>
          <para/>
          <xsl:apply-templates select="../*[(@kind=$thiskind) and (@country=$thiscountry)]" mode="doheading"/>
        </section>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template match="category">
    <row>
      <entry>
        <xsl:value-of select="../@kind"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@country"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates select="subcategory"/>
  </xsl:template>
  <xsl:template match="subcategory">
    <row>
      <entry>
        <xsl:choose>
          <xsl:when test="@id2"><xsl:value-of select="../../@kind"/><xsl:text>.</xsl:text><xsl:value-of select="../../@domain"/><xsl:text>.</xsl:text><xsl:value-of select="../../@country"/><xsl:text>.</xsl:text><xsl:value-of select="../@id"/><xsl:text>.[</xsl:text><xsl:value-of select="@id"/><xsl:text> - </xsl:text><xsl:value-of select="@id2"/>]</xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="../../@kind"/>
            <xsl:text>.</xsl:text>
            <xsl:value-of select="../../@domain"/>
            <xsl:text>.</xsl:text>
            <xsl:value-of select="../../@country"/>
            <xsl:text>.</xsl:text>
            <xsl:value-of select="../@id"/>
            <xsl:text>.</xsl:text>
            <xsl:value-of select="@id"/>
          </xsl:otherwise>
        </xsl:choose>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates select="specific"/>
  </xsl:template>
  <xsl:template match="specific">
    <row>
      <entry>
        <xsl:value-of select="../../../@kind"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../../@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../../@country"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates select="extra"/>
  </xsl:template>
  <xsl:template match="extra">
    <row>
      <entry>
        <xsl:value-of select="../../../../@kind"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../../../@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../../../@country"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates/>
  </xsl:template>
  <!--=== COT ===-->
  <xsl:template match="cot">
    <informaltable>
      <tgroup cols="2">
        <colspec colnum="2" colwidth="4*"/>
        <thead>
          <row>
            <entry>Field Value</entry>
            <entry>Description</entry>
          </row>
        </thead>
        <tbody>
          <xsl:apply-templates mode="cot"/>
        </tbody>
      </tgroup>
    </informaltable>
  </xsl:template>
  <xsl:template match="object" mode="cot">
    <row>
      <entry>
        <xsl:value-of select="@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@kind"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates select="category" mode="cot"/>
  </xsl:template>
  <xsl:template match="category" mode="cot">
    <row>
      <entry>
        <xsl:value-of select="../@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@kind"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
    <xsl:apply-templates select="subcategory" mode="cot"/>
  </xsl:template>
  <xsl:template match="subcategory" mode="cot">
    <row>
      <entry>
        <xsl:value-of select="../../@domain"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../../@kind"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="../@id"/>
        <xsl:text>.</xsl:text>
        <xsl:value-of select="@id"/>
      </entry>
      <entry>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </entry>
    </row>
  </xsl:template>
  <!--=== Record ===-->
  <xsl:template match="record">
    <table>
      <xsl:attribute name="id">
        <xsl:value-of select="@cname"/>
      </xsl:attribute>
      <title>
        <xsl:value-of select="@name"/>
      </title>
      <tgroup cols="2">
        <colspec colnum="1" colname="c1"/>
        <colspec colnum="2" colname="c2"/>
        <tbody>
          <xsl:apply-templates select="field" mode="record"/>
          <row>
            <entry namest="c1" nameend="c2" align="center">
              <emphasis>
                <xsl:value-of select="@name"/>
                <xsl:text> - total size </xsl:text>
                <xsl:value-of select="@length"/>
                <xsl:text> bits</xsl:text>
              </emphasis>
            </entry>
          </row>
        </tbody>
      </tgroup>
    </table>
  </xsl:template>
  <xsl:template match="field" mode="record">
    <row>
      <entry valign="middle">
        <xsl:choose>
          <xsl:when test="count(datatype)=0">
            <xsl:attribute name="namest">c1</xsl:attribute>
            <xsl:attribute name="nameend">c2</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:attribute name="morerows">
              <xsl:value-of select="count(datatype)-1"/>
            </xsl:attribute>
          </xsl:otherwise>
        </xsl:choose>
        <xsl:value-of select="@name"/>
      </entry>
      <xsl:apply-templates select="datatype[position()=1]" mode="entry"/>
    </row>
    <xsl:apply-templates select="datatype[position()&gt;1]" mode="record"/>
  </xsl:template>
  <xsl:template match="datatype" mode="entry">
    <entry valign="middle">
      <xsl:if test="@name">
        <xsl:value-of select="@name"/>
        <xsl:text> - </xsl:text>
      </xsl:if>
      <xsl:value-of select="@type"/>
    </entry>
  </xsl:template>
  <xsl:template match="datatype" mode="record">
    <row>
      <xsl:apply-templates select="." mode="entry"/>
    </row>
  </xsl:template>
  <!--=== Output Description ==-->
  <xsl:template match="*" mode="outputdescription">
    <xsl:value-of select="@description"/>
    <xsl:if test="@unused">(Unused)</xsl:if>
    <xsl:if test="@deleted">(Deleted)</xsl:if>
    <xsl:if test="@footnote">
      <footnote>
        <para>
          <xsl:value-of select="@footnote"/>
        </para>
      </footnote>
    </xsl:if>
    <xsl:if test="@xref">(See <xref><xsl:attribute name="linkend"><xsl:value-of select="@xref"/></xsl:attribute></xref>).</xsl:if>
  </xsl:template>
</xsl:stylesheet>
