<?xml version="1.0"?>
<!--
  xml2sql.xslt
  Transform EBV-MR XML file to SQL statements
  peter.ross@dsto.defence.gov.au
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="text"/>
  <xsl:template match="ebv">
    <xsl:text>BEGIN TRANSACTION;
</xsl:text>
    <xsl:text>INSERT INTO ebv (title,release,date,href,organisation) VALUES (</xsl:text>
    <xsl:apply-templates select="@title"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@release"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@date"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@href"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@organisation"/>
    <xsl:text>);
</xsl:text>
    <xsl:apply-templates mode="body"/>
    <xsl:text>COMMIT;
</xsl:text>
  </xsl:template>
  <!--=== Revisions ===-->
  <xsl:template match="revisions" mode="body">
    <xsl:apply-templates select="revision"/>
  </xsl:template>
  <xsl:template match="revision">
    <xsl:text>INSERT INTO revision (title</xsl:text>
    <xsl:if test="@date"><xsl:text>,date</xsl:text></xsl:if>
    <xsl:if test="@cr"><xsl:text>,cr</xsl:text></xsl:if>
    <xsl:if test="@cr2"><xsl:text>,cr2</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="@title"/>
    <xsl:if test="@date"><xsl:text>,</xsl:text><xsl:apply-templates select="@date"/></xsl:if>
    <xsl:if test="@cr"><xsl:text>,</xsl:text><xsl:value-of select="@cr"/></xsl:if>
    <xsl:if test="@cr2"><xsl:text>,</xsl:text><xsl:value-of select="@cr2"/></xsl:if>
    <xsl:text>);
</xsl:text>
  </xsl:template>
  <!--=== Acronyms ===-->
  <xsl:template match="acronyms" mode="body">
    <xsl:apply-templates select="acronym"/>
  </xsl:template>
  <xsl:template match="acronym">
    <xsl:text>INSERT INTO acronym (id,description) VALUES (</xsl:text>
    <xsl:apply-templates select="@id"/>
    <xsl:text>, </xsl:text><xsl:apply-templates select="@description"/>
  <xsl:text>);
</xsl:text>
  </xsl:template>
  <!--=== Enum ===-->
  <xsl:template match="enum" mode="body">
    <xsl:apply-templates select="." mode="table"/>
    <xsl:apply-templates select="enumrow" />
  </xsl:template>
  <xsl:template match="header">
    <!-- FIXME -->
  </xsl:template>
  <xsl:template match="col">
    <!-- FIXME -->
  </xsl:template>
  <xsl:template match="enumrow">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT INTO enum (table_id</xsl:text>
    <xsl:if test="name(..)='bitmaskrow'"><xsl:text>,bitmask_id</xsl:text></xsl:if>
    <xsl:text>,id</xsl:text>
    <xsl:if test="@id2"><xsl:text>,id2</xsl:text></xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:choose>
      <xsl:when test="name(..)='bitmaskrow'">
        <xsl:value-of select="../../@id"/>
        <xsl:text>,</xsl:text><xsl:value-of select="../@id"/>
      </xsl:when>
      <xsl:when test="name(..)='enum'"><xsl:value-of select="../@id"/></xsl:when>
    </xsl:choose>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
    <xsl:if test="@id2"><xsl:text>,</xsl:text><xsl:value-of select="@id2"/></xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
  </xsl:template>
  <!--=== Bitmask ===-->
  <xsl:template match="bitmask" mode="body">
    <xsl:apply-templates select="." mode="table"/>
    <xsl:apply-templates select="bitmaskrow" />
  </xsl:template>
  <xsl:template match="bitmaskrow">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT INTO bitmask (table_id,id</xsl:text>
    <xsl:if test="@id2"><xsl:text>,id2</xsl:text></xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:value-of select="../@id"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
    <xsl:if test="@id2"><xsl:text>,</xsl:text><xsl:value-of select="@id2"/></xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
    <xsl:apply-templates select="enumrow" />
  </xsl:template>
  <!--=== CET ===-->
  <xsl:template match="cet" mode="body">
    <xsl:apply-templates select="." mode="table"/>
    <xsl:apply-templates select="entity" />
  </xsl:template>
  <xsl:template match="entity">
    <xsl:apply-templates select="category" />
  </xsl:template>
  <xsl:template match="category">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cet(table_id,kind,domain,country,category</xsl:text>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cet-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
    <xsl:apply-templates select="subcategory" />
  </xsl:template>
  <xsl:template match="subcategory">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cet(table_id,kind,domain,country,category,subcategory</xsl:text>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cet-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
    <xsl:apply-templates select="specific" />
  </xsl:template>
  <xsl:template match="specific">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cet(table_id,kind,domain,country,category,subcategory,specific</xsl:text>
    <xsl:if test="@id2"><xsl:text></xsl:text>,specific2</xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cet-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
    <xsl:apply-templates select="extra" />
  </xsl:template>
  <xsl:template match="extra">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cet(table_id,kind,domain,country,category,subcategory,specific,extra</xsl:text>
    <xsl:if test="@id2"><xsl:text></xsl:text>,extra2</xsl:if>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cet-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
  </xsl:template>
  <xsl:template match="category" mode="output-cet-columns">
    <xsl:value-of select="../../@id"/>
    <xsl:text>,</xsl:text><xsl:value-of select="../@kind"/>
    <xsl:text>,</xsl:text><xsl:value-of select="../@domain"/>
    <xsl:text>,</xsl:text><xsl:value-of select="../@country"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
  </xsl:template>
  <xsl:template match="subcategory" mode="output-cet-columns">
    <xsl:apply-templates select=".." mode="output-cet-columns"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
  </xsl:template>
  <xsl:template match="specific" mode="output-cet-columns">
    <xsl:apply-templates select=".." mode="output-cet-columns"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
    <xsl:if test="@id2"><xsl:text>,</xsl:text><xsl:value-of select="@id2"/></xsl:if>
  </xsl:template>
  <xsl:template match="extra" mode="output-cet-columns">
    <xsl:apply-templates select=".." mode="output-cet-columns"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
    <xsl:if test="@id2"><xsl:text>,</xsl:text><xsl:value-of select="@id2"/></xsl:if>
  </xsl:template>
  <!--=== COT ===-->
  <xsl:template match="cot" mode="body">
    <xsl:apply-templates select="." mode="table"/>
    <xsl:apply-templates mode="cot" />
  </xsl:template>
  <xsl:template match="object" mode="cot">
    <xsl:apply-templates mode="cot" />
  </xsl:template>
  <xsl:template match="category" mode="cot">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cot(table_id,kind,domain,category</xsl:text>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cot-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  <xsl:text>);
</xsl:text>
  </xsl:template>
  <xsl:template match="subcategory" mode="cot">
    <xsl:apply-templates select="." mode="abstract"/>
    <xsl:text>INSERT into cot(table_id,kind,domain,category,subcategory</xsl:text>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused"><xsl:text>,abstract_id</xsl:text></xsl:if>
    <xsl:text>) VALUES (</xsl:text>
    <xsl:apply-templates select="." mode="output-cot-columns"/>
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
        <xsl:text>,(SELECT MAX(abstract_id) FROM abstract)</xsl:text>
    </xsl:if>
  </xsl:template>
  <xsl:template match="category" mode="output-cot-columns">
    <xsl:value-of select="../../@id"/>
    <xsl:text>,</xsl:text><xsl:value-of select="../@kind"/>
    <xsl:text>,</xsl:text><xsl:value-of select="../@domain"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
  </xsl:template>
  <xsl:template match="subcategory" mode="output-cot-columns">
    <xsl:apply-templates select=".." mode="output-cot-columns"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@id"/>
  </xsl:template>
  <!--=== Record ===-->
  <xsl:template match="record" mode="body">
  </xsl:template>
  <xsl:template match="field" mode="record">
  </xsl:template>
  <xsl:template match="datatype" mode="entry">
  </xsl:template>
  <xsl:template match="datatype" mode="record">
  </xsl:template>
  <!--=== Output Description ==-->
  <xsl:template match="*" mode="outputdescription">
  </xsl:template>

  <!-- Ignore any erroneous text in the XML document -->
  <xsl:template match="text()" mode="cot"></xsl:template>
  <xsl:template match="text()" mode="body"></xsl:template>
  <xsl:template match="text()"></xsl:template>

  <!-- table -->
  <xsl:template match="*" mode="table">
    <xsl:text>INSERT INTO tab (id, cname, length, name, source) VALUES (</xsl:text>
    <xsl:value-of select="@id"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@cname"/>
    <xsl:text>,</xsl:text><xsl:value-of select="@length"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@name"/>
    <xsl:text>,</xsl:text><xsl:apply-templates select="@source"/>
    <xsl:text>);
</xsl:text>
  </xsl:template>

  <!-- abstract -->
  <xsl:template match="*" mode="abstract">
    <xsl:if test="@description|@footnote|@xref|@delete|@unused">
      <xsl:text>INSERT INTO abstract (abstract_id</xsl:text>
      <xsl:if test="@description"><xsl:text>,description</xsl:text></xsl:if>
      <xsl:if test="@footnote"><xsl:text>,footnote</xsl:text></xsl:if>
      <xsl:if test="@xref"><xsl:text>,xref</xsl:text></xsl:if>
      <xsl:if test="@deleted"><xsl:text>,deleted</xsl:text></xsl:if>
      <xsl:if test="@unused"><xsl:text>,unused</xsl:text></xsl:if>
      <xsl:text>) VALUES (</xsl:text>
      <xsl:text>(SELECT max(abstract_id) FROM abstract)+1</xsl:text>
      <xsl:if test="@description"><xsl:text>,</xsl:text><xsl:apply-templates select="@description"/></xsl:if>
      <xsl:if test="@footnote"><xsl:text>,</xsl:text><xsl:apply-templates select="@footnote"/></xsl:if>
      <xsl:if test="@xref"><xsl:text>,</xsl:text><xsl:apply-templates select="@xref"/></xsl:if>
      <xsl:if test="@deleted"><xsl:text>,</xsl:text><xsl:value-of select="@deleted"/></xsl:if>
      <xsl:if test="@unused"><xsl:text>,</xsl:text><xsl:value-of select="@unused"/></xsl:if>
      <xsl:text>);
</xsl:text>
    </xsl:if>
  </xsl:template>

  <!-- output text in quotes -->
  <xsl:template match="@*">
    <xml:text>'</xml:text><xsl:value-of select="translate(.,&quot;'&quot;,'')"/><xml:text>'</xml:text>
  </xsl:template>

</xsl:stylesheet>
