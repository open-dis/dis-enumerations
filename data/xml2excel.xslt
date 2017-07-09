<?xml version="1.0"?>
<!--
  xml2xls.xslt
  Transform EBV-MR XML file to Microsoft Excel file
  peter.ross@dsto.defence.gov.au
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="urn:schemas-microsoft-com:office:spreadsheet" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:x="urn:schemas-microsoft-com:office:excel" xmlns:ss="urn:schemas-microsoft-com:office:spreadsheet" xmlns:html="http://www.w3.org/TR/REC-html40" version="1.0">
  <xsl:output method="xml"/>
  <xsl:template match="ebv">
    <Workbook xmlns="urn:schemas-microsoft-com:office:spreadsheet" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:x="urn:schemas-microsoft-com:office:excel" xmlns:ss="urn:schemas-microsoft-com:office:spreadsheet" xmlns:html="http://www.w3.org/TR/REC-html40">
      <DocumentProperties xmlns="urn:schemas-microsoft-com:office:office">
        <Title>
          <xsl:value-of select="@title"/>
        </Title>
        <Company>
          <xsl:value-of select="@organisation"/>
        </Company>
      </DocumentProperties>
      <Styles>
        <Style ss:ID="banner">
          <Alignment ss:Horizontal="Center" ss:Vertical="Center" ss:WrapText="1"/>
          <Font x:Family="Swiss" ss:Size="12" ss:Bold="1"/>
          <Interior ss:Color="#FF99CC" ss:Pattern="Solid"/>
        </Style>
        <Style ss:ID="heading">
          <Font x:Family="Swiss" ss:Bold="1"/>
          <Interior ss:Color="#CCFFCC" ss:Pattern="Solid"/>
        </Style>
        <Style ss:ID="hyperlink">
          <Font ss:Color="#0000FF" ss:Underline="Single"/>
        </Style>
        <Style ss:ID="valigncenter">
          <Alignment ss:Vertical="Center"/>
        </Style>
      </Styles>
      <Worksheet ss:Name="Index">
        <Table ss:ExpandedColumnCount="6" x:FullColumns="1" x:FullRows="1">
          <Column ss:Width="25"/>
          <Column ss:Width="200"/>
          <Column ss:Width="50"/>
          <Column ss:Width="50"/>
          <Column ss:Width="200"/>
          <Column ss:Width="60"/>
          <Row ss:AutoFitHeight="0" ss:Height="32">
            <Cell ss:MergeAcross="5" ss:StyleID="banner">
              <Data ss:Type="String">Enumeration and Bit Encoded Values for use with Protocols for Distributed Interactive Simulation Applications</Data>
            </Cell>
          </Row>
          <Row ss:AutoFitHeight="0" ss:Height="20">
            <Cell ss:MergeAcross="5" ss:StyleID="banner">
              <Data ss:Type="String">
                <xsl:value-of select="@organisation"/>
              </Data>
            </Cell>
          </Row>
          <Row ss:AutoFitHeight="0" ss:Height="20">
            <Cell ss:MergeAcross="5" ss:StyleID="banner">
              <Data ss:Type="String">Title: <xsl:value-of select="@title"/>, Release: <xsl:value-of select="@release"/>, Date: <xsl:value-of select="@date"/>
            </Data>
            </Cell>
          </Row>
          <Row>
          </Row>
          <Row>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">Id</Data>
            </Cell>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">CName</Data>
            </Cell>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">Type</Data>
            </Cell>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">Length</Data>
            </Cell>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">Name</Data>
            </Cell>
            <Cell ss:StyleID="heading">
              <Data ss:Type="String">Source</Data>
              <Comment ss:ShowAlways="1">
                <ss:Data>Original SISO-STD-010(2006) Section Number</ss:Data>
              </Comment>
            </Cell>
          </Row>
          <xsl:apply-templates mode="index"/>
        </Table>
        <WorksheetOptions xmlns="urn:schemas-microsoft-com:office:excel">
          <Selected/>
          <TabColorIndex>42</TabColorIndex>
        </WorksheetOptions>
      </Worksheet>
      <xsl:apply-templates mode="body"/>
    </Workbook>
  </xsl:template>
  <!--=== Index ===-->
  <xsl:template match="enum|bitmask|cet|cot|record" mode="index">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell ss:StyleID="hyperlink">
        <xsl:attribute name="ss:HRef">
          <xsl:value-of select="concat('#',@cname,'!A1')"/>
        </xsl:attribute>
        <Data ss:Type="String">
          <xsl:value-of select="@cname"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="local-name(.)"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@length"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@name"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@source"/>
        </Data>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== Revisions ===-->
  <xsl:template match="revisions" mode="body">
    <Worksheet ss:Name="Revisions">
      <Table ss:ExpandedColumnCount="4" ss:ExpandedRowCount="{count(revision)+1}" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="100"/>
        <Column ss:Width="100"/>
        <Column ss:Width="50"/>
        <Column ss:Width="50"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Document Number</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Publication Date</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">CR Lower</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">CR Upper</Data>
          </Cell>
        </Row>
        <xsl:apply-templates select="revision"/>
      </Table>
      <WorksheetOptions xmlns="urn:schemas-microsoft-com:office:excel">
        <TabColorIndex>42</TabColorIndex>
      </WorksheetOptions>
    </Worksheet>
  </xsl:template>
  <xsl:template match="revision">
    <Row>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@title"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@date"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@cr"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@cr2"/>
        </Data>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== Acronyms ===-->
  <xsl:template match="acronyms" mode="body">
    <Worksheet ss:Name="Acronyms">
      <Table ss:ExpandedColumnCount="2" ss:ExpandedRowCount="{count(acronym)+1}" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="100"/>
        <Column ss:Width="100"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Name</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Description</Data>
          </Cell>
        </Row>
        <xsl:apply-templates select="acronym"/>
      </Table>
      <WorksheetOptions xmlns="urn:schemas-microsoft-com:office:excel">
        <TabColorIndex>42</TabColorIndex>
      </WorksheetOptions>
    </Worksheet>
  </xsl:template>
  <xsl:template match="acronym">
    <Row>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@description"/>
        </Data>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== Enum ===-->
  <xsl:template match="enum" mode="body">
    <Worksheet>
      <xsl:attribute name="ss:Name">
        <xsl:value-of select="@cname"/>
      </xsl:attribute>
      <Table ss:ExpandedColumnCount="{3 + count(header/col)}" ss:ExpandedRowCount="{count(enumrow)+1}" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="50"/>
        <Column ss:Width="50"/>
        <Column ss:Width="200"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Value1</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Value2</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Description</Data>
          </Cell>
          <xsl:apply-templates select="header"/>
        </Row>
        <xsl:apply-templates select="enumrow"/>
      </Table>
    </Worksheet>
  </xsl:template>
  <xsl:template match="header">
    <xsl:apply-templates select="col"/>
  </xsl:template>
  <xsl:template match="col">
    <Cell ss:StyleID="heading">
      <Data ss:Type="String">
        <xsl:value-of select="@name"/>
      </Data>
    </Cell>
  </xsl:template>
  <xsl:template match="enumrow">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell>
        <xsl:if test="@id2">
          <Data ss:Type="Number">
            <xsl:value-of select="@id2"/>
          </Data>
        </xsl:if>
      </Cell>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
      <xsl:if test="../header">
        <xsl:variable name="tmpnode" select="."/>
        <xsl:for-each select="../header/col">
          <xsl:variable name="tmpid" select="@id"/>
          <Cell>
            <Data ss:Type="String">
              <xsl:value-of select="$tmpnode/meta[@id=$tmpid]/@value"/>
            </Data>
          </Cell>
        </xsl:for-each>
      </xsl:if>
    </Row>
  </xsl:template>
  <!--=== Bitmask ===-->
  <xsl:template match="bitmask" mode="body">
    <Worksheet>
      <xsl:attribute name="ss:Name">
        <xsl:value-of select="@id"/>
      </xsl:attribute>
      <Table ss:ExpandedColumnCount="4" ss:ExpandedRowCount="{count(bitmaskrow)+1}" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="100"/>
        <Column ss:Width="50"/>
        <Column ss:Width="50"/>
        <Column ss:Width="200"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Name</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">(MSB)</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">LSB</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Purpose</Data>
          </Cell>
        </Row>
        <xsl:apply-templates select="bitmaskrow"/>
      </Table>
    </Worksheet>
  </xsl:template>
  <xsl:template match="bitmaskrow">
    <Row>
      <Cell>
        <Data ss:Type="String">
          <xsl:value-of select="@name"/>
        </Data>
      </Cell>
      <Cell>
        <xsl:if test="@id2">
          <Data ss:Type="Number">
            <xsl:value-of select="@id2"/>
          </Data>
        </xsl:if>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== CET ===-->
  <xsl:template match="cet" mode="body">
    <Worksheet>
      <xsl:attribute name="ss:Name">
        <xsl:value-of select="@id"/>
      </xsl:attribute>
      <Table ss:ExpandedColumnCount="9" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="250"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Kind</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Domain</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Country</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Category</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Subcategory</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Specific</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Extra</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Description</Data>
          </Cell>
        </Row>
        <xsl:apply-templates/>
      </Table>
    </Worksheet>
  </xsl:template>
  <xsl:template match="entity">
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="category">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@country"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell/>
      <Cell/>
      <Cell/>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="subcategory">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@country"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
        <xsl:if test="@id2">
          <Comment ss:ShowAlways="1">
            <ss:Data>Range: [<xsl:value-of select="@id"/> - <xsl:value-of select="@id2"/>]</ss:Data>
          </Comment>
        </xsl:if>
      </Cell>
      <Cell/>
      <Cell/>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="specific">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../@country"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell/>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="extra">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../../@country"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates/>
  </xsl:template>
  <!--=== COT ===-->
  <xsl:template match="cot" mode="body">
    <Worksheet>
      <xsl:attribute name="ss:Name">
        <xsl:value-of select="@id"/>
      </xsl:attribute>
      <Table ss:ExpandedColumnCount="5" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="40"/>
        <Column ss:Width="250"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Domain</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Kind</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Category</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Subcategory</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Description</Data>
          </Cell>
        </Row>
        <xsl:apply-templates select="object" mode="cot"/>
      </Table>
    </Worksheet>
  </xsl:template>
  <xsl:template match="object" mode="cot">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@kind"/>
        </Data>
      </Cell>
      <Cell/>
      <Cell/>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates select="category" mode="cot"/>
  </xsl:template>
  <xsl:template match="category" mode="cot">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell/>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
    <xsl:apply-templates select="subcategory" mode="cot"/>
  </xsl:template>
  <xsl:template match="subcategory" mode="cot">
    <Row>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@domain"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../../@kind"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="../@id"/>
        </Data>
      </Cell>
      <Cell>
        <Data ss:Type="Number">
          <xsl:value-of select="@id"/>
        </Data>
      </Cell>
      <Cell>
        <xsl:apply-templates select="." mode="outputdescription"/>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== Record ===-->
  <xsl:template match="record" mode="body">
    <Worksheet>
      <xsl:attribute name="ss:Name">
        <xsl:value-of select="@id"/>
      </xsl:attribute>
      <Table ss:ExpandedColumnCount="2" x:FullColumns="1" x:FullRows="1">
        <Column ss:Width="150"/>
        <Column ss:Width="250"/>
        <Row>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Field</Data>
          </Cell>
          <Cell ss:StyleID="heading">
            <Data ss:Type="String">Datatype</Data>
          </Cell>
        </Row>
        <xsl:apply-templates select="field" mode="record"/>
      </Table>
    </Worksheet>
  </xsl:template>
  <xsl:template match="field" mode="record">
    <Row>
      <Cell ss:StyleID="valigncenter">
        <xsl:choose>
          <xsl:when test="count(datatype)=0">
            <xsl:attribute name="ss:MergeAcross">1</xsl:attribute>
          </xsl:when>
          <xsl:when test="count(datatype)=1">
          </xsl:when>
          <xsl:otherwise>
            <xsl:attribute name="ss:MergeDown">
              <xsl:value-of select="count(datatype)-1"/>
            </xsl:attribute>
          </xsl:otherwise>
        </xsl:choose>
        <Data ss:Type="String">
          <xsl:value-of select="@name"/>
        </Data>
      </Cell>
      <xsl:apply-templates select="datatype[position()=1]" mode="entry"/>
    </Row>
    <xsl:apply-templates select="datatype[position()&gt;1]" mode="record"/>
  </xsl:template>
  <xsl:template match="datatype" mode="entry">
    <Cell>
      <Data ss:Type="String">
        <xsl:if test="@name"><xsl:value-of select="@name"/> - </xsl:if>
        <xsl:value-of select="@type"/>
      </Data>
    </Cell>
  </xsl:template>
  <xsl:template match="datatype" mode="record">
    <Row>
      <Cell ss:Index="2">
        <Data ss:Type="String">
          <xsl:if test="@name"><xsl:value-of select="@name"/> - </xsl:if>
          <xsl:value-of select="@type"/>
        </Data>
      </Cell>
    </Row>
  </xsl:template>
  <!--=== Output Description ==-->
  <xsl:template match="*" mode="outputdescription">
    <Data ss:Type="String">
      <xsl:value-of select="@description"/>
      <xsl:if test="@unused">(Unused)</xsl:if>
      <xsl:if test="@deleted">(Deleted)</xsl:if>
    </Data>
    <xsl:if test="@footnote">
      <Comment ss:ShowAlways="1">
        <ss:Data>
          <xsl:value-of select="@footnote"/>
        </ss:Data>
      </Comment>
    </xsl:if>
  </xsl:template>
</xsl:stylesheet>
