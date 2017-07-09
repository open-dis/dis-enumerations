Machine Readable EBV, Draft $Revision: 34 $


FILES LISTING
=============

/
README.txt
siso-std-010.xsd        EBV Schema
siso-std-010.xml        EBV data file
xml2excel.xslt          EBV to Microsoft Excel translator
xml2docbook.xslt        EBV to DocBook translator
xml2sql.xslt		EBV to SQL translator
siso-std-010-schema-sqlite3.sql		SQL Schema
Makefile                Makefile to automate translation of XML to PDF/RTF/Excel.


USAGE EXAMPLES
=================
There are many ways to use the Machine Readable EBV. Here are two simple examples.

Unix - Generate PDF:
  Install "make", "xsltproc" and "docbook" packages. These packages are included with Debian and Fedora linux.
  $ xsltproc --output docbook.xml xml2docbook.xslt siso-std-010.xml
  $ docbook2pdf docbook.xml
  $ mv temp.xml siso-std-010.pdf

Microsoft Windows - Generate Excel file:
  Install Cygwin (http://www.cygwin.com/) and select the "libxslt" package.
  $ xsltproc --output siso-std-010.xls xml2excel.xslt siso-std-010.xml


TODO LIST
=========
The following problems are known to exist with the document.
* Deleted Entity Type enumeration are assigned the "(Deleted") or "(Unused)" text that is present in SISO-STD-010(2006). These need to be changed to use the XML deleted and unused attributes.
* Records have been included, but the xml schema was assembled in haste. More thought is needed.
* The presentation of the PDF/DOC document needs improving.
    * The title page is bland.
    * The header on each page lists the chapter number. Modify heading to show the country for the Comprehensive Entity Types section.
    * Add copyright statment to footer.
    * Section 4.2.3. Comprehensive Entity Type enumerations are not indented. This appears to be a limitation of DocBook.
    * Section 12.3.3.1 and 12.3.3.2. Decimal enumerations are shown, however original document used hexadecimal.
    * Section 4.5. CCTT and Digit Chevron special characters are not show (underscore, up and down arrow).
    * Section 7.1. The square symbol appears in document as "^2". The trademark symbol appears in document as "(tm)".
    * Footnotes are included inside the given enumeration table, and are not superscript.
    * Records are displayed used wide tables. Width should be reduced for consistency with the IEEE document. (This would also make it easier to discern them from the other enumeration tables).


DEVIATIONS FROM SISO-STD-010(2006)
==================================
This draft release is intended to replicate the full contents SISO-STD-010(2006). The following changes were made.
* Chapter 1, paragraph 2, changed "constituting Sections 3-9" to "Sections 3-12"
* Chapter 2, TBD removed from acronynm list.
* Section 4.7.1.2. Have defined concept of "offset" and "base" numbers for Articulated Parts.
* Section 8.3, Have reduced the verbosity of the IFF section.


RELEASE HISTORY
===============
draft1, 2007-12-21
draft2, 2008-09-03


CONTRIBUTORS
============
Peter Ross <peter.ross@dsto.defence.gov.au>
