SRC=siso-std-010.xml
XSD=siso-std-010.xsd

DBK=docbook.xml
PDF=siso-std-010.pdf
RTF=siso-std-010.doc
XLS=siso-std-010.xls
SQL=siso-std-010.sql

all: $(PDF) $(RTF) $(XLS) $(SQL)

$(PDF): $(DBK)
	docbook2pdf $^
	mv docbook.pdf $@

$(RTF): $(DBK)
	docbook2rtf $^
	mv docbook.rtf $@

$(DBK): xml2docbook.xslt $(SRC)
	xsltproc --output $@ $^

$(XLS): xml2excel.xslt $(SRC)
	xsltproc --nonet --output $@ $^

$(SQL): xml2sql.xslt $(SRC)
	xsltproc --nonet --output $@ $^

.PHONY: tarball
tarball:
	zip -9r siso-std-010-mrebv-r`svnversion -n`.zip .

.PHONY: tarball2
tarball2:
	zip -9r siso-std-010-mrebv-r`svnversion -n`.zip . -x ".svn/*"

clean:
	rm -f $(DBK) $(PDF) $(RTF) $(XLS) $(SQL)

test:
	xmllint --nonet --noout xml2docbook.xslt
	xmllint --nonet --noout xml2excel.xslt
	xmllint --nonet --noout xml2sql.xslt
	xmllint --nonet --noout $(XSD)
	xmllint --nonet --noout --schema $(XSD) $(SRC)

sqlite3test: $(SQL)
	less $(SQL)
	-rm test.db
	sqlite3 test.db < siso-std-010-schema-sqlite3.sql
	sqlite3 test.db < $(SQL)
	sqlite3 test.db '.dump'
